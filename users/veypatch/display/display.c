// Copyright 2025 VeyPatch (126267034+VeyPatch@users.noreply.github.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "config.h"
#include "qp.h"
#include "qp_surface.h"
#include "display.h"
#include "modules/drashna/layer_map/layer_map.h"

// Images
#include "graphics/patchouli.qgf.h"

// Fonts mono2
#include "graphics/fonts/Retron2000-27.qff.h"
#include "graphics/fonts/Retron2000-underline-27.qff.h"
#include "graphics/fonts/fonts.qff.h"

static const char *caps =        "C";
static const char *num =         "N";
static const char *scroll =      "S";
const char *layer = "undef";
const char *os = "undef";

bool force_redraw;

static painter_font_handle_t Retron27;
static painter_font_handle_t Retron27_underline;
static painter_font_handle_t proggy_clean_15;
static painter_image_handle_t my_image;

painter_device_t lcd;
painter_device_t lcd_surface;

led_t last_led_usb_state = {0};
layer_state_t last_layer_state = {0};
os_variant_t last_os = {0};
static bool last_swap_state = false;

static uint16_t lcd_surface_fb[135*240];

// All values (including hue) are scaled to 0-255
#define HSV_SPLITKB 145, 235, 155
#define HSV_CAPS_OFF 17, 104, 77
#define HSV_CAPS_ON 17, 191, 245
#define HSV_SCROLL_OFF 202, 104, 77
#define HSV_SCROLL_ON 202, 191, 245
#define HSV_NUM_OFF 142, 104, 77
#define HSV_NUM_ON 142, 191, 245
#define HSV_SWAP_ON 145, 235, 155
#define HSV_SWAP_OFF 145, 191, 245

#define HSV_LAYER_0 0, 0, 160
#define HSV_LAYER_3 0, 82, 255
#define HSV_LAYER_1 23, 89, 255
#define HSV_LAYER_2 43, 71, 255
#define HSV_LAYER_4 77, 64, 255
#define HSV_LAYER_6 131, 99, 255
#define HSV_LAYER_7 154, 94, 255
#define HSV_LAYER_5 176, 77, 255
// #define HSV_LAYER_8 213, 56, 255
#define HSV_LAYER_UNDEF 0, 255, 255

// clang-format off
__attribute__((weak)) const char PROGMEM code_to_name[256] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    c    D    E    F
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0', 'E', 'E', 'B', 'T', '_', '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/', 'C', 'F', 'F', 'F', 'F', 'F', 'F',  // 3x
    'F', 'F', 'F', 'F', 'F', 'F', 'P', 'S',  19, ' ', ' ', ' ', 'D', ' ', ' ', 'R',  // 4x
    'L', 'D', 'U', 'N', '/', '*', '-', '+',  23, '1', '2', '3', '4', '5', '6', '7',  // 5x
    '8', '9', '0', '.','\\', 'A',   0, '=', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M', 'V', 'V', ' ', ' ', ' ', ' ', ' ',  // Ax
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M', 'M', 'M',  // Cx
    'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M',  // Dx
    'C', 'S', 'A', 'G', 'C', 'S', 'A', 'G', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ex
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '   // Fx
};
// clang-format on

uint16_t extract_basic_keycode(uint16_t keycode, keyrecord_t *record, bool check_hold) {
    if (IS_QK_MOD_TAP(keycode)) {
        if (record->tap.count || !check_hold) {
            keycode = keycode_config(QK_MOD_TAP_GET_TAP_KEYCODE(keycode));
        } else {
            keycode = keycode_config(0xE0 + biton(QK_MOD_TAP_GET_MODS(keycode) & 0xF) +
                                     biton(QK_MOD_TAP_GET_MODS(keycode) & 0x10));
        }
    } else if (IS_QK_LAYER_TAP(keycode) && (record->tap.count || !check_hold)) {
        keycode = keycode_config(QK_LAYER_TAP_GET_TAP_KEYCODE(keycode));
    } else if (IS_QK_MODS(keycode)) {
        keycode = keycode_config(QK_MODS_GET_BASIC_KEYCODE(keycode));
    } else if (IS_QK_ONE_SHOT_MOD(keycode)) {
        keycode = keycode_config(0xE0 + biton(QK_ONE_SHOT_MOD_GET_MODS(keycode) & 0xF) +
                                 biton(QK_ONE_SHOT_MOD_GET_MODS(keycode) & 0x10));
    } else if (IS_QK_BASIC(keycode)) {
        keycode = keycode_config(keycode);
    }

    return keycode;
}

void update_display(void) {
    if(last_led_usb_state.raw != host_keyboard_led_state().raw || force_redraw) {
        led_t led_usb_state = host_keyboard_led_state();

        led_usb_state.caps_lock   ? qp_drawtext_recolor(lcd_surface, 5, Retron27->line_height * 2.5, Retron27_underline, caps,   HSV_CAPS_ON,   HSV_BLACK) : qp_drawtext_recolor(lcd_surface, 5, Retron27->line_height * 2.5, Retron27, caps,   HSV_CAPS_OFF,   HSV_BLACK);
        led_usb_state.num_lock    ? qp_drawtext_recolor(lcd_surface, (LCD_WIDTH - qp_textwidth(Retron27, scroll)) / 2, Retron27->line_height * 2.5, Retron27_underline, num,    HSV_NUM_ON,    HSV_BLACK) : qp_drawtext_recolor(lcd_surface, (LCD_WIDTH - qp_textwidth(Retron27, scroll)) / 2, Retron27->line_height * 2.5, Retron27, num,    HSV_NUM_OFF,    HSV_BLACK);
        led_usb_state.scroll_lock ? qp_drawtext_recolor(lcd_surface, LCD_WIDTH - qp_textwidth(Retron27, scroll) - 5, Retron27->line_height * 2.5, Retron27_underline, scroll, HSV_SCROLL_ON, HSV_BLACK) : qp_drawtext_recolor(lcd_surface, LCD_WIDTH - qp_textwidth(Retron27, scroll) - 5, Retron27->line_height * 2.5, Retron27, scroll, HSV_SCROLL_OFF, HSV_BLACK);

        last_led_usb_state = led_usb_state;
    }

    if(last_layer_state != layer_state || force_redraw) {
        qp_rect(lcd_surface, 5, 5, LCD_WIDTH, Retron27->line_height + 5, HSV_BLACK, true);
        switch (get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            layer = "Default";
            qp_drawtext_recolor(lcd_surface, 5, 5, Retron27_underline, layer, HSV_LAYER_0, HSV_BLACK);
            break;
        case 1:
            layer = "Dvorak";
            qp_drawtext_recolor(lcd_surface, 5, 5, Retron27_underline, layer, HSV_LAYER_1, HSV_BLACK);
            break;
        case 2:
            layer = "Colemak";
            qp_drawtext_recolor(lcd_surface, 5, 5, Retron27_underline, layer, HSV_LAYER_2, HSV_BLACK);
            break;
        case 3:
            layer = "Symbol";
            qp_drawtext_recolor(lcd_surface, 5, 5, Retron27_underline, layer, HSV_LAYER_3, HSV_BLACK);
            break;
        case 4:
            layer = "Nav";
            qp_drawtext_recolor(lcd_surface, 5, 5, Retron27_underline, layer, HSV_LAYER_4, HSV_BLACK);
            break;
        case 5:
            layer = "Function";
            qp_drawtext_recolor(lcd_surface, 5, 5, Retron27_underline, layer, HSV_LAYER_5, HSV_BLACK);
            break;
        case 6:
            layer = "Adjust";
            qp_drawtext_recolor(lcd_surface, 5, 5, Retron27_underline, layer, HSV_LAYER_6, HSV_BLACK);
            break;
        case 7:
            layer = "Game";
            qp_drawtext_recolor(lcd_surface, 5, 5, Retron27_underline, layer, HSV_LAYER_7, HSV_BLACK);
            break;
        default:
            layer = "Undef";
            qp_drawtext_recolor(lcd_surface, 5, 5, Retron27_underline, layer, HSV_LAYER_UNDEF, HSV_BLACK);
        }
        last_layer_state = layer_state;
    }

    bool current_swap_state = is_swap_hands_on();
    if (last_swap_state != current_swap_state || force_redraw) {
        is_swap_hands_on()
        ? qp_drawtext_recolor(
              lcd_surface,
              5,
              Retron27->line_height * 3.75,
              Retron27_underline,
              "Swap",
              HSV_SWAP_ON,
              HSV_BLACK
          )
        : qp_drawtext_recolor(
              lcd_surface,
              5,
              Retron27->line_height * 3.75,
              Retron27,
              "Swap",
              HSV_SWAP_OFF,
              HSV_BLACK
          );
        last_swap_state = current_swap_state;
    }
}

void update_layer_map(void) {
    if (get_layer_map_has_updated()) {
        uint16_t x = 0;
        uint16_t y = 160;
        uint16_t xpos = x, ypos = y;
        for (uint8_t lm_y = 0; lm_y < LAYER_MAP_ROWS; lm_y++) {
            xpos = x + 5;
            for (uint8_t lm_x = 0; lm_x < LAYER_MAP_COLS; lm_x++) {
                uint16_t keycode = extract_basic_keycode(layer_map[lm_y][lm_x], NULL, false);
                wchar_t  code[2] = {0};
                if (keycode > 0xFF) {
                    keycode = KC_SPC;
                }
                if (keycode < ARRAY_SIZE(code_to_name)) {
                    code[0] = pgm_read_byte(&code_to_name[keycode]);
                }
                xpos += qp_drawtext_recolor(
                    lcd_surface, xpos, ypos, proggy_clean_15, (char*)code,
                    0, 0, peek_matrix_layer_map(lm_y, lm_x) ? 0 : 255,
                    200, 255, peek_matrix_layer_map(lm_y, lm_x) ? 255 : 0);
                xpos += qp_drawtext_recolor(lcd_surface, xpos, ypos, proggy_clean_15, "", 0, 0, 0, 0, 0, 0);
            }
            ypos += proggy_clean_15->line_height + 4;
        }
        set_layer_map_has_updated(false);
    }
}

void display_detected_host_os_user(void) {
    os_variant_t detected_os = detected_host_os();
    qp_rect(lcd_surface, 5, Retron27->line_height * 1.25, LCD_WIDTH, Retron27->line_height * 2.5, HSV_BLACK, true);

    switch (detected_os) {
        case OS_MACOS:
            os = "Apple";
            qp_drawtext_recolor(lcd_surface, 5, Retron27->line_height * 1.25, Retron27, os, HSV_PURPLE, HSV_BLACK);
            break;
        case OS_IOS:
            os = "Apple";
            qp_drawtext_recolor(lcd_surface, 5, Retron27->line_height * 1.25, Retron27, os, HSV_PURPLE, HSV_BLACK);
            break;
        case OS_WINDOWS:
            os = "Windows";
            qp_drawtext_recolor(lcd_surface, 5, Retron27->line_height * 1.25, Retron27, os, HSV_PURPLE, HSV_BLACK);
            break;
        case OS_LINUX:
            os = "Linux";
            qp_drawtext_recolor(lcd_surface, 5, Retron27->line_height * 1.25, Retron27, os, HSV_PURPLE, HSV_BLACK);
            break;
        case OS_UNSURE:
            os = "Unsure";
            qp_drawtext_recolor(lcd_surface, 5, Retron27->line_height * 1.25, Retron27, os, HSV_PURPLE, HSV_BLACK);
            break;
    }
}

void display_post_init_user(void) {
    // Turn on backlight
    backlight_enable();

    // Make the devices
    lcd = qp_st7789_make_spi_device(LCD_WIDTH, LCD_HEIGHT, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, LCD_SPI_MODE);
    lcd_surface = qp_make_rgb565_surface(LCD_WIDTH, LCD_HEIGHT, lcd_surface_fb);

    // Initialise the LCD
    qp_init(lcd, LCD_ROTATION);
    qp_set_viewport_offsets(lcd, LCD_OFFSET_X, LCD_OFFSET_Y);
    qp_clear(lcd);
    qp_rect(lcd, 0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, HSV_BLACK, true);
    qp_power(lcd, true);
    qp_flush(lcd);

    // Initialise the LCD surface
    qp_init(lcd_surface, LCD_ROTATION);
    qp_rect(lcd_surface, 0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, HSV_BLACK, true);
    qp_surface_draw(lcd_surface, lcd, 0, 0, 0);
    qp_flush(lcd);

    force_redraw = 1;

    if(is_keyboard_master()) {
        Retron27 = qp_load_font_mem(font_Retron2000_27);
        Retron27_underline = qp_load_font_mem(font_Retron2000_underline_27);
        proggy_clean_15 = qp_load_font_mem(font_proggy_clean_15);
    }

    if (!is_keyboard_master()) {
        my_image = qp_load_image_mem(gfx_Untitled);
        qp_drawimage(lcd, 0, 0, my_image);
    }
}

void display_housekeeping_task_user(void) {
    if (is_keyboard_master()) {
        static uint32_t previous_matrix_activity_time = 0;
        if (previous_matrix_activity_time != last_matrix_activity_time()) {
            set_layer_map_dirty();
            previous_matrix_activity_time = last_matrix_activity_time();
        }
        update_display();
        update_layer_map();
        if(force_redraw == 1) {
            display_detected_host_os_user();
        }

        qp_surface_draw(lcd_surface, lcd, 0, 0, 0);

        force_redraw = 0;
    }
}

// Copyright 2025 VeyPatch (126267034+VeyPatch@users.noreply.github.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "config.h"
#include "qp.h"
#include "qp_surface.h"
#include "display.h"

// Images
#include "graphics/patchouli.qgf.h"

// Fonts mono2
#include "graphics/fonts/Retron2000-27.qff.h"
#include "graphics/fonts/Retron2000-underline-27.qff.h"

static const char *caps =        "Caps";
static const char *num =         "Num";
static const char *scroll =      "Scroll";
const char *layer = "undef";

static painter_font_handle_t Retron27;
static painter_font_handle_t Retron27_underline;
static painter_image_handle_t my_image;

painter_device_t lcd;
painter_device_t lcd_surface;

led_t last_led_usb_state = {0};
layer_state_t last_layer_state = {0};

static uint16_t lcd_surface_fb[135*240];

// All values (including hue) are scaled to 0-255
#define HSV_SPLITKB 145, 235, 155
#define HSV_CAPS_OFF 17, 104, 77
#define HSV_CAPS_ON 17, 191, 245
#define HSV_SCROLL_OFF 202, 104, 77
#define HSV_SCROLL_ON 202, 191, 245
#define HSV_NUM_OFF 142, 104, 77
#define HSV_NUM_ON 142, 191, 245

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

bool backlight_off = false;

// Timeout handling
void backlight_wakeup(void) {
    backlight_off = false;
    backlight_enable();
    if (get_backlight_level() == 0) {
        backlight_level(BACKLIGHT_LEVELS);
    }
}

// Timeout handling
void backlight_suspend(void) {
    backlight_off = true;
    backlight_disable();
}

void update_display(void) {
    static bool first_run_led = false;
    static bool first_run_layer = false;

    if(last_led_usb_state.raw != host_keyboard_led_state().raw || first_run_led == false) {
        led_t led_usb_state = host_keyboard_led_state();

        led_usb_state.caps_lock   ? qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height * 3 - 15, Retron27_underline, caps,   HSV_CAPS_ON,   HSV_BLACK) : qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height * 3 - 15, Retron27, caps,   HSV_CAPS_OFF,   HSV_BLACK);
        led_usb_state.num_lock    ? qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height * 2 - 10, Retron27_underline, num,    HSV_NUM_ON,    HSV_BLACK) : qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height * 2 - 10, Retron27, num,    HSV_NUM_OFF,    HSV_BLACK);
        led_usb_state.scroll_lock ? qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height - 5,      Retron27_underline, scroll, HSV_SCROLL_ON, HSV_BLACK) : qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height - 5,      Retron27, scroll, HSV_SCROLL_OFF, HSV_BLACK);

        last_led_usb_state = led_usb_state;
        first_run_led = true;
    }

    if(last_layer_state != layer_state || first_run_layer == false) {
        qp_rect(lcd_surface, 5, 5, LCD_WIDTH, Retron27->line_height + 5, HSV_BLACK, true);
        switch (get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            layer = "Qwerty";
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
            qip_drawtext_recolor(lcd_surface, 5, 5, Retron27_underline, layer, HSV_LAYER_6, HSV_BLACK);
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
        first_run_layer = true;
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

    if(is_keyboard_master()) {
        Retron27 = qp_load_font_mem(font_Retron2000_27);
        Retron27_underline = qp_load_font_mem(font_Retron2000_underline_27);
    }

    if (!is_keyboard_master()) {
        my_image = qp_load_image_mem(gfx_Untitled);
        qp_drawimage(lcd, 0, 0, my_image);
    }
}

void display_housekeeping_task_user(void) {
    if (is_keyboard_master()) {
        update_display();
        qp_surface_draw(lcd_surface, lcd, 0, 0, 0);
    }

    // Backlight feature
    if (last_input_activity_elapsed() <= HLC_BACKLIGHT_TIMEOUT) {
        if (backlight_off) {
            backlight_wakeup();
        }
    } else {
        if (!backlight_off) {
            backlight_suspend();
        }
    }
}

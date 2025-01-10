// Copyright 2025 VeyPatch (126267034+VeyPatch@users.noreply.github.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "qp.h"
#include "qp_surface.h"
#include "display.h"

// Images
#include "graphics/patchouli.qgf.h"

// Fonts mono2
#include "graphics/fonts/Retron2000-27.qff.h"
#include "graphics/fonts/Retron2000-underline-27.qff.h"

// Numbers mono2
#include "graphics/numbers/0.qgf.h"
#include "graphics/numbers/1.qgf.h"
#include "graphics/numbers/2.qgf.h"
#include "graphics/numbers/3.qgf.h"
#include "graphics/numbers/4.qgf.h"
#include "graphics/numbers/5.qgf.h"
#include "graphics/numbers/6.qgf.h"
#include "graphics/numbers/7.qgf.h"
#include "graphics/numbers/8.qgf.h"
#include "graphics/numbers/9.qgf.h"
#include "graphics/numbers/undef.qgf.h"

static const char *caps =        "Caps";
static const char *num =         "Num";
static const char *scroll =      "Scroll";

static painter_font_handle_t Retron27;
static painter_font_handle_t Retron27_underline;
static painter_image_handle_t layer_number;
static painter_image_handle_t my_image;

static uint8_t lcd_surface_fb[SURFACE_REQUIRED_BUFFER_BYTE_SIZE(135, 240, 16)];

painter_device_t lcd;
painter_device_t lcd_surface;

led_t last_led_usb_state = {0};
layer_state_t last_layer_state = {0};

void update_display(void) {
    static bool first_run_led = false;
    static bool first_run_layer = false;

    if( first_run_layer == false) {
        // Load fonts
        Retron27 = qp_load_font_mem(font_Retron2000_27);
        Retron27_underline = qp_load_font_mem(font_Retron2000_underline_27);
    }

    if(last_led_usb_state.raw != host_keyboard_led_state().raw || first_run_led == false) {
        led_t led_usb_state = host_keyboard_led_state();

        led_usb_state.caps_lock   ? qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height * 3 - 15, Retron27_underline, caps,   HSV_CAPS_ON,   HSV_BLACK) : qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height * 3 - 15, Retron27, caps,   HSV_CAPS_OFF,   HSV_BLACK);
        led_usb_state.num_lock    ? qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height * 2 - 10, Retron27_underline, num,    HSV_NUM_ON,    HSV_BLACK) : qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height * 2 - 10, Retron27, num,    HSV_NUM_OFF,    HSV_BLACK);
        led_usb_state.scroll_lock ? qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height - 5,      Retron27_underline, scroll, HSV_SCROLL_ON, HSV_BLACK) : qp_drawtext_recolor(lcd_surface, 5, LCD_HEIGHT - Retron27->line_height - 5,      Retron27, scroll, HSV_SCROLL_OFF, HSV_BLACK);

        last_led_usb_state = led_usb_state;
        first_run_led = true;
    }

    if(last_layer_state != layer_state || first_run_layer == false) {
        switch (get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            layer_number = qp_load_image_mem(gfx_0);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_0, HSV_BLACK);
            break;
        case 1:
            layer_number = qp_load_image_mem(gfx_1);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_1, HSV_BLACK);
            break;
        case 2:
            layer_number = qp_load_image_mem(gfx_2);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_2, HSV_BLACK);
            break;
        case 3:
            layer_number = qp_load_image_mem(gfx_3);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_3, HSV_BLACK);
            break;
        case 4:
            layer_number = qp_load_image_mem(gfx_4);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_4, HSV_BLACK);
            break;
        case 5:
            layer_number = qp_load_image_mem(gfx_5);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_5, HSV_BLACK);
            break;
        case 6:
            layer_number = qp_load_image_mem(gfx_6);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_6, HSV_BLACK);
            break;
        case 7:
            layer_number = qp_load_image_mem(gfx_7);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_7, HSV_BLACK);
            break;
        default:
            layer_number = qp_load_image_mem(gfx_undef);
            qp_drawimage_recolor(lcd_surface, 5, 5, layer_number, HSV_LAYER_UNDEF, HSV_BLACK);
        }
        qp_close_image(layer_number);
        last_layer_state = layer_state;
        first_run_layer = true;
    }
}

void display_post_init_user(void) {
    // Turn on backlight
    backlight_enable();

    // Initialise the LCD
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
}

void display_housekeeping_task_user(void) {
    if(is_keyboard_master()) {
        update_display();
        // Move surface to lcd
        qp_surface_draw(lcd_surface, lcd, 0, 0, 0);
        qp_flush(lcd);
    } else {
        static bool display_set = false;
        if (!display_set) {
            my_image = qp_load_image_mem(gfx_Untitled);
            qp_drawimage(lcd_surface, 0, 0, my_image);
        }
    }
}

#include "hlc_tft_display/hlc_tft_display.h"
#include "qp_surface.h"
#include "patchouli.qgf.h"

static painter_image_handle_t my_image;

painter_device_t lcd;
painter_device_t lcd_surface;

bool module_post_init_user(void) {
    return false;
}

bool display_module_housekeeping_task_user(bool second_display) {
    static bool display_set = false;

    if(second_display) {
        if (!display_set) {
            my_image = qp_load_image_mem(gfx_Untitled);
            qp_drawimage(lcd_surface, 0, 0, my_image);
        }
    }

    if(!second_display) {
        update_display();
    }

    qp_surface_draw(lcd_surface, lcd, 0, 0, 0);
    qp_flush(lcd);

    return false;
}

// Copyright 2025 VeyPatch (126267034+VeyPatch@users.noreply.github.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "veypatch.h"

#ifdef HALCYON_ENABLE
#   include "display/display.h"
#endif
#ifdef LIATRIS_ENABLE
#   include "arm/liatris/liatris.h"
#endif

void keyboard_pre_init_user(void) {
#ifdef LIATRIS_ENABLE
    liatris_pre_init_user();
#endif
}

void keyboard_post_init_user(void) {
#ifdef HALCYON_ENABLE
    display_post_init_user();
#endif
}

void housekeeping_task_user(void) {
#ifdef HALCYON_ENABLE
    display_housekeeping_task_user();
#endif
}

#if defined(OS_DETECTION_ENABLE)
bool process_detected_host_os_user(os_variant_t detected_os) {
    if (is_keyboard_master()) {

        switch (detected_os) {
            case OS_IOS:
            case OS_MACOS:
                keymap_config.swap_lctl_lgui = true;
                break;
            default:
                keymap_config.swap_lctl_lgui = false;
                break;
        }
    }
#ifdef HALCYON_ENABLE
    display_detected_host_os_user();
#endif

    return true;
}
#endif // OS_DETECTION_ENABLE

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _FUNCTION);
}

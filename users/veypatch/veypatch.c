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

bool process_detected_host_os_user(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }

    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            tap_code16(QK_MAGIC_SWAP_CTL_GUI); // Swap Ctrl and GUI
            break;
        case OS_WINDOWS:
        case OS_LINUX:
        case OS_UNSURE:
            tap_code16(QK_MAGIC_UNSWAP_CTL_GUI);
            break;
    }

    return true;
}

// Copyright 2025 VeyPatch (126267034+VeyPatch@users.noreply.github.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "veypatch.h"
#ifdef HALCYON_ENABLE
#include "display/display.h"
#endif
#ifdef LIATRIS_ENABLE
#include "arm/liatris/liatris.h"
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

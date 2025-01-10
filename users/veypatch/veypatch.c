// Copyright 2025 VeyPatch (126267034+VeyPatch@users.noreply.github.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "veypatch.h"
#include "display/display.h"


void keyboard_pre_init_user(void) {
}

void keyboard_post_init_user(void) {
    display_post_init_user();
}

void housekeeping_task_user(void) {
    display_housekeeping_task_user();
}

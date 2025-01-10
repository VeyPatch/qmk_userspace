// Copyright 2025 VeyPatch (126267034+VeyPatch@users.noreply.github.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

void display_housekeeping_task_user(void);
void display_post_init_user(void);

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

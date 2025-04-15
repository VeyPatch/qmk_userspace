// Copyright 2025 VeyPatch (126267034+VeyPatch@users.noreply.github.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define BACKLIGHT_LEVELS 10

#define LCD_WIDTH 135
#define LCD_HEIGHT 240
#define LCD_ROTATION QP_ROTATION_0
#define LCD_OFFSET_X 52
#define LCD_OFFSET_Y 40

// QP Configuration
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
#define ST7789_NO_AUTOMATIC_VIEWPORT_OFFSETS
#define ST7789_NUM_DEVICES 1

#define SURFACE_NUM_DEVICES 1

#define CUSTOM_QUANTUM_PAINTER_ENABLE

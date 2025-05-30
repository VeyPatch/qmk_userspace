// Copyright 2025 VeyPatch (126267034+VeyPatch@users.noreply.github.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include QMK_KEYBOARD_H

#include "keyrecords/wrappers.h"

extern bool force_redraw;

enum layers {
    _QWERTY = 0,
    _DVORAK,
    _COLEMAK,
    _SYM,
    _NAV,
    _FUNCTION,
    _ADJUST,
    _GAME,
};

enum unicode_names {
    EM_DASH,
    SNEK,
    CHECK,
    CROSS
};

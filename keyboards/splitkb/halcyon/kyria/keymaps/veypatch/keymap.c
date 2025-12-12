// Copyright 2025 VeyPatch (126267034+VeyPatch@users.noreply.github.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _SYM,
    _NAV,
    _FUNCTION,
    _ADJUST,
    _GAME,
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _FUNCTION);
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_5(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______, _______, _______, TG(_GAME), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_PSCR,
                      KC_LGUI, KC_LALT, KC_DEL, KC_LSFT, LT(_SYM, KC_ENTER), LT(_NAV, KC_TAB), KC_SPC, KC_BSPC, KC_APP,  MO(_ADJUST)
    ),

    [_SYM] = LAYOUT_split_3x6_5(
        _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                     _______, _______, KC_PIPE, KC_BSLS, KC_ESC,  _______,
        _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                      KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_QUOT, _______,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_EQL,  KC_UNDS, KC_AMPR, _______, KC_DQUO, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT_split_3x6_5(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   _______,
        _______, _______, _______, _______, KC_MUTE, KC_VOLD, _______, _______, _______,  _______, KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_FUNCTION] = LAYOUT_split_3x6_5(
        _______, KC_F1,  KC_F2,   KC_F3,   KC_F4,   _______,                                     KC_NUM,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_PMNS,
        _______, KC_F5,  KC_F6,   KC_F7,   KC_F8,   _______,                                     _______,  KC_P4,   KC_P5,   KC_P6,   KC_PEQL, KC_PAST,
        _______, KC_F9,  KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_PSLS,
                                  _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT
    ),

    [_ADJUST] = LAYOUT_split_3x6_5(
        _______, QK_BOOT, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                     RM_TOGG, RM_SATU, RM_HUEU, RM_VALU, RM_NEXT, RM_SPDU,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_SATD, RM_HUED, RM_VALD, RM_PREV, RM_SPDD,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_GAME] = LAYOUT_split_3x6_5(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                       _______, _______, _______, _______, _______, KC_BSPC,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   _______,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______, _______, _______, TG(_GAME), KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_PSCR,
                      KC_LGUI, KC_LALT, KC_DEL, KC_SPC, LT(_SYM, KC_ENTER), LT(_NAV, KC_TAB), KC_SPC, KC_BSPC, KC_APP,  MO(_ADJUST)
    )
};
// clang-format on

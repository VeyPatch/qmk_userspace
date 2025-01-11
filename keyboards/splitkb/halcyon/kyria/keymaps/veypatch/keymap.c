// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "veypatch.h"

enum layers {
    _QWERTY = 0,
    _DVORAK,
    _COLEMAK_DH,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
#define LAYOUT_kyria_base( \
    K01, K02, K03, K04, K05,                     K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15,                     K16, K17, K18, K19, K1A, K1B, \
    K21, K22, K23, K24, K25,                     K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
  KC_ESC,  K01, K02,     K03,    K04,     K05,                                                      K06,     K07, K08, K09, K0A, KC_BSPC , \
  KC_LSFT, K11, K12,     K13,    K14,     K15,                                                      K16,     K17, K18, K19, K1A, K1B,      \
  KC_LCTL, K21, K22,     K23,    K24,     K25,     KC_F23,          KC_CAPS,       KC_F22, KC_F24,  K26,     K27, K28, K29, K2A, KC_PSCR , \
                KC_LGUI, KC_DEL, KC_LALT, KC_LSFT, LT(3, KC_ENTER), LT(4, KC_TAB), KC_SPC, KC_BSPC, KC_RGUI, KC_APP \
    )
/* Re-pass though to allow templates to be used */
#define LAYOUT_base_wrapper(...)       LAYOUT_kyria_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),
    [_DVORAK] = LAYOUT_base_wrapper(
        _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
        _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
        _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
    ),
    [_COLEMAK_DH] = LAYOUT_base_wrapper(
        _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
        _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
        _________________COLEMAK_L3________________, _________________COLEMAK_R3________________
    ),
    [_NAV] = LAYOUT(
        _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_BSLS),                                     _______     , _______, _______, KC_BSLS   , _______, _______,
        _______, LSFT(KC_3), LSFT(KC_4), LSFT(KC_9)   , LSFT(KC_0)   , KC_GRV       ,                                     LSFT(KC_EQL), KC_MINS, KC_SLSH, LSFT(KC_8), _______, _______,
        _______, LSFT(KC_5), LSFT(KC_6), KC_LBRC      , KC_RBRC      , LSFT(KC_GRV) , _______, _______, _______, _______, LSFT(KC_7)  , KC_EQL , _______, _______   , _______, _______,
                             _______   , _______      , _______      , _______      , _______, MO(5)  , _______, _______, _______     , _______

    ),
    [_SYM] = LAYOUT(
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
        _______, _______, _______, _______, KC_MUTE, KC_VOLD, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
                          _______, MO(6)  , _______, _______, MO(5)  , _______, _______, _______, _______, _______
    ),
    [_FUNCTION] = LAYOUT(
        _______, KC_F1, KC_F2  , KC_F3  , KC_F4  , _______,                                     KC_NUM , KC_P7  , KC_P8, KC_P9, KC_PPLS, KC_PMNS,
        _______, KC_F5, KC_F6  , KC_F7  , KC_F8  , _______,                                     _______, KC_P4  , KC_P5, KC_P6, KC_PEQL, KC_PAST,
        _______, KC_F9, KC_F10 , KC_F11 , KC_F12 , _______, _______, _______, _______, _______, _______, KC_P1  , KC_P2, KC_P3, KC_PENT, KC_PSLS,
                        _______, _______, _______, _______, _______, _______, _______, _______, KC_P0  , KC_PDOT
    ),
    [_ADJUST] = LAYOUT(
        QK_BOOT, _______, _______, DF(0)  , _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, DF(1)  , _______, _______,                                     RM_TOGG, RM_SATU, RM_HUEU, RM_VALU, RM_NEXT, RM_SPDU,
        _______, _______, _______, DF(2)  , _______, _______, _______, _______, _______, _______, _______, RM_SATD, RM_HUED, RM_VALD, RM_PREV, RM_SPDD,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

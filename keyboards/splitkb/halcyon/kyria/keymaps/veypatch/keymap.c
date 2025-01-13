// Copyright 2025 VeyPatch (126267034+VeyPatch@users.noreply.github.com)
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
  KC_LCTL, K21, K22,     K23,    K24,     K25,     KC_F23,             KC_CAPS,          KC_F22, KC_F24,  K26,     K27, K28, K29, K2A, KC_PSCR , \
                KC_LGUI, KC_DEL, KC_LALT, KC_LSFT, LT(_NAV, KC_ENTER), LT(_SYM, KC_TAB), KC_SPC, KC_BSPC, KC_RGUI, KC_APP \
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
    [_NAV] = LAYOUT_wrapper(
        _______, ________________SYMBOLS_L1_________________,                                             ________________SYMBOLS_R1_________________, _______,
        _______, ________________SYMBOLS_L2_________________,                                             ________________SYMBOLS_R2_________________, _______,
        _______, ________________SYMBOLS_L3_________________, _______, _______, _______,         _______, ________________SYMBOLS_R3_________________, _______,
                                   _______, _______, _______, _______, _______, MO(_FUNCTION)  , _______, _______, _______, _______

    ),
    [_SYM] = LAYOUT_wrapper(
        _______, ________________NUMBER_LEFT________________,                                           ________________NUMBER_RIGHT_______________, _______,
        _______, _________________MEDIA_L2__________________,                                           ________________ARROWS_R2__________________, _______,
        _______, _________________MEDIA_L3__________________, _______, _______,       _______, _______, ________________ARROWS_R3__________________, _______,
                               _______, MO(_ADJUST), _______, _______, MO(_FUNCTION), _______, _______, _______, _______, _______
    ),
    [_FUNCTION] = LAYOUT_wrapper(
        _______, _________________FUNC_L1___________________,                                     __________________NUM_R1___________________, KC_PMNS,
        _______, _________________FUNC_L2___________________,                                     __________________NUM_R2___________________, KC_PAST,
        _______, _________________FUNC_L3___________________, _______, _______, _______, _______, __________________NUM_R3___________________, KC_PSLS,
                          _______, _______, _______, _______, _______, _______, _______, _______, __________________NUM_R4___________________
    ),
    [_ADJUST] = LAYOUT_wrapper(
        _______, __________________DF_L1____________________,                                     ___________________BLANK___________________, _______,
        _______, __________________DF_L2____________________,                                     __________________RGB_R1___________________, RM_SPDU,
        _______, __________________DF_L3____________________, _______, _______, _______, _______, __________________RGB_R2___________________, RM_SPDD,
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

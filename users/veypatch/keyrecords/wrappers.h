// Copyright 2025 VeyPatch (126267034+VeyPatch@users.noreply.github.com)
// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2020 @jola5
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/
// clang-format off
#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________       KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT
#define _________________COLEMAK_R3________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________DVORAK_L1_________________       KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define _________________DVORAK_L2_________________       KC_A,    KC_O,    KC_E,   KC_U,     KC_I
#define _________________DVORAK_L3_________________       KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define _________________DVORAK_R1_________________       KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _________________DVORAK_R2_________________       KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH
#define _________________DVORAK_R3_________________       KC_B,    KC_M,    KC_W,    KC_V,    KC_Z


#define ________________DVORAK_AU_L1_______________       KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define ________________DVORAK_AU_L2_______________       KC_O,    KC_A,    KC_E,   KC_I,     KC_U
#define ________________DVORAK_AU_L3_______________       KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define ________________DVORAK_AU_R1_______________       KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define ________________DVORAK_AU_R2_______________       KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH
#define ________________DVORAK_AU_R3_______________       KC_B,    KC_M,    KC_W,    KC_V,    KC_Z

#define _________________WORKMAN_L1________________       KC_Q,    KC_D,    KC_R,   KC_W,     KC_B
#define _________________WORKMAN_L2________________       KC_A,    KC_S,    KC_H,   KC_T,     KC_G
#define _________________WORKMAN_L3________________       KC_Z,    KC_X,    KC_M,   KC_C,     KC_V

#define _________________WORKMAN_R1________________       KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN
#define _________________WORKMAN_R2________________       KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT
#define _________________WORKMAN_R3________________       KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________NORMAN_L1_________________       KC_Q,    KC_W,    KC_D,    KC_F,    KC_K
#define _________________NORMAN_L2_________________       KC_A,    KC_S,    KC_E,    KC_T,    KC_G
#define _________________NORMAN_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________NORMAN_R1_________________       KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN
#define _________________NORMAN_R2_________________       KC_Y,    KC_N,    KC_I,    KC_O,    KC_U,    KC_QUOT
#define _________________NORMAN_R3_________________       KC_P,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________MALTRON_L1________________       KC_Q,    KC_P,    KC_Y,    KC_C,    KC_B
#define _________________MALTRON_L2________________       KC_A,    KC_N,    KC_I,    KC_S,    KC_F
#define _________________MALTRON_L3________________       KC_SCLN, KC_SLSH, KC_J,    KC_G,    KC_COMM

#define _________________MALTRON_R1________________       KC_V,    KC_M,    KC_U,    KC_Z,    KC_L
#define _________________MALTRON_R2________________       KC_D,    KC_T,    KC_D,    KC_O,    KC_R,    KC_QUOT
#define _________________MALTRON_R3________________       KC_DOT,  KC_W,    KC_K,    KC_MINS, KC_X


#define _________________EUCALYN_L1________________       KC_Q,    KC_W,    KC_COMM, KC_DOT,  KC_SCLN
#define _________________EUCALYN_L2________________       KC_A,    KC_O,    KC_E,    KC_I,    KC_U
#define _________________EUCALYN_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_F

#define _________________EUCALYN_R1________________       KC_M,    KC_R,    KC_D,    KC_Y,    KC_P
#define _________________EUCALYN_R2________________       KC_G,    KC_T,    KC_K,    KC_S,    KC_N,    KC_QUOT
#define _________________EUCALYN_R3________________       KC_B,    KC_H,    KC_J,    KC_L,    KC_SLSH

// Qwerty-like
#define _____________CARPLAX_QFMLWY_L1_____________       KC_Q,    KC_F,    KC_M,    KC_L,    KC_W
#define _____________CARPLAX_QFMLWY_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _____________CARPLAX_QFMLWY_L3_____________       KC_Z,    KC_V,    KC_G,    KC_C,    KC_X

#define _____________CARPLAX_QFMLWY_R1_____________       KC_Y,    KC_U,    KC_O,    KC_B,    KC_J
#define _____________CARPLAX_QFMLWY_R2_____________       KC_I,    KC_A,    KC_E,    KC_H,    KC_SCLN, KC_QUOT
#define _____________CARPLAX_QFMLWY_R3_____________       KC_P,    KC_K,    KC_COMM, KC_DOT,  KC_SLSH

// Colemak like
#define _____________CARPLAX_QGMLWB_L1_____________       KC_Q,    KC_G,    KC_M,    KC_L,    KC_W
#define _____________CARPLAX_QGMLWB_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _____________CARPLAX_QGMLWB_L3_____________       KC_Z,    KC_X,    KC_C,    KC_F,    KC_J

#define _____________CARPLAX_QGMLWB_R1_____________       KC_B,    KC_Y,    KC_U,    KC_V,    KC_SCLN
#define _____________CARPLAX_QGMLWB_R2_____________       KC_I,    KC_A,    KC_E,    KC_O,    KC_H,    KC_QUOT
#define _____________CARPLAX_QGMLWB_R3_____________       KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH

// colemak like, zxcv fixed
#define _____________CARPLAX_QGMLWY_L1_____________       KC_Q,    KC_G,    KC_M,    KC_L,    KC_W
#define _____________CARPLAX_QGMLWY_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _____________CARPLAX_QGMLWY_L3_____________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_J

#define _____________CARPLAX_QGMLWY_R1_____________       KC_Y,    KC_F,    KC_U,    KC_B,    KC_SCLN
#define _____________CARPLAX_QGMLWY_R2_____________       KC_I,    KC_A,    KC_E,    KC_O,    KC_H,    KC_QUOT
#define _____________CARPLAX_QGMLWY_R3_____________       KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH

// teeheehee
#define _____________CARPLAX_TNWCLR_L1_____________       KC_T,    KC_N,    KC_W,    KC_C,    KC_L
#define _____________CARPLAX_TNWCLR_L2_____________       KC_S,    KC_K,    KC_J,    KC_X,    KC_G
#define _____________CARPLAX_TNWCLR_L3_____________       KC_E,    KC_O,    KC_D,    KC_I,    KC_A

#define _____________CARPLAX_TNWCLR_R1_____________       KC_R,    KC_B,    KC_F,    KC_M,    KC_H
#define _____________CARPLAX_TNWCLR_R2_____________       KC_P,    KC_Q,    KC_Z,    KC_V,    KC_SCLN, KC_QUOT
#define _____________CARPLAX_TNWCLR_R3_____________       KC_U,    KC_Y,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________WHITE_R1__________________       KC_V,    KC_Y,    KC_D,    KC_COMM, KC_QUOT
#define _________________WHITE_R2__________________       KC_A,    KC_T,    KC_H,    KC_E,    KC_B
#define _________________WHITE_R3__________________       KC_P,    KC_K,    KC_G,    KC_W,    KC_Q

#define _________________WHITE_L1__________________       KC_INT1, KC_J,    KC_M,    KC_L,    KC_U
#define _________________WHITE_L2__________________       KC_MINS, KC_C,    KC_S,    KC_N,    KC_O,    KC_I
#define _________________WHITE_L3__________________       KC_X,    KC_R,    KC_F,    KC_DOT,  KC_Z


#define _________________HALMAK_L1_________________       KC_W,    KC_L,    KC_R,    KC_B,    KC_Z
#define _________________HALMAK_L2_________________       KC_S,    KC_H,    KC_N,    KC_T,    KC_COMM
#define _________________HALMAK_L3_________________       KC_F,    KC_M,    KC_V,    KC_V,    KC_SLASH

#define _________________HALMAK_R1_________________       KC_SCLN, KC_Q,    KC_U,    KC_D,    KC_J
#define _________________HALMAK_R2_________________       KC_DOT,  KC_A,    KC_E,    KC_O,    KC_I,    KC_QUOTE
#define _________________HALMAK_R3_________________       KC_G,    KC_P,    KC_X,    KC_K,    KC_Y


#define __________________ISRT_L1__________________       KC_W,    KC_C,    KC_L,    KC_M,    KC_K
#define __________________ISRT_L2__________________       KC_I,    KC_S,    KC_R,    KC_T,    KC_G
#define __________________ISRT_L3__________________       KC_Q,    KC_V,    KC_W,    KC_D,    KC_J

#define __________________ISRT_R1__________________       KC_Z,    KC_F,    KC_U,    KC_COMM, KC_QUOTE
#define __________________ISRT_R2__________________       KC_P,    KC_N,    KC_E,    KC_A,    KC_O,    KC_SCLN
#define __________________ISRT_R3__________________       KC_B,    KC_H,    KC_SLSH, KC_DOT,  KC_X


#define __________________SOUL_L1__________________       KC_Q,    KC_W,    KC_L,    KC_D,    KC_P
#define __________________SOUL_L2__________________       KC_A,    KC_S,    KC_R,    KC_T,    KC_G
#define __________________SOUL_L3__________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_J

#define __________________SOUL_R1__________________       KC_K,    KC_M,    KC_U,    KC_Y,    KC_SCLN
#define __________________SOUL_R2__________________       KC_F,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOTE
#define __________________SOUL_R3__________________       KC_B,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH


#define __________________NIRO_L1__________________       KC_Q,    KC_W,    KC_U,    KC_D,    KC_P
#define __________________NIRO_L2__________________       KC_A,    KC_S,    KC_E,    KC_T,    KC_G
#define __________________NIRO_L3__________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define __________________NIRO_R1__________________       KC_J,    KC_F,    KC_Y,    KC_L,    KC_SCLN
#define __________________NIRO_R2__________________       KC_H,    KC_N,    KC_I,    KC_R,    KC_O,    KC_QUOTE
#define __________________NIRO_R3__________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________ASSET_L1__________________       KC_Q,    KC_W,    KC_J,    KC_F,    KC_G
#define _________________ASSET_L2__________________       KC_A,    KC_S,    KC_E,    KC_T,    KC_D
#define _________________ASSET_L3__________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________ASSET_R1__________________       KC_Y,    KC_P,    KC_U,    KC_L,    KC_SCLN
#define _________________ASSET_R2__________________       KC_H,    KC_N,    KC_I,    KC_O,    KC_R,    KC_QUOTE
#define _________________ASSET_R3__________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________MTGAP_L1__________________       KC_Y,    KC_P,    KC_O,    KC_U,    KC_J
#define _________________MTGAP_L2__________________       KC_I,    KC_N,    KC_E,    KC_A,    KC_COMM
#define _________________MTGAP_L3__________________       KC_Q,    KC_Z,    KC_SLSH, KC_DOT,  KC_SCLN

#define _________________MTGAP_R1__________________       KC_K,    KC_D,    KC_L,    KC_C,    KC_W
#define _________________MTGAP_R2__________________       KC_M,    KC_H,    KC_T,    KC_S,    KC_R,    KC_QUOTE
#define _________________MTGAP_R3__________________       KC_B,    KC_F,    KC_G,    KC_V,    KC_X


#define _________________MINIMAK_L1________________       KC_Q,    KC_W,    KC_D,    KC_R,    KC_K
#define _________________MINIMAK_L2________________       KC_A,    KC_S,    KC_T,    KC_F,    KC_G
#define _________________MINIMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________MINIMAK_R1________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________MINIMAK_R2________________       KC_H,    KC_J,    KC_E,    KC_L,    KC_SCLN, KC_QUOT
#define _________________MINIMAK_R3________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define ________________MINIMAK_8_L1_______________       KC_Q,    KC_W,    KC_D,    KC_R,    KC_K
#define ________________MINIMAK_8_L2_______________       KC_A,    KC_S,    KC_T,    KC_F,    KC_G
#define ________________MINIMAK_8_L3_______________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define ________________MINIMAK_8_R1_______________       KC_Y,    KC_U,    KC_I,    KC_L,    KC_P
#define ________________MINIMAK_8_R2_______________       KC_H,    KC_N,    KC_E,    KC_O,    KC_SCLN, KC_QUOT
#define ________________MINIMAK_8_R3_______________       KC_J,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define _______________MINIMAK_12_L1_______________       KC_Q,    KC_W,    KC_D,    KC_F,    KC_K
#define _______________MINIMAK_12_L2_______________       KC_A,    KC_S,    KC_T,    KC_R,    KC_G
#define _______________MINIMAK_12_L3_______________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _______________MINIMAK_12_R1_______________       KC_Y,    KC_U,    KC_I,    KC_L,    KC_SCLN
#define _______________MINIMAK_12_R2_______________       KC_H,    KC_N,    KC_E,    KC_O,    KC_P,    KC_QUOT
#define _______________MINIMAK_12_R3_______________       KC_J,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ___________________BLANK___________________       _______, _______, _______, _______, _______


#define _________________LOWER_L1__________________       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________       _________________FUNC_LEFT_________________
#define _________________LOWER_L3__________________       _________________FUNC_RIGHT________________

#define _________________LOWER_R1__________________       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _________________LOWER_R2__________________       _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR
#define _________________LOWER_R3__________________       _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END



#define _________________RAISE_L1__________________       ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________       _________________FUNC_LEFT_________________
#define _________________RAISE_L3__________________       _________________FUNC_RIGHT________________

#define _________________RAISE_R1__________________       ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________       KC_NO  , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________       KC_NO  , KC_LEFT, KC_DOWN, KC_UP  ,  KC_RGHT


// Veypatch specific
#define L0_WIDE     KC_GRV
#define L1_WIDE     KC_ESC
#define L2_WIDE     KC_LSFT
#define L3_WIDE     KC_LCTL
#define R0_WIDE     KC_DEL
#define R1_WIDE     KC_BSPC
#define R2_WIDE
#define R3_WIDE     KC_PSCR

#define __________________THUMB_L1_________________       KC_LALT, KC_LSFT, LT(_NAV, KC_ENTER)
#define __________________THUMB_R1_________________                                             LT(_SYM, KC_TAB), KC_SPC, KC_BSPC

#define WIDE_THUMB_L1       KC_LGUI, KC_DEL
#define WIDE_THUMB_R1       KC_RGUI, KC_APP

#define _______________NAV_THUMB_L1________________       _______, _______, _______
#define _______________NAV_THUMB_R1________________                                             MO(_FUNCTION)  , _______, KC_DEL

#define _______________SYM_THUMB_L1________________       MO(_ADJUST), KC_LGUI, MO(_FUNCTION)
#define _______________SYM_THUMB_R1________________                                             _______, _______, _______

#define _______________FUNC_THUMB_L1_______________       _______, _______, _______
#define _______________FUNC_THUMB_R1_______________                                             _______, _______, _______

#define _______________ADJ_THUMB_L1________________       _______, _______, _______
#define _______________ADJ_THUMB_R1________________                                             _______, _______, _______

#define ________________SYMBOLS_L1_________________       LSFT(KC_1), LSFT(KC_2), LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_BSLS)
#define ________________SYMBOLS_L2_________________       LSFT(KC_3), LSFT(KC_4), LSFT(KC_9), LSFT(KC_0), KC_GRV
#define ________________SYMBOLS_L3_________________       LSFT(KC_5), LSFT(KC_6), KC_LBRC, KC_RBRC, LSFT(KC_GRV)

#define ________________SYMBOLS_R1_________________       _______, _______, KC_PIPE, KC_BSLS, _______
#define ________________SYMBOLS_R2_________________       LSFT(KC_EQL), KC_MINS, KC_SLSH, LSFT(KC_8), _______
#define ________________SYMBOLS_R3_________________       LSFT(KC_7)  , KC_EQL , _______, _______   , _______

#define _________________MEDIA_L2__________________       _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU
#define _________________MEDIA_L3__________________       _______, _______, _______, KC_MUTE, KC_VOLD
#define ________________ARROWS_R2__________________       KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______
#define ________________ARROWS_R3__________________       _______, KC_LEFT, KC_DOWN, KC_RGHT, _______

#define _________________FUNC_L1___________________       KC_F1, KC_F2, KC_F3, KC_F4, _______
#define _________________FUNC_L2___________________       KC_F5, KC_F6, KC_F7, KC_F8, _______
#define _________________FUNC_L3___________________       KC_F9, KC_F10, KC_F11, KC_F12, _______

#define __________________NUM_R1___________________       KC_NUM , KC_P7, KC_P8, KC_P9, KC_PPLS
#define __________________NUM_R2___________________       _______, KC_P4, KC_P5, KC_P6, KC_PEQL
#define __________________NUM_R3___________________       _______, KC_P1, KC_P2, KC_P3, KC_PENT

#define NUM_EXTRA       KC_P0  , KC_PDOT
#define NUM_R1_WIDE     KC_PMNS
#define NUM_R2_WIDE     KC_PAST
#define NUM_R3_WIDE     KC_PSLS

#define __________________RGB_R1___________________       RM_TOGG, RM_SATU, RM_HUEU, RM_VALU, RM_NEXT
#define __________________RGB_R2___________________       _______, RM_SATD, RM_HUED, RM_VALD, RM_PREV

#define RGB_R1_WIDE     RM_SPDU
#define RGB_R2_WIDE     RM_SPDD

#define __________________DF_L1____________________       QK_BOOT, _______, DF(0), _______, _______
#define __________________DF_L2____________________       _______, _______, DF(1), _______, _______
#define __________________DF_L3____________________       _______, _______, DF(2), _______, _______
// Veypatch specific end


#ifdef RGB_MATRIX_ENABLE
#    define _________________ADJUST_L1_________________       RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_TOGG
#    define _________________ADJUST_L3_________________       RM_PREV, RM_HUED, RM_SATD, RM_VALD, KC_RGB_T
#else
#    define _________________ADJUST_L1_________________       UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, UG_TOGG
#    define _________________ADJUST_L3_________________       UG_PREV, UG_HUED, UG_SATD, UG_VALD, KC_RGB_T
#endif
#define _________________ADJUST_L2_________________       MU_TOGG, CK_TOGG, AU_ON,   AU_OFF,  CG_NORM

#define _________________ADJUST_R1_________________       KC_SEC1, KC_SEC2, KC_SEC3, KC_SEC4, KC_SEC5
#define _________________ADJUST_R2_________________       CG_SWAP, QWERTY,  CLMKDH,  COLEMAK, DVORAK
#define _________________ADJUST_R3_________________       NK_TOGG, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT

// clang-format on

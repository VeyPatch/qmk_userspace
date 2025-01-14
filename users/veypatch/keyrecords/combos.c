// Copyright 2025 VeyPatch (126267034+VeyPatch@users.noreply.github.com)
// SPDX-License-Identifier: GPL-2.0-or-later

enum combos {
    CB_LCTL,
    AL_LALT
};

const uint16_t PROGMEM cb_combo[] = {LT(_SYM, KC_ENTER), KC_LSFT, COMBO_END};
const uint16_t PROGMEM al_combo[] = {LT(_NAV, KC_TAB), KC_SPC, COMBO_END};

combo_t key_combos[] = {
    [CB_LCTL] = COMBO(cb_combo, KC_LCTL),
    [AL_LALT] = COMBO(al_combo, KC_LALT),
};

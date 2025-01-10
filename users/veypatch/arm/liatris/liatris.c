// Copyright 2025 VeyPatch (126267034+VeyPatch@users.noreply.github.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

void liatris_pre_init_user(void) {
  // Set our LED pin as output
  gpio_set_pin_output(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  gpio_write_pin_high(24);
}

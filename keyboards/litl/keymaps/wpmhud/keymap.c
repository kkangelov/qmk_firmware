/* Copyright 2022 mohoyt
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "typehud.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all(
      KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
      KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
      SC_LSPO, KC_SLSH, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, SC_RSPC,
      KC_LCTL, KC_LGUI, KC_LALT, LT(1, KC_SPC), MO(2), LT(1, KC_SPC), KC_RALT, KC_RGUI, KC_RCTL, KC_MPLY, KC_MUTE ),

  [1] = LAYOUT_all(
  	  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
  	  TG(2), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_UP, KC_MINS, KC_EQL, KC_QUOT, KC_ENT,
  	  KC_TRNS, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_EQL, KC_SLSH, KC_TRNS,
  	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_MUTE ),

  [2] = LAYOUT_all(
      KC_TRNS, RGB_SAI, RGB_SAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO  , KC_UP, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, RGB_TOG, RGB_MOD, RGB_RMOD,KC_TRNS, KC_TRNS, KC_NO  , KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
      KC_TRNS, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_UP,
      AG_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, QK_BOOT )
};

//Encoder map
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][1][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] =   { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [2] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

bool oled_task_user(void) {
    typehud_render();

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    typehud_process_record(record);

    return true;
}

// Include all keys for wpm calculation
bool wpm_keycode_user(uint16_t keycode) {
    return true;
}

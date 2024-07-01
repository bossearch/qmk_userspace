/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [0] = LAYOUT_split_3x6_3(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, QK_GESC, 
    KC_MEH, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, 
    KC_LSFT, KC_LGUI, LT(1,KC_SPC), LT(2,KC_BSPC), KC_LALT, TG(4)
    ),

[1] = LAYOUT_split_3x6_3(
    KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV, 
    KC_MEH, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PMNS, KC_PSLS, KC_PPLS, KC_LBRC, KC_RBRC, KC_BSLS, 
    KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_PIPE, KC_PEQL, KC_LCBR, KC_RCBR, KC_ENT, 
    KC_LSFT, KC_LGUI, KC_TRNS, LT(2,KC_BSPC), KC_LALT, KC_NO
    ),

[2] = LAYOUT_split_3x6_3(
    KC_TAB, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, KC_GRV, 
    KC_MEH, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, 
    KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT, 
    KC_LSFT, KC_LGUI, LT(1,KC_SPC), KC_TRNS, KC_LALT, KC_NO
    ),

[3] = LAYOUT_split_3x6_3(
    QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_P0, KC_GRV, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_NO, KC_ENT, 
    KC_LSFT, KC_LGUI, KC_TRNS, KC_TRNS, KC_LALT, KC_NO
    ),

[4] = LAYOUT_split_3x6_3(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLU, KC_VOLU, KC_MPLY, KC_MRWD, KC_MFFD, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_BTN1, KC_BTN2, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_U, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS
    ) 

};

layer_state_t layer_state_set_user(layer_state_t state) {
return update_tri_layer_state(state, 1, 2, 3);
};

// Shift + Backspace = Delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(2,KC_BSPC), KC_DEL);

// Shift + esc = ~
const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRV));

// GUI + esc = `
const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_GUI, KC_ESC, KC_GRV);

const key_override_t **key_overrides = (const key_override_t *[]){
	&tilde_esc_override,
	&grave_esc_override,
    &delete_key_override,
	NULL
};
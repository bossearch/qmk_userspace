#include QMK_KEYBOARD_H

#include "layers.h"
#include "oled.c"
#include "macros.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_split_3x6_3(
    LT(_NAV,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_GRV,
    KC_MEH, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    KC_LGUI, KC_ESC, LT(_SYM,KC_SPC), LT(_NUM,KC_BSPC), KC_LSFT, KC_LALT
    ),

[_SYM] = LAYOUT_split_3x6_3(
    KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_LBRC, KC_PSLS, KC_BSLS, KC_RBRC, KC_PMNS, KC_PPLS, KC_PEQL, KC_GRV,
    MEH(KC_NO), KC_AMPR, KC_DLR, KC_PERC, KC_LPRN, KC_UNDS, KC_PIPE, KC_RPRN, KC_CIRC, KC_PAST, KC_COLN, KC_DQUO,
    KC_LCTL, MCR0, MCR1, MCR2, KC_LCBR, KC_LT, KC_GT, KC_RCBR, KC_NO, KC_NO, KC_NO, KC_ENT,
    KC_LGUI, KC_ESC, KC_TRNS, LT(_NUM,KC_BSPC), KC_LSFT, KC_LALT
    ),

[_NUM] = LAYOUT_split_3x6_3(
    KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV,
    KC_MEH, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
    KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT,
    KC_LGUI, KC_ESC, LT(_SYM,KC_SPC), KC_TRNS, KC_LSFT, KC_LALT
    ),

[_NAV] = LAYOUT_split_3x6_3(
    KC_TRNS, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_NO, TG(_GAME),
    KC_NO, KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_NO,
    QK_BOOT, KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_LGUI, KC_ESC, KC_BTN1, KC_BTN2, KC_LSFT, KC_LALT
    ),

[_GAME] = LAYOUT_split_3x6_3(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_GRV,
    KC_MEH, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    KC_LALT, KC_LSFT, KC_SPC, LT(_NUM,KC_BSPC), LT(_SYM,KC_ESC), KC_LGUI
    ),

};

// layer_state_t layer_state_set_user(layer_state_t state) {
// return update_tri_layer_state(state, 1, 2, 3);
// };

// Shift + Backspace = Delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(_NUM,KC_BSPC), KC_DEL);

#include "combos.c"

//Remove these line comment before compiling.
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (record->event.pressed) {
//         oled_timer = timer_read32();
//         add_keylog(keycode);
//     }
//     return true;
// };

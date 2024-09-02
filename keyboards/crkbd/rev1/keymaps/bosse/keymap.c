#include QMK_KEYBOARD_H

#include "layers.h"
#include "oled.c"
#include "macros.c" //Refer to macros-example.c if you want to use macro. If you don't go to line 60 ish.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_split_3x6_3(
    LT(_NAV,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_GRV,
    KC_MEH, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    KC_LGUI, KC_ESC, LT(_SYM,KC_SPC), LT(_NUM,KC_BSPC), OSM(MOD_LSFT), KC_LALT
    ),

[_SYM] = LAYOUT_split_3x6_3(
    KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_LPRN, KC_CIRC, KC_BSLS, KC_RPRN, KC_PMNS, KC_PPLS, KC_EQL, KC_GRV,
    KC_MEH, KC_AMPR, KC_DLR, KC_PERC, KC_LBRC, KC_UNDS, KC_PIPE, KC_RBRC, KC_PSLS, KC_PAST, KC_COLN, KC_DQUO,
    KC_LCTL, MCR0, MCR1, MCR2, KC_LCBR, KC_LT, KC_GT, KC_RCBR, KC_COMM, KC_DOT, KC_QUES, KC_ENT,
    KC_LGUI, KC_ESC, KC_TRNS, LT(_NUM,KC_BSPC), KC_LSFT, KC_LALT
    ),

[_NUM] = LAYOUT_split_3x6_3(
    KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KMCR0, KMCR1, KMCR2, KMCR3, KMCR4, KC_GRV,
    KC_MEH, KC_0, KC_9, KC_8, KC_7, KC_6, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_MSTP, KC_MUTE,
    KC_LCTL, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, KC_WBAK, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_ENT,
    KC_LGUI, KC_ESC, LT(_SYM,KC_SPC), KC_TRNS, KC_LSFT, KC_LALT
    ),

[_NAV] = LAYOUT_split_3x6_3(
    KC_TRNS, QK_BOOT, KC_F1, KC_F2, KC_F3, KC_F4, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_PSCR, TG(_GAME),
    GU_ON, CG_LSWP, KC_F5, KC_F6, KC_F7, KC_F8, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_INS, KC_HOME,
    GU_OFF, CG_LNRM, KC_F9, KC_F10, KC_F11, KC_F12, MCR3, KC_PGDN, KC_PGUP, MCR4, KC_END, KC_DEL,
    KC_LGUI, KC_LSFT, KC_LALT, KC_BTN1, KC_BTN2, KC_BTN3
    ),

[_GAME] = LAYOUT_split_3x6_3(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_GRV,
    KC_MEH, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_RCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    KC_LALT, KC_LSFT, KC_SPC, LT(_NUM,KC_BSPC), LT(_SYM,KC_ESC), KC_RGUI
    ),

};

// layer_state_t layer_state_set_user(layer_state_t state) {
// return update_tri_layer_state(state, 1, 2, 3);
// };

// Shift + Backspace = Delete
const key_override_t delete_ctrl_override = ko_make_basic(MOD_MASK_CTRL, LT(_NUM,KC_BSPC), KC_DEL);
const key_override_t delete_gui_override = ko_make_basic(MOD_MASK_GUI, LT(_NUM,KC_BSPC), KC_DEL);
const key_override_t **key_overrides = (const key_override_t *[]){
	&delete_ctrl_override,
	&delete_gui_override,
    NULL
};

#include "combos.c"

//!!! Remove these comment below before compiling without using macro.
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (record->event.pressed) {
//         oled_timer = timer_read32();
//         add_keylog(keycode);
//     }
//     return true;
// };

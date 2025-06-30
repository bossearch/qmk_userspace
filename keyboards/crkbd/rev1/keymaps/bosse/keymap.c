#include QMK_KEYBOARD_H
#include "layers.h"
#include "oled.c"
#include "macros.c" //Refer to macros-example.c if you want to use macro. If you don't, go to line 60 ish instead.

#define NAV_TAB LT(_NAV,KC_TAB)
#define SYM_SPC LT(_SYM,KC_SPC)
#define NUM_BSPC LT(_NUM,KC_BSPC)
#define SYM_ESC LT(_SYM,KC_ESC)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_LALT OSM(MOD_LALT)
#define ALT_ESC ALT_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_split_3x6_3(
    NAV_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_GRV,
    KC_MEH, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_HYPR, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    KC_LCTL, ALT_ESC, SYM_SPC, NUM_BSPC, OSM_LSFT, KC_LGUI
    ),

[_SYM] = LAYOUT_split_3x6_3(
    KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_LPRN, KC_CIRC, KC_BSLS, KC_RPRN, KC_PMNS, KC_PPLS, KC_EQL, KC_TILD,
    KC_MEH, KC_AMPR, KC_DLR, KC_PERC, KC_LBRC, KC_UNDS, KC_PIPE, KC_RBRC, KC_PSLS, KC_PAST, KC_COLN, KC_DQUO,
    KC_HYPR, MCR0, MCR1, MCR2, KC_LCBR, KC_LT, KC_GT, KC_RCBR, KC_COMM, KC_DOT, KC_QUES, KC_ENT,
    KC_LCTL, ALT_ESC, KC_TRNS, TMUX, KC_LSFT, KC_LGUI
    ),

[_NUM] = LAYOUT_split_3x6_3(
    KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, WWW,
    KC_MEH, KC_0, KC_9, KC_8, KC_7, KC_6, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_MUTE, KC_WFWD,
    KC_HYPR, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, BOOK, AF4, KC_BRID, KC_BRIU, TTY1, TTY2, KC_WBAK,
    KC_LCTL, ALT_ESC, OSM_LALT, KC_TRNS, KC_LSFT, KC_LGUI
    ),

[_NAV] = LAYOUT_split_3x6_3(
    KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, QK_BOOT, CG_NORM, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_HOME, KC_INS,
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_END, KC_DEL,
    KC_F12, KC_F11, KC_F10, KC_F9, KC_F8, KC_F7, KC_NUM, KC_PGDN, KC_PGUP, KC_SCRL, KC_PSCR, KC_ENT,
    KC_LCTL, KC_LALT, KC_SPC, KC_BSPC, OSM_LSFT, KC_LGUI
    ),

[_GAME] = LAYOUT_split_3x6_3(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_GRV,
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_RCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    KC_LSFT, KC_LALT, KC_SPC, NUM_BSPC, SYM_ESC, KC_RGUI
    ),

};

// TRILAYER
// layer_state_t layer_state_set_user(layer_state_t state) {
// return update_tri_layer_state(state, 1, 2, 3);
// };

// NUMLOCK AUTO ON
// bool led_update_user(led_t led_state) {
// 	if (!led_state.num_lock) {
// 		tap_code(KC_NUM_LOCK);
// 	}
// 	return true;
// }

// Shift + Backspace = Delete
//const key_override_t delete_ctrl_override = ko_make_basic(MOD_MASK_CTRL, LT(_NUM,KC_BSPC), KC_DEL);
//const key_override_t delete_gui_override = ko_make_basic(MOD_MASK_GUI, LT(_NUM,KC_BSPC), KC_DEL);
//const key_override_t *key_overrides = {
//	&delete_ctrl_override,
//	&delete_gui_override,
//};

//!!! Remove these comment below before compiling without using macro.
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (record->event.pressed) {
//         oled_timer = timer_read32();
//         add_keylog(keycode);
//     }
//     return true;
// };

#include "combos.c"

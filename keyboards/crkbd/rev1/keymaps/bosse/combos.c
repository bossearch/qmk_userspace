const uint16_t PROGMEM toggle_qwerty_combo[] = {KC_TAB, KC_T, COMBO_END};
const uint16_t PROGMEM toggle_ctrl_gui_combo[] = {KC_LCTL, KC_LGUI, COMBO_END};
const uint16_t PROGMEM toggle_alt_gui_combo[] = {KC_LALT, KC_LGUI, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    COMBO(toggle_qwerty_combo, TO(_QWERTY)),
    COMBO(toggle_ctrl_gui_combo, CG_TOGG),
    COMBO(toggle_alt_gui_combo, AG_TOGG),
};
// clang-format on

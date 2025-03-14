enum combos { GAME_COMBO, QWERTY_COMBO };

const uint16_t PROGMEM game_combo_keys[]     = {KC_MEH, KC_G, COMBO_END};
const uint16_t PROGMEM qwerty_combo_keys[] = {KC_ESC, KC_G, COMBO_END};
const uint16_t PROGMEM swap_ctrl_gui[] = {KC_LCTL, KC_LGUI, COMBO_END};

combo_t key_combos[] = {
    [GAME_COMBO]   = COMBO(game_combo_keys, TG(_GAME)),
    [QWERTY_COMBO] = COMBO(qwerty_combo_keys, TO(_QWERTY)),
    COMBO(swap_ctrl_gui, CG_TOGG),
};

// Action when the combo keys are released
bool process_combo_key_release(uint16_t combo_index, combo_t *combo, uint8_t key_index, uint16_t keycode) {
    switch (combo_index) {
        case GAME_COMBO:
            if (key_index == 0 || key_index == 1) {
            /*if (keycode == KC_MEH || keycode == KC_G) {*/
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_LSFT);
                tap_code(KC_G);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
            }
            return true;
        case QWERTY_COMBO:
            if (key_index == 0 || key_index == 1) {
            /*if (keycode == KC_ESC || keycode == KC_G) {*/
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_LSFT);
                tap_code(KC_G);
                unregister_code(KC_LCTL);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
            }
            return true;
    }
    return false;
}

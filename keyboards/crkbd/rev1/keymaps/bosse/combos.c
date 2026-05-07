enum combos { GAME_COMBO, QWERTY_COMBO };

const uint16_t PROGMEM swap_ctrl_gui[]     = {KC_LCTL, KC_LGUI, COMBO_END};

combo_t key_combos[] = {
    COMBO(swap_ctrl_gui, CG_TOGG),
};

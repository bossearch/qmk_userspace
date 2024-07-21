#ifdef OLED_ENABLE
#include "oled_assets.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static const char PROGMEM font_logo[16] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0
};

static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

// fillers between the modifier icons bleed into the icon frames
static const char PROGMEM off_off_1[] = {0xc5, 0};
static const char PROGMEM off_off_2[] = {0xc6, 0};
static const char PROGMEM on_off_1[] = {0xc7, 0};
static const char PROGMEM on_off_2[] = {0xc8, 0};
static const char PROGMEM off_on_1[] = {0xc9, 0};
static const char PROGMEM off_on_2[] = {0xca, 0};
static const char PROGMEM on_on_1[] = {0xcb, 0};
static const char PROGMEM on_on_2[] = {0xcc, 0};


void render_mod_status_gui_alt(uint8_t modifiers) {
   
    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}


void render_mod_status_ctrl_shift(uint8_t modifiers) {

    // // fillers between the modifier icons bleed into the icon frames
    // static const char PROGMEM off_off_1[] = {0xc5, 0};
    // static const char PROGMEM off_off_2[] = {0xc6, 0};
    // static const char PROGMEM on_off_1[] = {0xc7, 0};
    // static const char PROGMEM on_off_2[] = {0xc8, 0};
    // static const char PROGMEM off_on_1[] = {0xc9, 0};
    // static const char PROGMEM off_on_2[] = {0xca, 0};
    // static const char PROGMEM on_on_1[] = {0xcb, 0};
    // static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write(" QWR", false);
            oled_set_cursor(0, 1);
            oled_write_raw_P(layer0, sizeof(layer0));
            break;
        case _SYM:
            oled_write(" SYM", false);
            oled_set_cursor(0, 1);
            oled_write_raw_P(layer2, sizeof(layer2));
            break;
        case _NUM:
            oled_write(" NUM", false);
            oled_set_cursor(0, 1);
            oled_write_raw_P(layer3, sizeof(layer3));
            break;
        case _NAV:
            oled_write(" NAV", false);
            oled_set_cursor(0, 1);
            oled_write_raw_P(layer4, sizeof(layer4));
            break;
        case _GAME:
            oled_write(" AFK", false);
            oled_set_cursor(0, 1);
            oled_write_raw_P(layer1, sizeof(layer1));
            break;
        default:
            oled_write(" UNK", false);
    }
}

// void render_status_main(void) {
//     render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
//     render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
// //    render_layer_state();
// }

// void render_status_secondary(void) {
//     oled_write_P(font_logo, false);
//     oled_write("corne", false);
//     oled_set_cursor(0, 14);
//     oled_write("crkbd", false);
//     oled_set_cursor(0, 15);
//     oled_write("bosse", false);
// }



bool oled_task_user(void) {
    if (is_keyboard_master()) {
//        render_lock_status(host_keyboard_led_state());
//        render_mod_status(get_mods() | get_oneshot_mods());
//        oled_set_cursor(0, 15);
//        oled_set_cursor(0, 1);
        render_layer_state();
    } else {
        oled_write_P(font_logo, false);
        oled_write("corne", false);
        oled_set_cursor(0, 7);
        //oled_write_P(render_mod_status_gui_alt, false);
        // oled_write_P(render_mod_status_ctrl_shift, false);
        oled_set_cursor(0, 14);
        oled_write("crkbd", false);
        oled_set_cursor(0, 15);
        oled_write("bosse", false);
    } 
    return false;
}

#endif
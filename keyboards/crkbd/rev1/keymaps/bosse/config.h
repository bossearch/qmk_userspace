#pragma once

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define OLED_FONT_H "keyboards/crkbd/rev1/keymaps/bosse/glcdfont.c"
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

#define MOUSEKEY_DELAY              10    // Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL           6.061 // Time between cursor movements in milliseconds
#define MOUSEKEY_MOVE_DELTA         1     // Step size
#define MOUSEKEY_MAX_SPEED          8    // Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX        10    // Time until maximum cursor speed is reached

#define HOLD_ON_OTHER_KEY_PRESS
#define ONESHOT_TAP_TOGGLE 2

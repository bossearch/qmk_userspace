#include "raw_hid.h"


void raw_hid_receive(uint8_t *data, uint8_t length) {
    switch (data[0]) {
        case 0x01:
            layer_move(_GAME);
            break;
        case 0x00:
            layer_move(_QWERTY);
            break;
    }
}

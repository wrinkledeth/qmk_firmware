#include QMK_KEYBOARD_H

#define _COLEMAK 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_6x6(
        // KC_GRV,  KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
        // KC_ESC,  KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,                         KC_J  , KC_L  , KC_U  , KC_Y  ,KC_SCLN ,KC_BSLS,
        // KC_TAB,  KC_A  , KC_R  , KC_S  , KC_T  , KC_G  ,                         KC_M  , KC_N  , KC_E  , KC_I  ,KC_O,KC_QUOT,
        // RAISE, KC_Z  , KC_X  , KC_C  , KC_D  , KC_V  ,                           KC_K  , KC_H  ,KC_COMM,KC_DOT ,KC_SLSH,KC_EQL,
        //                 KC_LEFT,KC_RIGHT,                                                       KC_LBRC, KC_RBRC,
        //                                 KC_SPC,KC_LALT,                       KC_RSHIFT,KC_BSPC,
        //                                 KC_PSCR,KC_LCTL,                      KC_ENT,KC_UP,
        //                                 LCA(KC_SPC),KC_LGUI,                    KC_DEL,KC_DOWN
   

        KC_GRV , KC_1  ,KC_2   , KC_3  , KC_4  , KC_5  ,            KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
        KC_ESC , KC_Q  ,KC_W   , KC_F  , KC_P  , KC_B  ,            KC_J   , KC_L  , KC_U  , KC_Y  , KC_SCLN ,KC_BSLS,
        KC_TAB , KC_A  ,KC_R   , KC_S  , KC_T  , KC_G  ,            KC_M   , KC_N  , KC_E  , KC_I  ,KC_O, KC_QUOT,
        KC_0  , KC_Z  ,KC_X   , KC_C  , KC_D  , KC_V  ,             KC_K   , KC_H  ,KC_COMM, KC_DOT,KC_SLSH,KC_EQL,
        RAISE,  KC_LGUI, KC_1, KC_LEFT, KC_RGHT,_______,           _______ , KC_UP ,KC_DOWN,KC_LBRC,KC_RBRC,RAISE,
                                LCTL(KC_SPC), KC_LCTL,KC_4,                 KC_5, KC_ENT,KC_DEL, 
                                                KC_7,               KC_8,
                                                KC_SPC,             KC_BSPC, 
                                                KC_LALT,            KC_RSHIFT   
                            // LSA(kc): shift + alt 
    ),  
    [_RAISE] = LAYOUT_6x6(
        KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,        KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        RESET,_______,_______,_______,KC_PSCR,_______,        _______,_______,KC_PGUP,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,        KC_HOME,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_END,
        _______,_______,_______,_______,_______,_______,        _______,KC_PGUP,KC_PGDOWN,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,        _______,_______,_______,_______,_______,_______,
                                _______,_______,_______,        _______,_______,_______,
                                                _______,        _______,
                                                KC_LSFT,        _______,
                                                _______,        _______
    ),
    [_LOWER] = LAYOUT_6x6(
        _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                                       KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        _______,KC_EXLM,KC_AT  ,KC_LBRC,KC_RBRC,KC_PIPE,                                       KC_UP  ,KC_P7  ,KC_P8  ,KC_P9  ,KC_PAST,KC_F12 ,
        _______,KC_HASH,KC_DLR ,KC_LPRN,KC_RPRN,KC_GRV ,                                       KC_DOWN,KC_P4  ,KC_P5  ,KC_P6  ,KC_PPLS,_______,
        _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,                                       KC_AMPR,KC_P1  ,KC_P2  ,KC_P3  ,KC_PSLS,_______,
        QK_BOOT  ,_______,_______,_______,_______,_______,                                       _______,_______,KC_PDOT,KC_P0  ,KC_PEQL,_______,
                                                _______,_______,_______,       _______,_______,_______,
                                                                _______,       _______,
                                                                _______,       _______,
                                                                _______,       _______
    ),
};

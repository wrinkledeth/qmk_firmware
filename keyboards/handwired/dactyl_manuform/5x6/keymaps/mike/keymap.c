/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 
/* qmk compile -kb handwired/dactyl_manuform/5x6 -km default */

#include QMK_KEYBOARD_H
#define _QWERTY 0
#define _RAISE 1
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_GRV,  KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
     KC_ESC,  KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,                         KC_J  , KC_L  , KC_U  , KC_Y  ,KC_SCLN ,KC_BSLS,
     KC_TAB,  KC_A  , KC_R  , KC_S  , KC_T  , KC_G  ,                         KC_M  , KC_N  , KC_E  , KC_I  ,KC_O,KC_QUOT,
     RAISE, KC_Z  , KC_X  , KC_C  , KC_D  , KC_V  ,                           KC_K  , KC_H  ,KC_COMM,KC_DOT ,KC_SLSH,KC_EQL,
                      KC_LEFT,KC_RIGHT,                                                       KC_LBRC, KC_RBRC,
                                      KC_SPC,KC_LALT,                       KC_RSHIFT,KC_BSPC,
                                      KC_PSCR,KC_LCTL,                      KC_ENT,KC_UP,
                                      LCA(KC_SPC),KC_LGUI,                    KC_DEL,KC_DOWN
  ),

  [_RAISE] = LAYOUT_5x6(
     KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                        KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
     _______,_______,_______,_______,_______,_______,                        _______,_______,KC_PGUP,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        KC_HOME,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_END,
     _______,_______,_______,_______,_______,_______,                        _______,KC_PGDOWN,_______,_______,_______,RESET,
                       KC_HOME,KC_END,       				                  KC_LBRC,KC_RBRC,
                                               KC_LSHIFT,_______,             _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,             _______,_______
  ),
};

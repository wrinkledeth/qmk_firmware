#include QMK_KEYBOARD_H

#define _COLEMAK 0
#define _RAISE 1
#define _NUM 2
#define _MOUSE 3

#define RAISE MO(_RAISE)
#define NUM MO(_NUM)
#define MOUSE MO(_MOUSE)

// https://github.com/kevinsung/qmk_firmware/blob/kevinsung/keyboards/handwired/dactyl_promicro/keymaps/kevinsung/keymap.c
// https://github.com/wrinkledeth/qmk_firmware/blob/mikes_dactyls/keyboards/handwired/dactyl_promicro/keymaps/mike/keymap.c

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md                    
// https://jayliu50.github.io/qmk-cheatsheet/
// https://github.com/qmk/qmk_firmware/blob/master/docs/mod_tap.md

// Tap Dance Declarations
enum {
    TD_TAB,
    TD_QUIT,
    // TD_RAISE
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // simple tap dance
    [TD_TAB] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_TAB), LCTL(LALT(KC_TAB))), // alt tab / ctrl + alt + tab
    [TD_QUIT] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, LALT(KC_F4)), // esc / alt + f4 
    // [TD_RAISE] = ACTION_TAP_DANCE_DOUBLE(MO(_RAISE), TG(_RAISE)), 
    // To get Tap Dance Raise to work you would need to do this: 
    // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_tap_dance.md (ex 6)

    // complex tap dance function (to specify what happens when key is pressed 3+ times, for example). See full docs for how to define
    // [YOUR_TAPDANCE_2] = ACTION_TAP_DANCE_FN(your_function_name),iiii
};

// ctrl + up / down, make it skip to next paragraph
// map scrolllineup/down to ctrl+shift+up/down 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_6x6(
        KC_GRV , KC_1  ,KC_2   , KC_3  , KC_4  , KC_5  ,                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
        KC_ESC , KC_Q  ,KC_W   , KC_F  , KC_P  , KC_B  ,                        KC_J   , KC_L  , KC_U  , KC_Y  , KC_SCLN ,KC_BSLS,
        KC_TAB , KC_A  ,KC_R   , KC_S  , KC_T  , KC_G  ,                        KC_M   , KC_N  , KC_E  , KC_I  ,KC_O, KC_QUOT,
        KC_F12  , KC_Z  ,KC_X   , KC_C  , KC_D  , KC_V  ,                       KC_K   , KC_H  ,KC_COMM, KC_DOT,KC_SLSH,KC_EQL,
        NUM,  KC_LGUI, LCTL(KC_SLSH), KC_LEFT, KC_RGHT,_______,               _______ , KC_UP ,KC_DOWN,KC_LBRC,KC_RBRC,KC_F2,
                                KC_LALT, KC_LCTL, KC_HOME,                      KC_PGDOWN, KC_ENT,KC_DEL, 
                                                KC_END,                         KC_PGUP,    
                                                KC_SPC,                         KC_BSPC, 
                                                RAISE,                          KC_RSHIFT   
    ),              
    [_RAISE] = LAYOUT_6x6(            
        KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                        KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        TD(TD_QUIT),_______,_______,_______,KC_PSCR,_______,                    _______,KC_PGDOWN,KC_PGUP,_______,_______,_______,
        TD(TD_TAB),KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,_______,                       KC_HOME,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_END,
        _______,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),MOUSE,LCTL(KC_V),              _______,KC_WH_U, KC_WH_D,_______,_______,_______,
        _______,_______,LCTL(KC_W),LCTL(KC_PGUP) ,LCTL(KC_PGDOWN),_______,      _______,_______,_______,_______,_______,_______,
                                _______,_______,_______,                        _______,_______,_______,
                                                _______,                        _______,
                                                _______,                        _______,    
                                                _______,                        _______
    ),
    [_NUM] = LAYOUT_6x6(            
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______, _______,                       _______, KC_P7  , KC_P8  , KC_P9  , _______, RESET,
        _______,_______,_______,_______,_______, _______,                       _______, KC_P4  , KC_P5  , KC_P6  , _______, _______,
        _______,_______,_______,_______,_______, _______,                       _______, KC_P1  , KC_P2  , KC_P3  , _______, _______,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
                                _______,_______,_______,                        _______,_______,_______,
                                                _______,                        _______,
                                                _______,                        _______,    
                                                _______,                        _______
    ),
    [_MOUSE] = LAYOUT_6x6(
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                       _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
                               _______, _______, _______,                       _______, _______, _______, 
                                                 _______,                       _______,
                                                 _______,                       _______, 
                                                 _______,                       KC_BTN1
    ),
};

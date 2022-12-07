#include QMK_KEYBOARD_H

#define _COLEMAK 0
#define _RAISE 1

#define RAISE MO(_RAISE)

// https://github.com/kevinsung/qmk_firmware/blob/kevinsung/keyboards/handwired/dactyl_promicro/keymaps/kevinsung/keymap.c
// https://github.com/wrinkledeth/qmk_firmware/blob/mikes_dactyls/keyboards/handwired/dactyl_promicro/keymaps/mike/keymap.c

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md                    
// https://jayliu50.github.io/qmk-cheatsheet/
// https://github.com/qmk/qmk_firmware/blob/master/docs/mod_tap.md

// Tap Dance Declarations
// enum {
//     TD_1,
//     TD_GRV,
// };
// // Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // [TD_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, LGUI(KC_SPC)), // double tab ` = switch input language
    // [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, LCTL((KC_SPC))), //ctrl + space = toggle IME
};

enum combos {
  ALTESC_QUIT,
  GRAVE1_LANG,
  ONETWO_IME,
  RS_COMMENT,
  ZX_BACK,
  CD_FORWARD,
  QW_TABFWD,
  FP_TABBCK,
  // ZX_WINLEFT,
  // CD_WINRIGHT,
};

//combos: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
const uint16_t PROGMEM altesc_quit[] = {KC_ESC, KC_Q, COMBO_END};
const uint16_t PROGMEM grave1_lang[] = {KC_GRV, KC_1, COMBO_END};
const uint16_t PROGMEM onetwo_ime[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM rs_comment[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM zx_back[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM cd_forward[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM qw_tabfwd[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM fp_tabbck[] = {KC_F, KC_P, COMBO_END};
// const uint16_t PROGMEM zx_winleft[] = {KC_Z, KC_X, COMBO_END};
// const uint16_t PROGMEM cd_winright[] = {KC_C, KC_D, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [ALTESC_QUIT] = COMBO(altesc_quit, LALT(KC_F4)),
  [GRAVE1_LANG] = COMBO(grave1_lang, LGUI(KC_SPC)),
  [ONETWO_IME] = COMBO(onetwo_ime, LCTL(KC_SPC)),
  [RS_COMMENT] = COMBO(rs_comment, LCTL(KC_SLASH)),
  [ZX_BACK] = COMBO(zx_back,LALT(KC_LEFT)),
  [CD_FORWARD] = COMBO(cd_forward,LALT(KC_RIGHT)),
  [QW_TABFWD] = COMBO(qw_tabfwd,LCTL(KC_PGUP)),
  [FP_TABBCK] = COMBO(fp_tabbck,LCTL(KC_PGDN)),
  // [ZX_WINLEFT] = COMBO(zx_winleft,LGUI(KC_LEFT)),
  // [CD_WINRIGHT] = COMBO(cd_winright,LGUI(KC_RIGHT)),
};

// comment chord on homerow!!!!
// TAPDANCE SHOULD NEVER BE USED EVER!.

// Mod Tap: https://github.com/qmk/qmk_firmware/blob/master/docs/mod_tap.md (space bar) LALT_T(kc)
// Modifiers:
// F2 Refactor   (leave it default)
// F12: Go to definition (has its own key)
// win : F8: Go to next problem  
// UHOH: F9: Set breakpoint
// alt : F5: Continue          
// shift : F10: Step Over 
// ctrl : Step Into          

// KC_LBRC,  LGUI_T(KC_F8), LALT_T(KC_F5), LSFT_T(KC_F10), LCTL_T(KC_F11),_______, 
// KC_LGUI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_6x6(
        KC_GRV , KC_1  ,KC_2   , KC_3  , KC_4  , KC_5  ,                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
        KC_ESC , KC_Q  ,KC_W   , KC_F  , KC_P  , KC_B  ,                        KC_J   , KC_L  , KC_U  , KC_Y  , KC_SCLN ,KC_BSLS,
        KC_TAB , KC_A  ,KC_R   , KC_S  , KC_T  , KC_G  ,                        KC_M   , KC_N  , KC_E  , KC_I  ,KC_O, KC_QUOT,
        KC_F12  , KC_Z  ,KC_X   , KC_C  , KC_D  , KC_V  ,                       KC_K   , KC_H  ,KC_COMM, KC_DOT,KC_SLSH,KC_EQL,
        KC_LBRC,  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,_______,                   
                                                                                _______ ,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_RBRC,
                                KC_LALT, KC_LCTL, LCTL(KC_SLSH),                KC_3, KC_ENT,KC_DEL, 
                                                KC_LGUI,                        KC_4,    
                                                KC_SPC,                         KC_BSPC, 
                                                RAISE,                          KC_LSFT   
    ),              
    [_RAISE] = LAYOUT_6x6(            
        KC_F12 , KC_F1 , KC_F2 , KC_F3  , KC_F4  ,KC_F5  ,                      KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        LCTL(LALT(KC_TAB)),_______,_______,_______,KC_PSCR,_______,             _______,_______,_______,_______,_______,RESET,
        LALT(KC_TAB),_______,_______,_______,_______,_______,                   _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,LALT(LCTL(KC_V)),               _______,_______,_______,_______,_______,_______,
        LSFT(KC_9),KC_LGUI,KC_LALT,KC_LEFT,KC_RIGHT,_______,                    _______,KC_HOME,KC_PGDOWN,KC_PGUP,KC_END,LSFT(KC_0),
                                _______,_______,_______,                        _______,_______,_______,
                                                _______,                        _______,
                                                _______,                        KC_DEL,    
                                                _______,                        _______
    ),
}; 
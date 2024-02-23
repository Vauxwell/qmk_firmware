 /* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum layers {
    _PC = 0,
    _SYM,
    _FUNCTION,
    _MOVE,
};

// Aliases for readability
#define PC   DF(_PC)

#define BASE   TO(_PC)

#define SYM      MO(_SYM)
#define FUNC     MO(_FUNCTION)
#define MOVE     MO(_MOVE)

#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define ALT_QUOT MT(MOD_LALT, KC_QUOTE)
#define LSFT_ESC MT(MOD_LSFT, KC_ESC)

// Home row mods for QWERTY layer.
// Gui - Alt - Control - Shift

#define QHOME_A LGUI_T(KC_A)
#define QHOME_S LALT_T(KC_S)
#define QHOME_D LCTL_T(KC_D)
#define QHOME_F LSFT_T(KC_F)

#define QHOME_J RSFT_T(KC_J)
#define QHOME_K RCTL_T(KC_K)
#define QHOME_L LALT_T(KC_L)
#define QHOME_SC LGUI_T(KC_SCLN)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Base Layer: QWERTY
    [_PC] = LAYOUT(
//  ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                                 ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
      KC_TAB   , KC_Q     ,   KC_W   ,   KC_E   ,  KC_R    ,  KC_T    ,                                                     KC_Y     , KC_U     ,  KC_I    , KC_O     , KC_P     , KC_BSPC  ,
//  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                                 ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
      KC_LCTL  , KC_A     , QHOME_S  , QHOME_D  , QHOME_F  ,  KC_G    ,                                                   KC_H     , QHOME_J  , QHOME_K  , QHOME_L  , KC_SCLN  , KC_QUOTE ,
//  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐     ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
      KC_LSFT  , KC_Z   ,   KC_X   ,   KC_C   ,  KC_V    ,  KC_B    ,  FUNC    , _______  ,        _______ ,   FUNC   ,   KC_N     , KC_M     ,  KC_COMM , KC_DOT   , KC_SLSH  , KC_RSFT  ,
//  └──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤     ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
                                        KC_LGUI ,  KC_LALT ,  SYM     , KC_ESC ,   KC_LCTL  ,        KC_ENT  ,  KC_SPC  , MOVE     , KC_LGUI  ,  _______
//                                   └──────────┴──────────┴──────────┴──────────┴──────────┘     └──────────┴──────────┴──────────┴──────────┴──────────┘
    ),
  
// Sym Layer: Numbers and symbol
    [_SYM] = LAYOUT(
//  ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                                 ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
      KC_GRV   ,  XXXXXXX ,  KC_UNDS ,  KC_LBRC , KC_RBRC  , KC_INS   ,                                                    KC_EQL  ,  KC_7    ,  KC_8    ,  KC_9    ,  XXXXXXX ,  _______ ,
//  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                                 ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
      _______  ,  KC_LSFT ,  KC_MINS ,  KC_LCBR , KC_RCBR  , KC_BSLS  ,                                                    KC_PLUS ,  KC_4    ,  KC_5    ,  KC_6    ,  _______ ,  _______ ,
//  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐     ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
      _______  ,  KC_NO   ,  KC_BSLS ,  KC_LPRN , KC_RPRN  , XXXXXXX  , _______  ,  _______ ,       _______  , _______  ,  KC_DOT  ,  KC_1    ,  KC_2    ,  KC_3    ,  _______ ,  _______ ,
//  └──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤     ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
                                        _______ , _______  , _______  , _______  ,  _______ ,       _______  , _______  ,  KC_0    ,  _______ , _______
//                                   └──────────┴──────────┴──────────┴──────────┴──────────┘     └──────────┴──────────┴──────────┴──────────┴──────────┘
    ),

    // Movement Layer: Controls mouse and cursor movement with keys
    [_MOVE] = LAYOUT(
//  ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                                 ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
      _______  ,  XXXXXXX ,  KC_WH_D ,  KC_MS_U ,  KC_WH_U ,  XXXXXXX  ,                                                   XXXXXXX ,  KC_BTN1 ,  KC_BTN2 ,  KC_BTN3 ,  KC_PGUP ,  KC_DEL ,
//  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                                 ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
      _______  ,  XXXXXXX ,  KC_MS_L ,  KC_MS_D ,  KC_MS_R ,  XXXXXXX ,                                                    KC_LEFT , KC_DOWN  ,  KC_UP   , KC_RIGHT ,  KC_PGDN ,  _______ ,
//  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐     ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
      _______  ,  _______ ,  KC_WH_L ,  XXXXXXX ,  KC_WH_R ,  XXXXXXX ,  _______ ,  _______ ,        _______ ,  _______ ,  XXXXXXX ,  KC_HOME ,  KC_END ,  XXXXXXX  ,  XXXXXXX ,  _______ ,
//  └──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤     ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
                                        _______ ,  _______ , _______  ,  _______ ,  _______ ,        _______ ,  _______ ,  _______ ,  _______ ,  _______
//                                   └──────────┴──────────┴──────────┴──────────┴──────────┘     └──────────┴──────────┴──────────┴──────────┴──────────┘
    ),

// Function Layer: Function keys
    [_FUNCTION] = LAYOUT(
//  ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                                 ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
      _______  ,  XXXXXXX ,  XXXXXXX ,  KC_MPLY ,  KC_VOLU , _______  ,                                                    KC_F9   ,  KC_F10  ,  KC_F11  ,  KC_F12  ,  XXXXXXX ,  _______ ,
//  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                                 ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
      _______  ,  XXXXXXX ,  XXXXXXX ,  KC_MNXT ,  KC_VOLD , BASE     ,                                                    KC_F5   ,  KC_F6   ,  KC_F7   ,  KC_F8   ,  XXXXXXX ,  _______ ,
//  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐     ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
      _______  ,  XXXXXXX ,  XXXXXXX ,  KC_MPRV ,  KC_MUTE , XXXXXXX  , _______  , _______  ,        _______ ,  _______ ,  KC_F1   ,  KC_F2   ,  KC_F3   ,  KC_F4   ,  XXXXXXX ,  _______ ,
//  └──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤     ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
                                        _______ , _______  , _______  , _______  , _______  ,        _______ ,  _______ ,  _______ ,  _______ ,  _______
//                                   └──────────┴──────────┴──────────┴──────────┴──────────┘     └──────────┴──────────┴──────────┴──────────┴──────────┘
    ),


// /*
//  * Layer template(s)

/*

    [_NAME] = LAYOUT(
//  ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                                 ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
      _______  ,  _______ , _______ ,  _______ ,  _______ , _______  ,                                                    _______ ,  _______ ,  _______ ,  _______ ,  _______ ,  _______ ,
//  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                                 ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
      _______  ,  _______ , _______ ,  _______ ,  _______ , _______  ,                                                    _______ ,  _______ ,  _______ ,  _______ ,  _______ ,  _______ ,
//  ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┬──────────┐     ┌──────────┬──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
      _______  ,  _______ , _______ ,  _______ ,  _______ , _______  ,  _______ ,  _______ ,        _______ ,  _______ ,  _______ ,  _______ ,  _______ ,  _______ ,  _______ ,  _______ ,
//  └──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤     ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
                            _______ ,  _______ ,  _______ , _______  ,  _______ ,  _______ ,        _______ ,  _______ ,  _______ ,  _______ ,  _______
//                        └──────────┴──────────┴──────────┴──────────┴──────────┴──────────┘     └──────────┴──────────┴──────────┴──────────┴──────────┘
    ),

 */
};


// These are all taken from https://getreuer.info/posts/keyboards/achordion/index.html
// Pascal Getreuer's wonderful work on Achordian.
void matrix_scan_user(void) {
  achordion_task();
}


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  // Your macros ...

  return true;
}


uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    // case HOME_N:
    // Repeating is useful for Vim navigation keys.
    case QHOME_J:
    case QHOME_K:
    case QHOME_L:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}



// /* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("Kyria rev2.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _PC:
                oled_write_P(PSTR("PC\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _MOVE:
                oled_write_P(PSTR("Movement\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    }

    return false;
}
#endif


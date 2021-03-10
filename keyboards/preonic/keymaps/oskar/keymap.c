/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "keymap_swedish.h"


// Layer keys
#define NAV MO(_NAV)
#define SYM MO(_SYM)
#define MOUSE MO(_MOUSE)
#define ADJUST MO(_ADJUST)
#define SYM_ENT LT(_SYM, KC_ENT)

// Miscellaneous keyboard shortcuts in direct access
#define UNDO LCTL(SE_Z)
#define REDO LCTL(SE_Y)
#define C_INS LCTL(KC_INS)
#define S_INS LSFT(KC_INS)

// Left-hand home row mods
#define HOME_A LGUI_T(SE_A)
#define HOME_R LALT_T(SE_R)
#define HOME_S LSFT_T(SE_S)
#define HOME_T LCTL_T(SE_T)

// Right-hand home row mods
#define HOME_O LGUI_T(SE_O)
#define HOME_I LALT_T(SE_I)
#define HOME_E RSFT_T(SE_E)
#define HOME_N LCTL_T(SE_N)

#define NAV MO(_NAV)
#define ADJUST MO(_ADJUST)

enum preonic_layers {
    _COLEMAK_DHM = 0,
    _SYM,
    _NAV,
    _MOUSE,
    _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  _LOWER,
  _RAISE,
  LOWER,
  RAISE,
  BACKLIT,
  ALT_TAB,
  ND_TILD,
  ND_CIRC,
  NO_D_GRV,
  E_ACUTE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak DHM
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F0  | F11  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   \  |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite|   (  |   )  |A_TAB |Lower |    Space    |Raise |   [  |   ]  |   {  |  }   |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK_DHM] = LAYOUT_preonic_grid( \
  NO_D_GRV,KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  KC_TAB,  SE_Q,    SE_W,    SE_F,    SE_P,    SE_B,    SE_J,    SE_L,    SE_U,    SE_Y,    SE_SCLN, SE_MINS, \
  KC_ESC,  SE_A,    HOME_R,  HOME_S,  HOME_T,  SE_G,    SE_M,    HOME_N,  HOME_E,  HOME_I,  SE_O,    SE_QUOT, \
  SE_BSLS, SE_Z,    SE_X,    SE_C,    SE_D,    SE_V,    SE_K,    SE_H,    SE_COMM, SE_DOT,  SE_SLSH, SE_DQUO, \
  BACKLIT, SE_LPRN, SE_RPRN, ALT_TAB, NAV,     KC_SPC,  KC_BSPC, SYM_ENT, SE_LBRC, SE_RBRC, SE_LCBR, SE_RCBR \
),

/* Sym
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  å   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |  !   |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   =  |   ö  |  ä   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   |  |      |      |      |      |      |      |      |   <  |   >  |   ?  |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_SYM] = LAYOUT_preonic_grid( \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  _______,KC_1,    KC_2,  KC_3,    KC_4,   KC_5,   KC_6,    KC_7,   KC_8,   KC_9,   KC_0,  SE_ARNG, \
 ND_TILD,SE_EXLM, SE_AT, SE_HASH, SE_DLR,SE_PERC, ND_CIRC,SE_AMPR,SE_ASTR,SE_EQL, SE_ODIA,SE_ADIA, \
  SE_PIPE,_______,_______,_______,_______,_______,_______,_______,SE_LABK,SE_RABK,SE_QUES,SE_PLUS, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______ \
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | COPY | PASTE|      |   é  |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | HOME | LEFT |  UP  | DOWN | RIGHT| END  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

  [_NAV] = LAYOUT_preonic_grid( \
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______, \
        _______,_______, C_INS , S_INS ,_______,E_ACUTE,    _______,_______,_______,_______,_______,_______, \
        _______,_______,_______,_______,_______,_______,    KC_HOME,KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,KC_END , \
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______, \
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______ \
  ),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
/*[_LOWER] = LAYOUT_preonic_grid( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),*/

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
/*[_RAISE] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),*/

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/*[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)*/


};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      //  case QWERTY:
      //    if (record->event.pressed) {
      //      //set_single_persistent_default_layer(_QWERTY);
      //    }
      //    return false;
      //    break;
      //  case COLEMAK:
      //    if (record->event.pressed) {
      //      //set_single_persistent_default_layer(_COLEMAK);
      //    }
      //    return false;
      //    break;
      //  case DVORAK:
      //    if (record->event.pressed) {
      //      //set_single_persistent_default_layer(_DVORAK);
      //    }
      //    return false;
      //    break;
      //  case LOWER:
      //    if (record->event.pressed) {
      //      layer_on(_LOWER);
      //      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      //    } else {
      //      layer_off(_LOWER);
      //      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      //    }
      //    return false;
      //    break;
      //  case RAISE:
      //    if (record->event.pressed) {
      //      layer_on(_RAISE);
      //      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      //    } else {
      //      layer_off(_RAISE);
      //      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      //    }
      //    return false;
      //    break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
    case HOME_I:
        // This piece of code nullifies the effect of Right Shift when
        // tapping the HOME_I key. This helps rolling over HOME_E and HOME_I
        // to obtain the intended "ei" instead of "I". Consequently, capital I can
        // only be obtained by tapping HOME_I and holding HOME_S (which is the left shift mod tap).
        if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
            if (mod_state & MOD_BIT(KC_RSHIFT)) {
                unregister_code(KC_RSHIFT);
                tap_code(KC_E);
                tap_code(KC_I);
                set_mods(mod_state);
                return false;
            }
        }
        // else process HOME_I as usual.
        return true;


    case HOME_N:
         /*This piece of code nullifies the effect of Right Shift when*/
         /*tapping the HOME_N key. This helps rolling over HOME_E and HOME_N */
         /*to obtain the intended "en" instead of "N". Consequently, capital N can */
         /*only be obtained by tapping HOME_N and holding HOME_S (which is the left shift mod tap).*/
        if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
            if (mod_state & MOD_BIT(KC_RSHIFT)) {
                unregister_code(KC_RSHIFT);
                tap_code(KC_E);
                tap_code(KC_N);
                set_mods(mod_state);
                return false;
            }
        }
         /*else process HOME_N as usual.*/
        return true;

    case HOME_T:
         /*This piece of code nullifies the effect of Left Shift when*/
         /*tapping the HOME_T key. This helps rolling over HOME_S and HOME_T */
         /*to obtain the intended "st" instead of "T". Consequently, capital T can */
         /*only be obtained by tapping HOME_T and holding HOME_E (which is the right shift mod tap).*/
        if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
            if (mod_state & MOD_BIT(KC_LSHIFT)) {
                unregister_code(KC_LSHIFT);
                tap_code(KC_S);
                tap_code(KC_T);
                set_mods(mod_state);
                return false;
            }
        }
         /*else process HOME_T as usual.*/
        return true;

    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;

    case ND_TILD:
      //Compensate for the swedish layout...
      if (record->event.pressed) {
        SEND_STRING(SS_ALGR("]")" ");
      }
      break;
    case ND_CIRC:
      //Compensate for the swedish layout...
      if (record->event.pressed) {
        SEND_STRING("} ");
      }
      break;
    case NO_D_GRV:
      //Compensate for the swedish layout...
      if (record->event.pressed) {
        SEND_STRING("+ ");
      }
      break;
    case E_ACUTE:
      if(record->event.pressed) {
        SEND_STRING("=e");
      }
      break;
    }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

//void encoder_update_user(uint8_t index, bool clockwise) {
//  if (muse_mode) {
//    if (IS_LAYER_ON(_RAISE)) {
//      if (clockwise) {
//        muse_offset++;
//      } else {
//        muse_offset--;
//      }
//    } else {
//      if (clockwise) {
//        muse_tempo+=1;
//      } else {
//        muse_tempo-=1;
//      }
//    }
//  } else {
//    if (clockwise) {
//      register_code(KC_PGDN);
//      unregister_code(KC_PGDN);
//    } else {
//      register_code(KC_PGUP);
//      unregister_code(KC_PGUP);
//    }
//  }
//}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
/*
 * Cool Function where a single key does ALT+TAB
 * From: https://beta.docs.qmk.fm/features/feature_macros#super-alt-tab
 */
bool is_alt_tab_active = false;    // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;        // we will be using them soon.

void matrix_scan_user(void) {
    // The very important timer used for Super Alt Tab.
    if (is_alt_tab_active && timer_elapsed(alt_tab_timer) > 1000) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

//void matrix_init_user() {
//	set_unicode_input_mode(UC_LNX);
//};

enum layer_names {
    _COLEMAK_DHM = 0,
    _SYM,
    _NAV,
    _MOUSE,
    _GAME,
    _ADJUST,
};

// Layer keys
#define NAV MO(_NAV)
#define SYM MO(_SYM)
#define MOUSE MO(_MOUSE)
#define ADJUST MO(_ADJUST)
#define SYM_ENT LT(_SYM, KC_ENT)
// Toggle Layer
#define GAME TG(_GAME)

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
#define HOME_N RCTL_T(SE_N)
#define HOME_E RSFT_T(SE_E)
#define HOME_I RALT_T(SE_I)
#define HOME_O RGUI_T(SE_O)

#define NAV MO(_NAV)
#define ADJUST MO(_ADJUST)

enum unicode_names {
        e_ACUT,
        E_ACUT_U,
        u_ACUT,
        U_ACUT_U,
        a_GRAV,
        A_GRAV_U,
        e_GRAV,
        E_GRAV_U,
        u_GRAV,
        U_GRAV_U,
        a_CIRC,
        A_CIRC_U,
        e_CIRC,
        E_CIRC_U,
        i_CIRC,
        I_CIRC_U,
        o_CIRC,
        O_CIRC_U,
        u_CIRC,
        U_CIRC_U,
        i_UML,
        I_UML_U,
        o_UML,
        O_UML_U,
        c_CDIL,
        C_CDIL_U
};

const uint32_t PROGMEM unicode_map[] = {
    [e_ACUT] = 0x00E9,
    [E_ACUT_U] = 0x00C9,
    [u_ACUT] = 0x00F9,
    [U_ACUT_U] = 0x00D9,
    [a_GRAV] = 0x00E0,
    [A_GRAV_U] = 0x00C0,
    [e_GRAV] = 0x00E8,
    [E_GRAV_U] = 0x00C8,
    [u_GRAV] = 0x00F9,
    [U_GRAV_U] = 0x00D9,
    [a_CIRC] = 0x00E2,
    [A_CIRC_U] = 0x00C2,
    [e_CIRC] = 0x00EA,
    [E_CIRC_U] = 0x00CA,
    [i_CIRC] = 0x00EE,
    [I_CIRC_U] = 0x00CE,
    [o_CIRC] = 0x00F4,
    [O_CIRC_U] = 0x00D4,
    [u_CIRC] = 0x00FB,
    [U_CIRC_U] = 0x00DB,
    [i_UML]  = 0x00EF,
    [I_UML_U]  = 0x00CF,
    [o_UML]  = 0x00F6,
    [O_UML_U]  = 0x00DC,
    [c_CDIL] = 0x00E7,
    [C_CDIL_U] = 0x00C7
};

enum custom_keycodes {
    ARROW_R = SAFE_RANGE,
    G_DOWN,
    G_UP,
    G_HOME,
    G_END,
    ALT_TAB,
    NO_D_TILDE,
    NO_D_CIRC,
    NO_D_GRV,
    E_ACUTE
};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
// Initialize boolean variable which
// tells if the last key hit was an accented letter.
static bool has_typed_accent;
/*
 * Cool Function where a single key does ALT+TAB
 * From: https://beta.docs.qmk.fm/features/feature_macros#super-alt-tab
 */
bool is_alt_tab_active = false;    // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;        // we will be using them soon.

// The very important timer used for Super Alt Tab.
void matrix_scan_user(void) {
  if (is_alt_tab_active && timer_elapsed(alt_tab_timer) > 1000) {
    unregister_code(KC_LALT);
    is_alt_tab_active = false;
  }
}


bool process_bilateral_combinations(uint16_t keycode, uint16_t homerow_keycode, uint16_t modifier, uint8_t mod_state)
{
    unregister_code(modifier);
    tap_code(homerow_keycode);
    tap_code16(keycode);
    set_mods(mod_state);
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
	//Bilateral combinations for normal keycodes
	//Top Left keycodes
    case SE_Q:
    case SE_W:
    case SE_F:
    case SE_P:
    case SE_B:
	//Middle keycodes
    case SE_A:
    case HOME_R:
    case HOME_S:
    case HOME_T:
    case SE_G:
	//Bottom Right
    case SE_BSLS:
    case SE_Z:
    case SE_X:
    case SE_C:
    case SE_D:
    case SE_V:
        if (record->event.pressed && !record->tap.interrupted) {
            if (mod_state & MOD_BIT(KC_LCTL))
            {
                return process_bilateral_combinations(keycode, SE_T, KC_LCTL, mod_state);
            }
	    else if (mod_state & MOD_BIT(KC_LSHIFT))
            {
                return process_bilateral_combinations(keycode, SE_S, KC_LSHIFT, mod_state);
            }
	    else if (mod_state & MOD_BIT(KC_LALT))
            {
                return process_bilateral_combinations(keycode, SE_R, KC_LALT, mod_state);
            }
        }
        break;
	//Top Right keycodes
    case SE_J:
    case SE_L:
    case SE_U:
    case SE_Y:
    case SE_SCLN:
    case SE_MINS:
	//Middle non-mod-alphas
    case SE_M:
    case HOME_N:
    case HOME_E:
    case HOME_I:
    case SE_O:
    case SE_QUOT:
	//Bottom Right alphas
    case SE_K:
    case SE_H:
    case SE_COMM:
    case SE_DOT:
    case SE_SLSH:
    case SE_DQUO:

        if (record->event.pressed && !record->tap.interrupted) {
            if (mod_state & MOD_BIT(KC_RCTL))
            {
                return process_bilateral_combinations(keycode, SE_N, KC_RCTL, mod_state);
            }
	    else if (mod_state & MOD_BIT(KC_RSHIFT))
            {
                return process_bilateral_combinations(keycode, SE_E, KC_RSHIFT, mod_state);
            }
	    else if (mod_state & MOD_BIT(KC_RALT))
            {
                return process_bilateral_combinations(keycode, SE_I, KC_RALT, mod_state);
            }
        }
        break;

    case G_DOWN:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_DOWN);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_DOWN);
        }
	  break;

    case G_UP:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_UP);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_UP);
        }
	  break;

    case G_HOME:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_HOME);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_HOME);
        }
	  break;

    case G_END:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_END);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_END);
        }
		break;

    case KC_ESC:
        // Home row alt-tabbing.
        if (mod_state & MOD_MASK_ALT) {
            if (record->event.pressed) {
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
        }
        // Else, let QMK process the KC_ESC keycode as usual
        return true;


/*
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
*/
/*
    case HOME_N:
         //This piece of code nullifies the effect of Right Shift when
         //tapping the HOME_N key. This helps rolling over HOME_E and HOME_N
         //to obtain the intended "en" instead of "N". Consequently, capital N can
         //only be obtained by tapping HOME_N and holding HOME_S (which is the left shift mod tap).
        if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
            if (mod_state & MOD_BIT(KC_RSHIFT)) {
                unregister_code(KC_RSHIFT);
                tap_code(KC_E);
                tap_code(KC_N);
                set_mods(mod_state);
                return false;
            }
        }
         //else process HOME_N as usual.
        return true;
*/

/*
    case HOME_T:
         //This piece of code nullifies the effect of Left Shift when
         //tapping the HOME_T key. This helps rolling over HOME_S and HOME_T
         //to obtain the intended "st" instead of "T". Consequently, capital T can
         //only be obtained by tapping HOME_T and holding HOME_E (which is the right shift mod tap).
        if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
            if (mod_state & MOD_BIT(KC_LSHIFT)) {
                unregister_code(KC_LSHIFT);
                tap_code(KC_S);
                tap_code(KC_T);
                set_mods(mod_state);
                return false;
            }
        }
         //else process HOME_T as usual.
        return true;

*/
    // Toggle off boolean if any other non-accent key is hit.
    has_typed_accent = false;

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

    case NO_D_TILDE:
      //Compensate for the swedish layout...
      if (record->event.pressed) {
        SEND_STRING(SS_ALGR("]")" ");
      }
      break;
    case NO_D_CIRC:
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

enum {
    TD_DOT = 0,
    TD_EXCLM,
    CA_CC_CV,
    TD_C_BSPC
};

// Tap dance states
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;

// create a global instance of the tapdance state type
static td_state_t td_state;

// function to track the current tapdance state
int cur_dance (qk_tap_dance_state_t *state);

// `finished` function for each tapdance keycode
void CA_CC_CV_finished (qk_tap_dance_state_t *state, void *user_data);

// To do: Look into more advanced tap dance functions
// that have a callback to each tap
void sentence_end(qk_tap_dance_state_t *state, void *user_data) {
    /* Detect double tap of TD_DOT */
    if (state->count == 2) {
        if (!(get_mods() & MOD_MASK_SHIFT)) {
        /* Check that Shift is inactive */
            SEND_STRING(". ");
            /* Internal code of OSM(MOD_LSFT) */
            set_oneshot_mods(MOD_LSFT | get_oneshot_mods()); // NOTE: Watch out for nullified shift for rolling home row keys
        } else { // shift is active, so send '>>'
            tap_code(KC_DOT);
            tap_code(KC_DOT);
        }
    }
    else {
        /* send KC_DOT as many times as I have tapped the TD_DOT key */
        for (uint8_t i = state->count; i > 0; i--) {
            tap_code(KC_DOT);
        }
    }
}

void exclamative_sentence_end(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
            SEND_STRING("! ");
            set_oneshot_mods(MOD_LSFT | get_oneshot_mods()); // NOTE: Watch out for nullified shift for rolling home row keys
    } else {
        for (uint8_t i = state->count; i > 0; i--) {
            tap_code16(KC_EXLM);
        }
    }
}


// `finished` function for each tapdance keycode
void CA_CC_CV_finished (qk_tap_dance_state_t *state, void *user_data);

// track the tapdance state to return
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
        return SINGLE_TAP;
    } else {
        return SINGLE_HOLD;
    }
  }
  if (state->count == 2) {
      return DOUBLE_SINGLE_TAP;
  }
  else {
      return 3; // any number higher than the maximum state value you return above
  }
}

// handle the possible states for each tapdance keycode you define:

void CA_CC_CV_finished(qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      tap_code16(C(KC_C));
      break;
    case SINGLE_HOLD:
      tap_code16(C(KC_A));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(C(KC_V));
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_DOT] = ACTION_TAP_DANCE_FN (sentence_end),
    [TD_EXCLM] = ACTION_TAP_DANCE_FN (exclamative_sentence_end),
    [CA_CC_CV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CA_CC_CV_finished, NULL),
    [TD_C_BSPC] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, LCTL(KC_BSPC))

};



/*
 * Per key tapping term settings
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_I:
            // My ring finger tends to linger on the key
            // This tapping term allows me to type "ion" effortlessly.
            return TAPPING_TERM + 200;
        case HOME_R:
            return TAPPING_TERM + 200;
	default:
            return TAPPING_TERM;
    }
}

/*MAKE SURE THAT ADJUST AND RESET ARE ACCESSIBLE !!*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK_DHM] = LAYOUT_5x6(
       NO_D_GRV, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,    KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11,
         KC_TAB, SE_Q  , SE_W  , SE_F  , SE_P  , SE_B  ,    SE_J  , SE_L  , SE_U  , SE_Y  ,SE_SCLN,SE_MINS,
         KC_ESC, SE_A  , HOME_R, HOME_S, HOME_T, SE_G  ,    SE_M  , HOME_N, HOME_E, HOME_I, SE_O  ,SE_QUOT,
         SE_BSLS,SE_Z  , SE_X  , SE_C  , SE_D  , SE_V  ,    SE_K  , SE_H  ,SE_COMM, SE_DOT,SE_SLSH,SE_DQUO,
                        SE_LPRN,SE_RPRN,                                   SE_LBRC, SE_RBRC,
                                          NAV  , KC_SPC,    KC_BSPC, SYM_ENT,
                                        ALT_TAB, MOUSE ,    KC_DEL , KC_LGUI,
                                        KC_LALT,KC_LALT,    KC_LGUI, GAME
  ),

  [_SYM] = LAYOUT_5x6(

        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        KC_DOT , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,    KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,SE_ARNG,
     NO_D_TILDE,SE_EXLM, SE_AT ,SE_HASH,SE_DLR ,SE_PERC,  NO_D_CIRC,SE_AMPR,SE_ASTR,SE_EQL ,SE_ODIA,SE_ADIA,
        SE_PIPE,_______,_______,_______,_______,_______,    _______,_______,SE_LABK,SE_RABK,SE_QUES,SE_PLUS,
				SE_LABK,SE_RABK,                                    SE_LCBR,SE_RCBR,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    ADJUST, ADJUST
  ),

  [_NAV] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______, C_INS , S_INS ,_______,E_ACUTE,    KC_HOME,KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,KC_END ,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
                        _______,_______,                                    _______,_______,
                                         _______,_______,   _______,_______,
                                         _______,_______,   _______,_______,
                                           ADJUST,ADJUST,   _______,_______
  ),

    [_MOUSE] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,KC_WBAK,KC_MS_U,KC_WFWD,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,_______,
        _______,_______,_______,_______,_______,_______,    _______,KC_BTN3,KC_WH_D,KC_WH_U,_______,_______,
                        _______,_______,                                    _______,_______,
                                        _______,_______,    KC_BTN1,KC_BTN2,
                                        _______,_______,    KC_BTN3,_______,
                                        _______,_______,    _______,_______
  ),
 /*   [_GAME] = LAYOUT_5x6(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,    KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,_______,
        KC_TAB , KC_ESC, KC_Q  , KC_W  , KC_E  , KC_R  ,    KC_Y  , KC_U  , KC_UP , KC_O  , KC_P  ,SE_ARNG,
        KC_LSFT, KC_A  , KC_A  , KC_S  , KC_D  , KC_F  ,    KC_H  ,KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,SE_ADIA,
        KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,    KC_N  , KC_M  ,_______,_______,_______,_______,
                        _______,_______,                                   _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    ),*/
    [_GAME] = LAYOUT_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
                      KC_LALT,KC_LALT,                                                       KC_PLUS, KC_EQL,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    ),
    [_ADJUST] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______, RESET ,    _______,_______,_______,_______,_______,_______,
                        _______,_______,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    _______,_______
    )
};

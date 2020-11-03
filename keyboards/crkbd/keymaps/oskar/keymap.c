#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "keymap_swedish.h"

#ifdef OLED_DRIVER_ENABLE
#    include "oled.c"
#endif

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#    include "rgb.c"
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DHM_SWE] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_TAB,  SE_Q,    SE_W,    SE_F,    SE_P,    SE_B,                         SE_J,    SE_L,    SE_U,    SE_Y,    SE_SCLN, SE_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_ESC,  SE_A,    SE_R,    HOME_S,  HOME_T,  SE_G,                         SE_M,    HOME_N,  HOME_E,  SE_I,    SE_O,    SE_QUOT,
  //---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_BSLS, SE_Z,    SE_X,    SE_C,    SE_D,    SE_V,                         SE_K,    SE_H,    SE_COMM, SE_DOT,  SE_SLSH, SE_DQUO,
  //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         ALT_TAB, RAISE,   KC_SPC,     KC_BSPC, LOW_ENT, KC_LGUI
                                      //|--------------------------|  |--------------------------|

  ),

  [_LOWER] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     NO_D_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_ARNG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   NO_D_TILDE,SE_EXLM, SE_AT,   SE_HASH, SE_DLR,  SE_PERC,                     NO_D_CIRC,SE_AMPR, SE_ASTR, SE_EQL,  SE_ODIA, SE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SE_PIPE, _______, SE_LPRN, SE_RPRN, SE_LABK, SE_RABK,                      SE_LCBR, SE_RCBR, SE_LBRC, SE_RBRC, SE_QUES, SE_PLUS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,    _______, LOW_DEL, _______
                                      //|--------------------------|  |--------------------------|
  ),

  [_RAISE] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     _______, _______, C_INS,   S_INS,   _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,     KC_HOME, KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT, KC_END ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,    _______, _______, _______
                                      //|--------------------------|  |--------------------------|
  ),

  // CURRENTLY UNUSED!!!!
  [_ADJUST] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     XXXXXXX, CK_RST,  CK_DOWN, CK_UP,   CK_TOGG, RGB_TOG,                       MU_TOG, KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,                       MU_MOD, KC_F11,  KC_F4,   KC_F5,   KC_F6,   RESET,  \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGBRST,                        AU_TOG, KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,    _______, KC_VOLD, KC_VOLU \
                                      //|--------------------------|  |--------------------------|
  )
};
// clang-format off

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
layer_state_t layer_state_set_user(layer_state_t state) {
    /* For any layer other than default, save current RGB state and switch to layer-based RGB */
    if (layer_state_cmp(state, 0)) {
        restore_rgb_config();
    } else {
        uint8_t layer = get_highest_layer(state);
        if (layer_state_cmp(layer_state, 0)) save_rgb_config();
        rgb_by_layer(layer);
    }
    return state;
}
#endif

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
    if (record->event.pressed) {
        oled_timer = timer_read();
        add_keylog(keycode);
    }
#endif

    mod_state = get_mods();
    switch (keycode) {
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


        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
        case RGB_MOD:
        case RGB_TOG:
        case RGB_HUI:
        case RGB_HUD:
        case RGB_SAI:
        case RGB_SAD:
        case RGB_VAI:
        case RGB_VAD:
        case RGB_SPI:
        case RGB_SPD:
            /* Override layer-based RGB and resume RGB effect to be able to preview changes */
            if (record->event.pressed) {
                restore_rgb_config();
                process_rgb(keycode, record);
                save_rgb_config();
            }
            return false;
        case RGBRST:
            if (record->event.pressed) {
#    ifdef RGBLIGHT_ENABLE
                eeconfig_update_rgblight_default();
                rgblight_enable();
#    elif RGB_MATRIX_ENABLE
                eeconfig_update_rgb_matrix_default();
                rgb_matrix_enable();
#    endif
                save_rgb_config();
            }
            return false;
#endif
    }
    return true;
}

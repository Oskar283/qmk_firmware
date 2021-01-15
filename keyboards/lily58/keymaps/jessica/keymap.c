#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(	KC_ESC, SE_1, SE_2, SE_3, SE_4, SE_5,					SE_6, SE_7, SE_8, SE_9, SE_0, KC_BSPC,
			KC_TAB, SE_Q, SE_W, SE_E, SE_R, SE_T,					SE_Y, SE_U, SE_I, SE_O, SE_P, SE_ARNG,
			KC_LSFT, SE_A, SE_S, SE_D, SE_F, SE_G,					SE_H, SE_J, SE_K, SE_L, SE_ODIA, SE_ADIA,
			KC_LCTL, SE_Z, SE_X, SE_C, SE_V, SE_B, SE_LABK, 		SE_QUOT,SE_N, SE_M, SE_COMM, SE_DOT, SE_MINS, KC_RSFT,
			SE_BSLS, KC_LGUI, KC_LALT, KC_SPC,					KC_ENT, MO(1), KC_RALT, KC_DEL),


	[1] = LAYOUT(	KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,				KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 			KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,			KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_TRNS,
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,	KC_TRNS,KC_TRNS, SE_PLUS, SE_QUES, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,					KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};


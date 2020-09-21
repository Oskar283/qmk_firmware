#include QMK_KEYBOARD_H
#include "keymap_swedish.h"


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(LCTL(SE_Z), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,			KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
			  KC_TAB, SE_Q, SE_W, SE_F, SE_P, SE_B,				SE_J, SE_L, SE_U, SE_Y, SE_ODIA, SE_ARNG,
			  KC_GESC, SE_A, SE_R, LSFT_T(SE_S), LCTL_T(SE_T), SE_G,	SE_M, LCTL_T(SE_N), LSFT_T(SE_E), SE_I, SE_O, SE_ADIA,
			  KC_BSLS, SE_Z, SE_X, SE_C, SE_D, SE_V, SE_LBRC,		SE_RBRC, SE_K, SE_H, SE_COMM, SE_DOT, SE_SLSH, SE_EQL,
			  KC_LGUI, KC_LALT, MO(2), KC_SPC, 				KC_BSPC, LT(1,KC_ENT), KC_BSPC, KC_DEL),
	[1] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOT, SE_1, SE_2, SE_3, SE_4, SE_5, SE_6, SE_7, SE_8, SE_9, SE_0, KC_TRNS, KC_GRV, SE_EXLM, SE_AT, SE_HASH, SE_DLR, SE_PERC, SE_CIRC, SE_AMPR, SE_ASTR, SE_LPRN, SE_RPRN, SE_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SE_UNDS, SE_PLUS, SE_LCBR, SE_RCBR, SE_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_INS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

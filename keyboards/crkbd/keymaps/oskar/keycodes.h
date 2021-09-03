#pragma once

enum layers {
    _COLEMAK_DHM_SWE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes { COLEMAK_DHM_SWE = SAFE_RANGE, LOWER, RAISE, ADJUST, RGBRST, //Gotham keycodes
	               NO_D_TILDE, NO_D_CIRC, NO_D_GRV //Oskar keycodes
};

// Gotham defines
#define SFT_EQ MT(MOD_LSFT, KC_EQL)
#define SFT_QT MT(MOD_RSFT, KC_QUOT)

#define SFT_A MT(MOD_LSFT, KC_A)
#define CTL_Z MT(MOD_LCTL, KC_Z)

#define SFT_SCLN MT(MOD_RSFT, KC_SCLN)
#define CTL_SLSH MT(MOD_RCTL, KC_SLSH)

#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_EQ LT(_RAISE, KC_EQL)
#define RAI_ENT LT(_RAISE, KC_ENT)
#define LOW_ENT LT(_LOWER, KC_ENT)
#define LOW_BSP LT(_LOWER, KC_BSPC)
#define LOW_DEL LT(_LOWER, KC_DEL)
#define ADJ_GRV LT(_ADJUST, KC_GRV)
#define KC_ANGL LSFT(KC_COMM)
#define KC_ANGR LSFT(KC_DOT

// Oskar defines
// Left-hand home row mods
#define HOME_A LGUI_T(SE_A)
#define HOME_R LALT_T(SE_R)
>>>>>>> rebaseUpstream
#define HOME_S LSFT_T(SE_S)
#define HOME_T LCTL_T(SE_T)

// Right-hand home row mods
#define HOME_O LGUI_T(SE_O)
#define HOME_I LALT_T(SE_I)
>>>>>>> rebaseUpstream
#define HOME_E RSFT_T(SE_E)
#define HOME_N LCTL_T(SE_N)

#define C_INS LCTL(KC_INS)
#define S_INS LSFT(KC_INS)

#include QMK_KEYBOARD_H
#include "kb.h"

enum layers {
  _QWERT = 0,
  _Y = 1,
  _RAISE = 2,
};

#define FN MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERT] = LAYOUT(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_BSPC, KC_ESC, 
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_ENT, G(2), 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, 
		KC_LCTL, KC_LGUI, KC_LALT, KC_DOT, MO(1), KC_SPC),

	[_Y] = LAYOUT(
		KC_Y, KC_U, KC_I, KC_O, KC_P, KC_TRNS, KC_TRNS, 
		KC_H, KC_J, KC_K, KC_L, KC_TAB, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_B, KC_N, KC_M, KC_COMM, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_SLSH, KC_TRNS, KC_TRNS),

	[_RAISE] = LAYOUT(
		KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS, KC_TRNS, 
		KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, 
		KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};
/* Copyright 2020 Paul James
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERKCANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_swiss_de.h"

enum layers {
  _QWERTY = 0,
  _LOWER = 1,
  _RAISE = 2,
  _FUNCTION
};

enum custom_keycodes {
    AE = SAFE_RANGE,
    OE,
    UE
};


#define FN MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   `  |  1   |  2   |  3   |  4   |  5   | |  6   |  7   |  8   |  9   |  0   | BkSp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |  O   |  P   | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |  A   |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shft |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  ,   |  .   |  /   | Entr |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl | Lock | Alt  | Cmd  | MO1  | Spac | | Spac |  MO2 | Left | Down |  Up  | Rght |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x12(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, KC_CAPS, KC_LALT, KC_LGUI, MO(1),   KC_SPC,  KC_SPC,  MO(2),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* LOWER
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  | |  7   |  8   |  9   |  *   |  NO  | BkSp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |  F6  |  F7  |  F8  |  F9  |  F10 | |  4   |  5   |  6   |  -   |PSCREEN| Del |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |  F11 |  F12 |  F13 |  F14 |  F15 | |  1   |  2   |  3   |      |  NO   |  NO |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shft |  NO  |  NO  |  NO  |  NO  |  NO  | |  0   |  NO  |  ,   | Entr |  NO  | Entr |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |  Fn  | Alt  | Cmd  |  Fn  | Spac | | Spac |  Fn  | Home |PGDown| PGUp | End  |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_5x12(
    KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_KP_7,    KC_KP_8,  KC_KP_9,     KC_KP_ASTERISK,  KC_NUMLOCK,  KC_TRNS,
    KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_KP_4,    KC_KP_5,  KC_KP_6,     KC_KP_MINUS,     KC_PSCREEN,  KC_TRNS,
    KC_TRNS,  KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_KP_1,    KC_KP_2,  KC_KP_3,     KC_KP_PLUS,      KC_NO,       KC_NO,
    KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_KP_0,    KC_NO,    KC_KP_COMMA, KC_KP_ENTER,     KC_NO,       KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  MO(1),    KC_TRNS,  KC_TRNS,    MO(2),    KC_HOME,     KC_PGDOWN,       KC_PGUP,     KC_END
),

/* RAISE
 * ,-----------------------------------------. ,-----------------------------------------.
 * |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  | |  |   |  ¢   |  {   |   }  |  NO  | BkSp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |  NO  |  NO  |  NO  |  NO  |  NO  | |  NO  |  ü   |  NO  |  ö   |PSCREEN| Del |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |  ä   |  NO  |  NO  |  NO  |  NO  | |  NO  |  NO  |  NO  |  NO  |  [   |   ]  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shft |  NO  |  NO  |  NO  |  NO  |  NO  | |  NO  |  NO  |  -   |  =   | BSLS | Entr |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |  Fn  | Alt  | Cmd  |  Fn  | Spac | | Spac |  Fn  | Home |PGDown| PGUp | End  |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_5x12(
    KC_NO,   KC_NO,    KC_AT,    KC_HASH,    KC_NO,    KC_NO,    KC_NO,    KC_PIPE,    KC_NO,    KC_LCBR,    KC_RCBR,    KC_TRNS,
    KC_TRNS, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    UE,    KC_NO,    OE,    KC_NO,    KC_TRNS,
    KC_TRNS, AE,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_LBRC, KC_RBRC,
    KC_TRNS, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_MINS, KC_EQL,  KC_BSLS, KC_ENT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(1),   KC_TRNS,  KC_TRNS,  MO(2),   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS
),

/* Function
* ,------------------------------------------. ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_FUNCTION] = LAYOUT_ortho_5x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
)

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
   case AE:
       if (record->event.pressed) {
           SEND_STRING(
            SS_DOWN(X_LGUI) SS_TAP(X_SPC) SS_UP(X_LGUI)
            );
           tap_code(CH_ADIA);
           SEND_STRING(
           SS_DOWN(X_LGUI) SS_TAP(X_SPC) SS_UP(X_LGUI)
            );
       }
       break;

   case OE:
       if (record->event.pressed) {
           SEND_STRING(
            SS_DOWN(X_LGUI) SS_TAP(X_SPC) SS_UP(X_LGUI)
            );
           tap_code(CH_ODIA);
           SEND_STRING(
           SS_DOWN(X_LGUI) SS_TAP(X_SPC) SS_UP(X_LGUI)
            );
       }
       break;

   case UE:
       if (record->event.pressed) {
           SEND_STRING(
            SS_DOWN(X_LGUI) SS_TAP(X_SPC) SS_UP(X_LGUI)
            );
           tap_code(CH_UDIA);
           SEND_STRING(
           SS_DOWN(X_LGUI) SS_TAP(X_SPC) SS_UP(X_LGUI)
            );
       }
       break;
   }
   return true;
};

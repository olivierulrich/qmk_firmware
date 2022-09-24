#include QMK_KEYBOARD_H
#include "keymap_german_ch.h"

<<<<<<< HEAD
enum layers {
  _QWERTY = 0,
  _LOWER = 1,
  _RAISE = 2,
  _FUNCTION
=======
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _QWERTY,
    _COLEMAK,
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
>>>>>>> fe9c1d8e456c293166ff8664ff280710eb5aa416
};

#define FN MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,------------------------------------------------------------------------------------
   * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  <-  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  |   ¨  |
   * |------+------+------+------+------+-------------+------+------+------+------+------+
   * | Shift|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   '  |   ^  |
   * |------+------+------+------+------+------|------+------+------+------+------+------+
   * |  <>  |   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+
   * |      |      | GUI  |Space | Alt  |             |Bkspc |Space |Enter |      |      |
   * |------------------------------------------------------------------------------------
   * |      |      |      |Lower | Ctrl |             |Enter |Raise |      |      |      |
   * `------------------------------------------------------------------------------------
   */
  [_QWERTY] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
     KC_GESC ,CH_1    ,CH_2    ,CH_3    ,CH_4    ,CH_5    ,CH_6    ,CH_7    ,CH_8    ,CH_9    ,CH_0    ,KC_BSPC ,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
     KC_TAB  ,CH_Q    ,CH_W    ,CH_E    ,CH_R    ,CH_T    ,CH_Z    ,CH_U    ,CH_I    ,CH_O    ,CH_P    ,CH_DIAE ,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
     CH_LABK ,CH_A    ,CH_S    ,CH_D    ,CH_F    ,CH_G    ,CH_H    ,CH_J    ,CH_K    ,CH_L    ,CH_QUOT ,CH_CIRC ,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
     KC_LSFT ,CH_Y    ,CH_X    ,CH_C    ,CH_V    ,CH_B    ,CH_N    ,CH_M    ,CH_COMM ,CH_DOT  ,CH_MINS ,KC_ENT  ,
  //|--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------+
     KC_HYPR ,KC_LGUI ,KC_SPC  ,MO(1),   KC_LALT ,KC_LCTL ,KC_ENT  ,KC_BSPC ,MO(2),   KC_SPC  ,KC_ENT  ,KC_RGHT 
  //`--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------+
  ),

/* Lower
   * ,------------------------------------------------------------------------------------
   * | Esc  |   1  |   2  |   3  |   4  |   5  |   7  |   8  |   9  |      |   /  |  <-  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   4  |   5  |   6  |      |  up  |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------+
   * | Shift|   A  |   S  |   D  |   F  |   G  |   1  |   2  |   3  |      | down |right |
   * |------+------+------+------+------+------|------+------+------+------+------+------+
   * |  <>  |   Y  |   X  |   C  |   V  |   B  |   0  |   ,  |   .  | left |      |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+
   * |      |      | GUI  |Space | Alt  |       Enter |Space |Bkspc |      |      |      |
   * |------------------------------------------------------------------------------------
   * |      |      |      |Lower | Ctrl |             |Raise |Enter |      |      |      |
   * `------------------------------------------------------------------------------------
 */
[_LOWER] = LAYOUT(
  KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_KP_ASTERISK, KC_NUMLOCK, KC_TRNS,
  KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_KP_MINUS,    KC_UP,      KC_DEL,
  KC_TRNS,  KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_KP_PLUS,     KC_DOWN,    KC_RGHT,
  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_KP_0,    KC_NO,      KC_KP_COMMA,KC_LEFT,        KC_NO,      KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  MO(1),    KC_TRNS,  KC_TRNS,    MO(2),      KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS
), 

/* Raise
   * ,------------------------------------------------------------------------------------
   * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  <-  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Z  |   Ü  |   I  |   Ö  |   P  |   ¨  |
   * |------+------+------+------+------+-------------+------+------+------+------+------+
   * | Shift|   Ä  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   [  |   ]  |
   * |------+------+------+------+------+------|------+------+------+------+------+------+
   * |  <>  |   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   {  |   }  |   -  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+
   * |      |      | GUI  |Space | Alt  |             |Enter |Space |Bkspc |      |      |
   * |------------------------------------------------------------------------------------
   * |      |      |      |Lower | Ctrl |             |      |Raise |Enter |      |      |
   * `------------------------------------------------------------------------------------
 */
[_RAISE] = LAYOUT(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_BSPC, 
  KC_GRV,  KC_F11,  KC_F12,  _______, _______, _______, _______, CH_UDIA, _______, CH_ODIA, _______, KC_DEL , 
  KC_DEL,  CH_ADIA, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, 
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______, 
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  MO(1),    KC_TRNS,  KC_TRNS,    MO(2),      KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS
),

/* Adjust (Lower + Raise)
   * ,------------------------------------------------------------------------------------
   * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  <-  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  |   ¨  |
   * |------+------+------+------+------+-------------+------+------+------+------+------+
   * | Shift|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   '  |   ^  |
   * |------+------+------+------+------+------|------+------+------+------+------+------+
   * |  <>  |   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+
   * |      |      | GUI  |Space | Alt  |             |Enter |Space |Bkspc |      |      |
   * |------------------------------------------------------------------------------------
   * |      |      |      |Lower | Ctrl |             |      |Raise |Enter |      |      |
   * `------------------------------------------------------------------------------------
 */
<<<<<<< HEAD
[_FUNCTION] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 , 
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL , 
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______,  _______, _______, 
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, 
  KC_HYPR ,KC_LGUI ,KC_SPC  ,MO(1),KC_LALT ,KC_LCTL ,KC_ENT  ,KC_BSPC ,MO(2),KC_SPC  ,KC_ENT  ,KC_RGHT 
=======
[_ADJUST] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 , _______,
  _______, QK_BOOT,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL , _______,
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______, _______
>>>>>>> fe9c1d8e456c293166ff8664ff280710eb5aa416
)


};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
      }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MO(1):
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _FUNCTION);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _FUNCTION);
      }
      return false;
    case MO(2):
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _FUNCTION);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _FUNCTION);
      }
      return false;
    }
  return true;
}
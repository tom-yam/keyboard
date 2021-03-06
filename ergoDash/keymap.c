#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   -  |                    |   =  |   6  |   7  |   8  |   9  |   0  |   `  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | TAB  |   Q  |   W  |   E  |   R  |   T  |   {  |                    |   }  |   Y  |   U  |   I  |   O  |   P  |   |  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |  TAB |                    |  ESC |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |  Alt |                    |  ESC |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | CAPS |  GUI |  ALt |______| Lower|  GUI | Ctrl | Space||||||||  BS  | Enter| GUI  | Raise|______| Down |  Up  | HOME |
   * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                        KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB ,                        KC_ESC,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT,                        KC_ESC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_CAPS, KC_LGUI, KC_LALT,          LOWER,   KC_LGUI, KC_LCTL,  KC_SPC,       KC_BSPC,KC_ENT,  KC_RGUI, RAISE,            KC_DOWN, KC_UP,   KC_HOME\
  ),

  /* Raise 
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  ESC |  F1  |  F2  |  F3  |  F4  |  F5  |   _  |                    |   +  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  Tab |   !  |   @  |   #  |   $  |   T  |   {  |                    |   }  |   ^  |   &  |   *  |   (  |   )  |   |  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   1  |   2  |   3  |   4  |   5  |  TAB |                    |  ESC |   ^  |   &  |   *  |   (  |   )  |   "  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   _  |   +  |  Alt |                    |  ESC |   {  |   }  |   *  |   (  |   )  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | CAPS |  GUI |  ALt |______| Lower|  GUI | Ctrl | Space||||||||  BS  | Enter| GUI  | Raise|______| Down |  Up  | HOME |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_UNDS,                        KC_PLUS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_T,    KC_LCBR,                        KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TAB,                         KC_ESC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQT,  \
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_UNDS, KC_PLUS, KC_LALT,                        KC_ESC,  KC_LCBR, KC_RCBR, KC_ASTR, KC_LPRN, KC_RPRN, KC_RSFT, \
    KC_CAPS, KC_LGUI, KC_LALT,          LOWER,   KC_LGUI, KC_LCTL,  KC_SPC,       KC_BSPC,KC_ENT,  KC_RGUI, RAISE,            KC_DOWN, KC_UP,   KC_HOME\
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  ESC |  F1  |  F2  |  F3  |  F4  |  F5  |   _  |                    |   +  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  Tab |   !  |   @  |   #  |   $  |   T  |   {  |                    |   }  |   ^  |   &  |   *  |   (  |   )  |   |  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   !  |   @  |   #  |   $  |   %  |  TAB |                    | ESC  |   6  |   7  |   8  |   9  |   0  |  ,   | 
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   ^  |   &  |   *  |   -  |   =  |   |  |                    | ESC  |   [  |   ]  |  F8  |  F9  |  F10 |  F12 |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | CAPS |  GUI |  ALt |______| Lower|  GUI | Ctrl | Space||||||||  BS  | Enter| GUI  | Raise|______| Down |  Up  | HOME |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_UNDS,                        KC_PLUS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_LSFT, KC_LCBR,                        KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
    KC_LCTL, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TAB,                         KC_ESC,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DQT,  \
    KC_LSFT, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PEQL, KC_BSLS,                        KC_ESC , KC_LBRC, KC_RBRC, KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    KC_CAPS, KC_LGUI, KC_LALT,          LOWER,   KC_LGUI, KC_LCTL,  KC_SPC,       KC_BSPC,KC_ENT,  KC_RGUI, RAISE,            KC_DOWN, KC_UP,   KC_HOME\
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}





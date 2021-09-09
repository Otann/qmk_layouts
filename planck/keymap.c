/* Copyright 2021 Anton Chebotaev */

#include QMK_KEYBOARD_H
#include "config.h"

enum planck_layers {
  _QWERTY,
  _COLEMAK_DH,
  _LOWER,
  _RAISE,
  _FN
};


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define LOWER_T TG(_LOWER)
#define RAISE_T TG(_RAISE)
#define FN_GRV LT(_FN, KC_GRV)

#define T_QWERT DF(_QWERTY)
#define T_COLEM DF(_COLEMAK_DH)

#define PRV_TAB LCMD(KC_LCBR)
#define NXT_TAB LCMD(KC_RCBR)
#define CMD_ENT LCMD(KC_ENT)
#define CMD_S_4 SCMD(KC_4)
#define CMD_S_3 SCMD(KC_3)
#define UMLAUT  LALT(KC_U)

#define OPT_TAB MT(MOD_LALT, KC_TAB)  // Tab on tap, Option on hold
#define CTL_ESC MT(MOD_LCTL, KC_ESC)  // Esc on tap, Ctrl on hold
#define SHT_SPC MT(MOD_LSFT, KC_SPC)  // Space on tap, Shift on hold
#define SHT_ENT MT(MOD_LSFT, KC_ENT)  // Enter on tap, Shift on hold
#define LANG_SW LALT(KC_SPC)          // my language switching combo

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  FN  | COLE |   ⌃  |   ⌥  |   ⌘  |Enter |Space |Lower |Raise | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    OPT_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT,
    FN_GRV,  T_COLEM, KC_LCTL, KC_LALT, KC_LGUI, SHT_ENT, SHT_SPC, LOWER,   RAISE ,  KC_LEFT, KC_DOWN, KC_RGHT
),

/* Colemak DH 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  FN  | QWER |   ⌃  |   ⌥  |   ⌘  |Enter |Space |Lower |Raise | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK_DH] = LAYOUT_planck_grid(
    OPT_TAB, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT,
    FN_GRV,  T_QWERT, KC_LCTL, KC_LALT, KC_LGUI, SHT_ENT, KC_SPC,  LOWER,   RAISE ,  KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | TRNS |   !  |   @  |   {  |   }  |   %  |   ^  |  &   |  *   |   -  |   =  | TRNS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |   ?  |   $  |   (  |   )  |   <  |   >  | Left | Down |  Up  |Right |   `  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |   /  |   #  |   [  |   ]  |   ~  |   \  |  ¨   |  |   |   _  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS | lng  | TRNS | TRNS | TRNS | TRNS | TRNS |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______,
    _______, KC_QUES, KC_DLR,  KC_LPRN, KC_RPRN, KC_LT,   KC_GT,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_GRV,
    _______, KC_SLSH, KC_HASH, KC_LBRC, KC_RBRC, KC_TILD, KC_BSLS, UMLAUT,  KC_PIPE, KC_UNDS, KC_PLUS, XXXXXXX,
    _______, LANG_SW, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | TRNS |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | TRNS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |   6  |   7  |   8  |   9  |   0  |      |   4  |   5  |   6  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |      |   1  |   2  |   3  |   0  | TRNS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |      | TRNS | TRNS | TRNS | TRNS | TRNS |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
  */
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_4,    KC_5,    KC_6,    KC_0,    XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_0,    _______,
    _______, XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* FN Layer
 * ,-----------------------------------------------------------------------------------.
 * |reset |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |  F11 |  F12 | ⇧⌘3  | ⇧⌘4  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS | prev | pause| next | mute | vol- | vol+ |      |      |      |brgh- |brgh+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |      | TRNS | TRNS | TRNS | TRNS | TRNS |raiseT|lowerT|      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_planck_grid(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
    _______, KC_F11,  KC_F12,  CMD_S_3, CMD_S_4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,
    _______, KC_VOLD, KC_MUTE, KC_VOLU, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,
    _______, XXXXXXX, _______, _______, _______, _______, _______, LOWER_T, RAISE_T, XXXXXXX, XXXXXXX, XXXXXXX
)

};

#ifdef RGBLIGHT_ENABLE

#define MY_HSV_PURPLE 200, 255, 255
#define MY_HSV_GREEN 85, 255, 255
#define MY_HSV_ORANGE 30, 255, 255
#define MY_HSV_WHITE 0, 0, 255

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(200, 255, 255);
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _COLEMAK_DH:
        rgblight_sethsv_noeeprom(MY_HSV_GREEN);
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv_noeeprom(MY_HSV_PURPLE);
        break;
    }
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        rgblight_sethsv_noeeprom(MY_HSV_ORANGE);
        break;
    case _RAISE:
        rgblight_sethsv_noeeprom(MY_HSV_ORANGE);
        break;
    case _FN:
        rgblight_sethsv_noeeprom(MY_HSV_WHITE);
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv_noeeprom(MY_HSV_PURPLE);
        break;
    }
  return state;
}
#endif
// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_number {
    _DOTA_BASE = 0,
    _DOTA_MOD,
};

enum custom_keycodes {
    blank = SAFE_RANGE,
    STORE,
    THL,
    THM,
    THR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐  
      * │ A │ B │ C │ D │ E │  
      * ├───┼───┼───┼───┼───┤  
      * │ F │ G │ H │ I │ J │  
      * ├───┼───┼───┼───┼───┤    ┌───┐
      * │ K │ L │ M │ N │ O │    │ S │
      * └───┴───┴───┴───┴───┘    └───┘
      *           ┌───┐         ┌───┐
      *           │ P ├───┐     │ T │
      *           └───┤ Q ├───┐ └───┘
      *               └───┤ R │
      *                   └───┘
      */

    [ _DOTA_BASE ] = LAYOUT_sm(
        LT(0, KC_T),   KC_GRAVE,    KC_N,     KC_Z,         KC_X,               //UPPER
        KC_Q,          KC_W,        KC_E,     KC_R,         KC_B,               //HOME
        KC_A,          KC_D,        KC_F,     KC_V,         KC_C,               //LOWER
        KC_F1,         KC_1,       KC_F4,     KC_Y,         KC_MUTE             //THUMB
    ),

    [ _DOTA_MOD ] = LAYOUT_sm(
        KC_A,   KC_B,   KC_C,   KC_D,   KC_E,
        KC_F,   KC_G,   KC_H,   KC_I,   KC_J,
        KC_K,   KC_L,   KC_M,   KC_N,   KC_O,
        KC_P,   KC_Q,   KC_R,   KC_S,   KC_TRNS
    )
};

void matrix_scan_user(void){
    rgblight_setrgb_at(0, 0, 8, 0);
}

bool process_record_user( uint16_t keycode, keyrecord_t *record ){
    switch( keycode ) {

        case LT( 0, KC_T ):  // Sends T on Tap and KP7 on hold.
            if( record->tap.count && record->event.pressed ) {
                return true;
                break;
            } else if( record->event.pressed ) {
                tap_code16( KC_KP_7 );  // Intercept hold function to send KP7
                return false;
            }
    }
    return true;
}
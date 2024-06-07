// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_number {
    _DOTA_S = 0,
    _DOTA_D0,
    _DOTA_D1,
    _DOTA_D2,
    _LAYER_COUNT,        // Insert layers before this one.
    _LAYER_SELECT
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
      *
      *  [ _EXAMPLE ] = LAYOUT_sm(
      *     A,      B,      C,      D,      E,      //UPPER
      *     F,      G,      H,      I,      J,     //HOME
      *     K,      L,      M,      N,      O,     //LOWER
      *     P,      Q,      R,      T,      S     //THUMB
      *),
      */

    [ _DOTA_S ] = LAYOUT_sm(
        LT(0, KC_T),   KC_GRAVE,    KC_N,     KC_Z,         KC_X,               //UPPER
        KC_Q,          KC_W,        KC_E,     KC_R,         KC_B,               //HOME
        KC_A,          KC_D,        KC_F,     KC_V,         KC_C,               //LOWER
        KC_F1,         KC_1,       KC_F4,     KC_Y,         LT( _LAYER_SELECT, KC_MUTE )    //THUMB
    ),

    [ _DOTA_D0 ] = LAYOUT_sm(
        LT(_DOTA_D0, KC_T),   KC_D,   KC_F,                  KC_Z,   KC_X,
        KC_Q,                 KC_W,   KC_E,                  KC_R,   KC_C,
        LT(_DOTA_D0, KC_F4),  KC_N,   KC_B,                  KC_V,   KC_1,
        LT(_DOTA_D1, KC_A),   KC_F1,  LT(_DOTA_D2, KC_NO),   KC_NO,   LT( _LAYER_SELECT, KC_MUTE )
    ),

    [ _DOTA_D1 ] = LAYOUT_sm(
        KC_KP_7,   LALT(KC_D),   LALT(KC_F),   KC_Y,   _______,
        LALT(KC_Q),   LALT(KC_W),   LALT(KC_E),   LALT(KC_R),   _______,
        KC_F5,   _______,   _______,   KC_U,   _______,
        _______,   _______,   _______,   _______,   LT( _LAYER_SELECT, KC_MUTE )
    ),

    [ _DOTA_D2 ] = LAYOUT_sm(
        _______,   _______,   _______,   _______,   KC_J,
        _______,   _______,   KC_KP_8,   KC_KP_9,   KC_P,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   LT( _LAYER_SELECT, KC_MUTE )
    ),

    [ _LAYER_SELECT ] = LAYOUT_sm(
        _______,   TO(_DOTA_S),   TO(_DOTA_D0),   TO(_DOTA_D1),   _______,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   LT( _LAYER_SELECT, KC_MUTE )
    )
};

void matrix_scan_user(void){
    rgblight_setrgb_at(0, 0, 16, 0);
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
                break;
            }

            case LT( _DOTA_D0, KC_T ):  // Sends T on Tap and KP7 on hold.
            if( record->tap.count && record->event.pressed ) {
                return true;
                break;
            } else if( record->event.pressed ) {
                tap_code16( KC_KP_7 );  // Intercept hold function to send KP7
                return false;
                break;
            }

            case LT( _DOTA_D0, KC_F4 ):  // Sends T on Tap and KP7 on hold.
            if( record->tap.count && record->event.pressed ) {
                return true;
                break;
            } else if( record->event.pressed ) {
                tap_code16( KC_F3 );  // Intercept hold function to send KP7
                return false;
                break;
            }
    }
    return true;
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

// Draw to OLED
bool oled_task_user(){

    static const char DOTA_LOGO [] PROGMEM = {

        // 'HD Dota 2 Official White Logo Symbol PNG', 32x32px
        0x00, 0x00, 0x00, 0xf8, 0xf8, 0xf8, 0xf8, 0x78, 0xf8, 0xf8, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 
        0xf8, 0xf8, 0xf8, 0xf0, 0xf8, 0xf8, 0x78, 0xf8, 0xf8, 0xf0, 0xf8, 0xf8, 0xf0, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe1, 0xc3, 0x83, 0x07, 0x0f, 0x0f, 
        0x1f, 0x3f, 0x3f, 0x7e, 0xfc, 0xf8, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xcf, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xcf, 0xff, 0xff, 0x9f, 0x07, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xfe, 0xfc, 
        0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x01, 0x03, 0x03, 0xc7, 0xff, 0xff, 0xfd, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0e, 0x0e, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 
        0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00
    };

    switch ( get_highest_layer( layer_state ) ){
        case _DOTA_S :
            oled_set_cursor( 0, 0 );        //Set cursor to upper left of screen
            oled_write_raw_P( DOTA_LOGO, sizeof( DOTA_LOGO ) );     //Draw Dota logo
            oled_set_cursor( 0, 5 );        //Set cursor below logo
            oled_write_P( PSTR("Steff"), false );
            break;
        case _DOTA_D0 :
            oled_set_cursor( 0, 0 );        //Set cursor to upper left of screen
            oled_write_raw_P( DOTA_LOGO, sizeof( DOTA_LOGO ) );     //Draw Dota logo
            oled_set_cursor( 0, 5 );        //Set cursor below logo
            oled_write_P( PSTR("Dota1"), false );
            break;
        case _DOTA_D1 :
            oled_set_cursor( 0, 0 );        //Set cursor to upper left of screen
            oled_write_raw_P( DOTA_LOGO, sizeof( DOTA_LOGO ) );     //Draw Dota logo
            oled_set_cursor( 0, 5 );        //Set cursor below logo
            oled_write_P( PSTR("Dota2"), false );
            break;
    }

    return false;
}

#endif
// Copyright 2022 Stefan Kerkmann
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define DEBUG_MATRIX_SCAN_RATE

// #define QMK_WAITING_TEST_BUSY_PIN GP8
// #define QMK_WAITING_TEST_YIELD_PIN GP9

#define ENCODERS_PAD_A { GP27, GP18 }
#define ENCODERS_PAD_B { GP26, GP20 }

#define ENCODER_RESOLUTION 4

#define WS2812_DI_PIN GP17
#define RGBLIGHT_LED_COUNT 1     // Number of LEDs
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#define RGBLIGHT_DEFAULT_ON 0

// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

// settings for the oled keyboard demo with Adafruit 0.91" OLED display on the Stemma QT port
#define OLED_DISPLAY_128X32
#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP28
#define I2C1_SCL_PIN GP29

#undef VENDOR_ID
#undef PRODUCT_ID
#undef DEVICE_VER
#undef MANUFACTURER
#undef PRODUCT
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x4097
#define DEVICE_VER      0x0001
#define MANUFACTURER    "Hubby"
#define PRODUCT         "Steff's GamePad"
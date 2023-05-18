/* Copyright 2022 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* RP2040 Reset Behavior */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U // Timeout window in ms in which the double tap can occur.

#define CUSTOM_LAYER_READ

/* Key matrix configuration */
/* moved to info.json */
// #define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
// #define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
// #define DIODE_DIRECTION COL2ROW

/* Handedness */
// #define MASTER_LEFT // redundant, this is default

/* Encoder support */
/* moved to info.json */
// #define ENCODERS_PAD_A { F5 }
// #define ENCODERS_PAD_B { F4 }
// #define ENCODERS_PAD_A_RIGHT { F4 }
// #define ENCODERS_PAD_B_RIGHT { F5 }

/* RGB settings */
#ifdef RGB_MATRIX_ENABLE
#define WS2812_DI_PIN D3
#define RGB_MATRIX_LED_COUNT 58
// #define RGB_DI_PIN D3 // moved to info.json
// #define RGBLED_NUM 29 // moved to info.json
// #define RGB_MATRIX_SPLIT { 29, 29 } // moved to info.json

#define RGB_DISABLE_WHEN_USB_SUSPENDED     // turn off effects when suspended
#define SPLIT_TRANSPORT_MIRROR             // If LED_MATRIX_KEYPRESSES or LED_MATRIX_KEYRELEASES is enabled, you also will want to enable SPLIT_TRANSPORT_MIRROR

// #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100  // limits maximum brightness of LEDs (max 255). Higher may cause the controller to crash. // Moved to info.json

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
#define RGB_MATRIX_DEFAULT_HUE 116
#define RGB_MATRIX_DEFAULT_SAT 255
#define RGB_MATRIX_DEFAULT_VAL 36

/* RGB Animations */
/* These modes don’t require any additional defines */
// #define ENABLE_RGB_MATRIX_ALPHAS_MODS
// #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
// #define ENABLE_RGB_MATRIX_BAND_VAL
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
// #define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #define ENABLE_RGB_MATRIX_RAINDROPS
// #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #define ENABLE_RGB_MATRIX_HUE_BREATHING
// #define ENABLE_RGB_MATRIX_HUE_PENDULUM
// #define ENABLE_RGB_MATRIX_HUE_WAVE
// #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// #define ENABLE_RGB_MATRIX_PIXEL_FLOW
// #define ENABLE_RGB_MATRIX_PIXEL_RAIN

/* These modes require the RGB_MATRIX_FRAMEBUFFER_EFFECTS define */
// #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #define ENABLE_RGB_MATRIX_DIGITAL_RAIN

/* These modes require the RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES define */
// #define RGB_MATRIX_KEYPRESSES
// #define RGB_MATRIX_KEYRELEASES
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #define ENABLE_RGB_MATRIX_SPLASH
// #define ENABLE_RGB_MATRIX_MULTISPLASH
// #define ENABLE_RGB_MATRIX_SOLID_SPLASH
// #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH


#endif
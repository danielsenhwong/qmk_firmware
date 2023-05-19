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

#include "sofle_choc.h"

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
    return true;
}
#endif

#if defined(RGBLIGHT_ENABLE)

#define LED_LAYOUT( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05,  \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15,  \
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25,  \
    L30, L31, L32, L33, L34, L35,           R30, R31, R32, R33, R34, R35, \
              L40, L41, L42, L43, L44, R41, R42, R43, R44, R45 ) \
    { \
    /* Left half electrical wiring order */                \
    L05, L15, L25, L35, L44, L43, L42, L34, L24, L14, L04, \
    L03, L13, L23, L33, L41, L40, L32, L22, L12, L02,      \
    L01, L11, L21, L31, L30, L20, L10, L00,                \
    /* Right half electrical wiring order */               \
    R00, R10, R20, R30, R41, R42, R43, R31, R21, R11, R01, \
    R02, R12, R22, R32, R44, R45, R33, R23, R13, R03,      \
    R04, R14, R24, R34, R35, R25, R15, R05              \
 }

#define RGBLIGHT_LED_MAP LED_LAYOUT( \
     0,  4,  8, 13, 18, 23,            30, 35, 40, 45, 50, 54, \
     1,  5,  9, 14, 19, 24,            31, 36, 41, 46, 51, 55, \
     2,  6, 10, 15, 20, 25,            32, 37, 42, 47, 52, 56, \
     3,  7, 11, 16, 21, 26,            33, 38, 43, 48, 53, 57, \
            12, 17, 22, 27, 28,    29, 34, 39, 44, 49 )

/*
    54, 50, 45, 40, 35, 30,            23, 18, 13,  8,  4,  0, \
    55, 51, 46, 41, 36, 31,            24, 19, 14,  9,  5,  1, \
    56, 52, 47, 42, 37, 32,            25, 20, 15, 10,  6,  2, \
    57, 53, 48, 43, 38, 33,            26, 21, 16, 11,  7,  3, \
            49, 44, 39, 34, 29,    28, 27, 22, 17, 12 )
*/
#endif

#if defined(RGB_MATRIX_ENABLE)

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        // Left
        { 28, 21, 20, 11, 10,      0 },
        { 27, 22, 19, 12,  9,      1 },
        { 26, 23, 18, 13,  8,      2 },
        { 25, 24, 17, 14,  7,      3 },
        { 16, 15,  6,  5,  4, NO_LED },

        // Right
        { 57, 50, 49, 40, 39,     29 },
        { 56, 51, 48, 41, 38,     30 },
        { 55, 52, 47, 42, 37,     31 },
        { 54, 53, 46, 43, 36,     32 },
        { 45, 44, 35, 34, 33, NO_LED }
    }, {
        // LED Index to Physical Position
        // Left
        {  95,   7 }, {  95,  21 }, {  95,  36 }, {  95,  50 }, { 115,  64 },
        {  95,  64 }, {  76,  62 }, {  76,  48 }, {  76,  33 }, {  76,  19 },
        {  76,   5 }, {  57,   3 }, {  57,  17 }, {  57,  31 }, {  57,  46 },
        {  57,  62 }, {  38,  64 }, {  38,  48 }, {  38,  33 }, {  38,  19 },
        {  38,   5 }, {  19,   7 }, {  19,  21 }, {  19,  36 }, {  19,  50 },
        {   0,  50 }, {   0,  36 }, {   0,  21 }, {   0,   7 },

        // Right
        { 129,   7 }, { 129,  21 }, { 129,  36 }, { 129,  50 }, { 119, 64 },
        { 129,  64 }, { 148,  62 }, { 148,  48 }, { 148,  33 }, { 148, 19 },
        { 148,   5 }, { 167,   3 }, { 167,  17 }, { 167,  31 }, { 167, 46 },
        { 167,  62 }, { 186,  64 }, { 186,  48 }, { 186,  33 }, { 186, 19 },
        { 186,   5 }, { 209,   7 }, { 209,  21 }, { 209,  36 }, { 209, 50 },
        { 224,  50 }, { 224,  36 }, { 224,  21 }, { 224,   7 }
    }, {
        // LED Index to Flag
        // Left
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        1, 1, 1, 1,

        // Right
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        1, 1, 1, 1
    }
};

#endif
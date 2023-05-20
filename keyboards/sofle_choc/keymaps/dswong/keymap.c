/* Copyright 2023 Brian Low
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
#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_ENDASH = QK_KB_0,    // Insert en dash (ALT + 0150)
    CS_EUR,                 // Insert EUR currency symbol (ALT + 0128)
    CS_GBP,                 // Insert GBP currency symbol (ALT + 0163)
    CS_JPY,                 // Insert JPY currency symbol (ALT + 0165)
    RL_RESET,               // Reload RGB lighting settings from EEPROM
    RL_CVGRN,               // Set hue to CVGreen
    RL_RED, 
    RL_ORG, 
    RL_YEL, 
    RL_GRN,
    RL_BLU,
    RL_IND, 
    RL_VIO, 
    RL_WHT
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc~ |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | - _  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  ; : | ' "  |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  , < |  . > |  / ? | Enter|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | MEH  | LGUI | LALT |TO(1) | /Space  /       \Space \  |TO(2) | RALT | RGUI | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
    QK_GESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_MINUS,
    KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_MPLY,KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                      KC_MEH,  KC_LGUI, KC_LALT, TO(1),   KC_SPC,    KC_SPC, TO(2),    KC_RALT,  KC_RGUI, KC_RCTL
),
/* LOWER
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |  –   |  €   |  £   |  ¥   |      |                    | Ins  | Home | PgUp |  - _ | = +  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Pscr | Menu |      |      |                    | Del  | End  | PgDn | KP_7 | KP_8 | KP_9 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps | LAlt | LCtl |LShift|      |      |-------.    ,-------|      |  Up  |      | KP_4 | KP_5 | KP_6 |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste|      |-------|    |-------| Left | Down | Right| KP_1 | KP_2 | KP_3 |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LALT |TO(0) | /       /       \      \  |TO(3) |      |      | KP_0 |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
    _______, KC_ENDASH, CS_EUR, CS_GBP, CS_JPY,   _______,                         KC_INS,  KC_HOME,   KC_PGUP, KC_MINUS,  KC_EQUAL, _______,
    _______, XXXXXXX, KC_PSCR, KC_APP,  XXXXXXX,  XXXXXXX,                         KC_DEL,  KC_END,    KC_PGDN, KC_KP_7,   KC_KP_8,  KC_KP_9,
    KC_CAPS, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,  XXXXXXX,                         XXXXXXX, KC_UP,     XXXXXXX, KC_KP_4,   KC_KP_5,  KC_KP_6,
    _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, XXXXXXX, _______,       _______, KC_LEFT, KC_DOWN,   KC_RGHT, KC_KP_1,   KC_KP_2,  KC_KP_3,
                      _______, _______, _______,    TO(0), _______,       _______, TO(3),   XXXXXXX,   XXXXXXX, KC_KP_0
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |TO(0) | /       /       \      \  |TO(3) |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
    _______, KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_GRV,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    _______, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    _______, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                     _______, _______, _______, TO(0),   _______,       _______, TO(3),   _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |EE_CLR|Rainbo|RSwirl|Gradnt| Xmas |Twinkl|                    |RGBRed|RGBOrg|RGBYel|RGBGrn|RGBBlu|ACTogg|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BOOT | Spd+ | Val+ | Sat+ | Hue+ |Mode+ |                    |RGBInd|RGBVio|RGBWht|      |      |ComboT|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift| Spd- | Val- | Sat- | Hue- |Mode- |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|RGBTogg|    |RL_Rset|------+------+------+------+------+------|
 * |CGTogg|Static|Breath|Snake |Knight|RL_CVG|-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |TO(0) | /       /       \      \  |TO(0) |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
    EE_CLR,  RGB_M_R, RGB_M_SW, RGB_M_G, RGB_M_X, RGB_M_TW,                     RL_RED,  RL_ORG,  RL_YEL,  RL_GRN,  RL_BLU,  AC_TOGG,
    QK_BOOT, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,                       RL_IND,  RL_VIO,  RL_WHT,  XXXXXXX, XXXXXXX, CM_TOGG,
    KC_LSFT, RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD,                      XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
    CG_TOGG, RGB_M_P, RGB_M_B, RGB_M_SN, RGB_M_K, RL_CVGRN, RGB_TOG,   RL_RESET, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                      _______, _______, _______, TO(0),   _______,     _______, TO(0),   _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ENDASH:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_KP_0);
                tap_code(KC_KP_1);
                tap_code(KC_KP_5);
                tap_code(KC_KP_0);
                return false;
            } else {
                unregister_code(KC_LALT);
            }
            break;
        case CS_EUR:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_KP_0);
                tap_code(KC_KP_1);
                tap_code(KC_KP_2);
                tap_code(KC_KP_8);
                return false;
            } else {
                unregister_code(KC_LALT);
            }
            break;
        case CS_GBP:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_KP_0);
                tap_code(KC_KP_1);
                tap_code(KC_KP_6);
                tap_code(KC_KP_3);
                return false;
            } else {
                unregister_code(KC_LALT);
            }
            break;
        case CS_JPY:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_KP_0);
                tap_code(KC_KP_1);
                tap_code(KC_KP_6);
                tap_code(KC_KP_5);
                return false;
            } else {
                unregister_code(KC_LALT);
            }
            break;
        case RL_RESET:
            if (record->event.pressed) {
                rgblight_sethsv(HSV_GOLD);    // Hue: teal/green, Sat: max, Val: max limit
                rgblight_mode(9);
                rgblight_set_speed(0);
                return false;
            }
            break;
        case RL_CVGRN:  // Set hue to CVGreen
            if (record->event.pressed) {
                rgblight_sethsv(96, 255, 100);
                return false;
            }
            break;
        case RL_RED: 
            if (record->event.pressed) {
                rgblight_sethsv(HSV_RED);
                return false;
            }
            break;
        case RL_ORG: 
        if (record->event.pressed) {
                rgblight_sethsv(HSV_ORANGE);
                return false;
            }
            break;
        case RL_YEL: 
        if (record->event.pressed) {
                rgblight_sethsv(HSV_YELLOW);
                return false;
            }
            break;
        case RL_GRN:
        if (record->event.pressed) {
                rgblight_sethsv(HSV_GREEN);
                return false;
            }
            break;
        case RL_BLU:
        if (record->event.pressed) {
                rgblight_sethsv(HSV_BLUE);
                return false;
            }
            break;
        case RL_IND: 
        if (record->event.pressed) {
                rgblight_setrgb(0x4B, 0x00, 0x82);
                return false;
            }
            break;
        case RL_VIO: 
        if (record->event.pressed) {
                rgblight_setrgb(0x8F, 0x00, 0xFF);
                return false;
            }
            break;
        case RL_WHT:
        if (record->event.pressed) {
                rgblight_sethsv(HSV_WHITE);
                return false;
            }
            break;
    }
    return true;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER] =  { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(KC_WH_L, KC_WH_R) },
    [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),  ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),  ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
};
#endif

#if defined(OLED_ENABLE)

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

void write_int_ln(const char* prefix, uint8_t value) {
    oled_write_P(prefix, false);
    oled_write(get_u8_str(value, ' '), false);
}

// Hue values are 0 – 360, use this range when reporting on the OLED
// The QMK get_u16_str() function has a buffer of 6 since the max value of a 16-bit integer is 625535
// but there is no way of changing this, so declaring a new version here
// Also declaring a 16-bit version of the write_int_ln() function
const char *get_u16_str_buf4(uint16_t curr_num, char curr_pad) {
    static char     buf[4]   = {0};
    static uint16_t last_num = 0xFF;
    static char     last_pad = '\0';
    if (last_num == curr_num && last_pad == curr_pad) {
        return buf;
    }
    last_num = curr_num;
    last_pad = curr_pad;
    return get_numeric_str(buf, sizeof(buf), curr_num, curr_pad);
}

void write_int16_ln(const char* prefix, uint16_t value) {
    oled_write_P(prefix, false);
    oled_write(get_u16_str_buf4(value, ' '), false);
}

static void print_status_narrow(void) {
    oled_write_ln_P(PSTR("SofleChoc _____"), false);

    if (get_highest_layer(layer_state) == _ADJUST) {  
        // if (keymap_config.swap_lctl_lgui) {
        //     oled_write_ln_P(PSTR("CG sw"), false);
        // } else {
        //     oled_write_ln_P(PSTR("     "), false);
        // }
        
        #if defined(RGB_MATRIX_ENABLE)
        uint8_t mode  = rgb_matrix_get_mode();
        HSV     hsv   = rgb_matrix_get_hsv();
        uint8_t speed = rgb_matrix_get_speed();
        #elif defined(RGBLIGHT_ENABLE)
        uint8_t mode  = rgblight_get_mode();
        HSV     hsv   = rgblight_get_hsv();
        uint8_t speed = rgblight_get_speed();
        #else
        uint8_t mode  = 0;
        HSV     hsv   = {"h": 0, "s": 0, "v": 0};
        uint8_t speed = 0;
        #endif

        oled_write_ln("RGB", false);
        write_int_ln(PSTR("Mo"), mode);
        write_int16_ln(PSTR("H "), ((uint16_t) hsv.h * 360 / 255)); // calculate and display the hue for 360 not 255 max value
        write_int_ln(PSTR("S "), (hsv.s * 100 / 255));                // display the saturation in 0 – 100 scale
        write_int_ln(PSTR("V "), hsv.v);
        write_int_ln(PSTR("Sp"), speed);
        oled_write_P(PSTR("\n"), false);
    } else {
        oled_write_P(PSTR("\n\n\n\n\n\n\n"), false);
    }
    
    // Show me the current status of CAPS LOCK and CG_SWAP on all layers
    led_t led_usb_state = host_keyboard_led_state();
    if (led_usb_state.caps_lock) {
        oled_write_ln_P(PSTR(" CAP "), true);
    } else {
        oled_write_ln_P(PSTR("     "), false);
    }
    
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("CG ←→"), true);
    } else {
        oled_write_ln_P(PSTR("     "), false);
    }

    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Alpha"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Nav  "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Sym  "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj  "), false);
            break;
        default:
            oled_write_P(PSTR("???  "), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }

    return false;
}

#endif

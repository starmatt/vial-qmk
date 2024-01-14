/* Copyright 2023 splitkb.com <support@splitkb.com>
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

enum layers {
    _QWERTY = 0,
    _NAV,
    _SYM,
    _ADJUST,
    _GSHFT,
};

// Aliases for readability
#define QWERTY   DF(_QWERTY)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define ADJUST   TG(_ADJUST)
#define GSHFT    TG(_GSHFT)

// #define CTL_ESC  MT(MOD_LCTL, KC_ESC)
// #define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
// #define CTL_MINS MT(MOD_RCTL, KC_MINUS)
// #define ALT_ENT  MT(MOD_LALT, KC_ENT)

#define EURO    RALT(KC_5)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |      |LShift|  |RShift|      |   6  |   7  |   8  |   9  |   0  |  Esc   |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |      |LCtrl |  | RCtrl|      |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |  LGUI  |   A  |   S  |   D  |   F  |   G  |      | LAlt |  | RAlt |      |   H  |   J  |   K  |   L  | ;  : |  RGUI  |
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |Gshift| Mute |  | Play |Adjust|   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |CapsLk| LAlt | LCtrl| Space| Nav  |  | Sym  | Enter| RCtrl| AltGr| Menu |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,----------------------------.      ,------.                 ,----------------------------.      ,------.
 * | Prev | Next | Pause | Stop |      | Mute |                 | Prev | Next | Pause | Stop |      | Mute |
 * `----------------------------'      `------'                 `----------------------------'      '------'
 */
    [_QWERTY] = LAYOUT_myr(
      KC_ESC  , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,         KC_LSFT,     KC_RSFT,          KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 , KC_ESC ,
      KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,         KC_LCTL,     KC_RCTL,          KC_Y ,  KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
      KC_LGUI , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,         KC_LALT,     KC_RALT,          KC_H ,  KC_J ,  KC_K ,   KC_L ,KC_SCLN, KC_RGUI,
      KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , GSHFT  ,KC_MUTE,     KC_MPLY, RGB_TOG, KC_N ,  KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                KC_CAPS , KC_LALT, KC_LCTL, KC_SPC , NAV   ,     SYM    , KC_ENT ,KC_RCTL, KC_RALT, KC_APP,

      KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE,                            KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |  F11   |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |  F12   | KP_1 | KP_2 |   ↑  | KP_3 | KP_4 |      |      |  |      |      | Home | PgDn | PgUp | End  | VolUp|        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        | ,  < |  ←   |   ↓  |   →  | .  > |      |      |  |      |      |  ←   |   ↓  |   ↑  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * |        | KP / | KP * | KP - | KP = | KP + |      |      |  |      |      |M Prev| Pause|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,----------------------------.      ,------.                 ,----------------------------.      ,------.
 * | Prev | Next | Pause | Stop |      | Mute |                 | Prev | Next | Pause | Stop |      | Mute |
 * `----------------------------'      `------'                 `----------------------------'      '------'
 */
    [_NAV] = LAYOUT_myr(
      KC_F11 ,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,          _______, _______,           KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , _______,
      KC_F12 ,  KC_P1 ,  KC_P2 ,  KC_UP ,  KC_P4 ,  KC_P5 ,          _______, _______,          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_VOLU, _______,
      _______,KC_COMMA, KC_LEFT, KC_DOWN,KC_RIGHT, KC_DOT ,          _______, _______,          KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT, KC_VOLD, KC_INS,
      _______, KC_PSLS, KC_PAST, KC_PMNS, KC_PEQL, KC_PPLS, _______, _______, _______,  ADJUST, KC_MPRV,KC_PAUSE, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |      |  %   |  €   |  $   |      |      |      |  |      |      |   '  |  "   |  ^   |  `   |  ~   |  Del   |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |  <   |  {   |  [   |  (   |  \   |      |      |  |      |      |   /  |  )   |  ]   |  }   |  >   |        |
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * |        |  !   |  @   |  #   |  &   |  |   |      |      |  |      |      |   *  |  -   |  =   |  +   |  _   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,-----------------------------.      ,------.                ,---------------------------.      ,------.
 * |        |      |      |      |      |      |                |      |      |      |      |      |      |
 * `-----------------------------'      `------'                `---------------------------'      '------'
 */
    [_SYM] = LAYOUT_myr(
      KC_F11 ,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,          _______, _______,           KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , _______,
      KC_F12 , XXXXXXX, KC_PERC,  EURO  , KC_DLR , XXXXXXX,          _______, _______,         KC_QUOTE, KC_DQUO, KC_CIRC,KC_GRAVE, KC_TILD, KC_DEL ,
      _______,  KC_LT , KC_LCBR, KC_LBRC, KC_LPRN, KC_BSLS,          _______, _______,          KC_SLSH, KC_RPRN, KC_RBRC, KC_RCBR,  KC_GT , _______,
      _______, KC_EXLM,  KC_AT , KC_HASH, KC_AMPR, KC_PIPE, _______, _______, _______, _______, KC_ASTR,KC_MINUS,KC_EQUAL, KC_PLUS, KC_UNDS, _______,
                                 _______, _______, _______, _______, KC_BSPC, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |RGB Togl|
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      | Sat+ | Hue+ | Bri+ |Efct+ |RGB Mod+|
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      | Sat- | Hue- | Bri- |Efct- |RGB Mod-|
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,-----------------------------.      ,------.                ,---------------------------.      ,------.
 * |        |      |      |      |      |      |                |      |      |      |      |      |      |
 * `-----------------------------'      `------'                `---------------------------'      '------'
 */
    [_ADJUST] = LAYOUT_myr(
      _______, _______, _______, _______, _______, _______,         _______, _______,          _______, _______, _______, _______, _______, RGB_TOG,
      _______, _______, _______, _______, _______, _______,         _______, _______,          _______, RGB_SAI, RGB_HUI, RGB_VAI, RGB_SPI, RGB_MOD,
      _______, _______, _______, _______, _______, _______,         _______, _______,          _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_SPD,RGB_RMOD,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______

    ),

// /*
//  * GameShift Layer: for games!!!
//  *
//  * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
//  * |   Esc  |  1   |  2   |  3   |  4   |  5   |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |   Tab  |  T   |  Q   |  W   |  E   |  R   |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |  LCtrl |  G   |  A   |  S   |  D   |  F   |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
//  * | LShift |  B   |  Z   |  X   |  C   |  V   |Gshift|      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      | LGUI | LAlt | Space|      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  *
//  * ,-----------------------------.      ,------.                ,---------------------------.      ,------.
//  * |        |      |      |      |      |      |                |      |      |      |      |      |      |
//  * `-----------------------------'      `------'                `---------------------------'      '------'
//  */
     [_GSHFT] = LAYOUT_myr(
       KC_ESC ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,          _______, _______,          _______, _______, _______, _______, _______, _______,
       KC_TAB ,  KC_T  ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,          _______, _______,          _______, _______, _______, _______, _______, _______,
       KC_LCTL,  KC_G  ,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,          _______, _______,          _______, _______, _______, _______, _______, _______,
       KC_LSFT,  KC_B  ,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  GSHFT , _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, KC_LGUI, KC_LALT, KC_SPC , _______, _______, _______, _______, _______, _______,

       _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
     ),

// /*
//  * Layer template - LAYOUT
//  *
//  * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

// /*
//  * Layer template - LAYOUT_myr
//  *
//  * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  *
//  * ,-----------------------------.      ,------.                ,---------------------------.      ,------.
//  * |        |      |      |      |      |      |                |      |      |      |      |      |      |
//  * `-----------------------------'      `------'                `---------------------------'      '------'
//  */
//     [_LAYERINDEX] = LAYOUT_myr(
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//
//       _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/elora/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
void render_blank_line(bool inverted) {
    oled_write_P(PSTR("          "), inverted);
}

void render_current_layer(void) {
    oled_write_P(PSTR(" "), true);
    oled_write_P(PSTR(" Layer "), false);
    oled_write_P(PSTR("  "), true);
    render_blank_line(false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwerty    "), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav/Media "), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbols   "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("RGB Adjust"), false);
            break;
        case _GSHFT:
            oled_write_P(PSTR("Gameshift "), false);
            break;
        default:
            oled_write_P(PSTR("Undefined "), false);
            break;
    }
}

void render_active_mods(uint8_t modifiers, led_t led_usb_state) {
    oled_write_P(PSTR(" "), true);
    oled_write_P(PSTR(" Mods "), false);
    oled_write_P(PSTR("   "), true);
    render_blank_line(false);

    // First line
    if (modifiers & MOD_MASK_CTRL) {
        oled_write_P(PSTR("CTRL "), true);
    } else {
        oled_write_P(PSTR("CTRL "), false);
    }

    if (modifiers & MOD_MASK_ALT) {
        oled_write_P(PSTR("ALT  "), true);
    } else {
        oled_write_P(PSTR("ALT  "), false);
    }

    // Second line
    if (modifiers & MOD_MASK_SHIFT) {
        oled_write_P(PSTR("SHFT "), true);
    } else {
        oled_write_P(PSTR("SHFT "), false);
    }

    if (modifiers & MOD_MASK_GUI) {
        oled_write_P(PSTR("META "), true);
    } else {
        oled_write_P(PSTR("META "), false);
    }

    render_blank_line(false);

    // Third line
    if (led_usb_state.caps_lock) {
        oled_write_P(PSTR("["), false);
        oled_write_P(PSTR("*"), false);
        oled_write_P(PSTR("] CapsLk"), false);
    } else {
        oled_write_P(PSTR("[ ] CapsLk"), false);
    }
}

void render_wpm(void) {
    oled_write_P(PSTR(" "), true);
    oled_write_P(PSTR(" WPM "), false);
    oled_write_P(PSTR("    "), true);
    render_blank_line(false);
    oled_write_P(PSTR("       "), false);
    oled_write_P(get_u8_str(get_current_wpm(), ' '), false);
}

bool oled_task_user(void) {
    render_wpm();
    render_blank_line(false);
    render_blank_line(false);
    render_current_layer();
    render_blank_line(false);
    render_blank_line(false);
    render_active_mods(get_mods(), host_keyboard_led_state());

    return false;
}
#endif

// #ifdef ENCODER_ENABLE
// bool encoder_update_user(uint8_t index, bool clockwise) {
//   // Your code goes here
// }
// #endif

// Vial-specific encoder code

#if defined(ENCODER_MAP_ENABLE)
bool encoder_update_user(uint8_t index, bool clockwise) {
  return false;
}

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {
      // QWERTY
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [1] = {
      // NAV
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [2] = {
      // SYM
      ENCODER_CCW_CW(KC_BRID, KC_BRIU),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [3] = {
      // ADJUST
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [4] = {
      // GSHFT
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_NO, KC_NO),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    }
};
#endif

#include "layers.h"
#include "oled.h"

void render_layers(uint8_t start_row) {
    oled_set_cursor(0, start_row);

    switch (get_highest_layer(layer_state  | default_layer_state)) {
        case _QWERTY:
            oled_write_raw_P(base, sizeof(base));
            break;
        case _NUM:
            oled_write_raw_P(num, sizeof(num));
            break;
        case _SYM:
            oled_write_raw_P(sym, sizeof(sym));
            break;
        case _NAV:
            oled_write_raw_P(nav, sizeof(nav));
            break;
        case _ADJUST:
            oled_write_raw_P(adjst, sizeof(adjst));
            break;
        case _GSHFT:
            oled_write_raw_P(gshft, sizeof(gshft));
            break;
        case _MOUSE:
            oled_write_raw_P(mouse, sizeof(mouse));
            break;
        default:
            oled_write_P(PSTR("Undefined "), false);
    }
}

void render_mods_meta_alt(uint8_t mods) {
    if (mods & MOD_MASK_GUI) {
        if (mods & MOD_MASK_ALT) {
            oled_write_raw_P(meta_1_alt_1, sizeof(meta_1_alt_1));
        } else {
            oled_write_raw_P(meta_1_alt_0, sizeof(meta_1_alt_0));
        }
    } else {
        if (mods & MOD_MASK_ALT) {
            oled_write_raw_P(meta_0_alt_1, sizeof(meta_0_alt_1));
        } else {
            oled_write_raw_P(meta_0_alt_0, sizeof(meta_0_alt_0));
        }
    }
}

void render_mods_ctrl_shft(uint8_t mods) {
    if (mods & MOD_MASK_SHIFT) {
        if (mods & MOD_MASK_CTRL) {
            oled_write_raw_P(ctrl_1_shft_1, sizeof(ctrl_1_shft_1));
        } else {
            oled_write_raw_P(ctrl_0_shft_1, sizeof(ctrl_0_shft_1));
        }
    } else {
        if (mods & MOD_MASK_CTRL) {
            oled_write_raw_P(ctrl_1_shft_0, sizeof(ctrl_1_shft_0));
        } else {
            oled_write_raw_P(ctrl_0_shft_0, sizeof(ctrl_0_shft_0));
        }
    }
}

void render_mods(uint8_t start_row) {
    uint8_t modifiers = get_mods() | get_oneshot_mods();

    oled_set_cursor(0, start_row);
    render_mods_meta_alt(modifiers);

    oled_set_cursor(0, start_row + 2);
    render_mods_ctrl_shft(modifiers);
}

void render_leds(uint8_t start_row) {
     led_t led_usb_state = host_keyboard_led_state();

    oled_set_cursor(0, start_row);

    if (led_usb_state.caps_lock) {
        oled_write_raw_P(caps_1, sizeof(caps_1));
    } else {
        oled_write_raw_P(caps_0, sizeof(caps_0));
    }

    oled_set_cursor(0, start_row + 2);

    if (led_usb_state.num_lock) {
        oled_write_raw_P(numlck_1, sizeof(numlck_1));
    } else {
        oled_write_raw_P(numlck_0, sizeof(numlck_0));
    }
}

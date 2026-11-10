#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  GAME_TOGGLE,
};

#define GAME 6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // The top-left corner pair is for one-handed use with the right hand on the
  // mouse: Dictate (Super+D, Hyprland's dictation toggle) in the corner, where
  // it is easiest to find blind, and Enter beside it to send what was said.
  [0] = LAYOUT_voyager(
    LGUI(KC_D), KC_ENTER, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, KC_PSCR, KC_INS, KC_DEL, KC_PAUS,
    KC_TAB,         KC_RIGHT_ALT,   KC_G,           KC_D,           KC_L,           KC_W,                                           KC_Z,           KC_Q,           KC_U,           KC_B,           KC_BSPC,        KC_TRANSPARENT,
    KC_ESCAPE,      KC_N,           KC_S,           KC_T,           KC_R,           KC_C,                                           KC_A,           KC_O,           KC_E,           KC_I,           KC_H,           KC_ENTER,
    OSL(3),         OSL(4),         KC_P,           KC_V,           KC_F,           KC_M,                                           KC_X,           KC_K,           KC_J,           KC_Y,           KC_NO,          LSFT(KC_ENTER),
                                                    KC_SPACE,       OSL(2),                                         OSM(MOD_LSFT),  OSL(1)
  ),
  [1] = LAYOUT_voyager(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
    KC_HASH, KC_AT,          KC_MINUS,       KC_LBRC,        KC_RBRC,        KC_DLR,                                         KC_TILD,        KC_LABK,        KC_RABK,        KC_SLASH,       KC_ASTR,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_DQUO,        KC_QUES,        KC_LPRN,        KC_RPRN,        KC_AMPR,                                        KC_GRAVE,       KC_DOT,         KC_QUOTE,       KC_COMMA,       KC_COLN,        KC_TRANSPARENT,
    KC_PERCENT, KC_UNDERSCORE,        KC_EQUAL,       KC_LCBR,        KC_RCBR,        KC_PIPE,                                        KC_PLUS,        KC_SCLN,        KC_EXLM,        KC_BSLS,        KC_CIRC,        KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, GAME_TOGGLE,
    KC_TRANSPARENT, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_DEL, KC_TRANSPARENT, KC_TRANSPARENT, KC_SPC, KC_Q, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DOT,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, OSM(MOD_LSFT),  OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LGUI),  OSM(MOD_HYPR),                                  OSM(MOD_HYPR),  OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LSFT),  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LEFT_SHIFT, KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,     KC_TRANSPARENT,                                 MS_WHLL,        MS_WHLU,        MS_UP,          MS_WHLD,        MS_WHLR, KC_TRANSPARENT,
    TO(0),          MS_ACL0,        MS_ACL1,        MS_ACL2,        MS_BTN1,        MS_BTN2,                                        KC_TRANSPARENT,        MS_LEFT,        MS_DOWN,        MS_RGHT,        MS_BTN1,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PSCR, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, TO(0),                                          KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // Plain QWERTY for games: no tap-hold or one-shot keys, so every key acts on
  // press. Space stays on its base thumb and the Nav thumb becomes Shift (dash
  // in Deadlock); Ctrl and Alt sit on the outer column. The top-right key
  // toggles the layer with the Nav-position thumb held, going in and out.
  [GAME] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           GAME_TOGGLE,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPC,
    KC_LEFT_CTRL,   KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_ENTER,
    KC_LEFT_ALT,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_QUOTE,
                                                    KC_SPACE,       KC_LEFT_SHIFT,                                  KC_RIGHT_SHIFT, KC_ENTER
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  '*', '*', '*', '*'
);

// The mouse toggle is on the right hand: the left drives the Compose command
// map one-handed while the right holds a mouse, and Compose R T / T R rolls
// across the old left-hand T+R pair within the combo term. K and J are the
// right bottom-row index and middle keys; "jk" and "kj" almost never occur.
const uint16_t PROGMEM mouse_combo[] = {KC_K, KC_J, COMBO_END};
enum combo_events { MOUSE_COMBO };
combo_t key_combos[] = {
    [MOUSE_COMBO] = COMBO(mouse_combo, TG(5)),
};

// Typing "jk" in game chat must not open the mouse layer, and K and J should
// not wait out the combo term while gaming.
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return !(combo_index == MOUSE_COMBO && layer_state_is(GAME));
}




// The game layer lights the board orange. Indicators only draw while RGB is
// on, so entering turns it on without saving and leaving restores it.
static bool rgb_was_enabled;

layer_state_t layer_state_set_user(layer_state_t state) {
    bool entering = layer_state_cmp(state, GAME), leaving = layer_state_is(GAME);
    if (entering && !leaving) {
        rgb_was_enabled = rgb_matrix_is_enabled();
        rgb_matrix_enable_noeeprom();
    } else if (leaving && !entering && !rgb_was_enabled) {
        rgb_matrix_disable_noeeprom();
    }
    return state;
}

bool rgb_matrix_indicators_user(void) {
    if (layer_state_is(GAME)) {
        rgb_matrix_set_color_all(255, 72, 0);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case RGB_SLD:
                rgblight_mode(1);
                return false;
            // The same physical gesture both ways: the left inner thumb (Nav,
            // which is Left Shift on the game layer) held, then the top-right key.
            case GAME_TOGGLE:
                if (!layer_state_is(GAME)) {
                    layer_move(GAME);
                } else if (get_mods() & MOD_BIT(KC_LEFT_SHIFT)) {
                    unregister_mods(MOD_BIT(KC_LEFT_SHIFT));
                    layer_move(0);
                }
                return false;
        }
    }
    return true;
}

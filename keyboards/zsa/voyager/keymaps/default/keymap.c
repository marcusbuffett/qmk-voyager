#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TAB,         KC_B,           KC_G,           KC_D,           KC_L,           KC_K,                                           KC_Z,           KC_Q,           KC_U,           KC_J,           KC_BSPC,        KC_TRANSPARENT,
    KC_ESCAPE,      KC_C,           KC_S,           KC_T,           KC_N,           KC_R,                                           KC_A,           KC_O,           KC_E,           KC_I,           KC_F,           KC_ENTER,
    OSL(3),         OSL(4),         KC_P,           KC_V,           KC_H,           KC_M,                                           KC_X,           QK_LEAD,        OSM(MOD_HYPR),  KC_Y,           KC_W,           LSFT(KC_ENTER),
                                                    KC_SPACE,       OSL(2),                                         OSM(MOD_LSFT),  OSL(1)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_HASH, KC_AT,          KC_MINUS,       KC_LBRC,        KC_RBRC,        KC_DLR,                                         KC_TILD,        KC_LABK,        KC_RABK,        KC_SLASH,       KC_ASTR,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_DQUO,        KC_SCLN,        KC_LPRN,        KC_RPRN,        KC_AMPR,                                        KC_GRAVE,       KC_DOT,         KC_QUOTE,       KC_COMMA,       KC_COLN,        KC_TRANSPARENT,
    KC_PERCENT, KC_UNDERSCORE,        KC_EQUAL,       KC_LCBR,        KC_RCBR,        KC_PIPE,                                        KC_PLUS,        KC_QUES,        KC_EXLM,        KC_BSLS,        KC_CIRC,        KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_SPC, KC_Q,           KC_TRANSPARENT, KC_TRANSPARENT,
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
    KC_TRANSPARENT, LGUI(LSFT(KC_4)), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, TO(0),                                          KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  '*', '*', '*', '*'
);

const uint16_t PROGMEM mouse_combo[] = {KC_T, KC_N, COMBO_END};
combo_t key_combos[] = {
    COMBO(mouse_combo, TG(5)),
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

void leader_start_user(void) {
    clear_keyboard();  // Clear all modifiers and keys
    layer_clear();     // Return to base layer
}

void leader_end_user(void) {
    // Window Management (w prefix)
    if (leader_sequence_two_keys(KC_W, KC_M)) { // mnemonic: Window Maximize
        tap_code16(HYPR(KC_M));
    } else if (leader_sequence_two_keys(KC_W, KC_P)) { // mnemonic: Window dev layout (Position)
        tap_code16(HYPR(KC_P));

    // Media Controls (i prefix) - Interface/Media
    } else if (leader_sequence_two_keys(KC_I, KC_U)) { // mnemonic: Interface volume Up
        tap_code(KC_VOLU);
    } else if (leader_sequence_two_keys(KC_I, KC_D)) { // mnemonic: Interface volume Down
        tap_code(KC_VOLD);
    } else if (leader_sequence_two_keys(KC_I, KC_M)) { // mnemonic: Interface Mute
        tap_code(KC_MUTE);
    } else if (leader_sequence_two_keys(KC_I, KC_P)) { // mnemonic: Interface Play/pause
        tap_code(KC_MPLY);
    } else if (leader_sequence_two_keys(KC_I, KC_N)) { // mnemonic: Interface Next track
        tap_code(KC_MNXT);
    } else if (leader_sequence_two_keys(KC_I, KC_B)) { // mnemonic: Interface Back/previous track
        tap_code(KC_MPRV);
    } else if (leader_sequence_two_keys(KC_I, KC_S)) { // mnemonic: Interface speak (Wispr)
        tap_code16(LSFT(LCTL(KC_SPC)));
    } else if (leader_sequence_two_keys(KC_I, KC_I)) { // mnemonic: Interface input (off) - Zoom mute
        tap_code(KC_F13);

    // Tools (t prefix)
    } else if (leader_sequence_two_keys(KC_T, KC_C)) { // mnemonic: Tool Clipboard history
        tap_code(KC_F14);
    } else if (leader_sequence_two_keys(KC_T, KC_P)) { // mnemonic: Tool color Picker
        tap_code16(LGUI(LSFT(KC_M)));
    } else if (leader_sequence_two_keys(KC_T, KC_J)) { // mnemonic: Tool ocr (J for jump to text)
        tap_code(KC_F15);
    } else if (leader_sequence_two_keys(KC_T, KC_M)) { // mnemonic: Tool Measure (PixelSnap 2)
        tap_code16(LSFT(LALT(LGUI(KC_F))));
    } else if (leader_sequence_two_keys(KC_T, KC_S)) { // mnemonic: Tool Screenshot
        tap_code16(LGUI(LSFT(KC_3)));
    } else if (leader_sequence_two_keys(KC_T, KC_A)) { // mnemonic: Tool Area capture
        tap_code16(LGUI(LSFT(KC_4)));
    } else if (leader_sequence_two_keys(KC_T, KC_T)) { // mnemonic: Tool screenshot Tool
        tap_code16(LGUI(LSFT(KC_5)));
    } else if (leader_sequence_two_keys(KC_T, KC_E)) { // mnemonic: Tool Emoji picker
        tap_code16(LCTL(LGUI(KC_SPC)));
    } else if (leader_sequence_two_keys(KC_T, KC_D)) { // mnemonic: Tool Dictation
        tap_code16(LALT(LCTL(KC_SPC))); // Alt+Ctrl+Space for Flow dictation
    }
}

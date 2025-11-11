#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  RESET_STATE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TAB,         KC_B,           KC_G,           KC_D,           KC_L,           KC_K,                                           KC_Z,           KC_Q,           KC_U,           KC_J,           KC_BSPC,        KC_TRANSPARENT,
    KC_ESCAPE,      KC_C,           KC_S,           KC_T,           KC_N,           KC_R,                                           KC_A,           KC_O,           KC_E,           KC_I,           KC_F,           KC_ENTER,
    OSL(3),         OSL(4),         KC_P,           KC_V,           KC_H,           KC_M,                                           KC_X,           QK_LEAD,        RESET_STATE,    KC_Y,           KC_W,           LSFT(KC_ENTER),
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
    case RESET_STATE:
      if (record->event.pressed) {
        clear_keyboard();
        clear_oneshot_mods();
        clear_oneshot_locked_mods();
        layer_clear();
      }
      return false;
  }
  return true;
}

void leader_start_user(void) {
}

void leader_end_user(void) {
    // Single-key app shortcuts
    if (leader_sequence_one_key(KC_B)) {
        tap_code16(HYPR(KC_B));  // Zen Browser
    } else if (leader_sequence_one_key(KC_C)) {
        tap_code16(HYPR(KC_T));  // Ghostty Terminal

    // Open apps (o prefix)
    } else if (leader_sequence_two_keys(KC_O, KC_O)) {
        tap_code16(HYPR(KC_O));  // Obsidian
    } else if (leader_sequence_two_keys(KC_O, KC_A)) {
        tap_code16(HYPR(KC_A));  // TIDAL (Audio)
    } else if (leader_sequence_two_keys(KC_O, KC_D)) {
        tap_code16(HYPR(KC_D));  // Discord
    } else if (leader_sequence_two_keys(KC_O, KC_L)) {
        tap_code16(HYPR(KC_L));  // Linear
    } else if (leader_sequence_two_keys(KC_O, KC_S)) {
        tap_code16(HYPR(KC_S));  // Slack
    } else if (leader_sequence_two_keys(KC_O, KC_Z)) {
        tap_code16(HYPR(KC_Z));  // Zoom
    } else if (leader_sequence_two_keys(KC_O, KC_Y)) {
        tap_code16(HYPR(KC_Y));  // Spotify
    } else if (leader_sequence_two_keys(KC_O, KC_C)) {
        tap_code16(HYPR(KC_C));  // Cursor

    // Window Management (w prefix)
    } else if (leader_sequence_two_keys(KC_W, KC_M)) {
        tap_code16(HYPR(KC_M));  // Window Maximize
    } else if (leader_sequence_two_keys(KC_W, KC_P)) {
        tap_code16(HYPR(KC_P));  // Window dev layout (Position)

    // Media Controls (i prefix) - Interface/Media
    } else if (leader_sequence_two_keys(KC_I, KC_U)) {
        tap_code(KC_VOLU);  // Interface volume Up
    } else if (leader_sequence_two_keys(KC_I, KC_D)) {
        tap_code(KC_VOLD);  // Interface volume Down
    } else if (leader_sequence_two_keys(KC_I, KC_M)) {
        tap_code(KC_MUTE);  // Interface Mute
    } else if (leader_sequence_two_keys(KC_I, KC_P)) {
        tap_code(KC_MPLY);  // Interface Play/pause
    } else if (leader_sequence_two_keys(KC_I, KC_N)) {
        tap_code(KC_MNXT);  // Interface Next track
    } else if (leader_sequence_two_keys(KC_I, KC_B)) {
        tap_code(KC_MPRV);  // Interface Back/previous track
    } else if (leader_sequence_two_keys(KC_I, KC_S)) {
        tap_code16(LSFT(LCTL(KC_SPC)));  // Interface speak (Wispr)
    } else if (leader_sequence_two_keys(KC_I, KC_I)) {
        tap_code(KC_F13);  // Interface input (off) - Zoom mute

    // Tools (t prefix)
    } else if (leader_sequence_two_keys(KC_T, KC_C)) {
        tap_code(KC_F14);  // Tool Clipboard history
    } else if (leader_sequence_two_keys(KC_T, KC_P)) {
        tap_code16(LGUI(LSFT(KC_M)));  // Tool color Picker
    } else if (leader_sequence_two_keys(KC_T, KC_J)) {
        tap_code(KC_F15);  // Tool ocr (J for jump to text)
    } else if (leader_sequence_two_keys(KC_T, KC_M)) {
        tap_code16(LSFT(LALT(LGUI(KC_F))));  // Tool Measure (PixelSnap 2)
    } else if (leader_sequence_two_keys(KC_T, KC_S)) {
        tap_code16(LGUI(LSFT(KC_3)));  // Tool Screenshot
    } else if (leader_sequence_two_keys(KC_T, KC_A)) {
        tap_code16(LGUI(LSFT(KC_4)));  // Tool Area capture
    } else if (leader_sequence_two_keys(KC_T, KC_T)) {
        tap_code16(LGUI(LSFT(KC_5)));  // Tool screenshot Tool
    } else if (leader_sequence_two_keys(KC_T, KC_E)) {
        tap_code16(LCTL(LGUI(KC_SPC)));  // Tool Emoji picker
    } else if (leader_sequence_two_keys(KC_T, KC_D)) {
        tap_code16(LALT(LCTL(KC_SPC)));  // Tool Dictation (Flow)
    }
}

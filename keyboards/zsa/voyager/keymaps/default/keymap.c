#include QMK_KEYBOARD_H
#include "version.h"
#include "timer.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  RESET_STATE,
};

// ────── custom leader state ──────
static bool     custom_leader_active = false;
static uint16_t custom_leader_timer  = 0;
static uint16_t custom_leader_seq[3] = {0};   // 0…2 → max 2-key seq + safety
static uint8_t  custom_leader_len    = 0;

// ────── helper: reset timer on every new key ──────
static inline void reset_leader_timer(void) {
    custom_leader_timer = timer_read();
}

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
    // ── non-leader custom keys ──
    if (record->event.pressed) {
        switch (keycode) {
            case RGB_SLD:
                rgblight_mode(1);
                return false;
            case RESET_STATE:
                clear_keyboard();
                clear_oneshot_mods();
                clear_oneshot_locked_mods();
                layer_clear();
                return false;
        }
    }

    // ── leader handling (only on press) ──
    if (!record->event.pressed) return true;

    if (custom_leader_active) {
        // ----- timeout check (safety) -----
        if (custom_leader_timer && timer_elapsed(custom_leader_timer) > CUSTOM_LEADER_TIMEOUT) {
            custom_leader_active = false;
            custom_leader_len    = 0;
            custom_leader_timer  = 0;
            return true;               // let the late key act normally
        }

        // ----- add the pressed key to the buffer -----
        if (custom_leader_len < 2) {
            custom_leader_seq[custom_leader_len++] = keycode;
        }

        // ----- **reset timer on every key** (per-key timing) -----
        reset_leader_timer();

        // ----- immediate match evaluation -----
        bool matched = false;

        // ---- single-key shortcuts (no longer prefixes) ----
        if (custom_leader_len == 1) {
            switch (custom_leader_seq[0]) {
                case KC_B: tap_code16(HYPR(KC_B)); matched = true; break; // Zen Browser
                case KC_C: tap_code16(HYPR(KC_T)); matched = true; break; // Ghostty
            }
        }

        // ---- two-key shortcuts ----
        if (custom_leader_len == 2) {
            // Open apps (N prefix)
            if (custom_leader_seq[0] == KC_N) {
                switch (custom_leader_seq[1]) {
                    case KC_O: tap_code16(HYPR(KC_O)); matched = true; break; // Obsidian
                    case KC_A: tap_code16(HYPR(KC_A)); matched = true; break; // TIDAL
                    case KC_D: tap_code16(HYPR(KC_D)); matched = true; break; // Discord
                    case KC_L: tap_code16(HYPR(KC_L)); matched = true; break; // Linear
                    case KC_S: tap_code16(HYPR(KC_S)); matched = true; break; // Slack
                    case KC_Z: tap_code16(HYPR(KC_Z)); matched = true; break; // Zoom
                    case KC_Y: tap_code16(HYPR(KC_Y)); matched = true; break; // Spotify
                    case KC_C: tap_code16(HYPR(KC_C)); matched = true; break; // Cursor
                }
            }
            // Window Management (W prefix)
            else if (custom_leader_seq[0] == KC_W) {
                switch (custom_leader_seq[1]) {
                    case KC_M: tap_code16(HYPR(KC_M)); matched = true; break; // Maximize
                    case KC_P: tap_code16(HYPR(KC_P)); matched = true; break; // Position
                }
            }
            // Media Controls (I prefix)
            else if (custom_leader_seq[0] == KC_I) {
                switch (custom_leader_seq[1]) {
                    case KC_U: tap_code(KC_VOLU); matched = true; break;
                    case KC_D: tap_code(KC_VOLD); matched = true; break;
                    case KC_M: tap_code(KC_MUTE); matched = true; break;
                    case KC_P: tap_code(KC_MPLY); matched = true; break;
                    case KC_N: tap_code(KC_MNXT); matched = true; break;
                    case KC_B: tap_code(KC_MPRV); matched = true; break;
                    case KC_S: tap_code16(LSFT(LCTL(KC_SPC))); matched = true; break;
                    case KC_I: tap_code(KC_F13); matched = true; break;
                }
            }
            // Tools (T prefix)
            else if (custom_leader_seq[0] == KC_T) {
                switch (custom_leader_seq[1]) {
                    case KC_C: tap_code(KC_F16); matched = true; break;
                    case KC_P: tap_code16(LGUI(LSFT(KC_M))); matched = true; break;
                    case KC_J: tap_code(KC_F17); matched = true; break;
                    case KC_M: tap_code16(LSFT(LALT(LGUI(KC_F)))); matched = true; break;
                    case KC_S: tap_code16(LGUI(LSFT(KC_3))); matched = true; break;
                    case KC_A: tap_code16(LGUI(LSFT(KC_4))); matched = true; break;
                    case KC_T: tap_code16(LGUI(LSFT(KC_5))); matched = true; break;
                    case KC_E: tap_code16(LCTL(LGUI(KC_SPC))); matched = true; break;
                    case KC_D: tap_code16(LALT(LCTL(KC_SPC))); matched = true; break;
                }
            }
        }

        // ----- if we found a match → execute and exit leader mode -----
        if (matched) {
            custom_leader_active = false;
            custom_leader_len    = 0;
            custom_leader_timer  = 0;
            return false;   // swallow the key that triggered the action
        }

        // ----- buffer overflow (should never happen with max 2) -----
        if (custom_leader_len >= 2 && !matched) {
            custom_leader_active = false;
            custom_leader_len    = 0;
            custom_leader_timer  = 0;
        }

        return false;   // swallow keys during leader sequence
    }

    // ── start leader mode when QK_LEAD is pressed ──
    if (keycode == QK_LEAD) {
        clear_keyboard();
        layer_clear();
        custom_leader_active = true;
        custom_leader_len    = 0;
        reset_leader_timer();
        return false;                 // swallow the leader key itself
    }

    return true;
}

// ────── matrix_scan_user – precise timeout handling ──────
void matrix_scan_user(void) {
    if (custom_leader_active && custom_leader_timer &&
        timer_elapsed(custom_leader_timer) > CUSTOM_LEADER_TIMEOUT) {
        // timed out without a complete match → just cancel
        custom_leader_active = false;
        custom_leader_len    = 0;
        custom_leader_timer  = 0;
    }
}

// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum combos {
  UI_DELETE,
  WE_BSPC,
  NM_ESC,
  CV_TAB,
  COMBO_COUNT
};

const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [UI_DELETE] = COMBO(ui_combo, KC_DELETE),
  [WE_BSPC] = COMBO(we_combo, KC_BSPC),
  [NM_ESC] = COMBO(nm_combo, KC_ESC),
  [CV_TAB] = COMBO(cv_combo, KC_TAB),
};

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _QWERTY_PLAIN,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND
};

#define KC_QWERTY PDF(_QWERTY)
#define KC_QWERTY_PLAIN PDF(_QWERTY_PLAIN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |ALT_S |CTL_D |SFT_F |   G  |-------.    ,-------|SFT_H |CTL_J |ALT_K |   L  |   P  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |  XXX  |------+------+------+------+------+------|
 * |LShift|GUI_Z |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |GUI_. |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | Tab  |LWR/BS| /Enter  /       \Space \  |RAI/DL| Esc  | RCTL | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DELETE,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_SCLN,  KC_BSPC,
  KC_TAB,   KC_A, LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,                     RSFT_T(KC_H),    RCTL_T(KC_J), RALT_T(KC_K), KC_L, KC_P, KC_QUOT,
  KC_LSFT,  LGUI_T(KC_Z),   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  RGUI_T(KC_DOT), KC_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LALT,KC_TAB, MO(_LOWER), KC_ENT,      KC_SPC,  MO(_RAISE), KC_ESC, KC_RCTL, KC_RGUI
),
/*
 * QWERTY_PLAIN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   P  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |  XXX  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LCTL | LALT |TL_LWR| /Enter  /       \Space \  |TL_UPR| RCTL | RALT | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY_PLAIN] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DELETE,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_SCLN,  KC_BSPC,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_P,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LCTL,KC_LALT, TL_LOWR, KC_ENT,      KC_SPC,  TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  !   |  @   |  #   |  $   |  %   |                    |  ^   |  &   |  *   |  (   |  )   |  |   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |ALT_2 |CTL_3 |SFT_4 |   5  |-------.    ,-------|SFT_6 |CTL_7 |ALT_8 |   9  |   0  | F12  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  =   |  -   |  +   |  {   |  }   |-------|    |-------|  [   |  ]   |  ;   |  :   |  \   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  KC_GRV,  KC_1,    LALT_T(KC_2),    LCTL_T(KC_3),    LSFT_T(KC_4),    KC_5,                       RSFT_T(KC_6),    RCTL_T(KC_7),  RALT_T(KC_8),    KC_9,    KC_0,  KC_F12,
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu |      |      |                    |      |      |      |      |      | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LAlt | LCtl |LShift|      | Caps |-------.    ,-------| Left | Down |  Up  | Rght |      | Bspc |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | Undo | Cut  | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                     KC_GRV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_BSPC,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND, KC_QUOT , _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  |                    | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | XXX  | XXX  |QWERTY|PLAIN | XXX  | XXX  |                    | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |-------.    ,-------|  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|  XXX  |    |  XXX  |------+------+------+------+------+------|
 * | XXX  | F11  | F12  | XXX  | XXX  | XXX  |-------|    |-------| XXX  | XXX  | XXX  | XXX  | XXX  | XXX  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,KC_QWERTY,KC_QWERTY_PLAIN,XXXXXXX,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  XXXXXXX , KC_F11, KC_F12, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
    }
    return true;
}

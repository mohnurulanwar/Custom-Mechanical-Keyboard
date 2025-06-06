/* Copyright 2019 COSEYFANNITUTTI
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

#ifndef LED_CAPS_LOCK_PIN
  #define LED_CAPS_LOCK_PIN C1 
#endif

#ifndef LED_SCROLL_LOCK_PIN
  #define LED_SCROLL_LOCK_PIN C0 
#endif

void led_init_ports(void) {
    setPinOutput(LED_CAPS_LOCK_PIN);
    setPinOutput(LED_SCROLL_LOCK_PIN);
}

bool led_update_user(led_t led_state) {
    // Mengatur LED Caps Lock
    if (led_state.caps_lock) {
        writePinHigh(LED_CAPS_LOCK_PIN);
    } else {
        writePinLow(LED_CAPS_LOCK_PIN);
    }
    
    // Mengatur LED Scroll Lock
    if (led_state.scroll_lock) {
        writePinHigh(LED_SCROLL_LOCK_PIN);
    } else {
        writePinLow(LED_SCROLL_LOCK_PIN);
    }
    
    return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_tkl_ansi(
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_PRINT_SCREEN, KC_SCROLL_LOCK,   KC_PAGE_UP,   KC_PAGE_DOWN,   KC_HOME,  KC_END,   KC_INSERT,  KC_DELETE,
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,          KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,   KC_ENTER,
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_BSLS,
      KC_LSFT, KC_BSLS, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,  KC_UP,
      KC_LCTL, MO(1),   KC_RGUI, KC_LALT,                 KC_SPC,                KC_RALT, KC_APP, KC_RCTL,  KC_LEFT,  KC_RIGHT, KC_DOWN),
  
    [1] = LAYOUT_tkl_ansi(
      KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS,                  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS)
};


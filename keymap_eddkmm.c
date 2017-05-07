/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "keymap_common.h"

#include "led_controller.h"

/* Define layers */
#define LAYER_ALL 0
#define LAYER_EXTRA 1
#define LAYER_GAME 2
#define LAYER_MOUSE 3


const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  Backs|  `|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    ||Del|
     * |---------------------------------------------------------------|
     * |CapsLo|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |PgU|
     * |---------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgD|
     * |---------------------------------------------------------------|
     * |Ctrl|Gui |Alt |         Space          |MUT|VD |VU |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [0] = KEYMAP_VANILLA( \
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL ,BSPC,     GRV, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     DEL, \
        CAPS, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NUHS,ENT,     PGUP,\
        LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,     UP,  PGDN,\
        LCTL,FN0 ,LALT,               SPC,           MUTE,VOLD, VOLU,    LEFT,DOWN,RGHT \
    ), // EXTRA
    [1] = KEYMAP_VANILLA( \
        TRNS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,    TRNS,\
        TRNS,TRNS,TRNS,MYCM,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     F13,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     F14,\
        TRNS,TRNS,TRNS,TRNS,CALC,TRNS,TRNS,TRNS,MAIL,TRNS,TRNS,TRNS,TRNS,     MPLY,F15,\
        TRNS,TRNS,LGUI,               TRNS,          TRNS,TRNS,TRNS,     MPRV,MSTP,MNXT  \
    ), // GAME
    [2] = KEYMAP_VANILLA( \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     F1, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     F2,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,F3,\
        TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS \
    ), // MOUSE
    [3] = KEYMAP_VANILLA( \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,MS_U,TRNS,TRNS,TRNS,TRNS,TRNS,WH_U,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,TRNS,WH_L,WH_D,WH_R,TRNS,TRNS,TRNS,TRNS,     TRNS,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,BTN1,BTN2,BTN3,TRNS,TRNS,TRNS,     TRNS,TRNS,\
        TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS \
    ), /* Momentary layer for next function key */
    [4] = KEYMAP_VANILLA( \
        TRNS,FN4,FN5,FN6,FN7,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     FN1, \
        TRNS,TRNS,TRNS,TRNS,TRNS ,TRNS,TRNS,TRNS,TRNS,FN8,TRNS,TRNS,TRNS,TRNS,     FN2,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     MPLY,FN3,\
        TRNS,TRNS,LGUI,               TRNS,          TRNS,TRNS,TRNS,     MPRV,MSTP,MNXT \
    ),
};

/* Game Mode Lock flags */
bool game_lock = false;
bool game_mode_last = false;

bool br_inc_held = false;
bool br_dec_held = false;

uint16_t br_inc_time = 0;
uint16_t br_dec_time = 0;

/* Give numbers some descriptive names */
#define ACTION_FUNC_NEXT 1
#define ACTION_LED_BR_UP 2
#define ACTION_LED_BR_DOWN 3
#define ACTION_LED_BR_TOGGLE 4
#define ACTION_FUNC_ALL 5
#define ACTION_FUNC_EXTRA 6
#define ACTION_FUNC_GAME 7
#define ACTION_FUNC_MOUSE 8
#define ACTION_FUNC_FOX 9 // when tapped, switch to next layer; when held, reveal momentary layer 4
#define ACTION_LOCK_GAME 10 // toggle lock game mode

const action_t fn_actions[] = {
    [0] = ACTION_FUNCTION_TAP(ACTION_FUNC_FOX),
    [1] = ACTION_FUNCTION(ACTION_LED_BR_UP),
    [2] = ACTION_FUNCTION(ACTION_LED_BR_DOWN),
    [3] = ACTION_FUNCTION(ACTION_LED_BR_TOGGLE),
    [4] = ACTION_FUNCTION(ACTION_FUNC_ALL),
    [5] = ACTION_FUNCTION(ACTION_FUNC_EXTRA),
    [6] = ACTION_FUNCTION(ACTION_FUNC_GAME),
    [7] = ACTION_FUNCTION(ACTION_FUNC_MOUSE),
    [8] = ACTION_FUNCTION(ACTION_LOCK_GAME),
};

void goto_next_func() {
  uint8_t this_layer = biton32(layer_state);  
  uint8_t next_layer = this_layer + 1;
  if (this_layer == 2 && game_lock) {
    return;
  }
  if (next_layer > 3) {
    next_layer = 0;
    layer_clear();
  } else {
    layer_move(next_layer);
  }
  switch(next_layer) {
    // change LED state
    case LAYER_ALL:
        chMBPost(&led_mailbox, LED_MSG_ALL_TOGGLE, TIME_IMMEDIATE);
        break;
    case LAYER_EXTRA:
        chMBPost(&led_mailbox, LED_MSG_EXTRA_TOGGLE, TIME_IMMEDIATE);
        break;
    case LAYER_GAME:
        chMBPost(&led_mailbox, LED_MSG_GAME_TOGGLE, TIME_IMMEDIATE);
        break;
    case LAYER_MOUSE:
        chMBPost(&led_mailbox, LED_MSG_MOUSE_TOGGLE, TIME_IMMEDIATE);
        break;
  }
}

/* custom action function */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  (void)opt;
  switch(id) {
    case ACTION_FUNC_FOX:
        if (record->event.pressed) {
            if (record->tap.count > 0 && !record->tap.interrupted) {
                if (record->tap.interrupted) {
                    // Held: reveal momentary layer 4
                    game_mode_last = (biton32(layer_state) == 2) ? true : false;
                    layer_invert(4);
                }
            } else {
                // Released after hold
                game_mode_last = (biton32(layer_state) == 2) ? true : false;
                layer_invert(4);
            }
        } else {
            if (record->tap.count > 0 && !(record->tap.interrupted)) {
                // Tapped: switch to next layer
                goto_next_func();
                register_code(KC_NO);
                unregister_code(KC_NO);
                send_keyboard_report();
                record->tap.count = 0; // ad hoc: cancel tap
            } else if (biton32(layer_state) == 4) {
                layer_invert(4);
            }
        }
        break;
    case ACTION_LED_BR_UP:
        if (record->event.pressed) {
            br_inc_held = true;
            // led msg handled every matrix scan
            // chMBPost(&led_mailbox, LED_MSG_BRIGHT_INC, TIME_IMMEDIATE);
        } else {
            br_inc_held = false;
            br_inc_time = 0;
        }
      break;
    case ACTION_LED_BR_DOWN:
        if (record->event.pressed) {
            br_dec_held = true;
            // led msg handled every matrix scan
            // chMBPost(&led_mailbox, LED_MSG_BRIGHT_DEC, TIME_IMMEDIATE);
        } else {
            br_dec_held = false;
            br_dec_time = 0;
        }
      break;
    case ACTION_LED_BR_TOGGLE:
        if (record->event.pressed) {
          // toggle LED state per layer
            chMBPost(&led_mailbox, LED_MSG_BRIGHT_TOGGLE, TIME_IMMEDIATE);
        }
      break;
    case ACTION_FUNC_ALL:
        if (record->event.pressed) {
            if (!game_lock) {
                layer_clear();
                chMBPost(&led_mailbox, LED_MSG_ALL_TOGGLE, TIME_IMMEDIATE);
            }
        }
        break;
    case ACTION_FUNC_EXTRA:
        if (record->event.pressed) {
            if (!game_lock) {
                layer_move(1);
                chMBPost(&led_mailbox, LED_MSG_EXTRA_TOGGLE, TIME_IMMEDIATE);
            }
        }
        break;
    case ACTION_FUNC_GAME:
        if (record->event.pressed) {
            if (!game_lock) {
                layer_move(2);
                chMBPost(&led_mailbox, LED_MSG_GAME_TOGGLE, TIME_IMMEDIATE);
            }
        }
        break;
    case ACTION_FUNC_MOUSE:
        if (record->event.pressed) {
            if (!game_lock) {
                layer_move(3);
                chMBPost(&led_mailbox, LED_MSG_MOUSE_TOGGLE, TIME_IMMEDIATE);
            }
        }
        break;
    case ACTION_LOCK_GAME:
        if (record->event.pressed) {
            if (game_mode_last) {
                // game mode was last mode while in momentary layer 4
                if (game_lock) {
                    game_lock = false;
                    chMBPost(&led_mailbox, LED_MSG_GAME_LOCK_OFF, TIME_IMMEDIATE);
                } else {
                    game_lock = true;
                    chMBPost(&led_mailbox, LED_MSG_GAME_LOCK_ON, TIME_IMMEDIATE);
                }
            } else {
                register_code(KC_L);
                // unregister_code(KC_L);
                // send_keyboard_report();
            }
        }
        break;
  }
}

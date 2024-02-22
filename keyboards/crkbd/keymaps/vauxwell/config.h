#pragma once

// Define which half is the master half
#define MASTER_LEFT

// Turn on NKRO
#undef FORCE_NKRO
#define FORCE_NKRO

// // Set the tapping term that determines the time in milliseconds what is a tap and what is a hold
// #define TAPPING_FORCE_HOLD
// #undef TAPPING_TERM
// #define TAPPING_TERM 240
// #define RETRO_TAPPING

// #define TAPPING_FORCE_HOLD
// #define TAPPING_TERM 100

// Mouse control settings
#define MK_KINETIC_SPEED    //Turn on kinetic mouse control mode
#define MOUSEKEY_INTERVAL       12
#define MOUSEKEY_MOVE_DELTA     6
#define MOUSEKEY_ACCELERATED_SPEED 2700
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 64

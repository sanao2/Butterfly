#include "Global.h"


Animstate current_state = PLAYER_DEFAULT;
Animstate prev_state = PLAYER_DEFAULT;

Animstate GetcurrentAnimationState() { return current_state; }
void SetAnimationState(Animstate state) { current_state = state; }
Animstate GetPrevAnimationState() { return prev_state; }
void SetPrevAnimationState(Animstate state) { prev_state = state; }
#pragma once
#include <windows.h>
#include "AnimationMap.h" 


extern Animstate current_state; // current Animation State 
extern Animstate prev_state;    // Previous Animation State 

extern Animstate GetcurrentAnimationState();
extern void SetAnimationState(Animstate state);

extern Animstate GetPrevAnimationState();
extern void SetPrevAnimationState(Animstate state); 
#pragma once
#include "Global.h"
#include <windows.h>
#include <stdio.h>
#include "UI/timer.h"
#include "resource.h"

using namespace Input;

extern Animstate current_state; // current Animation State 
extern Animstate prev_state;    // Previous Animation State 


Animstate GetcurrentAnimationState() { return current_state; }
void SetAnimationState(Animstate state) { current_state = state; }
Animstate GetPrevAnimationState() { return prev_state; }
void SetPrevAnimationState(Animstate state) { prev_state = state; }

#pragma once
#include "Global.h"  // 이제 Global.h 하나만 include하면 됨#include <windows.h>
#include <stdio.h>
#include "UI/timer.h"
#include "resource.h"
#include "Render.h"

extern Render* render;
using namespace Input;

Animstate GetcurrentAnimationState() { return current_state; }
void SetAnimationState(Animstate state) { current_state = state; }
Animstate GetPrevAnimationState() { return prev_state; }
void SetPrevAnimationState(Animstate state) { prev_state = state; }

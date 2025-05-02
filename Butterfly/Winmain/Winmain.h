#pragma once
#include "Global.h"  // ���� Global.h �ϳ��� include�ϸ� ��#include <windows.h>
#include <stdio.h>
#include "UI/timer.h"
#include "resource.h"
#include "Render.h"
using namespace Input;

extern Render* render;

extern int g_width;
extern int g_height; 

Animstate GetcurrentAnimationState() { return current_state; }
void SetAnimationState(Animstate state) { current_state = state; }
Animstate GetPrevAnimationState() { return prev_state; }
void SetPrevAnimationState(Animstate state) { prev_state = state; }

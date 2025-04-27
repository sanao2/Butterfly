#pragma once
#include <windows.h>
#include <stdio.h>
#include "Move/MoveManagers.h"
#include "Event/KeyboardInputManager.h"
#include "Render.h"

using namespace Input;

Move::MoveManager* move; 
Render* render; 
extern HWND g_hWnd; 


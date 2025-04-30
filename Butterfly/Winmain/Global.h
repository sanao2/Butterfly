#pragma once
#include "Render.h"
#include <windows.h>
#include "Move/MoveManagers.h"
#include "Event/KeyboardInputManager.h"


extern Move::MoveManager* move;
extern Render* render;
extern HWND g_hWnd;
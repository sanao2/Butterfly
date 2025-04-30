#pragma once
#include <windows.h>
#include "Render.h"
#include "Move/MoveManagers.h"
#include "Event/KeyboardInputManager.h"


extern Move::MoveManager* move;
extern Render* render;
extern HWND g_hWnd;
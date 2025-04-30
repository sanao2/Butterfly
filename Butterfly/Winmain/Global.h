#pragma once
#include <windows.h>
#include "Render.h"
#include "Move/MoveManagers.h"
#include "Event/KeyboardInputManager.h"

extern Animstate current_state; // current Animation State 
extern Animstate prev_state;    // Previous Animation State 

extern Move::MoveManager* move;
extern Render* render;
extern ResourceManger* ResMgr;
extern HWND g_hWnd;

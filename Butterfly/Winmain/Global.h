#pragma once
#include <windows.h>
#include "Render.h"
#include "AnimationMap.h" 
#include "Move/MoveManagers.h"
#include "Event/KeyboardInputManager.h"

extern Render* render;
extern Move::MoveManager* move;
extern Animstate current_state; // current Animation State 
extern Animstate prev_state;    // Previous Animation State 



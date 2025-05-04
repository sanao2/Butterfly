#pragma once
#include "Global.h"  // ���� Global.h �ϳ��� include�ϸ� ��#include <windows.h>
#include <stdio.h>
#include "UI/timer.h"
#include "resource.h"
#include "Render.h"
#include "Move/MoveManagers.h"
#include "Move/PlayerMoveController.h"
using namespace Input;

extern Render* render;
extern RECT playerPos;
extern int g_width;
extern int g_height; 

//std::chrono::steady_clock::time_point          lastInputTime;
//Move::MoveManager* moveMgr = nullptr;
//Move::PlayerMoveController                     playerController;
//Input::InputManager<Input::KeyboardDevice>& key = Input::InputManager<Input::KeyboardDevice>::GetInstance();
//
//void MoveDirState();

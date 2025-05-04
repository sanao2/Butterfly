#pragma once 
#include "Global.h"
#include <windows.h> 
#include "ResourceManager.h"
#include "UI/Timer.h"
#include <iostream> 
#include <vector> 
#include <gdiplus.h>
#include <chrono>
#include "Move/MoveManagers.h"
#pragma comment(lib, "gdiplus.lib")

using namespace std::chrono;
using std::vector; 
using namespace std; 
using namespace Move;

extern int g_width; 
extern int g_height;
extern int current_frame;
extern RECT playerRc;

class Animation 
{
private :
	HINSTANCE hInstance; 
	ResourceManager* resManager;
	steady_clock::time_point lastReload; 

	Time::Timer<> timer;	 
	constexpr static float frameInterval = 0.25f; 

	Input::InputManager<Input::KeyboardDevice>& key = Input::InputManager<Input::KeyboardDevice>::GetInstance();
	Move::MoveManager* moveMgr;
	steady_clock::time_point lastMoveTime;
public : 
	Animation(HDC drawDC, HINSTANCE hInstance);
	~Animation(); 
		
	void Update();	
	void Render(HDC drawDC, RECT& rect, Gdiplus::Graphics* graphics, int x, int y, int curFrameIndex);
	void PlayerAnimationkeyInput();           // 플레이어 이동 키 입력 
	void Changestate(Animstate newState, HINSTANCE hInstance);
	ResourceManager* GetResourceManager() { return resManager; }
};


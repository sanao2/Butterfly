#pragma once
#include "Global.h"
#include <windows.h>
#include <gdiplus.h>
#include <iostream>
#include "Event/KeyboardInputManager.h"
#include "Swap.h"
#include "UI/Timer.h"
#include <string> 
using std::wstring;
using namespace std;
using namespace Gdiplus;

extern bool g_Quit;
extern bool isEndScene;
class EndScene
{
private:
	POINT clientSize = {};
	Swap* swap = nullptr;
	Time::Timer<> timer; 
	Gdiplus::Graphics* graphics = nullptr; 
	HDC memDC;	
	Input::InputManager<Input::KeyboardDevice>& key = Input::InputManager<Input::KeyboardDevice>::GetInstance();
public:
	EndScene(Swap* _swap, int width, int height);
	void KeyInput();
	void Update();
	void EndSceneRender();
};


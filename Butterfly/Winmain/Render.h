// Render.h
#pragma once
#include "Global.h"
#include <windows.h>
#include "Swap.h"
#include "EndScene.h"
#include "Animation.h"
#include <gdiplus.h>
#include <atltypes.h>
#include <chrono>
#include "AnimationMap.h"
#include "Move/MoveManagers.h"
#include "UI/Map/Map.h"
#include "collider.h"
#pragma comment(lib, "gdiplus.lib")
using namespace std::chrono;
using namespace Move;
using namespace Map;

extern bool isEndScene;

class Render
{
public:
	Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height, Gdiplus::Rect& rect);
	~Render();

	void Update();                           // 렌더 업데이트 및 스왑 호출  
	void RenderScene(HINSTANCE hInst);       // 실제 그리기 동작 
	void PlayerAnimationkeyInput();           // 플레이어 이동 키 입력 
	POINT GetBufferSize() const;

private:
	HWND                                           hWnd = nullptr;
	POINT                                          clientSize = { 0, 0 };
	HINSTANCE                                      hInst = nullptr;
	HDC                                            memDC = nullptr;

	Swap* swap = nullptr;
	Map::Object* object = nullptr;
	Gdiplus::Graphics* graphics = nullptr;
	Animation* animation = nullptr;
	Collider* collider = nullptr;

	Input::InputManager<Input::KeyboardDevice>& key = Input::InputManager<Input::KeyboardDevice>::GetInstance();
	Move::MoveManager* moveMgr = nullptr;
	steady_clock::time_point lastMoveTime;

};


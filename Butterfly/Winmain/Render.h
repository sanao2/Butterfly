// Render.h
#pragma once
#include "Global.h"
#include <windows.h>
#include "Swap.h"
#include "Animation.h"
#include <gdiplus.h>
#include <atltypes.h>
#include <chrono>
#include "AnimationMap.h"
#include "Move/MoveManagers.h"
#pragma comment(lib, "gdiplus.lib")

class Render
{
public:
    Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height);
    ~Render();

        void Update();                         // 렌더 업데이트 및 스왑 호출  
        void RenderScene(HINSTANCE hInst);     // 실제 그리기 동작 
       
        POINT GetBufferSize() const;
        
    private:
        HWND                                           hWnd = nullptr;
        POINT                                          clientSize = { 0, 0 };
        HINSTANCE                                      hInst = nullptr;

        Swap* swap = nullptr;
        HDC                                            memDC = nullptr;
        Gdiplus::Graphics* graphics = nullptr;
        Animation* animation = nullptr;

        void PlayerAnimationkeyInput();           // 플레이어 이동 키 입력 
        Input::InputManager<Input::KeyboardDevice>& key = Input::InputManager<Input::KeyboardDevice>::GetInstance();
        Move::MoveManager moveMgr;
        steady_clock::time_point lastMoveTime;
};
   

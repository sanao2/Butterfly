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
using namespace std::chrono;
using namespace Move;

class Render
{
public:
    Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height);
    ~Render();
                                                 
        void Update();                           // ���� ������Ʈ �� ���� ȣ��  
        void RenderScene(HINSTANCE hInst);       // ���� �׸��� ���� 
        void PlayerAnimationkeyInput();           // �÷��̾� �̵� Ű �Է� 
        POINT GetBufferSize() const;
        
    private:
        HWND                                           hWnd = nullptr;
        POINT                                          clientSize = { 0, 0 };
        HINSTANCE                                      hInst = nullptr;

        Swap* swap = nullptr;
        Time::Timer<> timer;
        HDC                                            memDC = nullptr;
        Gdiplus::Graphics* graphics = nullptr;
        Animation* animation = nullptr;
        Input::InputManager<Input::KeyboardDevice>& key = Input::InputManager<Input::KeyboardDevice>::GetInstance();
        Move::MoveManager* moveMgr = nullptr;
        steady_clock::time_point lastMoveTime;
       
};


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
#pragma comment(lib, "gdiplus.lib")

extern RECT playerRect;

class Render
{
public:
    Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height);
    ~Render();

    void Update();          // ���� ������Ʈ �� ���� ȣ��  
    void RenderScene(HINSTANCE hInst);     // ���� �׸��� ���� 
    void Moves(); 
    POINT GetBufferSize() const;

private:
    HWND                                           hWnd = nullptr;
    POINT                                          clientSize = { 0, 0 };
    HINSTANCE                                      hInst = nullptr;

    Swap*                                          swap = nullptr;
    HDC                                            memDC = nullptr;
    Gdiplus::Graphics*                             graphics = nullptr;
    Animation*                                     animation = nullptr;
  
    std::chrono::steady_clock::time_point          lastMoveTime;
    Input::InputManager<Input::KeyboardDevice>& key = Input::InputManager<Input::KeyboardDevice>::GetInstance();
    Move::PlayerMoveController                     playerController;
    Move::MoveManager* moveMgr = nullptr;
};

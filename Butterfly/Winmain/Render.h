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

extern RECT playerPos;
class Render
{
public:
    Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height);
    ~Render();

    void Update();          // 렌더 업데이트 및 스왑 호출  
    void RenderScene(HINSTANCE hInst);     // 실제 그리기 동작 
   
    POINT GetBufferSize() const;

private:
    HWND                                           hWnd = nullptr;
    POINT                                          clientSize = { 0, 0 };
    HINSTANCE                                      hInst = nullptr;

    Swap*                                          swap = nullptr;
    HDC                                            memDC = nullptr;
    Gdiplus::Graphics*                             graphics = nullptr;
    Animation*                                     animation = nullptr;
  


    
};

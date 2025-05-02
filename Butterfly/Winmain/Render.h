#pragma once
#include <windows.h>
#include "Swap.h"
#include "Animation.h"
#include <gdiplus.h> 
#pragma comment(lib, "gdiplus.lib")


class Render
{
private:
    HWND hWnd = nullptr;
    POINT clientSize = {0,0}; 
    HINSTANCE hInst; 
    HDC memDC = nullptr;
	Gdiplus::Graphics* graphics = nullptr; // GDI+ 그래픽스 객체

    Swap* swap = nullptr;
    // ResourceManager* ResMgr = nullptr;

public:
    Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height);
    ~Render();
    
    void Update();          // 렌더 업데이트 및 스왑 호출
    void RenderScene(HINSTANCE hInst);     // 실제 그리기 동작
    POINT GetBufferSize() const;

   
};
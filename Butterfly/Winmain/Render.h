#pragma once
#include <windows.h>
#include "Swap.h"
#include "Animation.h"
#include "ResourceManger.h" 

class Render
{
private:
    HWND hWnd;
    POINT clientSize;
    Swap* swap;
    ResourceManger* ResMgr;
    Animation* anim; 
    HDC memDC = nullptr;
	Gdiplus::Graphics* graphics = nullptr; // GDI+ 그래픽스 객체

public:
    Render(HDC drawDC, HWND hwnd, int width, int height);
    ~Render();
    
    void Update();          // 렌더 업데이트 및 스왑 호출
    void RenderScene(HINSTANCE hInst);     // 실제 그리기 동작
    POINT GetBufferSize() const;
};
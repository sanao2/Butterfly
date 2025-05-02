#pragma once
#include <windows.h>
#include "Swap.h"
#include "ResourceManger.h" 
#include "Animation.h"
class Render
{
private:
    HWND hWnd = nullptr;
    POINT clientSize = {0,0};
    Swap* swap = nullptr;
    ResourceManager* ResMgr = nullptr;
   // Animation* animation = nullptr; 
    HINSTANCE hInst; 
    HDC memDC = nullptr;
	Gdiplus::Graphics* graphics = nullptr; // GDI+ 그래픽스 객체

public:
    Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height);
    ~Render();
    
    void Update();          // 렌더 업데이트 및 스왑 호출
    void RenderScene(HINSTANCE hInst);     // 실제 그리기 동작
    POINT GetBufferSize() const;
};
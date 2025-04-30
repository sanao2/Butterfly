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
	Gdiplus::Graphics* graphics = nullptr; // GDI+ �׷��Ƚ� ��ü

public:
    Render(HDC drawDC, HWND hwnd, int width, int height);
    ~Render();
    
    void Update();          // ���� ������Ʈ �� ���� ȣ��
    void RenderScene(HINSTANCE hInst);     // ���� �׸��� ����
    POINT GetBufferSize() const;
};
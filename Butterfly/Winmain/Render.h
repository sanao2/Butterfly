#pragma once
#include <windows.h>
#include "Swap.h"
#include "Animation.h"
#include "ResourceManger.h" 

class Render
{
private:
    HWND hWnd = nullptr;
    POINT clientSize = {0,0};
    Swap* swap = nullptr;
    //ResourceManger* ResMgr;
   // Animation* animation = nullptr; 

    HDC memDC = nullptr;
	Gdiplus::Graphics* graphics = nullptr; // GDI+ �׷��Ƚ� ��ü

public:
    Render(HDC drawDC, HWND hwnd, int width, int height);
    ~Render();
    
    void Update();          // ���� ������Ʈ �� ���� ȣ��
    void RenderScene(HINSTANCE hInst);     // ���� �׸��� ����
    POINT GetBufferSize() const;
};
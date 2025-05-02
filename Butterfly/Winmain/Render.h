#pragma once
#include <windows.h>
#include "Swap.h"
#include <gdiplus.h> 
#pragma comment(lib, "gdiplus.lib")

class Animation; 

class Render
{
private:
    HWND hWnd = nullptr;
    POINT clientSize = {0,0}; 
    HINSTANCE hInst; 
    HDC memDC = nullptr;
	Gdiplus::Graphics* graphics = nullptr; // GDI+ �׷��Ƚ� ��ü

    Swap* swap = nullptr;
    // ResourceManager* ResMgr = nullptr;
    Animation* animation = nullptr;
public:
    Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height);
    ~Render();
    
    void Update();          // ���� ������Ʈ �� ���� ȣ��
    void RenderScene(HINSTANCE hInst);     // ���� �׸��� ����
    POINT GetBufferSize() const;

    friend class Animation; 
};
#pragma once
#include <windows.h>
#include "Swap.h"
#include "Animation.h"

class Render
{
private:
    HWND hWnd;
    POINT clientSize;
    Swap* swap;
    //Animation* anim; 
    HDC memDC = nullptr;

public:
    Render(HWND hwnd, int width, int height);
    ~Render();
    
    void Update();          // ���� ������Ʈ �� ���� ȣ��
    void RenderScene(HINSTANCE hInst);     // ���� �׸��� ����
    POINT GetBufferSize() const;
};
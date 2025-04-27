#pragma once
#include <windows.h>
#include "Swap.h"

class Render
{
private:
    HWND hWnd;
    POINT clientSize;
    Swap* swap;

public:
    Render(HWND hwnd, int width, int height);
    ~Render();

    void Update();          // ���� ������Ʈ �� ���� ȣ��
    void RenderScene();     // ���� �׸��� ����
    POINT GetBufferSize() const;
};
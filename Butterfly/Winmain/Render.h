#pragma once
#include <windows.h>
#include "Swap.h"
#include "UIManager.h"

class Render
{
private:
    HWND hWnd;
    POINT clientSize;
    Swap* swap;
    UIManager* UI;

public:
    Render(HWND hwnd, int width, int height);
    ~Render();

    void Update();          // ���� ������Ʈ �� ���� ȣ��
    void RenderScene();     // ���� �׸��� ����
    POINT GetBufferSize() const;
};
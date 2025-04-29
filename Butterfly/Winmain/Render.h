#pragma once
#include <windows.h>
#include "Swap.h"
#include "UI/ResourceManager.h"

class Render
{
private:
    HWND hWnd;
    POINT clientSize;
    Swap* swap;
	ResourceManager* RcManager; // ResourceManager ��ü�� ����ϱ� ���� ������

public:
    Render(HWND hwnd, int width, int height);
    ~Render();
    
    void Update();          // ���� ������Ʈ �� ���� ȣ��
    void RenderScene(HINSTANCE hInst);     // ���� �׸��� ����
    POINT GetBufferSize() const;
};
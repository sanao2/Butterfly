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

    void Update();          // 렌더 업데이트 및 스왑 호출
    void RenderScene();     // 실제 그리기 동작
    POINT GetBufferSize() const;
};
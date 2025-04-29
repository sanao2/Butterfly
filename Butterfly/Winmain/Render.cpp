#include "Render.h"

Render::Render(HWND hwnd, int width, int height)
    : hWnd(hwnd), clientSize{ width, height }
{
    swap = new Swap(hwnd, width, height);
    RcManager = new ResourceManager(hwnd, width, height); // ResourceManager 객체 생성 
    Time::InitTime(); // Timer start  Initialization 
}

Render::~Render()
{
    delete swap;
}

void Render::Update()
{
    Time::UpdateTime();
    swap->SwapBuffers();    // 백버퍼 -> 프론트버퍼 복사

}

void Render::RenderScene(HINSTANCE hInst)
{
    HDC memDC = swap->GetMemDC(); 
    HBITMAP tempBitmap = CreateCompatibleBitmap(GetDC(hWnd), clientSize.x, clientSize.y);
    SelectObject(memDC, tempBitmap);

    // 그리기 예제
   PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);
   /*  Rectangle(memDC, 50, 50, 200, 200);*/
   RcManager->Render(memDC, 0, 0, clientSize.x / 2, clientSize.y / 2); 

    // 스왑 메모리 DC에 복사 (swap 내부 메모리 DC를 가져오는 메소드 필요)
   // BitBlt(GetDC(hWnd), 0, 0, clientSize.x, clientSize.y, memDC, 0, 0, SRCCOPY);
   swap->SwapBuffers(); 

    DeleteObject(tempBitmap);
    DeleteDC(memDC);
}

POINT Render::GetBufferSize() const
{
    return clientSize;
}

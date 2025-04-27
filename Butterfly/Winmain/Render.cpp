#include "Render.h"

Render::Render(HWND hwnd, int width, int height)
    : hWnd(hwnd), clientSize{ width, height }
{
    swap = new Swap(hwnd, width, height);
}

Render::~Render()
{
    delete swap;
}

void Render::Update()
{
    swap->SwapBuffers();    // ����� -> ����Ʈ���� ����

}

void Render::RenderScene()
{
    HDC memDC = swap->GetMemDC(); 
    HBITMAP tempBitmap = CreateCompatibleBitmap(GetDC(hWnd), clientSize.x, clientSize.y);
    SelectObject(memDC, tempBitmap);

    // �׸��� ����
   PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);
   /*  Rectangle(memDC, 50, 50, 200, 200);*/


    // ���� �޸� DC�� ���� (swap ���� �޸� DC�� �������� �޼ҵ� �ʿ�)
   // BitBlt(GetDC(hWnd), 0, 0, clientSize.x, clientSize.y, memDC, 0, 0, SRCCOPY);
   swap->SwapBuffers(); 

    DeleteObject(tempBitmap);
    DeleteDC(memDC);
}

POINT Render::GetBufferSize() const
{
    return clientSize;
}

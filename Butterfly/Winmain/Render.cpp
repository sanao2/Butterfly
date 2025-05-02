#include "Render.h"

Render::Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height)
    : hWnd(hwnd), clientSize{ width, height }, hInst(hInstance)
{
    swap = new Swap(hwnd, width, height);
	animation = new Animation(drawDC, hInstance); // 애니메이션 객체 생성 
}   

Render::~Render()
{
    delete swap;
}

void Render::Update()
{ 
	// 스왑 메모리 DC에 복사 (swap 내부 메모리 DC를 가져오는 메소드 필요)
    animation->Update(); // 애니메이션 업데이트 
}

void Render::RenderScene(HINSTANCE hInst)
{
    Time::UpdateTime();

    memDC = swap->GetMemDC();
    HBITMAP tempBitmap = CreateCompatibleBitmap(GetDC(hWnd), clientSize.x, clientSize.y);
    SelectObject(memDC, tempBitmap);
    graphics = new Gdiplus::Graphics(memDC);

    // 화면 초기화 (배경을 흰색으로 채우기)
    PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);

	animation->Render(memDC, graphics, 0,0); 

    // 스왑 메모리 DC에 복사 (swap 내부 메모리 DC를 가져오는 메소드 필요)
    swap->SwapBuffers();

    // 리소스 해제
	delete graphics; 
    DeleteObject(tempBitmap);
    DeleteDC(memDC);
}

POINT Render::GetBufferSize() const
{
    return clientSize;
}

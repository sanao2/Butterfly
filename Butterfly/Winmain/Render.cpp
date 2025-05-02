#include "Render.h"

Render::Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height)
    : hWnd(hwnd), clientSize{ width, height }, hInst(hInstance)
{
    swap = new Swap(hwnd, width, height);
  
}   

Render::~Render()
{
    delete swap;
}

void Render::Update()
{
	// 스왑 메모리 DC에 복사 (swap 내부 메모리 DC를 가져오는 메소드 필요)
	swap->SwapBuffers();


}

void Render::RenderScene(HINSTANCE hInst)
{
    memDC = swap->GetMemDC();
    HBITMAP tempBitmap = CreateCompatibleBitmap(GetDC(hWnd), clientSize.x, clientSize.y);
    SelectObject(memDC, tempBitmap);
    graphics = new Gdiplus::Graphics(memDC);

    // 화면 초기화 (배경을 흰색으로 채우기)
    PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);

    // 리소스 로딩 - 이미지를 로드하기 위해 LoadImages 호출              
	//ResMgr->LoadImages(hInst); // 리소스 매니저를 통해 이미지 로드 
	//ResMgr->RenderImage(*graphics, 0, 0); // 이미지를 그리기 
       
    // 스왑 메모리 DC에 복사 (swap 내부 메모리 DC를 가져오는 메소드 필요)
    swap->SwapBuffers();

    // 리소스 해제
    DeleteObject(tempBitmap);
    DeleteDC(memDC);
}

POINT Render::GetBufferSize() const
{
    return clientSize;
}

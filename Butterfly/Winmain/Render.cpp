#include "Render.h"
#include <iostream>

Render::Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height)
                : hWnd(hwnd), clientSize{ width, height }, hInst(hInstance)
{ 
    swap = new Swap(hwnd, width, height);
	//ResMgr = new ResourceManager(drawDC, hInstance); // 리소스 매니저 객체 생성
	animation = new Animation(drawDC, hInstance); // 애니메이션 객체 생성 
}

Render::~Render()
{
    delete swap;
}

void Render::Update()
{
    swap->SwapBuffers();    // 백버퍼 -> 프론트버퍼 복사
	
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
	//ResMgr->RenderFrame(graphics, 0, 0, 1.0f); // 애니메이션 프레임 그리기 
   
	// 애니메이션 생성 및 렌더링
	
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

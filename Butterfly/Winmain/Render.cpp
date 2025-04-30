#include "Render.h"
#include <iostream>

Render::Render(HDC drawDC, HWND hwnd,  int width, int height)
    : hWnd(hwnd), clientSize{ width, height }
{
    swap = new Swap(hwnd, width, height);
	ResMgr = new ResourceManger(hwnd); // 리소스 매니저 객체 생성
	//anim = new Animation(hwnd, width, height); // Animation 객체 생성 


    Gdiplus::GdiplusStartupInput gsi;
    Gdiplus::GdiplusStartup(&GdiPlusToken, &gsi, nullptr);
    graphics = new Gdiplus::Graphics(drawDC);

}

Render::~Render()
{
    delete swap;
}

void Render::Update()
{
    swap->SwapBuffers();    // 백버퍼 -> 프론트버퍼 복사
    //anim->Update(); // Animation Update 
}

void Render::RenderScene(HINSTANCE hInst)
{
    memDC = swap->GetMemDC();
    HBITMAP tempBitmap = CreateCompatibleBitmap(GetDC(hWnd), clientSize.x, clientSize.y);
    SelectObject(memDC, tempBitmap);

    // 화면 초기화 (배경을 흰색으로 채우기)
    PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);
    ResMgr->Initialize(); 
    // 리소스 로딩 - 이미지를 로드하기 위해 LoadImages 호출
    try {
		ResMgr->LoadImages(hInst); // 리소스 매니저를 통해 이미지 로드 
		ResMgr->RenderImage(Gdiplus::Graphics, 0, 0); // 이미지를 그리기 
    }
    catch (const std::exception& e) {
        std::cerr << "Error loading images: " << e.what() << std::endl;
    }

    // 애니메이션 업데이트 및 렌더링
    //anim->Update(); // 애니메이션 업데이트
    // anim->Render(memDC); // 애니메이션 렌더링

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

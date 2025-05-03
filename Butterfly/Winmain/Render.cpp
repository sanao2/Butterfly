#include "Render.h"

using namespace Input;
//int boxDraw()
//{
//    PatBlt(drawDC, 0, 0, g_width, g_height, WHITENESS);
//    Rectangle(drawDC, rect.left, rect.top, rect.right, rect.bottom);
//
//    ReleaseDC(g_hWnd, drawDC); // Release 해줘야 리소스 누수 안 생김
//    return S_OK;
//}

Render::Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height)
   : hWnd(hwnd), clientSize{ width, height }, hInst(hInstance)
{
   swap = new Swap(hwnd, width, height);
   animation = new Animation(drawDC, hInstance);
 
}   

Render::~Render()
{
	DeleteDC(memDC);
	delete graphics;
    delete swap;
}

void Render::Update()
{ 
   // 이동을 위한 업데이트 
	animation->Update(); // 애니메이션 업데이트 
}

void Render::RenderScene(HINSTANCE hInst)
{
   Time::UpdateTime();
   
   memDC = swap->GetMemDC();
   graphics = new Gdiplus::Graphics(memDC);

   // 화면 초기화 (배경을 흰색으로 채우기)
   PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);
  
   animation->Render(memDC, graphics, 0, 0, current_frame);

   // 스왑 메모리 DC에 복사 (swap 내부 메모리 DC를 가져오는 메소드 필요)
   swap->SwapBuffers();
   
}


POINT Render::GetBufferSize() const
{
   return clientSize;
}

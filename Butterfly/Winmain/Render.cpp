#include "Render.h"

using namespace Input;

Render::Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height)
   : hWnd(hwnd), clientSize{ width, height }, hInst(hInstance)
{
   swap = new Swap(hwnd, width, height);
   animation = new Animation(drawDC, hInstance); // 애니메이션 객체 생성 

   RECT rect = { 0, 0, width, height }; // rect 정의 추가
   auto& key = InputManager<KeyboardDevice>::GetInstance();
   std::unique_ptr<Move::MoveManager> move = std::make_unique<Move::MoveManager>(key, rect); // rect 사용
}   

Render::~Render()
{
   delete swap;
}

void Render::Update()
{ 
   // 스왑 메모리 DC에 복사 (swap 내부 메모리 DC를 가져오는 메소드 필요)
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

   animation->Update(current_frame); // 애니메이션 업데이트 
   animation->Render(memDC, graphics, 0, 0, current_frame);

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

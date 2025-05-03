#include "Render.h"

using namespace Input;

Render::Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height)
   : hWnd(hwnd), clientSize{ width, height }, hInst(hInstance)
{
   swap = new Swap(hwnd, width, height);
   animation = new Animation(drawDC, hInstance); // �ִϸ��̼� ��ü ���� 

   RECT rect = { 0, 0, width, height }; // rect ���� �߰�
   auto& key = InputManager<KeyboardDevice>::GetInstance();
   std::unique_ptr<Move::MoveManager> move = std::make_unique<Move::MoveManager>(key, rect); // rect ���
}   

Render::~Render()
{
   delete swap;
}

void Render::Update()
{ 
   // ���� �޸� DC�� ���� (swap ���� �޸� DC�� �������� �޼ҵ� �ʿ�)
}

void Render::RenderScene(HINSTANCE hInst)
{
   Time::UpdateTime();

   memDC = swap->GetMemDC();
   HBITMAP tempBitmap = CreateCompatibleBitmap(GetDC(hWnd), clientSize.x, clientSize.y);
   SelectObject(memDC, tempBitmap);
   graphics = new Gdiplus::Graphics(memDC);

   // ȭ�� �ʱ�ȭ (����� ������� ä���)
   PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);

   animation->Update(current_frame); // �ִϸ��̼� ������Ʈ 
   animation->Render(memDC, graphics, 0, 0, current_frame);

   // ���� �޸� DC�� ���� (swap ���� �޸� DC�� �������� �޼ҵ� �ʿ�)
   swap->SwapBuffers();

   // ���ҽ� ����
   delete graphics; 
   DeleteObject(tempBitmap);
   DeleteDC(memDC);
}

POINT Render::GetBufferSize() const
{
   return clientSize;
}

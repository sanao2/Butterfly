#include "Render.h"

using namespace Input;
//int boxDraw()
//{
//    PatBlt(drawDC, 0, 0, g_width, g_height, WHITENESS);
//    Rectangle(drawDC, rect.left, rect.top, rect.right, rect.bottom);
//
//    ReleaseDC(g_hWnd, drawDC); // Release ����� ���ҽ� ���� �� ����
//    return S_OK;
//}
POINT playerPos = { 0,0 };

Render::Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height)
   : hWnd(hwnd), clientSize{ width, height }, hInst(hInstance)
{
   swap = new Swap(hwnd, width, height);
   animation = new Animation(drawDC, hInstance); // �ִϸ��̼� ��ü ���� 
   auto& key = InputManager<KeyboardDevice>::GetInstance();
   move = std::make_unique<Move::MoveManager>(key, playerPos);
 
}   

Render::~Render()
{
	DeleteDC(memDC);
	delete graphics;
    delete swap;
}

void Render::Update()
{ 
   // �̵��� ���� ������Ʈ 
	move->MoveUpdate();
	animation->Update(); // �ִϸ��̼� ������Ʈ 
}

void Render::RenderScene(HINSTANCE hInst, POINT playerPos)
{
   Time::UpdateTime();
   
   memDC = swap->GetMemDC();
   graphics = new Gdiplus::Graphics(memDC);

   // ȭ�� �ʱ�ȭ (����� ������� ä���)
   PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);
   
   animation->Render(memDC, graphics, playerPos.x, playerPos.y, current_frame);

   // ���� �޸� DC�� ���� (swap ���� �޸� DC�� �������� �޼ҵ� �ʿ�)
   swap->SwapBuffers();

   // ���ҽ� ����

   //DeleteObject(tempBitmap);
   
}

POINT Render::GetBufferSize() const
{
   return clientSize;
}

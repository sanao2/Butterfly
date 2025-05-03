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

Render::Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height)
   : hWnd(hwnd), clientSize{ width, height }, hInst(hInstance)
{
   swap = new Swap(hwnd, width, height);
   animation = new Animation(drawDC, hInstance); // �ִϸ��̼� ��ü ���� 

}   

Render::~Render()
{
	DeleteDC(memDC);
	delete graphics;
    delete swap;
}

void Render::Update()
{ 
   // ���� �޸� DC�� ���� (swap ���� �޸� DC�� �������� �޼ҵ� �ʿ�)
	auto& key = InputManager<KeyboardDevice>::GetInstance();
	std::unique_ptr<Move::MoveManager> move = std::make_unique<Move::MoveManager>(key, rect);
	move->MoveUpdate();

}

void Render::RenderScene(HINSTANCE hInst, RECT rect)
{
   Time::UpdateTime();
   
   memDC = swap->GetMemDC();
   graphics = new Gdiplus::Graphics(memDC);

   // ȭ�� �ʱ�ȭ (����� ������� ä���)
   PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);

   animation->Update(); // �ִϸ��̼� ������Ʈ 
   animation->Render(memDC, graphics, 0, 0, current_frame);

   // ���� �޸� DC�� ���� (swap ���� �޸� DC�� �������� �޼ҵ� �ʿ�)
   swap->SwapBuffers();

   // ���ҽ� ����

   //DeleteObject(tempBitmap);
   
}

POINT Render::GetBufferSize() const
{
   return clientSize;
}

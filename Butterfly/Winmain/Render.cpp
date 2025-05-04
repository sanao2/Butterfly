#include "Render.h"
using namespace Input;


Render::Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height)
	: hWnd(hwnd), clientSize{ width, height },
	hInst(hInstance)
{
	swap = new Swap(hwnd, width, height);
	animation = new Animation(drawDC, hInstance);
}

Render::~Render()
{
	DeleteDC(memDC);
	delete graphics;
	delete animation;
	delete swap;
}

void Render::Update()
{
	// �̵��� ���� ������Ʈ 
	animation->Update(); // �ִϸ��̼� ������Ʈ 
}

void Render::RenderScene(HINSTANCE hInst)
{
	Time::UpdateTime();

	memDC = swap->GetMemDC();
	graphics = new Gdiplus::Graphics(memDC);

	// ȭ�� �ʱ�ȭ (����� ������� ä���)
	PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);
	
	animation->Render(memDC, playerPos, graphics, 0, 0, current_frame);

	// ���� �޸� DC�� ���� (swap ���� �޸� DC�� �������� �޼ҵ� �ʿ�)
	swap->SwapBuffers();

}

//void  Render::MoveDirection()
//{
//	auto now = steady_clock::now();
//
//	Move::MoveDirection dir = playerController.GetDirection();
//
//	lastInputTime = now;
//
//	Animstate curstate = MoveDirstate();
//	auto elapsed = duration_cast<seconds>(now - lastInputTime);
//
//	if (dir != Move::MoveDirection::None)
//	{
//		lastInputTime = now;
//		SetAnimationState(curstate);
//	}
//	else if (elapsed.count() >= 1.0f && dir == Move::MoveDirection::None)
//	{
//		SetAnimationState(PLAYER_DEFAULT);
//
//	}
//}

POINT Render::GetBufferSize() const
{
	return clientSize;
}
//int boxDraw()
//{
//    PatBlt(drawDC, 0, 0, g_width, g_height, WHITENESS);
//    Rectangle(drawDC, rect.left, rect.top, rect.right, rect.bottom);
//
//    ReleaseDC(g_hWnd, drawDC); // Release ����� ���ҽ� ���� �� ����
//    return S_OK;
//}


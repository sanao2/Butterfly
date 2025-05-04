#include "Render.h"
using namespace Input;


Render::Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height)
	: hWnd(hwnd), clientSize{ width, height }, lastMoveTime(steady_clock::now()),
	hInst(hInstance), moveMgr(Move::MoveManager(key, playerRc))
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
	// 이동을 위한 업데이트 
	moveMgr.MoveUpdate();
	
	bool ismoving = moveMgr.IsMoving(); 
	auto now = steady_clock::now(); 

	auto elapsed = duration_cast<seconds> (now - lastMoveTime).count(); 
	
		ProgressAnimationKey();
	
	
	

	
}

void Render::RenderScene(HINSTANCE hInst)
{
	Time::UpdateTime();

	memDC = swap->GetMemDC();
	graphics = new Gdiplus::Graphics(memDC);

	// 화면 초기화 (배경을 흰색으로 채우기)
	PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);

	animation->Render(memDC, playerRc, graphics, 0, 0, current_frame);

	// 스왑 메모리 DC에 복사 (swap 내부 메모리 DC를 가져오는 메소드 필요)
	swap->SwapBuffers();

}

void Render::Moves()
{
	if (current_state == PLAYER_DEFAULT) return;
	
	auto now = steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastMoveTime);
	

}
void  Render::ProgressAnimationKey()
{
	if (key.IsKeyDown(VK_RIGHT))
	{

		SetAnimationState(PLAYER_RIGHTWALK);
	}
	else if (key.IsKeyDown(VK_LEFT))
	{
		SetAnimationState(PLAYER_LEFTWALK);
	}
	else if (key.IsKeyDown(VK_DOWN))
	{
		SetAnimationState(PLAYER_DOWNWALK);
	}
	else if (key.IsKeyDown(VK_UP))
	{
		SetAnimationState(PLAYER_UPWALK);
	}
}

POINT Render::GetBufferSize() const
{
	return clientSize;
}



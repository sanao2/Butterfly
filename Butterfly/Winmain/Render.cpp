#include "Render.h"
using namespace Input;


Render::Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height)
	: hWnd(hwnd), clientSize{ width, height }, lastMoveTime(steady_clock::now()),
	hInst(hInstance), playerController(key), moveMgr(new Move::MoveManager(key, playerRect))
{
	swap = new Swap(hwnd, width, height);
	animation = new Animation(drawDC, hInstance);
}

Render::~Render()
{
	DeleteDC(memDC);
	delete moveMgr; 
	delete graphics;
	delete animation;
	delete swap;
}

void Render::Update()
{
	// 이동을 위한 업데이트 
	moveMgr->MoveUpdate();

	bool ismoving = moveMgr->IsMoving(); 
	auto now = steady_clock::now(); 

	auto elapsed = duration_cast<seconds> (now - lastMoveTime).count(); 

	if (ismoving) {
		lastMoveTime = now;   // 타이머 리셋

		if(key.IsKeyDown(VK_DOWN) && elapsed < 1)
		{
			SetAnimationState(PLAYER_DOWNWALK);
		}
		if (key.IsKeyDown(VK_RIGHT) && elapsed < 1)
		{
			SetAnimationState(PLAYER_RIGHTWALK);
		}
		if (key.IsKeyDown(VK_LEFT) && elapsed < 1)
		{
			SetAnimationState(PLAYER_LEFTWALK);
		}
		if (key.IsKeyDown(VK_UP) && elapsed < 1)
		{
			SetAnimationState(PLAYER_UPWALK);
		}
		animation->Update();
	}
}

void Render::RenderScene(HINSTANCE hInst)
{
	Time::UpdateTime();

	memDC = swap->GetMemDC();
	graphics = new Gdiplus::Graphics(memDC);

	// 화면 초기화 (배경을 흰색으로 채우기)
	PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);

	animation->Render(memDC, playerRect, graphics, 0, 0, current_frame);

	// 스왑 메모리 DC에 복사 (swap 내부 메모리 DC를 가져오는 메소드 필요)
	swap->SwapBuffers();

}

void Render::Moves()
{
	if (current_state == PLAYER_DEFAULT) return;
	
	auto now = steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastMoveTime);
	
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



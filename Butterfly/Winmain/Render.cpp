#include "Render.h"
using namespace Input;


Render::Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height)
	: hWnd(hwnd), clientSize{ width, height }, hInst(hInstance), moveMgr(new Move::MoveManager(key, playerRc))
{
	swap = new Swap(hwnd, width, height);
	animation = new Animation(drawDC, hInstance);
	object = new Map::Object(drawDC, hInstance);

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
	moveMgr->MoveUpdate();
	animation->Update();

}

void Render::RenderScene(HINSTANCE hInst)
{
	Time::UpdateTime();

	memDC = swap->GetMemDC();
	graphics = new Gdiplus::Graphics(memDC);

	// ȭ�� �ʱ�ȭ (����� ������� ä���)
	PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);

	//animation->Render(memDC, graphics, 0, 0, current_frame);
	Gdiplus::Rect rc = { 10,10,10,10 };

	// Object 
	object->MapLoop(*graphics);

	animation->Render(memDC, graphics, playerRc.left, playerRc.top, current_frame);

	// ���� �޸� DC�� ���� (swap ���� �޸� DC�� �������� �޼ҵ� �ʿ�)
	swap->SwapBuffers();

}


POINT Render::GetBufferSize() const
{
	return clientSize;
}

void Render::PlayerAnimationkeyInput()
{
	auto now = steady_clock::now();
	auto elapsed = duration_cast<seconds> (now - lastMoveTime).count();

	//  Ű �Է����� ���� ���� ����
	Animstate newState = current_state;
	if (key.IsKeyDown(VK_RIGHT))
	{
		newState = PLAYER_RIGHTWALK;
	}
	else if (key.IsKeyDown(VK_LEFT))
	{
		newState = PLAYER_LEFTWALK;
	}
	else if (key.IsKeyDown(VK_DOWN))
	{
		newState = PLAYER_DOWNWALK;
	}
	else if (key.IsKeyDown(VK_UP))
	{
		newState = PLAYER_UPWALK;
	}
	else if (elapsed >= 1.0f) {
		newState = PLAYER_DEFAULT;
	}
	else  return;


	// ���°� ����Ǿ��� ���� ��ȯ
	if (newState != current_state)
	{
		ResourceManager* resManager = animation->GetResourceManager();

		for (auto img : resManager->AnimationFrames) {
			delete img;
		}
		resManager->AnimationFrames.clear();

		resManager->SetIsLoaded(false);
		resManager->LoadeFrames(hInst);

		current_frame = 0;
		current_state = newState;
		timer.Reset();
	};
}

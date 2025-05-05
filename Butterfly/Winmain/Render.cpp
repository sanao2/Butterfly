#include "Render.h"
using namespace Input;


Render::Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height)
	: hWnd(hwnd), clientSize{ width, height }, hInst(hInstance), moveMgr(new Move::MoveManager(key, playerrect))
{
	swap = new Swap(hwnd, width, height);
	animation = new Animation(drawDC, hInstance);
	object = new Map::Object(drawDC, hInstance);
	collider = new Collider(); 
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
	memDC = swap->GetMemDC();
	graphics = new Gdiplus::Graphics(memDC);

	// ȭ�� �ʱ�ȭ (����� ������� ä���)
	PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);

	// Object 
	object->MapLoop(*graphics);
	auto floors = object->GetfloorsRects();


	bool onPath = false; 

	for (auto& path : floors)
	{
		if (playerrect.IntersectsWith(path))
		{
			onPath = true; 
			break; 
		}
	}

	if (collider->IsCompleteOffPath(playerrect, floors)) {
		// ���� �� �� �� ���� ��ġ�� ����
		int width = playerrect.Width; 
		int hegiht = playerrect.Height;
		
		playerrect.X = 0;
		playerrect.Y = 0;
	}

	animation->Render(memDC, graphics,playerrect.X, playerrect.Y, current_frame);

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

	};
}

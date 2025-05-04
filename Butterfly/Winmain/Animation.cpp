#include "Animation.h"
using namespace Move;
int current_frame = 0;

Animation::Animation(HDC drawDC, HINSTANCE hInstance) 	: moveMgr( Move::MoveManager(key, playerRc)), lastMoveTime(steady_clock::now())
{
    resManager = new ResourceManager(drawDC, hInstance);
    resManager->LoadeFrames(hInstance);
 
}

Animation::~Animation()
{
    delete resManager;
}

void Animation::Update()
{
    // �̵��� ���� ������Ʈ 
    moveMgr.MoveUpdate();
    
   if (timer.IsElapsed(frameInterval)) {
       timer.Reset();
       current_frame = (current_frame + 1) % resManager->AnimationFrames.size(); // ������ ������Ʈ
   }
   bool ismoving = moveMgr.IsMoving();
   auto now = steady_clock::now();

   auto elapsed = duration_cast<seconds> (now - lastMoveTime).count();
}

void Animation::Render(HDC drawDC, RECT& rect, Gdiplus::Graphics* graphics, int x, int y, int curFrameIndex)
{
    resManager->RenderFrame(graphics, rect, x, y, curFrameIndex); // ���� �������� �׸���
}

void Animation::Changestate(Animstate newState, HINSTANCE hInstance)
{
    SetPrevAnimationState(GetcurrentAnimationState()); 

    SetAnimationState(newState); // currentAnimstate Setting 

    for (auto image : resManager->AnimationFrames) {
        delete image; 
    }

    resManager->AnimationFrames.clear(); 
    resManager->SetIsLoaded(false); 

    resManager->LoadeFrames(hInstance); 
    lastReload = steady_clock::now(); 
    timer.Reset(); 

   
}
void  Animation::PlayerAnimationkeyInput()
{
	//  Ű �Է����� ���� ���� ����
	Animstate newState = current_state;
	if (key.IsKeyDown(VK_RIGHT))	  newState = PLAYER_RIGHTWALK;
	else if (key.IsKeyDown(VK_LEFT))  newState = PLAYER_LEFTWALK;
	else if (key.IsKeyDown(VK_DOWN))  newState = PLAYER_DOWNWALK;
	else if (key.IsKeyDown(VK_UP))    newState = PLAYER_UPWALK;
	else                              newState = PLAYER_DEFAULT;

	// ���°� ����Ǿ��� ���� ��ȯ
	if (newState != current_state)
	{		
		for (auto img : resManager->AnimationFrames) {
			POINT     playerRcPos = { img->GetWidth(), img->GetHeight() };
			delete img;
		}
		resManager->AnimationFrames.clear();

		resManager->SetIsLoaded(false);
		resManager->LoadeFrames(hInstance);

		current_frame = 0;
		current_state = newState;
	};
}
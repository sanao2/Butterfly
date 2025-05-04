#include "Animation.h"
int current_frame = 0;

Animation::Animation(HDC drawDC, HINSTANCE hInstance) 	: hInstance(hInstance),  
		lastMoveTime(steady_clock::now()), moveMgr(new Move::MoveManager(key, playerRc))
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
	// 이동을 위한 업데이트 
	moveMgr->MoveUpdate();
		   
   if (timer.IsElapsed(frameInterval)) {
       timer.Reset();
       current_frame = (current_frame + 1) % resManager->AnimationFrames.size(); // 프레임 업데이트
   }

   bool ismoving = moveMgr->IsMoving();
   auto now = steady_clock::now();

   auto elapsed = duration_cast<seconds> (now - lastMoveTime).count();

   PlayerAnimationkeyInput();
}

void Animation::Render(HDC drawDC, RECT& rect, Gdiplus::Graphics* graphics, int x, int y, int curFrameIndex)
{
    resManager->RenderFrame(graphics, rect, x, y, curFrameIndex); // 현재 프레임을 그리기
}

void Animation::PlayerAnimationkeyInput()
{

	//  키 입력으로 다음 상태 결정
	Animstate newState = current_state;

	if (key.IsKeyDown(VK_RIGHT))	  newState = PLAYER_RIGHTWALK;
	else if (key.IsKeyDown(VK_LEFT))  newState = PLAYER_LEFTWALK;
	else if (key.IsKeyDown(VK_DOWN))  newState = PLAYER_DOWNWALK;
	else if (key.IsKeyDown(VK_UP))    newState = PLAYER_UPWALK;
	else                              newState = PLAYER_DEFAULT;

	// 상태가 변경되었을 때만 교환
	if (newState != current_state)
	{
		ResourceManager* resManager = GetResourceManager();
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

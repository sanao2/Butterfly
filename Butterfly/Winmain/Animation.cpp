#include "Animation.h"
int current_frame = 0;

Animation* g_pPlayeranimation = nullptr;

Animation::Animation(HDC drawDC, HINSTANCE hInstance) : hInstance(hInstance)
{
	g_pPlayeranimation = this;
	resManager = new ResourceManager(drawDC, hInstance);
	resManager->LoadeFrames(hInstance);
<<<<<<< HEAD

=======
	Time::InitTime(); // Timer start  Initialization  
>>>>>>> 5f00e2ed61ee77d6d5d1cb1ef5eeb9a29ab30afa
}

Animation::~Animation()
{
<<<<<<< HEAD
=======
	timer.Reset(); 
>>>>>>> 5f00e2ed61ee77d6d5d1cb1ef5eeb9a29ab30afa
	delete resManager;
}

void Animation::Update()
{
<<<<<<< HEAD
=======
	Time::UpdateTime();
	
	// moveMgr->MoveUpdate();
>>>>>>> 5f00e2ed61ee77d6d5d1cb1ef5eeb9a29ab30afa
	if (timer.IsElapsed(frameInterval)) {
		timer.Reset();

		current_frame = (current_frame + 1) % resManager->AnimationFrames.size(); // 프레임 업데이트
	}

}

void Animation::Render(HDC drawDC, Gdiplus::Graphics* graphics, int x, int y, int curFrameIndex)
{
	resManager->RenderFrame(graphics, x, y, curFrameIndex); // 현재 프레임을 그리기
}


//void Changestate(Animstate newState, HINSTANCE hInstance)
//{
//    SetPrevAnimationState(GetcurrentAnimationState()); 
//
//    SetAnimationState(newState); // currentAnimstate Setting 
//	ResourceManager* 
//    for (auto image : resManager->AnimationFrames) {
//        delete image; 
//    }
//
//    resManager->AnimationFrames.clear(); 
//    resManager->SetIsLoaded(false); 
//
//    resManager->LoadeFrames(hInstance); 
//    lastReload = steady_clock::now(); 
//    timer.Reset(); 
//
//   
//}

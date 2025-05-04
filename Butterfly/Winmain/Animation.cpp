#include "Animation.h"
int current_frame = 0;

Animation::Animation(HDC drawDC, HINSTANCE hInstance) 	
	: hInstance(hInstance)
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
    
    
   if (timer.IsElapsed(frameInterval)) {
       timer.Reset();
       current_frame = (current_frame + 1) % resManager->AnimationFrames.size(); // 프레임 업데이트
   }

}

void Animation::Render(HDC drawDC, RECT& rect, Gdiplus::Graphics* graphics, int x, int y, int curFrameIndex)
{
    resManager->RenderFrame(graphics, rect, x, y, curFrameIndex); // 현재 프레임을 그리기
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

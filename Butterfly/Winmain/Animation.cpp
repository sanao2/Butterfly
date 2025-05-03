#include "Animation.h"

int current_frame = 0;

Animation::Animation(HDC drawDC, HINSTANCE hInstance) : hInst(hInstance)
{
	Initialize(drawDC);
	LoadeFrames(hInstance); // 애니메이션 프레임 로드 	

}

Animation::~Animation()
{
}

void Animation::Update()
{
    if (timer.IsElapsed(frameInterval)) {
		timer.Reset(); 
		current_frame = (current_frame + 1) % this->AnimationFrames.size(); // 프레임 업데이트
    }	
}

void Animation::Render(HDC drawDC, Gdiplus::Graphics* graphics, int x, int y, int curFrameIndex)
{
	this->RenderFrame(graphics, x, y, curFrameIndex); // 현재 프레임을 그리기 	
}

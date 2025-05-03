#include "Animation.h"

Animation::Animation(HDC drawDC, HINSTANCE hInstance) : hInst(hInstance), current_frame(0)
{
	this->Initialize(drawDC, hInstance); // 리소스 매니저 초기화
	LoadeFrames(hInstance); // 애니메이션 프레임 로드 	

}

Animation::~Animation()
{
	/*if (graphics)
	{
		delete graphics;
		graphics = nullptr;
	}*/
	
}

void Animation::Update(int framecurrentIndex)
{
    if (timer.IsElapsed(frameInterval)) {
    	
		framecurrentIndex = (framecurrentIndex + 1) % this->AnimationFrames.size(); // 프레임 업데이트
    }	
}

void Animation::Render(HDC drawDC, Gdiplus::Graphics* graphics, int x, int y, int curFrameIndex)
{
	graphics->Clear(Gdiplus::Color::White); // 배경을 흰색으로 초기화
	
			// 애니메이션 프레임을 그리기 
	this->RenderFrame(graphics, x, y, curFrameIndex); // 현재 프레임을 그리기 	

}

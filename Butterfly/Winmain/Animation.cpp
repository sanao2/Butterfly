#include "Animation.h"

Animation::Animation(HDC drawDC, HINSTANCE hInstance) : hInst(hInstance), current_frame(0)
{
	this->Initialize(drawDC, hInstance); // 리소스 매니저 초기화
	LoadeFrames(hInstance); // 애니메이션 프레임 로드 	
	timer.Reset();
}

Animation::~Animation()
{
	/*if (graphics)
	{
		delete graphics;
		graphics = nullptr;
	}*/
	
}

void Animation::Update()
{
    if (timer.IsElapsed(frameInterval)) {
    	
		if (this->AnimationFrames.size() > 0)
		{
			current_frame = (current_frame + 1) % this->AnimationFrames.size(); // 프레임 업데이트
		}  	
		timer.Reset();
    }	
}

void Animation::Render(HDC drawDC, Gdiplus::Graphics* graphics, int x, int y)
{
	graphics->Clear(Gdiplus::Color::White); // 배경을 흰색으로 초기화
	
		// 애니메이션 프레임을 그리기 
	this->RenderFrame(graphics, x, y, current_frame); // 현재 프레임을 그리기 	

}

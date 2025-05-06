#include "Animation.h"
int current_frame = 0;

Animation* g_pPlayeranimation = nullptr;

Animation::Animation(HDC drawDC, HINSTANCE hInstance) : hInstance(hInstance)
{
	g_pPlayeranimation = this;
	resManager = new ResourceManager(drawDC, hInstance);
	resManager->LoadeFrames(hInstance);
	Time::InitTime(); // Timer start  Initialization  
}

Animation::~Animation()
{
	timer.Reset();
	delete resManager;
}

void Animation::Update()
{
	Time::UpdateTime();
	if (timer.IsElapsed(frameInterval)) {
		timer.Reset();

		current_frame = (current_frame + 1) % resManager->AnimationFrames.size(); // 프레임 업데이트
	}

}

void Animation::Render(HDC drawDC, Gdiplus::Graphics* graphics, int x, int y, int curFrameIndex)
{
	resManager->RenderFrame(graphics, x, y, curFrameIndex); // 현재 프레임을 그리기
}


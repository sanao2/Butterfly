#include "Animation.h"
using namespace Move;
int current_frame = 0;

Animation::Animation(HDC drawDC, HINSTANCE hInstance)
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

void Animation::Render(HDC drawDC, Gdiplus::Graphics* graphics, int x, int y, int curFrameIndex)
{
    resManager->RenderFrame(graphics, x, y, curFrameIndex); // 현재 프레임을 그리기
}
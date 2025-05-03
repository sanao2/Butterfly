#include "Animation.h"

int current_frame = 0;

Animation::Animation(HDC drawDC, HINSTANCE hInstance)
{
    resManager.LoadeFrames(hInstance);
}

Animation::~Animation()
{
    delete resManager;
}

void Animation::Update()
{
   if (timer.IsElapsed(frameInterval)) {
       timer.Reset();
       current_frame = (current_frame + 1) % this->AnimationFrames.size(); // ������ ������Ʈ
   }
}

void Animation::Render(HDC drawDC, Gdiplus::Graphics* graphics, int x, int y, int curFrameIndex)
{
   this->RenderFrame(graphics, x, y, curFrameIndex); // ���� �������� �׸���
}

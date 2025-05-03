#include "Animation.h"

int current_frame = 0;

Animation::Animation(HDC drawDC, HINSTANCE hInstance) : hInst(hInstance)
{
	this->Initialize(drawDC, hInstance); // ���ҽ� �Ŵ��� �ʱ�ȭ
	LoadeFrames(hInstance); // �ִϸ��̼� ������ �ε� 	

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
	
		current_frame = (current_frame + 1) % this->AnimationFrames.size(); // ������ ������Ʈ
    }	
}

void Animation::Render(HDC drawDC, Gdiplus::Graphics* graphics, int x, int y, int curFrameIndex)
{
	this->RenderFrame(graphics, x, y, curFrameIndex); // ���� �������� �׸��� 	
}

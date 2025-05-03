#include "Animation.h"

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
	graphics->Clear(Gdiplus::Color::White); // ����� ������� �ʱ�ȭ
	
	// �ִϸ��̼� �������� �׸��� 
	for (curFrameIndex; curFrameIndex < AnimationFrames.size(); ++curFrameIndex)
	{
		this->RenderFrame(graphics, x, y, curFrameIndex); // ���� �������� �׸��� 	

	}

}

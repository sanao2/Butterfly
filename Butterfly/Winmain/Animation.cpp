#include "Animation.h"

Animation::Animation(HDC drawDC, HINSTANCE hInstance) : hInst(hInstance), current_frame(0)
{
	this->Initialize(drawDC, hInstance); // ���ҽ� �Ŵ��� �ʱ�ȭ
	LoadeFrames(hInstance); // �ִϸ��̼� ������ �ε� 	
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
			current_frame = (current_frame + 1) % this->AnimationFrames.size(); // ������ ������Ʈ
		}  	
		timer.Reset();
    }	
}

void Animation::Render(HDC drawDC, Gdiplus::Graphics* graphics, int x, int y)
{
	graphics->Clear(Gdiplus::Color::White); // ����� ������� �ʱ�ȭ
	
		// �ִϸ��̼� �������� �׸��� 
	this->RenderFrame(graphics, x, y, current_frame); // ���� �������� �׸��� 	

}

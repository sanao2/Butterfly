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
	float totaltime = Time::GetTotalTime(); 

    timer.Elapsed(); 
    
    if (timer.IsElapsed(frameInterval)) {
    	
    	current_frame = (current_frame + 1) % this->AnimationFrames.size(); // ������ ������Ʈ
    	timer.Reset();
    }
}

void Animation::Render(Gdiplus::Graphics* graphics, int x, int y)
{
	PatBlt(graphics->GetHDC(), 0, 0, g_width, g_height, WHITENESS); // ȭ�� �ʱ�ȭ 

		// �ִϸ��̼� �������� �׸��� 
	this->RenderFrame(graphics, x, y, current_frame); // ���� �������� �׸��� 	

}

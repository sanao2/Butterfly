#include "Animation.h"

Animation::Animation(HDC drawDC, HINSTANCE hInstance) : hInst(hInstance), current_frame(0)
{
	//graphics = new Gdiplus::Graphics(drawDC);
	//ResMgr = new ResourceManager(drawDC, hInstance); // ���ҽ� �Ŵ��� ��ü ���� 	
	this->Initialize(drawDC, hInstance); // ���ҽ� �Ŵ��� �ʱ�ȭ
	LoadeFrames(hInstance); // �ִϸ��̼� ������ �ε� 
	
	timer.Elapsed();
}

Animation::~Animation()
{
	if (graphics)
	{
		delete graphics;
		graphics = nullptr;
	}
	
	//Gdiplus::GdiplusShutdown(GdiPlusToken);
}

void Animation::Update()
{
	float totaltime = Time::GetTotalTime(); 

	for(; totaltime >= frameTime;)
	{
			

		if (timer.IsElapsed(5.0f)) {
			
			frameTime = (frameTime + 1) % this->AnimationFrames.size(); // ������ ������Ʈ
			timer.Reset();
		}
	} 

}

void Animation::Render(Gdiplus::Graphics* graphics, int x, int y)
{
	PatBlt(graphics->GetHDC(), 0, 0, g_width, g_height, WHITENESS); // ȭ�� �ʱ�ȭ 

		// �ִϸ��̼� �������� �׸��� 
	this->RenderFrame(graphics, x, y, current_frame); // ���� �������� �׸��� 	

}

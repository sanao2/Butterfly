#include "Animation.h"

Animation::Animation(HDC drawDC, HINSTANCE hInstance) : hInst(hInstance), current_frame(0)
{
	//graphics = new Gdiplus::Graphics(drawDC);
	//ResMgr = new ResourceManager(drawDC, hInstance); // ���ҽ� �Ŵ��� ��ü ���� 
	
	this->Initialize(drawDC, hInstance); // ���ҽ� �Ŵ��� �ʱ�ȭ
	LoadeFrames(hInstance); // �ִϸ��̼� ������ �ε� 
	timer.Reset(); 
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
	Time::Duration frameInterval = Time::Duration(0.5f); // 0.5�� �������� �ִϸ��̼� ������Ʈ 
	Time::TimePoint lastTime = Time::Clock::now();
	
	float totaltime = Time::GetTotalTime(); 
	int frameTime = 0; 

	for(; totaltime >= frameTime;)
	{
		Time::TimePoint currentTime = Time::Clock::now(); 
		float deltaTime = Time::GetDeltaTime();

		lastTime = currentTime; // ������ �ð� ������Ʈ 
		totaltime += deltaTime; 

		if (totaltime >= frameInterval.count()) {
			timer.Reset(); 
			frameTime = (frameTime + 1) % this->AnimationFrames.size(); // ������ ������Ʈ
		}
	} 

}

void Animation::Render(Gdiplus::Graphics* graphics, int x, int y)
{
	PatBlt(graphics->GetHDC(), 0, 0, g_width, g_height, WHITENESS); // ȭ�� �ʱ�ȭ 

		// �ִϸ��̼� �������� �׸��� 
	this->RenderFrame(graphics, x, y, current_frame); // ���� �������� �׸��� 	

}

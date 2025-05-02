#include "Animation.h"

Animation::Animation(HDC drawDC, HINSTANCE hInstance) : hInst(hInstance), current_frame(0)
{
	//graphics = new Gdiplus::Graphics(drawDC);
	//ResMgr = new ResourceManager(drawDC, hInstance); // 리소스 매니저 객체 생성 
	
	this->Initialize(drawDC, hInstance); // 리소스 매니저 초기화
	LoadeFrames(hInstance); // 애니메이션 프레임 로드 
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
	Time::Duration frameInterval = Time::Duration(0.5f); // 0.5초 간격으로 애니메이션 업데이트 
	Time::TimePoint lastTime = Time::Clock::now();
	
	float totaltime = Time::GetTotalTime(); 
	int frameTime = 0; 

	for(; totaltime >= frameTime;)
	{
		Time::TimePoint currentTime = Time::Clock::now(); 
		float deltaTime = Time::GetDeltaTime();

		lastTime = currentTime; // 마지막 시간 업데이트 
		totaltime += deltaTime; 

		if (totaltime >= frameInterval.count()) {
			timer.Reset(); 
			frameTime = (frameTime + 1) % this->AnimationFrames.size(); // 프레임 업데이트
		}
	} 

}

void Animation::Render(Gdiplus::Graphics* graphics, int x, int y)
{
	PatBlt(graphics->GetHDC(), 0, 0, g_width, g_height, WHITENESS); // 화면 초기화 

		// 애니메이션 프레임을 그리기 
	this->RenderFrame(graphics, x, y, current_frame); // 현재 프레임을 그리기 	

}

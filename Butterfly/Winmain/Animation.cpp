#include "Animation.h"
////#include "Animation.h"
////
////Animstate Animation::currAnim;
////Animstate Animation::prevAnim;
////
////Animation::Animation(HWND hwnd, int width, int height)
////{
////    clientDC = GetDC(hwnd);
////   
////    Gdiplus::GdiplusStartupInput gsi;
////    Gdiplus::GdiplusStartup(&GdiplusToken, &gsi, nullptr);
////    backDCgraphics = new Gdiplus::Graphics(memDC);
////    Image = nullptr;
////    timer.Elapsed();
////}
////
////Animation::~Animation()
////{
////    if (Image)
////    {
////        Image = nullptr;
////    }
////    if (backDCgraphics)
////    {
////        delete backDCgraphics;
////        backDCgraphics = nullptr;
////    }
////    if (hBitmap)
////    {
////        DeleteObject(hBitmap);
////        hBitmap = nullptr;
////    }
////    if (memDC)
////    {
////        DeleteDC(memDC);
////        memDC = nullptr;
////    }
////    Gdiplus::GdiplusShutdown(GdiplusToken);
////}
////
////void Animation::createAnimation(HINSTANCE hInst, float frameTime)
////{
////    this->hInst = hInst;
////    this->frameTime = frameTime;
////
////    // 리소스 매니저를 통해 이미지 로드
////
////    ResMgr->LoadImages(hInst); // 리소스 매니저를 통해 이미지 로드 
////
////}
////
////void Animation::Update()
////{
////
////    DeltaTime = timer.Elapsed();
////    TotalTime += DeltaTime;
////
////    try {
////    if (TotalTime >= frameTime)
////    {
////        frameCount++;
////        TotalTime = 0.0f;
////      
////        auto it = AnimStateFrameMap.find(currAnim);
////        if (it == AnimStateFrameMap.end()) {
////            // 키가 없으면 건너뛰거나 기본값 처리
////            return; 
////        }
////        size_t frameSize = it->second.ImageID.size();
////		if (frameCount >= frameSize)
////		{
////			frameCount = 0;
////		}
////      
////	}
////    for (int i = 0; i < frameCount; ++i)
////    {
////        RESOURCE_ID[i] = GetAnimationFrameID(currAnim, frameCount);
////    }	
////  
////	Image = ResMgr->GetIamge();	
////    ResMgr->SetImage(Image); // Set Image 
////
////	if (Image == nullptr)
////	{
////		std::cerr << "Failed to get image." << std::endl;
////		return;
////	}
////
////    timer.Reset();
////    }
////    catch (const std::exception& e) {
////        std::cerr << "Animation::Update 예외 발생: " << e.what() << std::endl;
////    }
////    catch (...) {
////        std::cerr << "Animation::Update 알 수 없는 예외 발생" << std::endl;
////    }
////}
////
////void Animation::Render(HDC drawDC)
////{	
////
////    ResMgr->RenderImage(*backDCgraphics, 0, 0); // 이미지를 그리기 
//// 
////}


Animation::Animation(HDC drawDC, HINSTANCE hInstance) : hInst(hInstance), current_frame(0)
{
	//graphics = new Gdiplus::Graphics(drawDC);
	//ResMgr = new ResourceManager(drawDC, hInstance); // 리소스 매니저 객체 생성 
	LoadeFrames(hInstance); // 애니메이션 프레임 로드 

	timer.Elapsed(); 
}

Animation::~Animation()
{
	/*if (graphics)
	{
		delete graphics;
		graphics = nullptr;
	}*/
	
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
			frameTime = (frameTime + 1) % AnimationFrames.size(); // 프레임 업데이트
		}
	} 

}

void Animation::Render(Gdiplus::Graphics* graphics, int x, int y)
{
	RenderFrame(graphics, x, y, current_frame); // 현재 프레임을 그리기 
}

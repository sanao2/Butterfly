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
////    // ���ҽ� �Ŵ����� ���� �̹��� �ε�
////
////    ResMgr->LoadImages(hInst); // ���ҽ� �Ŵ����� ���� �̹��� �ε� 
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
////            // Ű�� ������ �ǳʶٰų� �⺻�� ó��
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
////        std::cerr << "Animation::Update ���� �߻�: " << e.what() << std::endl;
////    }
////    catch (...) {
////        std::cerr << "Animation::Update �� �� ���� ���� �߻�" << std::endl;
////    }
////}
////
////void Animation::Render(HDC drawDC)
////{	
////
////    ResMgr->RenderImage(*backDCgraphics, 0, 0); // �̹����� �׸��� 
//// 
////}


Animation::Animation(HDC drawDC, HINSTANCE hInstance) : hInst(hInstance), current_frame(0)
{
	//graphics = new Gdiplus::Graphics(drawDC);
	//ResMgr = new ResourceManager(drawDC, hInstance); // ���ҽ� �Ŵ��� ��ü ���� 
	LoadeFrames(hInstance); // �ִϸ��̼� ������ �ε� 

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
			frameTime = (frameTime + 1) % AnimationFrames.size(); // ������ ������Ʈ
		}
	} 

}

void Animation::Render(Gdiplus::Graphics* graphics, int x, int y)
{
	RenderFrame(graphics, x, y, current_frame); // ���� �������� �׸��� 
}

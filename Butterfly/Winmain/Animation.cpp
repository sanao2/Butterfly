#include "Animation.h"
//#include "Animation.h"
//
//Animstate Animation::currAnim;
//Animstate Animation::prevAnim;
//
//Animation::Animation(HWND hwnd, int width, int height)
//{
//    clientDC = GetDC(hwnd);
//   
//    Gdiplus::GdiplusStartupInput gsi;
//    Gdiplus::GdiplusStartup(&GdiplusToken, &gsi, nullptr);
//    backDCgraphics = new Gdiplus::Graphics(memDC);
//    Image = nullptr;
//    timer.Elapsed();
//}
//
//Animation::~Animation()
//{
//    if (Image)
//    {
//        Image = nullptr;
//    }
//    if (backDCgraphics)
//    {
//        delete backDCgraphics;
//        backDCgraphics = nullptr;
//    }
//    if (hBitmap)
//    {
//        DeleteObject(hBitmap);
//        hBitmap = nullptr;
//    }
//    if (memDC)
//    {
//        DeleteDC(memDC);
//        memDC = nullptr;
//    }
//    Gdiplus::GdiplusShutdown(GdiplusToken);
//}
//
//void Animation::createAnimation(HINSTANCE hInst, float frameTime)
//{
//    this->hInst = hInst;
//    this->frameTime = frameTime;
//
//    // 리소스 매니저를 통해 이미지 로드
//
//    ResMgr->LoadImages(hInst); // 리소스 매니저를 통해 이미지 로드 
//
//}
//
//void Animation::Update()
//{
//
//    DeltaTime = timer.Elapsed();
//    TotalTime += DeltaTime;
//
//    try {
//    if (TotalTime >= frameTime)
//    {
//        frameCount++;
//        TotalTime = 0.0f;
//      
//        auto it = AnimStateFrameMap.find(currAnim);
//        if (it == AnimStateFrameMap.end()) {
//            // 키가 없으면 건너뛰거나 기본값 처리
//            return; 
//        }
//        size_t frameSize = it->second.ImageID.size();
//		if (frameCount >= frameSize)
//		{
//			frameCount = 0;
//		}
//      
//	}
//    for (int i = 0; i < frameCount; ++i)
//    {
//        RESOURCE_ID[i] = GetAnimationFrameID(currAnim, frameCount);
//    }	
//  
//	Image = ResMgr->GetIamge();	
//    ResMgr->SetImage(Image); // Set Image 
//
//	if (Image == nullptr)
//	{
//		std::cerr << "Failed to get image." << std::endl;
//		return;
//	}
//
//    timer.Reset();
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Animation::Update 예외 발생: " << e.what() << std::endl;
//    }
//    catch (...) {
//        std::cerr << "Animation::Update 알 수 없는 예외 발생" << std::endl;
//    }
//}
//
//void Animation::Render(HDC drawDC)
//{	
//
//    ResMgr->RenderImage(*backDCgraphics, 0, 0); // 이미지를 그리기 
// 
//}

Animation::Animation(HDC drawDC, HINSTANCE hInst)
{
	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&GdiPlusToken, &gsi, nullptr);
	graphics = new Gdiplus::Graphics(drawDC);
	image = nullptr;
	timer.Elapsed();

	current_state = PLAYER_DEFAULT; 
	prev_state = PLAYER_DEFAULT;

}

Animation::~Animation()
{
	if (image)
	{
		delete image;
		image = nullptr;
	}
	if (graphics)
	{
		delete graphics;
		graphics = nullptr;
	}
	
	Gdiplus::GdiplusShutdown(GdiPlusToken);
}

void Animation::loadAnimationImage()
{
}

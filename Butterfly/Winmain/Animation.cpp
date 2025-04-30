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
vector<vector<Gdiplus::Image*>, float> AnimationFrames; // Resource vector 

Animation::Animation(HDC drawDC, HINSTANCE hInst)
{
	imageResource = new ImageResource();
	imageRenderer = new GdiPlusImageRenderer(); // Correctly references the class

	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&GdiPlusToken, &gsi, nullptr);
	graphics = new Gdiplus::Graphics(drawDC);
	image = nullptr;
	timer.Elapsed();
 
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
void Animation::Update()
{
	float deltaTime = Time::GetDeltaTime(); // Get delta time 
	float totalTime = Time::GetTotalTime(); // Get total time 

	if (totalTime >= frameTime)
	{
		current_frame++;
		totalTime = 0.0f;
		auto it = AnimStateFrameMap.find(current_state);
		if (it == AnimStateFrameMap.end()) {
			return; // 키가 없으면 건너뛰거나 기본값 처리
		}
		size_t frameSize = it->second.ImageID.size();
		if (current_frame >= frameSize)
		{
			current_frame = 0;
		}

	} 

}
void Animation::LoadAnimationFrame()
{
	AnimationFrames.clear(); // Clear previous frames

	auto& frame = AnimStateFrameMap[current_state].ImageID;
	for (int id : frame)
	{
		imageResource->LoadFromResource(hInst, id, RESOURCE_TYPE);
		image = imageResource->GetBitmap();

		if (image == nullptr)
		{
			AnimationFrames[id].push_back(image);
			AnimationFrames[id])
		}
	}
}
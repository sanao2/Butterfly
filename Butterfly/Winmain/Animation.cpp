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
//    // ���ҽ� �Ŵ����� ���� �̹��� �ε�
//
//    ResMgr->LoadImages(hInst); // ���ҽ� �Ŵ����� ���� �̹��� �ε� 
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
//            // Ű�� ������ �ǳʶٰų� �⺻�� ó��
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
//        std::cerr << "Animation::Update ���� �߻�: " << e.what() << std::endl;
//    }
//    catch (...) {
//        std::cerr << "Animation::Update �� �� ���� ���� �߻�" << std::endl;
//    }
//}
//
//void Animation::Render(HDC drawDC)
//{	
//
//    ResMgr->RenderImage(*backDCgraphics, 0, 0); // �̹����� �׸��� 
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
			return; // Ű�� ������ �ǳʶٰų� �⺻�� ó��
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
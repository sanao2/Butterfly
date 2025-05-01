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


constexpr wchar_t RESOURCE_TYPE[] = L"PNG";

Animation::Animation(HDC drawDC, HINSTANCE hInstance) : hInst(hInstance)
{
	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&GdiPlusToken, &gsi, nullptr);
	graphics = new Gdiplus::Graphics(drawDC);
	imageResource = new ImageResource();
	ResMgr = new ResourceManger(hInst); 
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

void Animation::Render()
{
	for (int frameCount = 0; frameCount < AnimationFrames.size(); ++frameCount)
	{
		ResMgr->RenderFrame(graphics, 0, 0, frameCount);
	}
}

void Animation::LoadAnimationFrame(HINSTANCE hInst)
{
	const auto& frameCount = AnimStateFrameMap[current_state].ImageID.size();

	for (int i = 0; i < frameCount; ++i)
	{
		int id = GetAnimationFrameID(current_state, i); 
		if (imageResource->LoadFromResource(hInst, id, RESOURCE_TYPE))
		{
			image = imageResource->GetBitmap(); 
			AnimationFrames.push_back(image);
		}
		else
		{
			cerr << "���ҽ� �ε� ���� ID : " << id << endl; 
		}
	}
}
void Animation::RenderFrame(Gdiplus::Graphics* graphics, int x, int y, int frameIndex)
{
	for (frameIndex = 0; frameIndex < AnimationFrames.size(); ++frameIndex)
	{
		if (frameIndex < AnimationFrames.size() && AnimationFrames[frameIndex])
		{
			imageRenderer->Render(*graphics, AnimationFrames[frameIndex], x, y);
		}
		else {
			std::cerr << "�߸��� ������ �ε���: " << frameIndex << std::endl;
		}
	}

}
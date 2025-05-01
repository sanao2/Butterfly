#include "ResourceManger.h"

int RESOURCE_ID = IDB_PLAYER_DOWNWALK_IDLE; 
vector<Gdiplus::Image*> AnimationFrames;
constexpr wchar_t RESOURCE_TYPE[] = L"PNG";

ResourceManger::ResourceManger(HDC drawDC,HINSTANCE hInstance) : hInst(hInstance)
{											
	imageResource = new ImageResource();
	imageRenderer = new GdiPlusImageRenderer(); // Correctly references the class

	//// Gdiplus 초기화 
	//Gdiplus::GdiplusStartupInput gsi;
	//Gdiplus::GdiplusStartup(&GdiPlusToken, &gsi, nullptr);
	graphics = new Gdiplus::Graphics(drawDC); // GDI+ 그래픽스 객체 생성
	
}

ResourceManger::~ResourceManger()
{
	//delete image; 
	
	if (graphics) delete graphics;				// GDI+ Graphics Delete
	if (imageResource) delete imageResource;		// imageResource Delete 
	if (imageRenderer) delete imageRenderer;		// imageRenderer Delete
	//Gdiplus::GdiplusShutdown(GdiPlusToken);       // GDI+ ShoutDown
}

//void ResourceManger::LoadImages(HINSTANCE hInst)
//{
//	try {			
//
//		imageResource->LoadFromResource(hInst, RESOURCE_ID, RESOURCE_TYPE); // Load image from resource 
//	
//		
//		//image = imageResource->GetBitmap();
//		AnimationFrames.push_back(image); 
//
//		if (image == nullptr)
//		{
//			cerr << "Failed to load image resource." << endl;
//			return;
//		}
//
//	}
//	catch (const std::exception& e) {
//		std::cerr << "Error loading images: " << e.what() << std::endl;
//	}
//	if (image != nullptr)
//	{
//		cerr << "Failed to load images." << endl;
//	}
//	
//}

void ResourceManger::LoadeFrames(HINSTANCE hInst)
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
			cerr << "리소스 로드 실패 ID : " << id << endl;
		}
	}
}

//void ResourceManger::Render(Gdiplus::Graphics& graphics, int x, int y)
//{
//	imageRenderer->Render(graphics, image, x, y);
//	
//}

void ResourceManger::RenderFrame(Gdiplus::Graphics* graphics, int x, int y, int frameIndex)
{
	for (frameIndex = 0; frameIndex < AnimationFrames.size(); ++frameIndex)
	{
		if (frameIndex < AnimationFrames.size() && AnimationFrames[frameIndex])
		{
			imageRenderer->Render(*graphics, AnimationFrames[frameIndex], x, y);
		}
		else {
			std::cerr << "잘못된 프레임 인덱스: " << frameIndex << std::endl;
		}
	}

}
#include "ResourceManager.h"

int RESOURCE_ID = IDB_PLAYER_DOWNWALK_IDLE; 
constexpr wchar_t RESOURCE_TYPE[] = L"PNG";

ResourceManager::ResourceManager(HDC drawDC,HINSTANCE hInstance) : hInst(hInstance)
{											
	imageResource = new ImageResource();
	imageRenderer = new GdiPlusImageRenderer(); // Correctly references the class

	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&GdiPlusToken, &gsi, nullptr);
	
	graphics = new Gdiplus::Graphics(drawDC); // GDI+ 그래픽스 객체 생성
	AnimationFrames.clear(); // Initialize the vector 
}

ResourceManager::~ResourceManager()
{
	delete image; 

	if (graphics) delete graphics;					// GDI+ Graphics Delete
	if (imageResource) delete imageResource;		// imageResource Delete 
	if (imageRenderer) delete imageRenderer;		// imageRenderer Delete
	Gdiplus::GdiplusShutdown(GdiPlusToken);       // GDI+ ShoutDown
}

void ResourceManager::Initialize(HDC drawDC, HINSTANCE hInstance)
{
	imageResource = new ImageResource();
	imageRenderer = new GdiPlusImageRenderer(); // Correctly references the class

	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&GdiPlusToken, &gsi, nullptr);

	graphics = new Gdiplus::Graphics(drawDC); // GDI+ 그래픽스 객체 생성
	AnimationFrames.clear();  // Initialize the vector 
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

void ResourceManager::LoadeFrames(HINSTANCE hInst)
{
	if (isLoaded) return; // 이미 로드된 경우 리턴 

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
	isLoaded = true; 
}

//void ResourceManger::Render(Gdiplus::Graphics& graphics, int x, int y)
//{
//	imageRenderer->Render(graphics, image, x, y);
//	
//}

void ResourceManager::RenderFrame(Gdiplus::Graphics* graphics, int x, int y, int frameIndex)
{
	
	if (frameIndex < 0 && frameIndex <= AnimationFrames.size())
	{
		for (frameIndex = 0; frameIndex < AnimationFrames.size(); ++frameIndex)
		{
			imageRenderer->Render(*graphics, AnimationFrames[frameIndex], x, y);
		}
	}
	else {
		std::cerr << "잘못된 프레임 인덱스: " << frameIndex << std::endl;
	}
	

}
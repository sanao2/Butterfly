#include "ResourceManager.h"
constexpr wchar_t RESOURCE_TYPE[] = L"PNG";

ResourceManager::ResourceManager(HDC drawDC,HINSTANCE hInstance) : hInst(hInstance)
{											
	imageResource = new ImageResource();
	imageRenderer = new GdiPlusImageRenderer(); // Correctly references the class

	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&GdiPlusToken, &gsi, nullptr);
	
	graphics = new Gdiplus::Graphics(drawDC); // GDI+ �׷��Ƚ� ��ü ����
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

	graphics = new Gdiplus::Graphics(drawDC); // GDI+ �׷��Ƚ� ��ü ����
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
	if (isLoaded) return; // �̹� �ε�� ��� ���� 

	Animstate currentstate = GetcurrentAnimationState(); // ���� �ִϸ��̼� ���� �������� 
	const auto& frameCount = AnimStateFrameMap[currentstate].ImageID;

	for (int i = 0; i < frameCount.size(); ++i)
	{	
		int id = GetAnimationFrameID(currentstate, i);

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
	isLoaded = true; 
}

//void ResourceManger::Render(Gdiplus::Graphics& graphics, int x, int y)
//{
//	imageRenderer->Render(graphics, image, x, y);
//	
//}

void ResourceManager::RenderFrame(Gdiplus::Graphics* graphics, int x, int y, int frameIndex)
{
	if (frameIndex < 0 || frameIndex >= AnimationFrames.size())
	{
		std::cerr << "�߸��� ������ �ε���: " << frameIndex
			<< (AnimationFrames.size() - 1) << endl;
		return;
	}
	
	auto& img = AnimationFrames[frameIndex]; 

	UINT ImgWidth = img->GetWidth();
	UINT Imgheight = img->GetHeight(); 

	imageRenderer->Render(*graphics, AnimationFrames[frameIndex],ImgWidth,Imgheight, x, y);
	
	
	isLoaded = false; 
}

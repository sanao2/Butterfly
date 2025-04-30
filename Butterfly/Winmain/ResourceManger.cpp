#include "ResourceManger.h"

vector<int> RESOURCE_ID = { 0, };
constexpr wchar_t RESOURCE_TYPE[] = L"PNG";
vector<Gdiplus::Image*> images; // Resource vector 

ResourceManger::ResourceManger(HDC drawDC, HINSTANCE hInstance,int width, int height) : hInst(hInstance)
{											
	imageResource = new ImageResource();
	imageRenderer = new GdiPlusImageRenderer(); // Correctly references the class

	// Gdiplus 초기화 
	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&GdiPlusToken, &gsi, nullptr);
	graphics = new Gdiplus::Graphics(drawDC); // GDI+ 그래픽스 객체 생성
	
	animation = new Animation(drawDC, hInstance); // 애니메이션 객체 생성);
}

ResourceManger::~ResourceManger()
{
	DeleteObject(image);
	for (auto frames : RESOURCE_ID)
	{
		RESOURCE_ID.clear(); 
	}
	if (graphics) delete graphics;				// GDI+ Graphics Delete
	if (imageResource) delete imageResource;    // imageResource Delete 
	if (imageRenderer) delete imageRenderer;    // imageRenderer Delete
	Gdiplus::GdiplusShutdown(GdiPlusToken);     // GDI+ ShoutDown
}

void ResourceManger::LoadImages(HINSTANCE hInst)
{
	try {		
		for (current_frame = 0; current_frame <= RESOURCE_ID.size(); ++current_frame)
		{
			RESOURCE_ID.push_back(GetAnimationFrameID(current_state, current_frame));
			imageResource->LoadFromResource(hInst, RESOURCE_ID[current_frame], RESOURCE_TYPE);
		}

		image = imageResource->GetBitmap();
		
		if (image == nullptr)
		{
			cerr << "Failed to load image resource." << endl;
			return;
		}

	}
	catch (const std::exception& e) {
		std::cerr << "Error loading images: " << e.what() << std::endl;
	}
	if (image != nullptr)
	{
		cerr << "Failed to load images." << endl;
	}
	
}

void ResourceManger::RenderImage(Gdiplus::Graphics& graphics, int x, int y)
{
	if (image == nullptr)
	{
		cerr << "Bitmap is null." << endl;
		return;
	} 
	imageRenderer->Render(graphics, image, x, y);
}

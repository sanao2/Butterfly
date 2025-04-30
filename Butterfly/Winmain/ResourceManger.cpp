#include "ResourceManger.h"

int current_frame = 0;
vector<int> RESOURCE_ID = { 0, };
constexpr wchar_t RESOURCE_TYPE[] = L"PNG";
vector<Gdiplus::Image*> AnimationFrames = { 0, };

ResourceManger::ResourceManger(HDC drawDC, HINSTANCE hInstance,int width, int height) : hInst(hInstance)
{											
	imageResource = new ImageResource();
	imageRenderer = new GdiPlusImageRenderer(); // Correctly references the class

	// Gdiplus 초기화 
	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&GdiPlusToken, &gsi, nullptr);
	graphics = new Gdiplus::Graphics(drawDC); // GDI+ 그래픽스 객체 생성
	
}

ResourceManger::~ResourceManger()
{
	DeleteObject(image);
	
	if (graphics) delete graphics;				// GDI+ Graphics Delete
	if (imageResource) delete imageResource;    // imageResource Delete 
	if (imageRenderer) delete imageRenderer;    // imageRenderer Delete
	Gdiplus::GdiplusShutdown(GdiPlusToken);     // GDI+ ShoutDown
}

void ResourceManger::LoadImages(HINSTANCE hInst)
{
	try {		
		// Load image from resource
		const auto& frameID = AnimStateFrameMap[current_state].ImageID; 
		for (int id : frameID)
		{
			RESOURCE_ID.push_back(id); 
			imageResource->LoadFromResource(hInst, RESOURCE_ID[id], RESOURCE_TYPE); // Load image from resource 
		}	
		
		image = imageResource->GetBitmap();
		AnimationFrames.push_back(image); 

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

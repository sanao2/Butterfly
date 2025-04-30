#include "ResourceManger.h"

vector<int> RESOURCE_ID = { 0, };
constexpr wchar_t RESOURCE_TYPE[] = L"PNG";

ResourceManger::ResourceManger(HDC drawDC, int width, int height) 
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
	
	delete imageResource;
	delete imageRenderer; 
}


void ResourceManger::LoadImages(HINSTANCE hInst)
{
try {

	for (int i = 0; i < RESOURCE_ID.size(); ++i)
	{
		if (RESOURCE_ID[i] == 0)
		{
			cerr << "Resource ID is 0." << endl;
			return;
		}
		bool Res = imageResource->LoadFromResource(hInst, RESOURCE_ID[i], RESOURCE_TYPE);
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

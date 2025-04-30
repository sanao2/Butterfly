#include "ResourceManger.h"


ResourceManger::ResourceManger(HDC drawDC, int width, int height) 
{											
	imageResource = new ImageResource();
	imageRenderer = new GdiPlusImageRenderer(); // Correctly references the class
}

ResourceManger::~ResourceManger()
{	
	DeleteObject(image);
	
	delete imageResource;
	delete imageRenderer; 
}

void ResourceManger::Initialize()
{

}

void ResourceManger::LoadImages(HINSTANCE hInst)
{
	bool Res = imageResource->LoadFromResource(hInst, RESOURCE_ID, RESOURCE_TYPE); 
	
	if (image == nullptr)
	{
		cerr << "Failed to load image resource." << endl;
		return;
	}

	image = imageResource->GetBitmap();
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

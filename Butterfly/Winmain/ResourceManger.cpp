#include "ResourceManger.h"

ResourceManger::ResourceManger(HDC drawDC, int width, int height) 
{											
	imageResource = new ImageResource();

}

ResourceManger::~ResourceManger()
{	
	DeleteObject(bitmap); 

	delete imageResource;
	delete imageRenderer; 



}

void ResourceManger::Initialize()
{
	
}

void ResourceManger::LoadImages(HINSTANCE hInst)
{
	if (bitmap == nullptr)
	{
		cerr << "Failed to load image resource." << endl;
		return;
	}

	imageResource->LoadFromResource(hInst, RESOURCE_ID, RESOURCE_TYPE); 
	bitmap = imageResource->GetBitmap(); 
	
}

void ResourceManger::RenderImage(Gdiplus::Graphics& graphics, int x, int y)
{
	if (bitmap == nullptr)
	{
		cerr << "Bitmap is null." << endl;
		return;
	} 
	imageRenderer->Render(graphics, bitmap, x, y); 
}

#include "ResourceManger.h"

ResourceManger::ResourceManger(HWND hWnd, HINSTANCE hInstance, int width, int height) 
																	: hInst(hInstance)
{
	clientDC = GetDC(hWnd); 
	memDC = CreateCompatibleDC(clientDC); 
	hBitmap = CreateCompatibleBitmap(clientDC, width, height);
	SelectObject(memDC, bitmap); 

}

ResourceManger::~ResourceManger()
{
	delete hInst; 
	DeleteObject(bitmap); 
}

void ResourceManger::Initialize()
{
	imageResource = new ImageResource();
}

void ResourceManger::LoadImages(HINSTANCE hInst)
{
	imageResource->LoadFromResource(hInst, RESOURCE_ID, RESOURCE_TYPE); 
	bitmap = imageResource->GetBitmap(); 

	if (bitmap == nullptr)
	{
		cerr << "Failed to load image resource." << endl;
		return;
	}
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

#include "ResourceManager.h"



ResourceManager::ResourceManager(HWND _hWnd,int width, int height) : hWnd(_hWnd)
{
	Gdiplus::GdiplusStartup(&GdiplusToken, &gsi, nullptr);
	backDCgraphics = Gdiplus::Graphics::FromHDC(backDC);
}

ResourceManager::~ResourceManager()
{
	DeleteDC(backDC); 
	delete backDCgraphics;
	delete ImgBitmap;
	Gdiplus::GdiplusShutdown(GdiplusToken);
}

void ResourceManager::Initialize()
{
}


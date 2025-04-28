#include "ResourceManager.h"



ResourceManager::ResourceManager(HWND _hWnd,int width, int height) : hWnd(_hWnd)
{
	clientDC = GetDC(hWnd);
	memDC = CreateCompatibleDC(clientDC); 

	Gdiplus::GdiplusStartup(&GdiplusToken, &gsi, nullptr);
	backDCgraphics = Gdiplus::Graphics::FromHDC(memDC);
}

ResourceManager::~ResourceManager()
{
	DeleteDC(memDC); 
	delete backDCgraphics;
	delete ImgBitmap;
	Gdiplus::GdiplusShutdown(GdiplusToken);
}

void ResourceManager::Initialize()
{

}


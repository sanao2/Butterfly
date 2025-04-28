#include "ResourceManager.h"



ResourceManager::ResourceManager(HWND _hWnd, HINSTANCE hIns, int width, int height) : hWnd(_hWnd), hInstance(hIns)
{
	Gdiplus::GdiplusStartup(&GdiplusToken, &gsi, nullptr);
	backDCgraphics = Gdiplus::Graphics::FromHDC(backDC);
}

ResourceManager::~ResourceManager()
{
	DeleteDC(backDC); 
	delete backDCgraphics;
	delete ImgBitmap;
	delete hInstance; 
	Gdiplus::GdiplusShutdown(GdiplusToken);
}


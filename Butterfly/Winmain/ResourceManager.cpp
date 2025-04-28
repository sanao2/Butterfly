#include "ResourceManager.h"



ResourceManager::ResourceManager(HWND _hWnd, int width, int height) : hWnd(_hWnd)
{
	clientDC = GetDC(hWnd);
	memDC = CreateCompatibleDC(clientDC);

	Gdiplus::GdiplusStartup(&GdiplusToken, &gsi, nullptr);
	backDCgraphics = Gdiplus::Graphics::FromHDC(memDC);

	clientSize = { width, height };
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

void ResourceManager::LoadImages(SpriteState SprState)
{
	for (int i = 0; i < SPRITECOUNT; ++i)
	{
		auto& path = GetResourcePath(SprState);

		if (!path.empty())
		{
			Sprites[i] = new Gdiplus::Bitmap(path.c_str()); 

			if (Sprite[i])
		}
	}
}

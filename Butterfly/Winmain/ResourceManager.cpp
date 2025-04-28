#include "ResourceManager.h"



ResourceManager::ResourceManager(HWND _hWnd, int width, int height) : hWnd(_hWnd)
{
	clientDC = GetDC(hWnd);
	memDC = CreateCompatibleDC(clientDC);
	memBitmap = CreateCompatibleBitmap(clientDC, clientSize.x, clientSize.y);
	SelectObject(memDC, memBitmap);  // memDC and memBitmap linked 

	Gdiplus::GdiplusStartup(&GdiplusToken, &gsi, nullptr);
	backDCgraphics = Gdiplus::Graphics::FromHDC(memDC);

	clientSize = { width, height };
}

ResourceManager::~ResourceManager()
{
	DeleteDC(memDC); 
	DeleteObject(memBitmap); 
	delete backDCgraphics;
	delete ImgBitmap;	
	ReleaseDC(hWnd, clientDC);
	Gdiplus::GdiplusShutdown(GdiplusToken);
}

void ResourceManager::Initialize()
{

}

void ResourceManager::Update()
{

}



void ResourceManager::LoadImages()
{
	for (int i = 0; i < SPRITECOUNT; ++i)
	{
		auto& path = GetResourcePath(static_cast<SpriteState>(i));

		if (path.empty()) return; 		

		auto& Image = new Gdiplus::Bitmap(path.c_str());

		if (Image->GetLastStatus() == Gdiplus::Ok)
		{
			Sprites[i] = Image; 
		}

		else {
			delete Image; 
			Sprites[i] = nullptr; 
		}
	}
}
void ResourceManager::SetSpriteSize(Gdiplus::Bitmap* Image) {
	int width = Image->GetWidth();
	int height = Image->GetHeight();
	SpriteSize = { width,height };
}
POINT ResourceManager::GetSpriteSize() { return SpriteSize; }
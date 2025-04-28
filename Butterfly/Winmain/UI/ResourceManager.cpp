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

void ResourceManager::Render(HDC drawDC, int x, int y, int width, int height)
{
	PatBlt(drawDC, x, y, clientSize.x, clientSize.y, WHITENESS); 

	auto& Image = Sprites[currState];

	backDCgraphics->DrawImage(Image, Gdiplus::Rect(SpritePos.x, SpritePos.y, SpriteSize.x, SpriteSize.y));
}

void ResourceManager::LoadImages()
{
	for (int i = 0; i < SPRITECOUNT; ++i)
	{
		auto& path = GetResourcePath(static_cast<SpriteState>(i));

		if (path.empty()) return; 		

		ImgBitmap = new Gdiplus::Bitmap(path.c_str());

		SetSpriteSize(ImgBitmap);

		if (ImgBitmap->GetLastStatus() == Gdiplus::Ok)
		{
			Sprites[i] = ImgBitmap;
		}
	}
}

void ResourceManager::SetSpriteSize(Gdiplus::Bitmap* Image) {
	int width = Image->GetWidth();
	int height = Image->GetHeight();

	SpriteSize = { width,height };
}
POINT ResourceManager::GetSpriteSize() { return SpriteSize; }
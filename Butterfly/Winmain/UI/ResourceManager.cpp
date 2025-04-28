#include "ResourceManager.h"

HINSTANCE* hInst = nullptr;

ResourceManager::ResourceManager(HWND _hWnd, int width, int height) : hWnd(_hWnd)
{
	clientDC = GetDC(hWnd);
	clientSize = { width, height };

	memDC = CreateCompatibleDC(clientDC);
	memBitmap = CreateCompatibleBitmap(clientDC, clientSize.x, clientSize.y);
	SelectObject(memDC, memBitmap);  // memDC and memBitmap linked 

	Gdiplus::GdiplusStartup(&GdiplusToken, &gsi, nullptr);
	backDCgraphics = Gdiplus::Graphics::FromHDC(memDC);

	
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

	auto& Image = Sprites[currSprState];

	if (Image)
	{
		backDCgraphics->DrawImage(Image, 
			Gdiplus::Rect(SpritePos.x, SpritePos.y, 
						  SpriteSize.x, SpriteSize.y));
	}

	BitBlt(drawDC, x, y, clientSize.x, clientSize.y, memDC, 0, 0, SRCCOPY);

	
}

void ResourceManager::LoadImages(HINSTANCE hInst)
{
	for (int i = 0; i < SPRITECOUNT; ++i)
	{
		auto SpriteID = GetResourcePath(currSprState);
		ImgBitmap = new Gdiplus::Bitmap(hInst, MAKEINTRESOURCE(SpriteID));

		if (ImgBitmap->GetLastStatus() == Gdiplus::Ok)
		{
			Sprites[i] = ImgBitmap; 
			SetSpriteSize(ImgBitmap); 
		}
		else
		{
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
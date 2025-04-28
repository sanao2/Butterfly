#include "ResourceManager.h"

SpriteState ResourceManager::currSprState = PLAYER_IDLE;


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
	for (auto bmp : Sprites) delete bmp;
	delete backDCgraphics;

	DeleteObject(memBitmap);
	DeleteDC(memDC);

	ReleaseDC(hWnd, clientDC);
	Gdiplus::GdiplusShutdown(GdiplusToken);
}

void ResourceManager::Update()
{
	
}

void ResourceManager::Render(HDC drawDC, int x, int y, int width, int height)
{
	backDCgraphics->Clear(WHITENESS);
	auto& Image = Sprites[currSprState];

	if (Image)
	{
		backDCgraphics->DrawImage(Image, 
			Gdiplus::Rect(SpritePos.x, SpritePos.y, 
						  SpriteSize.x, SpriteSize.y));
	}

	BitBlt(drawDC, x, y, width, height, memDC, 0, 0, SRCCOPY); // 원하는 위치에 원하는 길이로 그린다. 
}

void ResourceManager::LoadImages(HINSTANCE hInst)
{
	for (int i = 0; i < SPRITECOUNT; ++i)
	{
		auto SprID = static_cast<SpriteState>(i);
		int resId = GetResourceID(SprID);
		ImgBitmap = new Gdiplus::Bitmap(hInst, MAKEINTRESOURCE(resId));

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

void ResourceManager::SetSpriteState(SpriteState newState)
{
	if (currSprState == newState && (newState < 0 || newState >= SPRITECOUNT)) return;

	currSprState = newState; 
}

void ResourceManager::SetSpriteSize(Gdiplus::Bitmap* Image) {
	int width = Image->GetWidth();
	int height = Image->GetHeight();

	SpriteSize = { width,height };
}
POINT ResourceManager::GetSpriteSize() { return SpriteSize; }
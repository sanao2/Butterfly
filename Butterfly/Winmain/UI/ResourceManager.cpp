#include "ResourceManager.h"

SpriteState currSprState = PLAYER_IDLE;


ResourceManager::ResourceManager(HWND _hWnd, int width, int height) : hWnd(_hWnd)
{
	clientDC = GetDC(hWnd);

	memDC = CreateCompatibleDC(clientDC);
	hBitmap = CreateCompatibleBitmap(clientDC,width,height);
	SelectObject(memDC, hBitmap);  // memDC and memBitmap linked 

	Gdiplus::GdiplusStartup(&GdiplusToken, &gsi, nullptr);
	backDCgraphics = Gdiplus::Graphics::FromHDC(memDC);
		
}

ResourceManager::~ResourceManager()
{
	for (auto bmp : Sprites) delete bmp;
	delete backDCgraphics;

	DeleteObject(hBitmap);
	DeleteDC(memDC);

	ReleaseDC(hWnd, clientDC);
	Gdiplus::GdiplusShutdown(GdiplusToken);
}

void ResourceManager::Initialize()
{
	if (currSprState > 0 || currSprState <= SPRITECOUNT) return;
	
}

void ResourceManager::Update()
{

}

void ResourceManager::Render(HDC drawDC, int x, int y, int width, int height)
{
	backDCgraphics->Clear(WHITENESS);
	auto& Image = Sprites[currSprState];

	SetSpriteRect(x, y, Image); // Set Sprite Rect

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
		}
		else
		{
			Sprites[i] = nullptr;
		}
	}	
}

void ResourceManager::SetSpriteRect(int x, int y, Gdiplus::Bitmap* Image)
{
	if (currSprState < 0 || currSprState <= SPRITECOUNT) return;

	if (currSprState)
	{
		SetSpritePos(x, y);		// Set Sprite Position 
		SetSpriteSize(Image);   // Set Sprite Size
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
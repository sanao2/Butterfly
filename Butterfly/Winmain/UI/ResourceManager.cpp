#include "ResourceManager.h"


Resource::Resource(HWND hwnd, int width, int height) : hWnd(hwnd)
{
	clientDC = GetDC(hwnd); 
	memDC = CreateCompatibleDC(clientDC); // �޸� DC ���� 

	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&g_GdiPlusToken, &gsi, nullptr);
    memGraphics = Gdiplus::Graphics::FromHDC(memDC);
}

Resource::~Resource()
{
	delete Image;
	delete memGraphics;
	Gdiplus::GdiplusShutdown(g_GdiPlusToken);
}

void Resource::LoadImages(HINSTANCE hInst)
{
	
}

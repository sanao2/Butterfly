#pragma once
#include <windows.h>
#include <cstdint> 
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
#include "ImageResource.h"
#include "IImageRenderer.h"
#include "GdiplusImageRenderer.h" // Ensure this header is included
#include "resource.h"
#include <iostream>
using namespace std; 

const int RESOURCE_ID = IDB_PLAYER_DOWNWALK_IDLE; 
const wchar_t* RESOURCE_TYPE = L"PNG"; 

class ResourceManger
{
private : 
	ImageResource* imageResource = nullptr;
	IImageRenderer* imageRenderer = nullptr; 
 
	Gdiplus::Image* image = nullptr; 
	POINT ResPos = { 0, 0 }; 

	ULONG_PTR GdiPlusToken;
	HBITMAP hBitmap = nullptr;
	Gdiplus::Graphics* graphics = nullptr;

public : 
	ResourceManger(HDC drawDC,int width, int height);
	~ResourceManger();

	void Initialize(); 
	void LoadImages(HINSTANCE hInst); 
	void RenderImage(Gdiplus::Graphics& graphics, int x, int y);
};


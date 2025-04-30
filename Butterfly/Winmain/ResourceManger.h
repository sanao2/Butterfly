#pragma once
#include "Global.h"
#include "ImageResource.h"
#include "IImageRenderer.h"
#include "resource.h"
#include <iostream>
using namespace std; 

const int RESOURCE_ID = IDB_PLAYER_DOWNWALK_IDLE; 
const wchar_t* RESOURCE_TYPE = L".PNG"; 

class ResourceManger
{
private : 
	ImageResource* imageResource = nullptr;
	IImageRenderer* imageRenderer = nullptr; 
	HINSTANCE hInst = nullptr; 
	HDC clientDC = nullptr; 
	HDC memDC = nullptr; 
	HBITMAP hBitmap = nullptr; 
	Gdiplus::Bitmap* bitmap = nullptr; 
	POINT ResPos = { 0, 0 }; 

public : 
	ResourceManger(HWND hWnd, HINSTANCE hInstance, int width, int height);
	~ResourceManger();

	void Initialize(); 
	void LoadImages(HINSTANCE hInst); 
	void RenderImage(Gdiplus::Graphics& graphics, int x, int y); 
};


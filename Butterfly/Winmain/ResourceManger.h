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
#include <vector>
using namespace std; 
using std::vector;

extern vector<int> RESOURCE_ID; 
extern const wchar_t RESOURCE_TYPE[];

class ResourceManger
{
private : 
	ImageResource* imageResource = nullptr;
	IImageRenderer* imageRenderer = nullptr; 
 

	POINT ResPos = { 0, 0 }; 

	ULONG_PTR GdiPlusToken;
	HBITMAP hBitmap = nullptr;
	Gdiplus::Graphics* graphics = nullptr;
	Gdiplus::Image* image = nullptr;

public : 
	ResourceManger(HDC drawDC,int width, int height);
	~ResourceManger();

	void LoadImages(HINSTANCE hInst); 
	void RenderImage(Gdiplus::Graphics& graphics, Gdiplus::Image* image, int x, int y);

	Gdiplus::Image* GetIamge() { return image;}
	void SetImage(Gdiplus::Image* image) { this->image = image; } // Set Image 
};


#pragma once
#include <windows.h>
#include <cstdint> 
#include <gdiplus.h>
#include "AnimationMap.h"
#pragma comment(lib, "gdiplus.lib")
#include "ImageResource.h"
#include "IImageRenderer.h"
#include "GdiplusImageRenderer.h" // Ensure this header is included
#include "resource.h"
#include <iostream>
#include <vector>
#include "Animation.h"
using namespace std; 
using std::vector;

extern Animstate current_state; 
extern int RESOURCE_ID; 
extern const wchar_t RESOURCE_TYPE[];
int current_frame = 0; 
class ResourceManger
{
private : 
	ImageResource* imageResource = nullptr;
	IImageRenderer* imageRenderer = nullptr; 
	Animation* animation = nullptr; 

	HINSTANCE hInst = nullptr; 

	ULONG_PTR GdiPlusToken;
	HBITMAP hBitmap = nullptr;
	Gdiplus::Graphics* graphics = nullptr;
	Gdiplus::Image* image = nullptr;

public : 
	ResourceManger(HDC drawDC, HINSTANCE hInstance, int width, int height);
	~ResourceManger();

	void LoadImages(HINSTANCE hInst); 
	void RenderImage(Gdiplus::Graphics& graphics, int x, int y);

	Gdiplus::Image* GetIamge() { return image;}
	void SetImage(Gdiplus::Image* image) { this->image = image; } // Set Image 
};


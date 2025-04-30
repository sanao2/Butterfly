#pragma once
#include "Global.h"
#include "ImageResource.h"
#include "IImageRenderer.h"
#include <windows.h>

class ResourceManger
{
private : 
	ImageResource* imageResource = nullptr;
	IImageRenderer* imageRenderer = nullptr; 
	HINSTANCE hInst = nullptr; 

public : 
	ResourceManger(HINSTANCE hInstance);
	~ResourceManger();

	void Initialize(); 
	void LoadImages(HINSTANCE hInst); 
	void RenderImage(Gdiplus::Graphics& graphics, int x, int y); 
};


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
	Gdiplus::Bitmap* bitmap = nullptr; 
	UINT width = 0; 
	UINT height = 0; 
public : 
	ResourceManger(HINSTANCE hInstance);
	~ResourceManger();

	void Initialize(); 
	void LoadImages(HINSTANCE hInst); 
	void RenderImage(Gdiplus::Graphics& graphics, int x, int y); 
};


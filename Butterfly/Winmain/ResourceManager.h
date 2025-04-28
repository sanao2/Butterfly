#pragma once
#include <windows.h>
#include <iostream> 
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
using namespace std;

class ResourceManager
{
private : 
	HWND	hWnd = NULL;
	HDC		frontDC = NULL;	// FrontBuffer
	HDC		backDC = NULL;		// BackBuffer
	
	POINT	BitmapSize = { 0,0 }; // Bitmap size 
	POINT   BitmapPos = { 0,0 };  // Bitmap Position 

	Gdiplus::Graphics* backDCgraphics = nullptr;
	ULONG_PTR GdiplusToken = NULL;
	Gdiplus::GdiplusStartupInput gsi = NULL; 

public : 
	ResourceManager(HWND _hWnd, int width, int height); 
	~ResourceManager(); 

	void Initialize(); 
	void Update(); 
	void Render(); 


};


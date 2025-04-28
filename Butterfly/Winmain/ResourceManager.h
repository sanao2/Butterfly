#pragma once
#include <windows.h>
#include <iostream> 
using namespace std; 

class ResourceManager
{
private : 
	HWND	hWnd; 
	HDC		frontDC;	// FrontBuffer
	HDC		backDC;		// BackBuffer
	HBITMAP backBitmap; // BackBuffer Linked Bitmap
	POINT	BitmapSize; // Bitmap size 
	POINT   BitmapPos;  // Bitmap Position 
public : 
	ResourceManager(); 
	~ResourceManager(); 

	void Initialize(); 
	void Update(); 
	void Render(); 


};


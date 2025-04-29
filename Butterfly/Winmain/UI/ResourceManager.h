#include <windows.h>
#include <iostream>
#include <gdiplus.h>
#include "../Resource.h"
#pragma comment(lib, "gdiplus.lib")
using namespace std; 

const int GetResourcePath[] = {
	IDB_PLAYER_DOWNWALK_IDLE,
	IDB_PLAYER_DOWNWALK_ONE,
	IDB_PLAYER_DOWNWALK_SECOND,
	IDB_PLAYER_DOWNWALK_THREE
};

class Resource
{
private : 
	HWND hWnd = nullptr;
	HDC clientDC = nullptr;
	HDC memDC = nullptr;

	ULONG_PTR g_GdiPlusToken;
	Gdiplus::Graphics* memGraphics = nullptr;
	Gdiplus::Bitmap* Image = nullptr; 

public : 
	Resource(HWND hwnd, int width, int height); 
	~Resource();

	void LoadImages(HINSTANCE hInst);
	void Render(); 
};
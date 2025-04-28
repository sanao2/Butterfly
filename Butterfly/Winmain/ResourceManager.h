#pragma once
#include <windows.h>
#include <iostream> 
#include <gdiplus.h>
#include <string> 
#pragma comment(lib, "gdiplus.lib")
using namespace std;
using std::string;
using std::wstring;
#include <unordered_map>
using::unordered_map;

enum SpriteState {
	IDLE, 
	PICKAX_USE,
	HOE,			// ���� 
	WATERINGCAN
};

struct SpriteInfo {
	wstring SpriteImg;
};

const unordered_map<SpriteState, SpriteInfo> resourceMap = {
	{IDLE, {L"player_IDLE.png"}}
};

class ResourceManager
{
private : 
	HWND		hWnd = NULL;
	HDC			backDC = NULL;			// BackBuffer

	POINT	BitmapSize = { 0,0 };   // Bitmap size 
	POINT   BitmapPos = { 0,0 };    // Bitmap Position 

	Gdiplus::Bitmap* ImgBitmap = nullptr; 
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


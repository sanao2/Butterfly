#pragma once
#include <windows.h>
#include <iostream> 
#include <gdiplus.h>
#include <string> 
#include <array>
#pragma comment(lib, "gdiplus.lib")
using namespace std;
using std::array;
using std::string;
using std::wstring;
#include <unordered_map>
#include "../resource.h"
using::unordered_map;

extern HINSTANCE* hInst;

const wstring RESOURCE_DIR = L"..\\Resources\\";

enum SpriteState {
	PLAYER_IDLE, 
	SHOP,
	FLOOR_TILE_ONE,
	POND,		 // ¿¬¸ø 
	TREE,
	SPRITECOUNT 
};

inline int GetResourcePath(SpriteState SprState)
{
	static int pathes[] = {
		IDB_PLAYER_IDLE,
		IDB_SHOP,
		IDB_FLOOR_TILE_ONE,
		IDB_POND,
		IDB_TREE
	};

	if (SprState < 0 || SprState >= SPRITECOUNT) return NULL;

	return pathes[SprState];
};


class ResourceManager
{
private : 
	HWND		hWnd = NULL;
	HDC			clientDC = NULL; 
	HDC			memDC = NULL;			// BackBuffer
	HBITMAP		memBitmap = NULL; 

	array<Gdiplus::Bitmap*, SpriteState::SPRITECOUNT> Sprites; // All Resource Save in array

	POINT	clientSize = { 0,0 }; 
	POINT	SpriteSize = { 0,0 };		// Bitmap size 
	POINT   SpritePos = { 0,0 };		// Bitmap Position

	SpriteState currSprState; 

	ULONG_PTR GdiplusToken = NULL;
	Gdiplus::GdiplusStartupInput gsi = NULL;
	Gdiplus::Bitmap* ImgBitmap = nullptr; 
	Gdiplus::Graphics* backDCgraphics = nullptr;

public : 
	ResourceManager(HWND _hWnd, int width, int height);
	~ResourceManager(); 

	void Initialize(); 
	void Update(); 
	void Render(HDC drawDC,int x, int y,  int width, int height); 

	void LoadImages(HINSTANCE hInst);

	void SetSpritePos(int x, int y) { SpritePos = { x,y }; }
	POINT GetSpritePos() { return SpritePos; }
	void SetSpriteSize(Gdiplus::Bitmap* Image);
	POINT GetSpriteSize();
};


#pragma once
#include <windows.h>
#include <iostream> 
#include <gdiplus.h>
#include <string> 
#include <array>
#include <unordered_map>
#include "../resource.h"
#pragma comment(lib, "gdiplus.lib")
using namespace std;
using std::array;
using std::string;
using std::wstring;
using::unordered_map;

enum SpriteState {
	PLAYER_IDLE, 
	SHOP,
	FLOOR_TILE_ONE,
	POND,			// 연못 
	TREE,			// 나무
	SPRITECOUNT 
};

inline int GetResourceID(SpriteState SprState)
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
	HWND		hWnd =		NULL;
	HDC			clientDC =  NULL; 
	HDC			memDC =		NULL;			// BackBuffer
	HBITMAP		hBitmap = NULL; 

	SpriteState currSprState;
	array<Gdiplus::Bitmap*, SpriteState::SPRITECOUNT> Sprites; // All Resource Save in array

	POINT	SpriteSize = { 0,0 };		// Bitmap size 
	POINT   SpritePos = { 0,0 };		// Bitmap Position

	ULONG_PTR GdiplusToken = NULL;
	Gdiplus::GdiplusStartupInput gsi = NULL;
	Gdiplus::Bitmap* ImgBitmap = nullptr; 
	Gdiplus::Graphics* backDCgraphics = nullptr;

public : 
	ResourceManager(HWND _hWnd, int width, int height);
	~ResourceManager(); 
	
	void Initialize(); 
	void Update();
	void Render(HDC drawDC,int x, int y, int width, int height); 

	void LoadImages(HINSTANCE hInst);
	void SetSpriteRect(int x, int y, Gdiplus::Bitmap* Image);

	void SetSpriteState(SpriteState newState);
	void SetSpritePos(int x, int y) { SpritePos = { x,y }; }
	POINT GetSpritePos() { return SpritePos; }
	void SetSpriteSize(Gdiplus::Bitmap* Image);
	POINT GetSpriteSize();
};


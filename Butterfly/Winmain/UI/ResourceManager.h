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
using::unordered_map;

extern HINSTANCE* hInst;

const wstring RESOURCE_DIR = L"..\\Resources\\";

enum SpriteState {
	PLAYER_IDLE, 
	SHOP,
	FLOOR_TILE, 
	POND,		 // ¿¬¸ø 
	TREE,
	SPRITECOUNT 
};

//struct SpriteInfo {
//	wstring SpriteImg;
//};
//
//const unordered_map<SpriteState, SpriteInfo> resourceMap = {
//	{PLAYER_IDLE, {L"player_IDLE.png"}}, 
//	{SHOP, {L"shop_8bits.png"}},
//	{FLOOR_TILE, {L"floorTile_1.png"}},	
//	{POND, {L"Pond.png"}},
//	{TREE, {L"Tree.png"}},
//};
//
//const wstring GetResourcePath(SpriteState SprState)
//{
//	auto iter = resourceMap.find(SprState); 
//
//	if (iter != resourceMap.end())
//	{
//		return RESOURCE_DIR + iter->second.SpriteImg; 
//	}
//
//	return L""; 
//}

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

	SpriteState currState; 

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

	void LoadImages(); 

	void SetSpritePos(int x, int y) { SpritePos = { x,y }; }
	POINT GetSpritePos() { return SpritePos; }
	void SetSpriteSize(Gdiplus::Bitmap* Image);
	POINT GetSpriteSize();
};


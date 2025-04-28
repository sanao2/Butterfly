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

const wstring RESOURCE_DIR = L"..\\Resources\\";

enum SpriteState {
	PLAYER_IDLE, 
	SHOP,
	FLOOR_TILE, 
	POND,		 // ¿¬¸ø 
	TREE,
	SPRITECOUNT 
};

struct SpriteInfo {
	wstring SpriteImg;
};

const unordered_map<SpriteState, SpriteInfo> resourceMap = {
	{PLAYER_IDLE, {L"player_IDLE.png"}}, 
	{SHOP, {L"shop_8bits.png"}},
	{FLOOR_TILE, {L"floorTile_1.png"}},	
	{POND, {L"Pond.png"}},
	{TREE, {L"Tree.png"}},
};

const wstring GetResourcePath(SpriteState SprState)
{
	auto iter = resourceMap.find(SprState); 

	if (iter != resourceMap.end())
	{
		return RESOURCE_DIR + iter->second.SpriteImg; 
	}

	return L""; 
}

class ResourceManager
{
private : 
	HWND		hWnd = NULL;
	HDC			clientDC = NULL; 
	HDC			memDC = NULL;			// BackBuffer

	array<vector<SpriteInfo>, SpriteState::SPRITECOUNT> frame; // All Resource Save in array

	POINT	BitmapSize = { 0,0 };		// Bitmap size 
	POINT   BitmapPos = { 0,0 };		// Bitmap Position 

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


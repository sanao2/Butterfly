#pragma once
#include "../../Global.h"
#include <windows.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
#include "resource.h"
#include "GdiplusImageRenderer.h"
#include "ImageResource.h"
#include "IImageRenderer.h"

constexpr wchar_t SPRITE_TYPE[] = L"PNG";

enum Spritestate
{
	FLOORTILE,
	TREE,
	BRANCH,
	POND,
	RESOURCE_COUNT
};

<<<<<<< HEAD
//struct SpriteInfo {
//	vector<int> ImageID;
//	SpriteInfo() = default;
//	SpriteInfo(std::initializer_list<int> list)
//		: ImageID(list) {
//	}
//};
//
//unordered_map<Spritestate, SpriteInfo> SpriteStateFrameMap = {
//   {FLOORTILE, { IDB_FLOOR_TILE_ONE,IDB_FLOOR_TILE_SECOND,IDB_FLOOR_TILE_THREE }},
//   {TREE,{ IDB_TREE}},
//   {BRANCH, {IDB_BRANCH}},
//   {POND, { IDB_POND}}
//
//};
//
//inline const int GetSpriteID(Spritestate Sprstate, size_t frameIndex)
//{
//	auto it = SpriteStateFrameMap.find(Sprstate);
//	if (it == SpriteStateFrameMap.end()) {
//		throw std::runtime_error("Animstate가 AnimStateFrameMap에 존재하지 않습니다.");
//	}
//	auto& vec = it->second.ImageID;
//	if (frameIndex >= vec.size()) {
//		throw std::out_of_range("frameIndex가 ImageID 벡터의 범위를 초과했습니다.");
//	}
//
//	return vec[frameIndex];
//}
enum TileType {
	Empty,    // 통과 가능
	Wall      // 충돌 처리할 벽
};
struct Tile {
	Gdiplus::Rect rect;  // 화면상 위치
	TileType      type;  // 충돌 여부
};

=======
struct SpriteInfo {
	vector<int> ImageID;
	SpriteInfo() = default;
	SpriteInfo(std::initializer_list<int> list)
		: ImageID(list) {
	}
};
enum TileType {
	Empty,    // 통과 가능
	Wall      // 충돌 처리할 벽

};
struct Tile {
	Gdiplus::Rect rect;   // 화면상 위치
	TileType      type;   // 충돌 여부
	Spritestate   state;  // 어떤 이미지로 그릴지
};

extern std::unordered_map<Spritestate, SpriteInfo> SpriteStateFrameMap;

inline const int GetSpriteID(Spritestate Sprstate, size_t frameIndex)
{
	auto it = SpriteStateFrameMap.find(Sprstate);
	if (it == SpriteStateFrameMap.end()) {
		throw std::runtime_error("Animstate가 AnimStateFrameMap에 존재하지 않습니다.");
	}
	auto& vec = it->second.ImageID;
	if (frameIndex >= vec.size()) {
		throw std::out_of_range("frameIndex가 ImageID 벡터의 범위를 초과했습니다.");
	}

	return vec[frameIndex];
}

>>>>>>> 5f00e2ed61ee77d6d5d1cb1ef5eeb9a29ab30afa
namespace Map
{
	class Object
	{
	private :
		vector<Tile> tiles;
		vector<std::vector<Gdiplus::Image*>> tileBitmaps;
		ImageResource* imageResource = nullptr;
<<<<<<< HEAD
		//Todo test code 
		vector<Tile> tiles;


	public:
		Object(HDC drawDC, int width, int height);
		~Object();
=======
		IImageRenderer* imageRenderer = nullptr;
>>>>>>> 5f00e2ed61ee77d6d5d1cb1ef5eeb9a29ab30afa

	public :
		Object(HDC drawDC, HINSTANCE hInstance);
		~Object();
		void Initialize(const vector<std::tuple<Gdiplus::Rect, TileType, Spritestate>>& defs);
		void AddTile(const Gdiplus::Rect& rect, TileType type, Spritestate state);
		void LoadTileImages(HINSTANCE hInst, Spritestate state);
		vector<Gdiplus::Rect> GetWallRects() const;
		void MapLoop(Gdiplus::Graphics& graphics);
		void RectAngle(Gdiplus::Graphics& graphics);
		vector<Gdiplus::Rect> GetfloorsRects() const;
	};
}


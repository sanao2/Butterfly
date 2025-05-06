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
struct SpriteInfo {
	vector<int> ImageID;
	SpriteInfo() = default;
	SpriteInfo(std::initializer_list<int> list)
		: ImageID(list) {
	}
};

extern std::unordered_map<Spritestate, SpriteInfo> SpriteStateFrameMap;

enum TileType {
	Empty,    // 통과 가능
	Wall      // 충돌 처리할 벽
};
struct Tile {
	Gdiplus::Rect rect;  // 화면상 위치
	TileType      type;  // 충돌 여부
	Spritestate  state;
};


extern std::vector<std::tuple<Gdiplus::Rect, TileType, Spritestate>> defs;


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

namespace Map
{
	class Object
	{
	private:

		vector<std::vector<Gdiplus::Image*>> tileBitmaps;
		ImageResource* imageResource = nullptr;
		IImageRenderer* imageRenderer = nullptr;
		Gdiplus::Rect lastTile;

	public:
		Object(HDC drawDC, HINSTANCE hInstance);
		~Object();

		vector<Tile> tiles;
		void MapLoop(Gdiplus::Graphics& graphics);
		void MapDraw();
		void Initialize(const vector<std::tuple<Gdiplus::Rect, TileType, Spritestate>>& defs);
		void AddTile(const Gdiplus::Rect& rect, TileType type, Spritestate state);
		void LoadTileImages(HINSTANCE hInst, Spritestate state);

		void RectAngle(Gdiplus::Graphics& graphics);
		vector<Gdiplus::Rect> GetfloorsRects() const;

		Gdiplus::Rect& GetlastTile() { return lastTile; }
	};
}


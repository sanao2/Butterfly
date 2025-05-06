#include "Map.h"
using namespace std;
using namespace Map;


unordered_map<Spritestate, SpriteInfo> SpriteStateFrameMap = {
   {FLOORTILE, { IDB_FLOOR_TILE_ONE }},
   {TREE,{IDB_TREE}},
   {BRANCH, {IDB_BRANCH}},
   {POND, { IDB_POND}}

};

namespace Map
{
	Object::Object(HDC drawDC, HINSTANCE hInstance)
	{
		imageResource = new ImageResource();
		imageRenderer = new GdiPlusImageRenderer();
		tileBitmaps.resize(static_cast<int>(RESOURCE_COUNT));

		LoadTileImages(hInstance, FLOORTILE);
		LoadTileImages(hInstance, TREE);
	}

	Object::~Object()
	{
		delete imageResource;
		delete imageRenderer;
	}

	void Object::Initialize(const vector<std::tuple<Gdiplus::Rect, TileType, Spritestate>>& defs)
	{
		tiles.clear();
		for (auto& data : defs) {
			auto& [rect, type, state] = const_cast<std::tuple<Gdiplus::Rect, TileType, Spritestate>&>(data);
			tiles.push_back({ rect, type, state });
		}

	}

	void Object::AddTile(const Gdiplus::Rect& rect, TileType type, Spritestate state)
	{
		tiles.push_back({ rect, type, state });
	}

	vector<Gdiplus::Rect> Object::GetfloorsRects() const
	{
		vector<Gdiplus::Rect> floors;

		for (auto& tile : tiles)
		{
			if (tile.type == TileType::Empty)
				floors.push_back(tile.rect);
		}
		return floors;
	}

	void Object::LoadTileImages(HINSTANCE hInst, Spritestate state)
	{
		const auto& info = SpriteStateFrameMap[state];
		auto& vec = tileBitmaps[static_cast<int>(state)];  // enum→인덱스

		for (size_t i = 0; i < info.ImageID.size(); ++i) {
			int resID = GetSpriteID(state, i);

			if (!imageResource->LoadFromResource(hInst, resID, SPRITE_TYPE))
				throw std::runtime_error("이미지 로드 실패");


			Gdiplus::Image* img = imageResource->GetBitmap();
			vec.push_back(img);
		}
	}
	void Object::MapLoop(Gdiplus::Graphics& graphics)
	{
<<<<<<< HEAD
		const int windowWidth = 600;
		const int windowHeight = 800;
		// 타일 크기
		const int tileWidth = 30;
		const int tileHeight = 40;

		for (int y = 0; y < windowHeight; y += tileHeight)
		{
			for (int x = 0; x < windowWidth; x += tileWidth)
			{
				Gdiplus::Rect rect = createObject(x, y, tileWidth, tileHeight);
				RectAngle(&graphics, rect);
			}
		}
=======
		std::vector<std::tuple<Gdiplus::Rect, TileType, Spritestate>> defs = {
			// floorstart
			{ { -20, 30, 80, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 50, 30, 80, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 50, 30, 80, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 120, 30, 80, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 180, 30, 30, 90 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 180, 100, 30, 90 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 180, 80, 80, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 250, 80, 80, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 300, 80, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 300, 80, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 180, 180, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 330, 80, 100, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 400, 80, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 400, 160, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 300, 180, 100, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 90, 250, 120, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 30, 250, 80, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 30, 200, 30, 80 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 30, 120, 30, 80 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 30, 90, 90, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 180, 280, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 180, 280, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 180, 360, 100, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 250, 360, 100, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 90, 360, 100, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 70, 360, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 70, 430, 100, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 150, 430, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 150, 460, 100, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 250, 390, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 70, 500, 80, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 30, 500, 50, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 30, 500, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 320, 310, 30, 80 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 320, 280, 80, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 400, 250, 30, 90 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 400, 330, 30, 90 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 400, 380, 30, 90 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 430, 250, 80, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 500, 250, 70, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 540, 250, 30, 80 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 540, 320, 30, 80 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 470, 390, 100, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 470, 390, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 400, 460, 70, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 370, 460, 100, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 370, 460, 100, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 340, 460, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 340, 550, 100, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 470, 550, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 470, 480, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 430, 550, 100, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 530, 480, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 340, 550, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 340, 620, 160, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 60, 570, 90, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 170, 570, 100, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 140, 570, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 140, 640, 30, 100 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 30, 680, 200, 100 }, TileType::Empty, Spritestate::FLOORTILE },
		};
		Initialize(defs);

		RectAngle(graphics);
>>>>>>> 5f00e2ed61ee77d6d5d1cb1ef5eeb9a29ab30afa

	}
	void Object::RectAngle(Gdiplus::Graphics& graphics)
	{
		for (auto& tile : tiles) {
			auto& imgs = tileBitmaps[static_cast<int>(tile.state)];

			if (!imgs.empty()) {
				Gdiplus::Image* image = imgs[0];

				// 첫 번째 프레임만 그리기
				imageRenderer->Render(graphics, tile.rect,image);
			}
			else {
				// 대체 드로잉
				Gdiplus::Pen pen(Gdiplus::Color(255, 0, 128, 255), 2.0f);
				Gdiplus::Rect rect = { 10,10,20,20 };
				graphics.DrawRectangle(&pen, rect);
			}
		}

	}


}

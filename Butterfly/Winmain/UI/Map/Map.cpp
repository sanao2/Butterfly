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
	}

	Object::~Object()
	{
		delete imageResource;
		delete imageRenderer;
	}

	void Object::Initialize(const vector<tuple<Gdiplus::Rect, TileType, Spritestate>>& defs)
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

	vector<Gdiplus::Rect> Object::GetWallRects() const
	{
		vector<Gdiplus::Rect> walls;

		for (auto& tile : tiles)
		{
			if (tile.type == TileType::Wall)
				walls.push_back(tile.rect); 

			return walls; 
		}
	}
	//void Object::LoadTileImages(HINSTANCE hInstance, Spritestate state)
	//{
	//	// 1) �ش� state�� ���ε� ���ҽ� ID ����Ʈ ��������
	//	const auto& info = SpriteStateFrameMap[state];
	//	// 2) tileBitmaps[state] ���Ϳ� �̹��� �����͸� �������� ����
	//	auto& imgs = tileBitmaps[state];

	//	for (size_t i = 0; i < info.ImageID.size(); ++i) {
	//		int resID = GetSpriteID(state, i);

	//		// 3) ImageResource �κ��� ���ҽ� �ε�
	//		if (!imageResource->LoadFromResource(hInstance, resID, SPRITE_TYPE)) {
	//			throw std::runtime_error(
	//				"�̹��� �ε� ����: state=" + std::to_string(static_cast<int>(state))
	//				+ " frame=" + std::to_string(i));
	//		}
	//		// 4) Gdiplus::Bitmap* �� Gdiplus::Image �� ���μ� unique_ptr �� ���
	//		imgs.push_back(
	//			std::make_unique<Gdiplus::Image>(imageResource->GetBitmap())
	//		);
	//	}
	//}
	void LoadTileImages(HINSTANCE hInst, Spritestate state)
	{
		const auto& info = SpriteStateFrameMap[state];
		auto& vec = tileBitmaps[static_cast<int>(state)];  // enum���ε���

		for (size_t i = 0; i < info.ImageID.size(); ++i) {
			int resID = GetSpriteID(state, i);

			if (!imageResource->LoadFromResource(hInst, resID, SPRITE_TYPE))
				throw std::runtime_error("�̹��� �ε� ����");

			// ResourceManager / ImageResource�� �����ϴ� Bitmap*�� �޾ƿͼ�
			// raw �����ͷ� ����
			Gdiplus::Image* img = imageResource->GetBitmap();
			vec.push_back(img);
	}
	void Object::MapLoop()
	{
		

		
		std::vector<std::tuple<Gdiplus::Rect, TileType, Spritestate>> defs = {
			{ {  0,   0, 30, 30 }, TileType::Wall,  Spritestate::TREE      },
			{ { 30,   0, 30, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			{ { 60,   0, 30, 30 }, TileType::Empty, Spritestate::FLOORTILE },
			// �����ϴ� ��ġ��ũ�⸸ŭ ����
		};
		Initialize(defs);
	}

	

}
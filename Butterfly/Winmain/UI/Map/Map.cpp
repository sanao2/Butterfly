#include "Map.h"
using namespace std; 


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
		resMgr = new ResourceManager(drawDC, hInstance);
	}

	Object::~Object()
	{
		delete resMgr; 
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

	void Object::MapLoop()
	{

	}

	

}
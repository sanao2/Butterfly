#include <windows.h>
#include <gdiplus.h>
#include "/BF/Butterfly/Winmain/resource.h"
#include "ImageResource.h"
#include "IImageRenderer.h"
#include "GdiplusImageRenderer.h"
#pragma comment(lib, "gdiplus.lib")
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map> // Add this line to include the unordered_map header
#include <stdexcept>
using namespace std; 
using std::unordered_map;
using std::vector; 
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

unordered_map<Spritestate, SpriteInfo> SpriteStateFrameMap = {
   {FLOORTILE, { IDB_FLOOR_TILE_ONE,IDB_FLOOR_TILE_SECOND,IDB_FLOOR_TILE_THREE }},
   {TREE,{ IDB_TREE}},
   {BRANCH, {IDB_BRANCH}},
   {POND, { IDB_POND}}  

};

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
		ImageResource* imageResource = nullptr;
		IImageRenderer* imageRenderer = nullptr;
		Gdiplus::Image* image = nullptr;
		POINT ObjectPos = {};
		Spritestate Sprstate;

		POINT ObjectScale = {};
		int  ResourceID = 0; 			

		vector<Gdiplus::Image*> SpriteFrames;

	public:
		Object(HDC drawDC, int width, int height);
		~Object(); 

		void drawMap();
		Gdiplus::Image* LoadImages(HINSTANCE hInstance);		 
		void Update(); 
		void Render(Gdiplus::Graphics* graphics,int x, int y);

		Spritestate GetSpritestate() { return Sprstate;  }
		void SetSpritestate(Spritestate state) { Sprstate = state; }
	};
}


//void ResourceManger::LoadImages(HINSTANCE hInst)
//{
//	try {			
//
//		imageResource->LoadFromResource(hInst, RESOURCE_ID, RESOURCE_TYPE); // Load image from resource 
//	
//		
//		//image = imageResource->GetBitmap();
//		AnimationFrames.push_back(image); 
//
//		if (image == nullptr)
//		{
//			cerr << "Failed to load image resource." << endl;
//			return;
//		}
//
//	}
//	catch (const std::exception& e) {
//		std::cerr << "Error loading images: " << e.what() << std::endl;
//	}
//	if (image != nullptr)
//	{
//		cerr << "Failed to load images." << endl;
//	}
//	
//}
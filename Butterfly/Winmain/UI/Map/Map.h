#include <windows.h>
#include <gdiplus.h>
//#include "../Map/resource.h"
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
//		throw std::runtime_error("Animstate�� AnimStateFrameMap�� �������� �ʽ��ϴ�.");
//	}
//	auto& vec = it->second.ImageID;
//	if (frameIndex >= vec.size()) {
//		throw std::out_of_range("frameIndex�� ImageID ������ ������ �ʰ��߽��ϴ�.");
//	}
//
//	return vec[frameIndex];
//}
struct Tile {
	RECT      rect;      //Todo ȭ��� ��ġ
	Spritestate type;    //Todo � ���ҽ�(Ÿ��) Ÿ������
};
namespace Map
{
	class Object
	{
	private:
		POINT objsize;		//Todo ������Ʈ ������ 
		POINT objPos;		//Todo ������Ʈ 
		int ResourceID;		//Todo ���ҽ� ���̵� 

		IImageRenderer* imageRenderer = nullptr;
		ImageResource* imageResource = nullptr;
	public:
		Object(HDC drawDC, int width, int height);
		~Object();

		void MapLoop();
		Gdiplus::Rect createObject(int x, int y, int width, int height);
		//void LoadImages(int resourceID, const wchar_t* resourceType);
		//void ObjectRender(Gdiplus::Graphics* graphics, Gdiplus::Image* image, int x, int y);
		void RectAngle(Gdiplus::Graphics* graphics, Gdiplus::Rect& rect);
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
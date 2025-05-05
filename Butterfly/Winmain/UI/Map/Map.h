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
enum TileType {
	Empty,    // ��� ����
	Wall      // �浹 ó���� ��

};
struct Tile {
	Gdiplus::Rect rect;   // ȭ��� ��ġ
	TileType      type;   // �浹 ����
	Spritestate   state;  // � �̹����� �׸���
};

extern std::unordered_map<Spritestate, SpriteInfo> SpriteStateFrameMap;

inline const int GetSpriteID(Spritestate Sprstate, size_t frameIndex)
{
	auto it = SpriteStateFrameMap.find(Sprstate);
	if (it == SpriteStateFrameMap.end()) {
		throw std::runtime_error("Animstate�� AnimStateFrameMap�� �������� �ʽ��ϴ�.");
	}
	auto& vec = it->second.ImageID;
	if (frameIndex >= vec.size()) {
		throw std::out_of_range("frameIndex�� ImageID ������ ������ �ʰ��߽��ϴ�.");
	}

	return vec[frameIndex];
}

namespace Map
{
	class Object
	{
	private : 
		vector<Tile> tiles; 
		vector<std::vector<Gdiplus::Image*>> tileBitmaps;
		ImageResource* imageResource = nullptr; 
		IImageRenderer* imageRenderer = nullptr; 

	public : 
		Object(HDC drawDC, HINSTANCE hInstance); 
		~Object(); 
		void Initialize(const vector<std::tuple<Gdiplus::Rect, TileType, Spritestate>>& defs);
		void AddTile(const Gdiplus::Rect& rect, TileType type, Spritestate state);
		void LoadTileImages(HINSTANCE hInst, Spritestate state);
		vector<Gdiplus::Rect> GetWallRects() const;
		void MapLoop(Gdiplus::Graphics& graphics);
		void RectAngle(Gdiplus::Graphics& graphics);
	};
}

/*

void MapLoop(Gdiplus::Graphics& graphics);
		Gdiplus::Rect createObject(int x, int y, int width, int height);
		void Initialize();
		void LoadImages(int resourceID, const wchar_t* resourceType);
		void TileImageRender(Gdiplus::Graphics* graphics, Gdiplus::Image* image, int x, int y);
		void RectAngle(Gdiplus::Graphics* graphics, Gdiplus::Rect& rect);
		Object::Object(HDC drawDC, int width, int height)
		: objsize{ 0,0 }, objPos{ 0,0 }, ResourceID(0)
	{
		imageRenderer = new GdiPlusImageRenderer();
		imageResource = new ImageResource();

	}

	Object::~Object()
	{
		delete imageRenderer;
		delete imageResource;
	}

	void Object::MapLoop(Gdiplus::Graphics& graphics)
	{
		const int windowWidth = 600;
		const int windowHeight = 800;
		// Ÿ�� ũ��
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

	}

	Gdiplus::Rect Object::createObject(int x, int y, int width, int height)
	{
		Gdiplus::Rect rect = { x,y,width, height };

		return rect;
	}

	void Object::Initialize()
	{

	}


	void Object::TileImageRender(Gdiplus::Graphics* graphics, Gdiplus::Image* image, int x, int y)
	{
		Gdiplus::Pen pen(Gdiplus::Color(255, 0, 128, 255), 2.0f);
		int width = image->GetWidth();
		int height = image->GetHeight();

		Gdiplus::Rect rect = {x,y,width,height};
		graphics->DrawImage(image, rect);
	}

	void Object::RectAngle(Gdiplus::Graphics* graphics, Gdiplus::Rect& rect)
	{
		Gdiplus::Pen pen(Gdiplus::Color(255, 0, 128, 255), 2.0f);
		graphics->DrawRectangle(&pen, rect);
	}

*/
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
#include "Map.h"

namespace Map
{
	Map::Object::Object(HDC drawDC, int width, int height)
		: Sprstate(RESOURCE_COUNT),
		ObjectPos{ 0,0 }, ObjectScale{ 0,0 }
	{
		imageResource = new ImageResource();
		imageRenderer = new GdiPlusImageRenderer();

	}

	Map::Object::~Object()
	{
		delete imageRenderer;
		if (imageResource) {
			delete image;
			delete imageResource;
		}

	}

	void Object::Initialize(HINSTANCE hInstance)
	{

	}

	Gdiplus::Image* Map::Object::LoadImages(HINSTANCE hInstance)
	{
		auto& ids = SpriteStateFrameMap[Sprstate].ImageID;
		auto& frames = spriteframes[Sprstate];

		for (int id : ids) {
			if (imageResource->LoadFromResource(hInstance, id, SPRITE_TYPE)) {
				frames.push_back(imageResource->GetBitmap());
			}
			else {
				std::cerr << "리소스 로드 실패 ID: " << id << std::endl;
			}
		}

		return frames.empty() ? nullptr : frames.front();
	}

	void Map::Object::Update() //Todo 리소스 이미지 ID 변환 
	{


	}

	void Map::Object::Render(Gdiplus::Graphics* graphics, int x, int y)
	{
		int Objwidth = image->GetWidth();
		int Objheight = image->GetHeight();

		RECT destRect = { x,y,Objwidth,Objheight };
		imageRenderer->Render(*graphics, destRect, image, Objwidth, Objheight, x, y);
	}

}
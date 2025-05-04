#include "Map.h"

namespace Map
{
	Map::Object::Object(HDC drawDC, int width, int height)
		:  SpriteFrames{ 0, }, Sprstate(RESOURCE_COUNT),
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

	Gdiplus::Image* Map::Object::LoadImages(HINSTANCE hInstance)
	{
		auto& sprState = SpriteStateFrameMap[Sprstate].ImageID;

		for (int i = 0; i < sprState.size(); ++i)
		{
			int ID = GetSpriteID(Sprstate, i);

			if (imageResource->LoadFromResource(hInstance, ID, SPRITE_TYPE))
			{
				image = imageResource->GetBitmap();
				SpriteFrames.push_back(image);
			}
			else
			{
				cerr << "리소스 로드 실패 ID : " << ID << endl;
			}
		}

		return image;
	}

	void Map::Object::Update()
	{
		
		
	}

	void Map::Object::Render( Gdiplus::Graphics* graphics, int x, int y)
	{
		int Objwidth = image->GetWidth();
		int Objheight = image->GetHeight();

		RECT destRect = { x,y,Objwidth,Objheight };
		imageRenderer->Render(*graphics, destRect, image, Objwidth, Objheight, x, y);
	}

}
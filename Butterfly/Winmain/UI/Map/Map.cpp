#include "Map.h"

namespace Map
{
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

	}

	Gdiplus::Rect Object::createObject(int x, int y, int width, int height)
	{
		Gdiplus::Rect rect = { x,y,width, height };

		return rect;
	}


	void Object::RectAngle(Gdiplus::Graphics* graphics, Gdiplus::Rect& rect)
	{
		Gdiplus::Pen pen(Gdiplus::Color(255, 0, 128, 255), 2.0f);
		graphics->DrawRectangle(&pen, rect);
	}



}
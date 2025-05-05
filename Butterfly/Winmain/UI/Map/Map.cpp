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

	void Object::MapLoop()
	{
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
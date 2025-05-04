#include <windows.h>
#include <gdiplus.h>
#include "ImageResource.h"
#include "IImageRenderer.h"
#include "GdiplusImageRenderer.h"
#pragma comment(lib, "gdiplus.lib")

namespace Map
{
	class Object
	{
	private:
		HDC memDC;
		ULONG_PTR GdiPlusToken;
		Gdiplus::GdiplusStartupInput gsi;
		Gdiplus::Graphics* graphics = nullptr;
		Gdiplus::Image* image = nullptr;

		POINT clientSize = {};
		POINT ObjectPos = {};
		POINT ObjectScale = {};

		ImageResource* imageResource = nullptr; 
		IImageRenderer* imageRenderer = nullptr; 
		

	public:
		Object(HDC drawDC, int width, int height);
		~Object(); 

		void CreateObject(Gdiplus::Image* image, int x, int y); 
		void drawMap(); 
		void Update(); 
		void Render(Gdiplus::Graphics* graphics, RECT& rect, Gdiplus::Image* image, int width, int height, int x, int y);
	};
}
#include <windows.h>
#include <gdiplus.h>
#include "resource.h"
#include "ImageResource.h"
#include "IImageRenderer.h"
#include "GdiplusImageRenderer.h"
#pragma comment(lib, "gdiplus.lib")

enum Spritestate
{
	FLOORTILE, 
	THREE,
	BRANCH,
	POND
};

inline int GetAnimPath(Spritestate Sprstate)
{
	// static 으로 일정한 값을 구현 
	static int SpriteIDs[] = {
	IDB_POND, 
	};

	if (state < 0 || state >= ANIMCOUNT) return nullptr;

	return RESOURCE_DIR + paths[state];
}


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
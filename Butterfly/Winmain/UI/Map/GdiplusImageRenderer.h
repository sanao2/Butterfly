#pragma once
#include <windows.h>
#include <gdiplus.h>
#include "IImageRenderer.h" 
#pragma comment(lib, "gdiplus.lib")

class GdiPlusImageRenderer : public IImageRenderer {
public:
	// Rect drawing code space 
<<<<<<< HEAD
	void Render(Gdiplus::Graphics& graphics, RECT& rect, Gdiplus::Image* image, int width, int height, int x, int y) override
	{
		if (image) {
			graphics.DrawImage(image, x, y, width, height);
=======
	virtual void Render(Gdiplus::Graphics& graphics, Gdiplus::Rect& rect, Gdiplus::Image* image) override
	{
		if (image) {
			graphics.DrawImage(image, rect);
>>>>>>> 5f00e2ed61ee77d6d5d1cb1ef5eeb9a29ab30afa
		}
	}
	void Render(Gdiplus::Graphics& graphics, Gdiplus::Image* image, int width, int height, int x, int y) override
	{
		if (image) {
			graphics.DrawImage(image, x, y, width, height);
		}
	}
<<<<<<< HEAD
=======
	void Render(Gdiplus::Graphics& graphics, Gdiplus::Image* image, Gdiplus::Rect& rect)
	{
		if (image) {
			graphics.DrawImage(image, rect);
		}
	}
>>>>>>> 5f00e2ed61ee77d6d5d1cb1ef5eeb9a29ab30afa
	//RealCode 
	void Render(Gdiplus::Graphics& graphics, Gdiplus::Image* image, int x, int y) override {
		if (image) {
			graphics.DrawImage(image, x, y);
		}
	}
};
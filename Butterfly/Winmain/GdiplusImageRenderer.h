#pragma once
#include <windows.h>
#include <gdiplus.h>
#include "IImageRenderer.h" 
#pragma comment(lib, "gdiplus.lib")

class GdiPlusImageRenderer : public IImageRenderer {
public:
   //testCode 
   void Render(Gdiplus::Graphics& graphics, RECT& rc, Gdiplus::Image* image, int x, int y) override {
       if (image) {
           UINT width = image->GetWidth();
           UINT height = image->GetHeight();

           Gdiplus::Rect destRect(rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top);
           graphics.DrawImage(image, destRect, x, y, width, height, Gdiplus::UnitPixel);
       }
   }
   //RealCode 
   void Render(Gdiplus::Graphics& graphics, Gdiplus::Image* image, int x, int y) override {
       if (image) {
           graphics.DrawImage(image, x, y);        
       }
   }
};
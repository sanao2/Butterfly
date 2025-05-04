#pragma once
#include <windows.h>
#include <gdiplus.h>
#include "IImageRenderer.h" 
#pragma comment(lib, "gdiplus.lib")

class GdiPlusImageRenderer : public IImageRenderer {
public:
   // Rect drawing code space 
    void Render(Gdiplus::Graphics& graphics, RECT& rect, Gdiplus::Image* image, int width, int height, int x, int y) override
    {
        if (image) {
            graphics.DrawImage(image, x, y, width, height);
        }
    }
  
   //RealCode 
   void Render(Gdiplus::Graphics& graphics, Gdiplus::Image* image, int x, int y) override {
       if (image) {
           graphics.DrawImage(image, x, y);        
       }
   }
};
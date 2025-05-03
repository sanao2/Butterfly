#pragma once
#include <windows.h>
#include <cstdint> 
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
class IImageRenderer {
public:
    //test Code 
    virtual void Render(Gdiplus::Graphics& graphics,RECT& rc, Gdiplus::Image* image, int x, int y) = 0;
    //Real Code
    virtual void Render(Gdiplus::Graphics& graphics, Gdiplus::Image* image, int x, int y) = 0;
    virtual ~IImageRenderer() = default;
};

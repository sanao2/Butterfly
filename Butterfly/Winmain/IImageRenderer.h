#pragma once
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

class IImageRenderer {
public:
    virtual void Render(Gdiplus::Graphics& graphics, Gdiplus::Image* image, int x, int y) = 0;
    virtual ~IImageRenderer() = default;
};

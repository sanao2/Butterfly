#pragma once
#include "Global.h"

class IImageRenderer {
public:
    virtual void Render(Gdiplus::Graphics& graphics, Gdiplus::Image* image, int x, int y) = 0;
    virtual ~IImageRenderer() = default;
};

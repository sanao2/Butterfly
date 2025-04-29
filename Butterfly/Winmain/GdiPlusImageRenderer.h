#pragma once
#include "IImageRenderer.h"

class GdiPlusImageRenderer : public IImageRenderer {
public:
    void Render(Gdiplus::Graphics& graphics, Gdiplus::Image* image, int x, int y) override {
        if (image) {
            graphics.DrawImage(image, x, y);
        }
    }
};

#pragma once
#include <gdiplus.h>
#include <string>
#pragma comment(lib, "gdiplus.lib")

class ImageResource {
private:
    Gdiplus::Bitmap* bitmap = nullptr;

public:
    ImageResource() = default;
    ~ImageResource();

    bool LoadFromResource(HINSTANCE hInstance, int resourceID, const wchar_t* resourceType);
    Gdiplus::Bitmap* GetBitmap() const { return bitmap; }
};

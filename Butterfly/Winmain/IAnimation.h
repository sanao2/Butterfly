#pragma once
#include "Global.h"

class IAnimation
{
public:
    virtual ~IAnimation() = default;
    virtual void Update(float deltaTime) = 0;
    virtual void Render(Gdiplus::Graphics& graphics, int x, int y) = 0;
};


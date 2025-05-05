#include "collider.h"

bool Collider::Check(const Gdiplus::Rect& playerRect, const vector<Gdiplus::Rect>& floors)
{
    for (auto& floor : floors)
    {
        if (playerRect.X < floor.X + floor.Width &&
            playerRect.X + playerRect.Width > floor.X &&
            playerRect.Y < floor.Y + floor.Height &&
            playerRect.Y + playerRect.Height > floor.Y)
        {
            return true; 
        }

    }
    return false; 
}

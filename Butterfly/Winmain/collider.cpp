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

bool Collider::IsCompleteOffPath(const Gdiplus::Rect& player, const vector<Gdiplus::Rect>& paths)
{
    for (auto& playerpath : paths)
    {
        if (player.IntersectsWith(playerpath))
        {
            return false; 
        }
   }
    return true; 
}

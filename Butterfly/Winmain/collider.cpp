#include "collider.h"


Collider::Collider(HDC drawDC, HINSTANCE hInstance, int width, int height)
{
	object = new Map::Object(drawDC, hInstance);
	End = new EndScene(drawDC, width, height);
}

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

void Collider::ColliderCheck(vector<Gdiplus::Rect>& floors)
{
	bool onPath = false;

	for (auto& path : floors)
	{
		if (playerrect.IntersectsWith(path))
		{
			onPath = true;
			break;
		}
	}
	if (!object->tiles.empty())
	{
		const Tile& lastTile = object->tiles.back();  // ������ Ÿ��
		if (playerrect.IntersectsWith(lastTile.rect))
		{
			if (playerrect.X == 145 && playerrect.Y == 675 &&
				lastTile.state == Spritestate::FLOORTILE && lastTile.type == TileType::Empty)
			{
				End->EndSceneRender();
				return;
			}
		}

	}

	if (IsCompleteOffPath(playerrect, floors)) {
		// ���� �� �� �� ���� ��ġ�� ����
		int width = playerrect.Width;
		int hegiht = playerrect.Height;

		playerrect.X = 0;
		playerrect.Y = 0;
	}
}

#include "collider.h"

bool isEndScene = false;

Collider::Collider(HDC drawDC, HINSTANCE hInstance, Swap* swap, int width, int height)
{
	object = new Map::Object(drawDC, hInstance);
	End = new EndScene(swap, width, height);
}

void Collider::Update()
{
	End->Update();
	End->KeyInput();
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
		auto& lastTile = object->tiles.back();  // 마지막 타일
		if (playerrect.IntersectsWith(lastTile.rect))
		{
			isEndScene = true;
			End->EndSceneRender();
		}

	}

	if (IsCompleteOffPath(playerrect, floors)) {
		// 완전 길 밖 → 시작 위치로 리셋
		int width = playerrect.Width;
		int hegiht = playerrect.Height;


		playerrect.X = 10;
		playerrect.Y = 10;
	}
}

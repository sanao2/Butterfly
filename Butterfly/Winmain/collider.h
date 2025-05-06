#pragma once
#include "Global.h"
#include <windows.h>
#include "EndScene.h"
#include "UI/Map/Map.h"
extern Gdiplus::Rect playerrect;

extern bool isEndScene;

class Collider
{
private:
	Map::Object* object = nullptr;
public:
	Collider(HDC drawDC, HINSTANCE hInstance, int width, int height);

	static bool Check(const Gdiplus::Rect& playerRect, const vector<Gdiplus::Rect>& floors);
	bool IsCompleteOffPath(const Gdiplus::Rect& player, const vector<Gdiplus::Rect>& paths);
	void ColliderCheck(vector<Gdiplus::Rect>& floors);
};


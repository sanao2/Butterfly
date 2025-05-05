#pragma once
#include "Global.h"
#include <windows.h>
#include "UI/Map/Map.h"

class Collider
{
private : 

public :
	static bool Check(const Gdiplus::Rect& playerRect, const vector<Gdiplus::Rect>& floors); 
};


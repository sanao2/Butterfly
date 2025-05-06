#pragma once
#include "Global.h"
#include <windows.h>
#include <gdiplus.h>
#include <iostream>
using namespace std;
using namespace Gdiplus;

class EndScene
{
private:
	POINT clientSize = {};
	HDC memDC;

public:
	EndScene(HDC drawDC, int width, int height);
	void EndSceneRender();
};


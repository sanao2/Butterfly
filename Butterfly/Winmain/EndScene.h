#pragma once
#include "Global.h"
#include <windows.h>
#include <gdiplus.h>
#include <iostream>
#include "Swap.h"
using namespace std;
using namespace Gdiplus;

class EndScene
{
private:
	POINT clientSize = {};
	HDC memDC;
	Swap* swap = nullptr;

public:
	EndScene(Swap* _swap, int width, int height);
	void EndSceneRender();
};


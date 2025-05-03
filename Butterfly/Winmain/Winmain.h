#pragma once
#include "Global.h"  // 이제 Global.h 하나만 include하면 됨#include <windows.h>
#include <stdio.h>
#include "UI/timer.h"
#include "resource.h"
#include "Render.h"
using namespace Input;

extern Render* render;
extern RECT playerPos;
extern int g_width;
extern int g_height; 


//StretchBlt(그려질 위치 left,
//
//	top,
//
//	right,
//
//	bottm,
//
//	그림을가지고 있는 메모리의 DC,
//
//	원본그림의 left,
//
//	top,
//
//	right,
//
//	bottom);

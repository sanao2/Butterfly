#pragma once
#include "Global.h"  // 이제 Global.h 하나만 include하면 됨#include <windows.h>
#include <stdio.h>
#include "UI/timer.h"
#include "resource.h"
#include "Render.h"
using namespace Input;

extern Render* render;
extern RECT playerRc;
extern int g_width;
extern int g_height; 


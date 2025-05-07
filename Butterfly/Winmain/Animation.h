#pragma once 
#include "Global.h"
#include <windows.h> 
#include "ResourceManager.h"
#include "UI/Timer.h"
#include <iostream> 
#include <vector> 
#include <gdiplus.h>
#include <chrono>
#pragma comment(lib, "gdiplus.lib")

using std::vector;
using namespace std;
using namespace std::chrono;

extern int g_width;
extern int g_height;
extern int current_frame;

class Animation;

extern RECT playerRc;
extern Animation* g_pPlayeranimation;


class Animation
{
private:
	HINSTANCE hInstance;
	ResourceManager* resManager;
	steady_clock::time_point lastReload;

	Time::Timer<> timer;
	constexpr static float frameInterval = 0.25f;

public:
	Animation(HDC drawDC, HINSTANCE hInstance);
	~Animation();

	void Update();
	void Render(HDC drawDC, Gdiplus::Graphics* graphics, int x, int y, int curFrameIndex);

	ResourceManager* GetResourceManager() { return resManager; }
};

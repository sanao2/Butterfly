#pragma once 
#include "Global.h"
#include <windows.h> 
#include "ResourceManager.h"
#include "UI/Timer.h"
#include <iostream> 
#include <vector> 
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
using std::vector; 
using namespace std; 

extern int g_width; 
extern int g_height;

class Animation : public ResourceManager
{
private : 
	HINSTANCE hInst; 
	Time::Timer<> timer;
	int current_frame = 0;
	constexpr static float frameInterval = 0.5f; 
		
public : 
	Animation(HDC drawDC, HINSTANCE hInstance);
	~Animation(); 
	void Update();	
	void Render(HDC drawDC, Gdiplus::Graphics* graphics, int x, int y );

};


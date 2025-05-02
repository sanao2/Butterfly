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

class Animation : private ResourceManager
{
private : 
	HINSTANCE hInst; 
	Time::Timer<> timer;
	int current_frame = 0;

	//ULONG_PTR GdiPlusToken;
	Gdiplus::Graphics* graphics = nullptr;	

public : 
	Animation(HDC drawDC, HINSTANCE hInstance);
	~Animation(); 
	void Update();	
	void Render(Gdiplus::Graphics* graphics, int x, int y );

};


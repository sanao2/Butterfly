#pragma once
#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;

extern int g_width;
extern int g_height;

class Render
{
private:
	HWND hWnd;		  // Window ID Handle
	HDC memDC;		  // Back Buffer 
	HDC clientDC;     // Front Buffer 
	HBITMAP g_Bitmap; // Bitmap 

public:
	Render(HWND hwnd);
	~Render();
};


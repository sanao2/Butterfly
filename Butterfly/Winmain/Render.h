#pragma once
#include <windows.h>
#include <stdio.h>
#include "Swap.h"
#include <iostream>
using namespace std;

extern int g_width;
extern int g_height;

 

class Render
{
private:
	HWND hWnd;			 // Window ID Handle
	HDC memDC;			 // Back Buffer 
	HDC clientDC;		 // Front Buffer 
	HBITMAP g_Bitmap;	 // Bitmap 
	POINT clientsize;	 // Client Size
	Swap* swap;			 // Swap Class
public:
	void render(); // Back Buffer Swap and Render.
	void Update(); // Render Update. Buffer Swaping and Resource, check Update. 
	POINT BufferSize(HWND _hwnd);

	Render(HWND hwnd, int w_width, int w_height); 
	~Render();
};


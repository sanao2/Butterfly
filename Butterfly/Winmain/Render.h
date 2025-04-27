#pragma once
#include <windows.h>
#include <stdio.h>
#include "Swap.h"
#include <iostream>
using namespace std;
#include <mutex>
using std::mutex;
#include <thread>
using std::thread;

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
	void render(HDC backDC, HWND _hWnd);	    // Back Buffer Swap and Render.
	void Update(HWND _hwnd);					// Render Update. Buffer Swaping and Resource, check Update. 
	POINT GetBufferSize(HWND _hwnd);			// Render Buffer Size POINT

	Render(HWND hwnd, int w_width, int w_height); 
	~Render();
};


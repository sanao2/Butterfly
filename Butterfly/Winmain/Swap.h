#pragma once
#include <windows.h>
#include <stdio.h>

class Swap
{
private:
	HWND hWnd;	  // Window ID Handle
	HDC memDC;    //  Back Buffer DC
	HDC clientDC; // Front Buffer DC

public:
	Swap(HWND _hWnd) : hWnd(_hWnd)
	{
		memDC = CreateCompatibleDC(clientDC);
	}
	~Swap()
	{

	}
};
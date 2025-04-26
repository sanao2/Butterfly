#include "Render.h"

Render::Render(HWND hwnd, int w_width, int w_height) : hWnd(hwnd) 
{
	clientDC = GetDC(hwnd);											// Get Client DC
	memDC = CreateCompatibleDC(clientDC);							// Create Memory DC
	g_Bitmap = CreateCompatibleBitmap(clientDC, w_width, w_height); // Create Memory Area
	SelectObject(memDC, g_Bitmap);									// Specify MemDC Memory Area 
}

Render::~Render()
{
	DeleteObject(g_Bitmap); // Delete Bitmap
	DeleteDC(memDC);		 // Delete Memory DC
	ReleaseDC(hWnd, clientDC); // Release Client DC
}

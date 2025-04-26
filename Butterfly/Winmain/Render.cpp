#include "Render.h"

POINT Render::BufferSize(HWND _hwnd)
{
	RECT rcClient;
	GetClientRect(_hwnd, &rcClient);					// Get Client Area Size
	int clientwidth = rcClient.right - rcClient.left;   // Get Client Width 
	int clientheight = rcClient.bottom - rcClient.top;  // Get Client Height 
	
	clientsize = { clientwidth, clientheight };		    // Get Client Size 

	return clientsize; 
}

Render::Render(HWND hwnd, int w_width, int w_height) : hWnd(hwnd)
{
	 // GDI Double Buffer Create and Initialize 
	clientDC = GetDC(hwnd);											// Get Client DC
	memDC = CreateCompatibleDC(clientDC);							// Create Memory DC
	g_Bitmap = CreateCompatibleBitmap(clientDC, w_width, w_height); // Create Memory Area
	SelectObject(memDC, g_Bitmap);									// Specify MemDC Memory Area 
	clientsize = { 0,0 }; // Get Client Size 
}

Render::~Render()
{
	DeleteObject(g_Bitmap); // Delete Bitmap
	DeleteDC(memDC);		 // Delete Memory DC
	ReleaseDC(hWnd, clientDC); // Release Client DC
}

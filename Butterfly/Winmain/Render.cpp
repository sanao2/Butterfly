#include "Render.h"

void Render::render() // Back Buffer Swap and Render.
{
	PatBlt(memDC, 0, 0, w_width, w_height, WHITENESS); //Back Buffer Begin Erager
}

void Render::Update()
{
	//swap->SwapBuffers(clientDC); // Swap Buffers 
}

POINT Render::BufferSize(HWND _hwnd)
{
	RECT Buffersize;
	GetClientRect(_hwnd, &Buffersize);					// Get Client Area Size

	// Get Client Area Size
	int clientwidth = Buffersize.right - Buffersize.left;   // Get Client Width 
	int clientheight = Buffersize.bottom - Buffersize.top;  // Get Client Height 
	
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

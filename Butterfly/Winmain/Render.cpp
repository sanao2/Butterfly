#include "Render.h"


void Render::Update(HWND _hwnd)
{
	GetBufferSize(_hwnd); // Get Buffer Size 
	
	if (swap->GetisSwaping() == true) // Swaping Check
	{
		swap->SwapBuffers(_hwnd); // Swap Buffers 
	}
	else
	{
		swap->ResetneedSwap(); // Reset Swaping Check
	}
}

void Render::render(HDC backDC, HWND _hWnd) // Back Buffer Swap and Render.
{
	PatBlt(backDC, 0, 0, clientsize.x, clientsize.y, WHITENESS); // Back Buffer Swap and Render 

	swap->SetisSwaping(true); // memDC -> clientDC Swap setting

	BitBlt(clientDC, 0, 0, clientsize.x, clientsize.y, memDC, 0, 0, SRCCOPY); // Back Buffer Swap and Render 
}

POINT Render::GetBufferSize(HWND _hwnd)
{
	RECT Buffersize;
	GetClientRect(_hwnd, &Buffersize);							// Get Client Area Size

	// Get Client Area Size
	int clientwidth = Buffersize.right - Buffersize.left;		// Get Client Width 
	int clientheight = Buffersize.bottom - Buffersize.top;		// Get Client Height 
	
	clientsize = { clientwidth, clientheight };					// Get Client Size 

	return clientsize; 
}

Render::Render(HWND hwnd, int w_width, int w_height) : hWnd(hwnd)
{
	// GDI Double Buffer Create and Initialize 
	clientDC = GetDC(hwnd);											// Get Client DC
	memDC = CreateCompatibleDC(clientDC);							// Create Memory DC
	g_Bitmap = CreateCompatibleBitmap(clientDC, w_width, w_height); // Create Memory Area
	SelectObject(memDC, g_Bitmap);									// Specify MemDC Memory Area 
	clientsize = { 0,0 };											// Buffer Size Saved POINT Init

	swap = new Swap(hwnd, w_width, w_height);
}

Render::~Render()
{
	DeleteObject(g_Bitmap);			// Delete Bitmap
	DeleteDC(memDC);				// Delete Memory DC
	ReleaseDC(hWnd, clientDC);		// Release Client DC
}

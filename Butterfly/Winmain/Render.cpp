#include "Render.h"

Render::Render(HWND hwnd) : hWnd(hwnd)
{
	memDC = CreateCompatibleDC(clientDC);
	g_Bitmap = CreateCompatibleBitmap(clientDC, g_width, g_height); // 메모리 영역생성
	SelectObject(memDC, g_Bitmap); // MemDC의 메모리영역 지정
}

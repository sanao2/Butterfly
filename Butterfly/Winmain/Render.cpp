#include "Render.h"

Render::Render(HWND hwnd) : hWnd(hwnd)
{
	memDC = CreateCompatibleDC(clientDC);
	g_Bitmap = CreateCompatibleBitmap(clientDC, g_width, g_height); // �޸� ��������
	SelectObject(memDC, g_Bitmap); // MemDC�� �޸𸮿��� ����
}

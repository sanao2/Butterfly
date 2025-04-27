#include "UIManager.h"


UIManager::UIManager(HWND hwnd, HDC _dc) : hWnd(hwnd), drawDC(_dc),
									 ObjPos{ 0,0 }, ObjSize{ 0,0 }
{
	drawDC = GetDC(hWnd); 
}

UIManager::~UIManager() {}

void UIManager::Render(HDC drawDC)
{

}


#include "UIManager.h"

UIManager::UIManager(HWND hwnd, int w_width, int w_height)
	: hWnd(hwnd), ObjPos{ 0,0 },
	ObjSize{ 0,0 }, clientsize{ w_width, w_height } {}

UIManager::~UIManager() {}

void UIManager::Update()
{
	// Update logic here
}

void UIManager::Render(HDC drawDC)
{
	PatBlt(drawDC, 0, 0, clientsize.x, clientsize.y, WHITENESS);
	Rectangle(drawDC,
		ObjPos.x,
		ObjPos.y,
		ObjPos.x + ObjSize.x,
		ObjPos.y + ObjSize.y);
}


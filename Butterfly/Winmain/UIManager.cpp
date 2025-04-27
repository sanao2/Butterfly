#include "UIManager.h"


UIManager::UIManager(HWND hwnd) : hWnd(hwnd), ObjPos{ 0,0 }, ObjSize{ 0,0 }
{
	memDC = CreateCompatibleDC(NULL);
}

UIManager::~UIManager() {}

void UIManager::Update()
{
	// Update logic here
}

void UIManager::Render(HDC drawDC)
{
	Rectangle(drawDC,
		ObjPos.x,
		ObjPos.y,
		ObjPos.x + ObjSize.x,
		ObjPos.y + ObjSize.y);
}


#pragma once
#include <Windows.h> 
#include <stdio.h>
#include <string>
using std::string;
using std::wstring;


class UIManager
{
private:
	HWND hWnd; 
	HDC drawDC; 
	POINT ObjPos;  // °´Ã¼ À§Ä¡ 
	POINT ObjSize; // °´Ã¼ Å©±â 

public:
	UIManager(HWND hwnd, HDC _dc);
	~UIManager();

	void SetObjPos(RECT rc) { ObjPos.x = (rc.right - rc.left); ObjPos.y = (rc.bottom - rc.top); }
	void SetObjSize(int x, int y) { ObjSize.x = x; ObjSize.y = y; }

	void DrawObj(HDC drawDC); // Object Draw 

	void Update();
	void Render(HDC drawDC);


};


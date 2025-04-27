#pragma once
#include <Windows.h> 
#include <stdio.h>
#include <string>
using std::string;
using std::wstring;


class UIManager
{
private:
	POINT ObjPos;  // °´Ã¼ À§Ä¡ 
	POINT ObjSize; // °´Ã¼ Å©±â 

public:
	UIManager();
	~UIManager();

	void SetObjPos(int x, int y) { ObjPos.x = x; ObjPos.y = y; }
	void SetObjSize(int x, int y) { ObjSize.x = x; ObjSize.y = y; }

	void CreateObj(HWND hWnd, HDC drawDC, RECT rc); // Object Create 
	void DrawObj(HDC drawDC); // Object Draw 

	void Update();
	void Render();


};


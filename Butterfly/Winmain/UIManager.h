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
	HDC memDC; 
	POINT ObjPos;  // ��ü ��ġ 
	POINT ObjSize; // ��ü ũ�� 

public:
	UIManager(HWND hwnd);
	~UIManager();

	void SetObjPos(RECT rc) { ObjPos.x = (rc.right - rc.left); ObjPos.y = (rc.bottom - rc.top); }
	void SetObjSize(int x, int y) { ObjSize.x = x; ObjSize.y = y; }

	void Update();
	void Render(HDC drawDC);


};


#pragma once
#include <Windows.h> 
#include <string>
using std::string;
using std::wstring;


class UIManager
{
private:
	HWND hWnd;
	POINT ObjPos;  // °´Ã¼ À§Ä¡ 
	POINT ObjSize; // °´Ã¼ Å©±â 

public:
	UIManager(HWND hwnd);
	~UIManager();

	void SetObjPos(int x, int y) { ObjPos = { x,y }; }
	void SetObjSize(int w, int h) { ObjSize = { w,h }; }

	void Update();
	void Render(HDC drawDC);


};


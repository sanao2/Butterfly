#pragma once
#include <Windows.h> 
#include <string>
using std::string;
using std::wstring;


class UIManager
{
private:
	HWND hWnd;
	POINT ObjPos;  // 객체 위치 
	POINT ObjSize; // 객체 크기 
	POINT clientsize; // 클라이언트 사이즈 

public:
	UIManager(HWND hwnd, int w_width, int w_height);
	~UIManager();

	void SetObjPos(int x, int y) { ObjPos = { x,y }; }
	void SetObjSize(int w, int h) { ObjSize = { w,h }; }
	    
	void Update();
	void Render(HDC drawDC);


};


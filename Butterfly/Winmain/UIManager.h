#pragma once
#include <Windows.h> 
#include <string>
using std::string;
using std::wstring;


class UIManager
{
private:
	HWND hWnd;
	POINT ObjPos;  // ��ü ��ġ 
	POINT ObjSize; // ��ü ũ�� 
	POINT clientsize; // Ŭ���̾�Ʈ ������ 
	HPEN  pen;
public:
	UIManager(HWND hwnd, int w_width, int w_height);
	~UIManager();

	void SetObjPos(int x, int y) { ObjPos = { x,y }; }
	void SetObjSize(int w, int h) { ObjSize = { w,h }; }

    void SetBrush(HDC _dc) {  
       pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // Corrected "RGP" to "RGB"  
       HBRUSH hBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
	   SelectObject(_dc, pen);
	   SelectObject(_dc, hBrush); 

    }

	void Update();
	void Render(HDC drawDC);


};


#pragma once  
#include "Global.h"  
#include <windows.h>  
#include "Swap.h"  
#include "Animation.h"  
#include <gdiplus.h>  
#pragma comment(lib, "gdiplus.lib")  

extern RECT playerPos; 

class Render  
{  
private:  
   HWND hWnd = nullptr;  
   POINT clientSize = {0,0};   
   HINSTANCE hInst;   
   HDC memDC = nullptr;  
   Gdiplus::Graphics* graphics = nullptr; // GDI+ �׷��Ƚ� ��ü  
   
   Swap* swap = nullptr;  
   Animation* animation = nullptr; // �ִϸ��̼� ��ü   
public:  
   Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height);  
   ~Render();  
   
   void Update();          // ���� ������Ʈ �� ���� ȣ��  
   void RenderScene(HINSTANCE hInst);     // ���� �׸��� ���� 
   POINT GetBufferSize() const;  
};
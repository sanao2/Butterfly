#pragma once  
#include "Global.h"  
#include <windows.h>  
#include "Swap.h"  
#include "Animation.h"  
#include <gdiplus.h>  
#include <atltypes.h>
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
   std::chrono::steady_clock::time_point lastInputTime;

   Move::MoveManager* moveMgr;
   Move::PlayerMoveController  playerController;
   Input::InputManager<Input::KeyboardDevice>& key = Input::InputManager<Input::KeyboardDevice>::GetInstance();
public:  
   Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height);  
   ~Render();  
   
   void Update();          // ���� ������Ʈ �� ���� ȣ��  
   void RenderScene(HINSTANCE hInst);     // ���� �׸��� ���� 
   void Moves(); 

   POINT GetBufferSize() const;  
};
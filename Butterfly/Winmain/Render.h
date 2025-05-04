#pragma once  
#include "Global.h"  
#include <windows.h>  
#include "Swap.h"  
#include "Animation.h"  
#include <gdiplus.h>  
#include <atltypes.h>
#pragma comment(lib, "gdiplus.lib")  

extern RECT playerPos; 

/*
if (key.IsKeyDown(VK_RIGHT) && time == 100)
		{
			// 해당 애니메이션 이 움직입니다.
		}
*/
class Render  
{  
private:  
   HWND hWnd = nullptr;  
   POINT clientSize = {0,0};   
   HINSTANCE hInst;   
   HDC memDC = nullptr;  
   Gdiplus::Graphics* graphics = nullptr; // GDI+ 그래픽스 객체  

   Move::MoveManager* moveMgr;
   Move::PlayerMoveController  playerController;
   Input::InputManager<Input::KeyboardDevice>& key = Input::InputManager<Input::KeyboardDevice>::GetInstance();
   Move::MoveDirection lastDir = Move::MoveDirection::Down;
   std::chrono::steady_clock::time_point lastInputTime;

   Swap* swap = nullptr;  
   Animation* animation = nullptr; // 애니메이션 객체    
    
public:  
   Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height);  
   ~Render();  
   
   void Update();          // 렌더 업데이트 및 스왑 호출  
   void RenderScene(HINSTANCE hInst);     // 실제 그리기 동작 
   void MoveDirection();
   Animstate MoveDirstate(); 

   POINT GetBufferSize() const;  
};
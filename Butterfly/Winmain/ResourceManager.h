#pragma once
#include "Global.h" 
#include <windows.h>
#include <cstdint> 
#include "AnimationMap.h"
#include "ImageResource.h"
#include "IImageRenderer.h"
#include "GdiplusImageRenderer.h" // Ensure this header is included
#include "Move/MoveManagers.h"
#include "Move/PlayerMoveController.h"
#include "Swap.h"
#include "resource.h"
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

extern Animstate current_state; 
extern const wchar_t RESOURCE_TYPE[];

/*
if (key.IsKeyDown(VK_RIGHT) && time == 100)
		{
			// 해당 애니메이션 이 움직입니다.
		}
*/

class ResourceManager  
{  
public : 
    vector<Gdiplus::Image*> AnimationFrames;
	
private:  
   ImageResource*				imageResource = nullptr;  
   IImageRenderer*				imageRenderer = nullptr; 

   Swap* swap = nullptr; 
  
   HINSTANCE hInst = nullptr;  

   ULONG_PTR GdiPlusToken;  
   Gdiplus::Graphics* graphics = nullptr;  
   Gdiplus::Image* image = nullptr;  
   bool isLoaded = false;  


public:  
	ResourceManager() = delete;
   ResourceManager(HDC drawDC, HINSTANCE hInstance);
   ~ResourceManager();  
    
   void LoadeFrames(HINSTANCE hInst);  
   void RenderFrame(Gdiplus::Graphics* graphics, RECT& rect, int x, int y, int frameIndex);
  
   bool IsLoaded() const { return isLoaded; } 
   void SetIsLoaded(bool loaded) { isLoaded = loaded; } 


};


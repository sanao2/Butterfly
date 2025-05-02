#pragma once
#include "Global.h" 
#include <windows.h>
#include <cstdint> 
#include <gdiplus.h>
#include "AnimationMap.h"
#pragma comment(lib, "gdiplus.lib")
#include "ImageResource.h"
#include "IImageRenderer.h"
#include "GdiplusImageRenderer.h" // Ensure this header is included
#include "resource.h"
#include <iostream>
#include <vector>

using namespace std; 
using std::vector;

extern Animstate current_state; 
extern const wchar_t RESOURCE_TYPE[];

class ResourceManager  
{  
protected : 
    vector<Gdiplus::Image*> AnimationFrames;

private:  
   ImageResource* imageResource = nullptr;  
   IImageRenderer* imageRenderer = nullptr;  

   HINSTANCE hInst = nullptr;  

   ULONG_PTR GdiPlusToken;  
   Gdiplus::Graphics* graphics = nullptr;  
   Gdiplus::Image* image = nullptr;  
   bool isLoaded = false;  

public:  
   ResourceManager() = default;  
   ResourceManager(HDC drawDC, HINSTANCE hInstance);  
   ~ResourceManager();  
     
   void Initialize(HDC drawDC, HINSTANCE hInstance);  
   void LoadeFrames(HINSTANCE hInst);  
   void UnloadFrames(); 
   void RenderFrame(Gdiplus::Graphics* graphics, int x, int y, int frameIndex);  



};


#pragma once
#include <windows.h>
#include <vector>
#include <iostream>
#include <gdiplus.h>
#include <memory>
#include "UI/Timer.h"
#include "resource.h"
#include "AnimationMap.h"
#include "ResourceManger.h" 
#pragma comment(lib, "gdiplus.lib")
using std::vector;
using std::wstring;

extern int g_width;
extern int g_height;

class Animation
{
private:
    HDC clientDC = nullptr;
    HDC memDC = nullptr;
    HINSTANCE hInst = nullptr;

    static Animstate currAnim;
    static Animstate prevAnim;

    float DeltaTime = 0.0f;
    float frameTime = 0.0f;
    float TotalTime = 0.0f;
    int frameCount = 0;

    Time::Timer<> timer;
    ResourceManger* ResMgr = nullptr; 

    ULONG_PTR GdiplusToken;
    Gdiplus::GdiplusStartupInput gsi;   
    Gdiplus::Graphics* backDCgraphics = nullptr;
    HBITMAP hBitmap = nullptr;
    Gdiplus::Image* Image = nullptr;

public:
    Animation(HWND hwnd, int width, int height);
    ~Animation();

    void createAnimation(HINSTANCE hInst, float frameTime);
    void Update();
    void Render(HDC drawDC);

    void SetcurrAnimState(Animstate animstate) { currAnim = animstate; }
    Animstate GetcurrAnimState() { return currAnim; }
};
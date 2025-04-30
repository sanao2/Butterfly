#include "Animation.h"

Animstate Animation::currAnim = PLAYER_DEFAULT;
Animstate Animation::prevAnim = PLAYER_DEFAULT;

Animation::Animation(HWND hwnd, int width, int height)
{
    clientDC = GetDC(hwnd);
}

Animation::~Animation()
{
    if (bitmap)
    {
        delete bitmap;
        bitmap = nullptr;
    }
    if (backDCgraphics)
    {
        delete backDCgraphics;
        backDCgraphics = nullptr;
    }
    if (hBitmap)
    {
        DeleteObject(hBitmap);
        hBitmap = nullptr;
    }
    if (memDC)
    {
        DeleteDC(memDC);
        memDC = nullptr;
    }
    Gdiplus::GdiplusShutdown(GdiplusToken);
}

void Animation::createAnimation(HINSTANCE hInst, float frameTime)
{
    this->hInst = hInst;
    this->frameTime = frameTime;
    
}

void Animation::Initialize()
{
    Gdiplus::GdiplusStartup(&GdiplusToken, &gsi, nullptr);

    memDC = CreateCompatibleDC(nullptr);
    hBitmap = CreateCompatibleBitmap(GetDC(nullptr), g_width, g_height);
    SelectObject(memDC, hBitmap);

    backDCgraphics = new Gdiplus::Graphics(memDC);

    timer.Elapsed();
  
}

void Animation::Update()
{
    DeltaTime = timer.Elapsed();
    TotalTime += DeltaTime;

    if (TotalTime >= frameTime)
    {
        currFrame++;
        TotalTime = 0.0f;
      
        auto it = AnimStateFrameMap.find(currAnim);
        if (it == AnimStateFrameMap.end()) {
            // 키가 없으면 건너뛰거나 기본값 처리
            return; 
        }
        size_t frameCount = it->second.ImageID.size();
       
        if (currFrame >= frameCount)
            currFrame = 0;
    }

    timer.Reset();
}

void Animation::Render(HDC drawDC)
{
    int frameID;
    for (currFrame = 0; currFrame < PLAYER_ANIMCOUNT; ++currFrame)
    {
       frameID = GetAnimationFrameID(currAnim, currFrame);
    }   
  
   
}
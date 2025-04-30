#include "Animation.h"

Animstate Animation::currAnim = PLAYER_DEFAULT;
Animstate Animation::prevAnim = PLAYER_DEFAULT;

Animation::Animation(HWND hwnd, int width, int height)
{
    clientDC = GetDC(hwnd);
    ULONG_PTR token;
    Gdiplus::GdiplusStartupInput gsi;
    Gdiplus::GdiplusStartup(&GdiplusToken, &gsi, nullptr);
    backDCgraphics = new Gdiplus::Graphics(memDC);

    timer.Elapsed();
}

Animation::~Animation()
{
    if (Image)
    {
        Image = nullptr;
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
    // 리소스 매니저를 통해 이미지 로드 
    ResMgr->LoadImages(hInst); // 리소스 매니저를 통해 이미지 로드 

}

void Animation::Update()
{
    DeltaTime = timer.Elapsed();
    TotalTime += DeltaTime;

    if (TotalTime >= frameTime)
    {
        frameCount++;
        TotalTime = 0.0f;
      
        auto it = AnimStateFrameMap.find(currAnim);
        if (it == AnimStateFrameMap.end()) {
            // 키가 없으면 건너뛰거나 기본값 처리
            return; 
        }
        size_t frameCount = it->second.ImageID.size();
       
        if (frameCount >= frameCount)
            frameCount = 0;
    }

    timer.Reset();
}

void Animation::Render(HDC drawDC)
{
    for (frameCount = 0; frameCount < PLAYER_ANIMCOUNT; ++frameCount)
    {
        RESOURCE_ID[frameCount] = GetAnimationFrameID(currAnim, frameCount);
    }     

    ResMgr->RenderImage(*backDCgraphics, 0, 0); // 이미지를 그리기 
 
}
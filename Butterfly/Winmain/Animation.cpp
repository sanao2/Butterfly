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

    // ���ҽ� �Ŵ����� ���� �̹��� �ε�
     for (frameCount = 0; frameCount < 6; ++frameCount)
    {
        for (int i = 0; i < 6; ++i)
        {
          RESOURCE_ID[frameCount] = GetAnimationFrameID(currAnim, frameCount);
        }  
    }

    ResMgr->LoadImages(hInst); // ���ҽ� �Ŵ����� ���� �̹��� �ε� 

}

void Animation::Update()
{

    DeltaTime = timer.Elapsed();
    TotalTime += DeltaTime;

    try {
    if (TotalTime >= frameTime)
    {
        frameCount++;
        TotalTime = 0.0f;
      
        auto it = AnimStateFrameMap.find(currAnim);
        if (it == AnimStateFrameMap.end()) {
            // Ű�� ������ �ǳʶٰų� �⺻�� ó��
            return; 
        }
        size_t frameCount = it->second.ImageID.size();
       
        if (frameCount >= frameCount)
            frameCount = 0;
    }

    timer.Reset();
    }
    catch (const std::exception& e) {
        std::cerr << "Animation::Update ���� �߻�: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Animation::Update �� �� ���� ���� �߻�" << std::endl;
    }
}

void Animation::Render(HDC drawDC)
{	

    ResMgr->RenderImage(*backDCgraphics,Image, 0, 0); // �̹����� �׸��� 
 
}
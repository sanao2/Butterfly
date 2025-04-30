#include <windows.h> 
#include "ResourceManger.h" 
#include "AnimationMap.h" 
#include <vector> 
#include <iostream> 
#include "AnimationMap.h"
#include "UI/Timer.h"
#include "ImageResource.h"
#include "IImageRenderer.h"
#include "GdiplusImageRenderer.h"
#pragma comment(lib, "gdiplus.lib")
using std::vector; 
using namespace std; 

class Animation
{
private : 
	HINSTANCE hInst; 
	ImageResource* imageResource = nullptr;
	IImageRenderer* imageRenderer = nullptr;

	ULONG_PTR GdiPlusToken;
	HBITMAP hBitmap = nullptr;
	Gdiplus::Graphics* graphics = nullptr;
	Gdiplus::Image* image = nullptr;

	Time::Timer<> timer;
	float deltaTime = 0.0f; 
	float totalTime = 0.0f; 
	float frameTime = 0.0f;

public : 
	Animation(HDC drawDC, HINSTANCE hInst);
	~Animation(); 
	void Update();	
	void LoadAnimationFrame();
	 
};

//class Animation
//{
//private:
//    HDC clientDC = nullptr;
//    HDC memDC = nullptr;
//    HINSTANCE hInst = nullptr;
//
//    static Animstate currAnim;
//    static Animstate prevAnim;
//
//    float DeltaTime = 0.0f;
//    float frameTime = 0.0f;
//    float TotalTime = 0.0f;
//    int frameCount = 0;
//
//    Time::Timer<> timer;
//    ResourceManger* ResMgr = nullptr; 
//
//    ULONG_PTR GdiplusToken;
//    Gdiplus::GdiplusStartupInput gsi;   
//    Gdiplus::Graphics* backDCgraphics = nullptr;
//    HBITMAP hBitmap = nullptr;
//    Gdiplus::Image* Image = nullptr;
//
//public:
//    Animation(HWND hwnd, int width, int height);
//    ~Animation();
//
//    void createAnimation(HINSTANCE hInst, float frameTime);
//    void Update();
//    void Render(HDC drawDC);
//
//    void SetcurrAnimState(Animstate animstate) { currAnim = animstate; }
//    Animstate GetcurrAnimState() { return currAnim; }
//};
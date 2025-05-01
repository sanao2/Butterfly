#include "Global.h"
#include <windows.h> 
#include <vector> 
#include <iostream> 
#include "UI/Timer.h"
#include "ResourceManger.h"
#pragma comment(lib, "gdiplus.lib")
using std::vector; 
using namespace std; 


class Animation 
{
private : 
	HINSTANCE hInst; 

	ULONG_PTR GdiPlusToken;
	Gdiplus::Graphics* graphics = nullptr;
	Gdiplus::Image* image = nullptr;

	Time::Timer<> timer;
	ResourceManger* ResMgr = nullptr; 
	int current_frame = 0;

public : 
	Animation(HDC drawDC, HINSTANCE hInstance);
	~Animation(); 
	void Update();	

};

//
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
//   
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
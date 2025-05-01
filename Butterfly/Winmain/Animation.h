#include "Global.h"
#include <windows.h> 
#include <vector> 
#include <iostream> 
#include "UI/Timer.h"
#include "ImageResource.h"
#include "GdiplusImageRenderer.h"
#pragma comment(lib, "gdiplus.lib")
using std::vector; 
using namespace std; 

extern const wchar_t RESOURCE_TYPE[]; 
extern vector<Gdiplus::Image*> AnimationFrames;
extern int current_frame;

class Animation 
{
private : 
	HINSTANCE hInst; 

	ULONG_PTR GdiPlusToken;
	Gdiplus::Graphics* graphics = nullptr;
	Gdiplus::Image* image = nullptr;

	Time::Timer<> timer;
	ImageResource* imageResource = nullptr;
	
public : 
	Animation(HDC drawDC, HINSTANCE hInst);
	~Animation(); 
	void Update();	
	void RednerFrame(Gdiplus::Graphics graphics, int x, int y, int frameIndex);
	void LoadAnimationFrame(HINSTANCE hInst);
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
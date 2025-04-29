#include "Animation.h"

Animation::Animation(HWND hwnd,int width, int height ) : hWnd(hwnd)
{
	clientDC = GetDC(hWnd);
	memDC = CreateCompatibleDC(clientDC);
	hInst = GetModuleHandle(nullptr);

	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&GdiplusToken, &gsi, nullptr);
	backDCgraphics = Gdiplus::Graphics::FromHDC(memDC);
}

Animation::~Animation()
{
	delete backDCgraphics;
	Gdiplus::GdiplusShutdown(GdiplusToken);
	ReleaseDC(hWnd, clientDC);
	DeleteDC(memDC);
}

void Animation::createAnimation(HINSTANCE hInst)  
{  
   if (!frameId.empty()) return;

   for (int i = 0; i < PLAYER_ANIMCOUNT; ++i)
   {
	   auto frames = GetAnimationFrameID(currAnim, i);
	   frameId.push_back({ static_cast<Animstate>(frames) }); // Properly store the frame in the vector

	   Gdiplus::Bitmap* Images = Gdiplus::Bitmap::FromBITMAPINFO(
		   hInst , 
		   MAKEINTRESOURCE(frames),
		   L"PNG"
	   )

	   if (bmp.GetLastStatus() == Gdiplus::Ok)
	   {
		   UINT width = bmp.GetWidth(); 
		   UINT height = bmp.GetHeight();
	   }
   
      
   }  

   
}

void Animation::findAnimation(Animstate animState, int frameIndex)
{	
	auto ResPath = GetAnimationFrameID(animState, frameIndex);

	
	
}

void Animation::Initialize()
{
	Time::InitTime(); // Timer Initialization
}

void Animation::Update()
{
	Time::UpdateTime();
	DeltaTime = Time::GetDeltaTime(); // Get Frame deltaTime 


}
	

void Animation::Render()
{
}

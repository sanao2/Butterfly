#include "Animation.h"

Animation::Animation(HWND hwnd,int width, int height ) : hWnd(hwnd)
{
	clientDC = GetDC(hWnd);
	memDC = CreateCompatibleDC(clientDC);
	hInst = GetModuleHandle(nullptr);

	
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

void Animation::createAnimation(HINSTANCE hInst, float frameTime)  
{  
   if (!frames.empty()) return;

   for (int i = 0; i < PLAYER_ANIMCOUNT; ++i)
   {
	   auto frame = GetAnimationFrameID(currAnim, i);

	   frames.push_back({ static_cast<Animstate>(frame) }); // Properly store the frame in the vector
   }     
}

vector<int> Animation::findAnimation(Animstate animState)
{	
	return frames[static_cast<int>(animState)];
}

void Animation::Initialize()
{
	Time::InitTime(); 
	TotalTime = Time::GetTotalTime(); 
	DeltaTime = Time::GetDeltaTime(); 
}

void Animation::Update()
{	
	Time::UpdateTime();
	frameTime += DeltaTime;

	if (frameTime >= timer.IsElapsed(5.0f)) {
		timer.Reset();  // Timer Reset 
		currFrame = (currFrame + 1) % frames.size();
	}
	
	return;
}
	

void Animation::Render()
{
}

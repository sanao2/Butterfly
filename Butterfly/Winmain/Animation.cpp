#include "Animation.h"

Animstate Animation::currAnim = PLAYER_IDLE;

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
    frames.resize(PLAYER_ANIMCOUNT);

    for (int state = 0; state < PLAYER_ANIMCOUNT; ++state) {
        int frameCount = AnimStateFrameMap.at(static_cast<Animstate>(state)).ImageID.size();
      
        for (int i = 0; i < frameCount; ++i) {
            frames[state].push_back( GetAnimationFrameID(static_cast<Animstate>(state), i));
        }
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
		currFrame = (currFrame + 1) % frames[currAnim].size();
	}
	
	return;
}
	

void Animation::Render()
{
}

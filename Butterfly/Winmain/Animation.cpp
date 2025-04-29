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

}

void Animation::createAnimation()  
{  
   if (!frame.empty()) return;  

   for (int i = 0; i < PLAYER_ANIMCOUNT; ++i)  
   {  
       auto frames = GetAnimationFrameID(currAnim, i);  
       frame.push_back({ static_cast<Animstate>(frames) }); // Properly store the frame in the vector  
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
	deltaTime = Time::GetDeltaTime(); // Get Frame deltaTime 

	if ()


}
	

void Animation::Render()
{
}

#include "Animation.h"

Animation::Animation(HWND hwnd,int width, int height ) : hWnd(hwnd)
{
	hInst = GetModuleHandle(nullptr);
	ResMgr = new ResourceManager(hwnd, width, height);
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

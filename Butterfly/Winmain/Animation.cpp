#include "Animation.h"

Animation::Animation()
{
	hInst = GetModuleHandle(nullptr);
}

Animation::~Animation()
{
}



void Animation::createAnimation()
{
	if (!frame.empty()) return; 

	for (int i = 0; i < PLAYER_ANIMCOUNT; ++i)
	{
		auto frames = GetAnimMotionImage(currAnim, i);
	}
}

void Animation::findAnimation(Animstate animState, int frameIndex)
{
	
	
	auto ResPath = GetAnimMotionImage(animState, frameIndex);

	HRSRC hResInfo = FindResource(hInst,
					 MAKEINTRESOURCE(ResPath),
					 RT_BITMAP
					 );
}

void Animation::Initialize()
{
	Time::InitTime(); // Timer Initialization
}

void Animation::Update()
{
	Time::UpdateTime();
	DeltaTime = Time::GetDeltaTime(); // Get Frame deltaTime 
	
	if ()


}
	

void Animation::Render()
{
}

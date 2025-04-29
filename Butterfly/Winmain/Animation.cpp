#include "Animation.h"

Animation::Animation()
{
	Gtimer = &Time::GlobalTimer::GetInstance();
	
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

void Animation::findAnimation()
{
}

void Animation::Initialize()
{
	Time::InitTime(); // Timer Initialization
	TimeInstance.Init();
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

#include "Animation.h"

Animation::~Animation()
{
}



void Animation::findAnimation()
{
}

void Animation::Initialize()
{
	Time::InitTime(); // Timer Initialization
}

void Animation::Update()
{
	Time::UpdateTime();
	DeltaTime = Time::GetDeltaTime(); // Get Frame deltaTime 
	
	for (int i = 0; i < PLAYER_ANIMCOUNT; i++)
	{
		int AnimImage = GetAnimMotionImage(currAnim, i);
	}

}
	

void Animation::Render()
{
}

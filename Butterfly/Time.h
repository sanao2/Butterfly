#pragma once
#include <chrono>

namespace Time
{
	void InitTime();
	void UpdateTime();
	float GetDeltaTime();
	float GetTotalTime();
}
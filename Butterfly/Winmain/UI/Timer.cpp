#include "Timer.h"

namespace Time
{
	GlobalTimer::GlobalTimer()
		: start{}, last{}, deltaTime{0.0f}, totalTime{0.0f}
	{}

	GlobalTimer& GlobalTimer::GetInstance()
	{
		static GlobalTimer instance;
		return instance;
	}

	void GlobalTimer::Init()
	{
		start = Clock::now();
		last = start;
	}

	void GlobalTimer::Update()
	{
		TimePoint now = Clock::now();
		deltaTime = std::chrono::duration_cast<Duration>(now - last).count();
		totalTime = std::chrono::duration_cast<Duration>(now - start).count();
		last = now;
	}

	float GlobalTimer::GetDeltaTime() const { return deltaTime; }
	float GlobalTimer::GetTotalTime() const { return totalTime; }

	void InitTime() { GlobalTimer::GetInstance().Init(); }
	void UpdateTime() { GlobalTimer::GetInstance().Update(); }
	float GetDeltaTime() { return GlobalTimer::GetInstance().GetDeltaTime(); }
	float GetTotalTime() { return GlobalTimer::GetInstance().GetTotalTime(); }
}

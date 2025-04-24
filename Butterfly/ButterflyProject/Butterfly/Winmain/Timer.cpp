#include "Timer.h"

	void Timer::TimeShoutdown()
	{		
		system("cls");
	}

	void Timer::TimeRender()
	{
		printf("경과 시간 : %.3f\n", deltatime);
	}

	Timer::Timer(double time) : cur_Time(time)
	{
		startclock = clock(); 
		endclock = clock(); 
		deltatime = (double)(endclock - startclock) / CLOCKS_PER_SEC;
	}

	Timer::~Timer()
	{
		TimeReset();
		TimeShoutdown();
		
	}

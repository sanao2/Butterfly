#pragma once
#include <time.h>
#include <windows.h>
#include <stdio.h>


class Timer
{
private : 
	clock_t startclock;		// startTime 
	clock_t endclock;		// endTime 
	double  deltatime;		// deltaTime 
	double  cur_Time = 0;    // currentTime 

public:
	void TimeReset() { deltatime = 0; };
	void TimeShoutdown(); // Time ShotDown
	void TimeRender();	  // Time Render 

	// Timer Get code 
	clock_t GetStartTime() { return startclock;  }
	clock_t GetEndTime() { return startclock;  }

	Timer(double time);   // Timer Create 
	~Timer();			  // Timer Delete  
};

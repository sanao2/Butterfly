#pragma once
#include <time.h>
#include <windows.h>
#include <stdio.h>


class Timer
{
private : 
	clock_t startTime;		// startTime 
	clock_t endTime;		// endTime 
	double  deltatime;		// deltaTime 
	double  cur_Time = 0;    // currentTime 

public:
	void TimeReset() { deltatime = 0; }; // Time Reset 
	void TimeShoutdown();				 // Time ShotDown
	void TimeRender();					 // Time Render 

	// Timer Get code 
	clock_t GetStartTime() { return startTime;  }
	clock_t GetEndTime() { return startTime;  }
	void SetStartTime(double curTime) { startTime = curTime;  }

	Timer(double time);   // Timer Create 
	~Timer();			  // Timer Delete  
};

#pragma once
#include <chrono>

namespace Time
{
	using Clock = std::chrono::high_resolution_clock;
    using TimePotint = std::chrono::time_point<Clock>;
    using Duration = std::chrono::duration<float>;

    class GlobalTimer
    {
      public:
        static GlobalTimer& Instance()
        {
          static GlobalTimer instance;
          return instance;
        }

        void Init()
        {
          start = Clock::now();
          last = start;
        }

        void Update()
        {
        }
    }
}
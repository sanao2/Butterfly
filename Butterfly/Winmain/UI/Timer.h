#pragma once
#include <chrono>

namespace Time
{
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = std::chrono::time_point<Clock>;
    using Duration = std::chrono::duration<float>;

    class GlobalTimer
    {
    public:
        static GlobalTimer& GetInstance();

        void Init();
        void Update();

        float GetDeltaTime() const;
        float GetTotalTime() const;

    private:
        GlobalTimer();

        TimePoint start;
        TimePoint last;
        float deltaTime;
        float totalTime;
    };

    void InitTime();
    void UpdateTime();
    float GetDeltaTime();
    float GetTotalTime();

    template<typename Tag = void>
    class Timer
    {
    public:
        Timer() { Reset(); }

        void Reset() { start = Clock::now(); }

        float Elapsed() const
        {
            return std::chrono::duration_cast<Duration>(Clock::now() - start).count();
        }

        bool IsElapsed(float seconds) const
        {
            return Elapsed() >= seconds;
        }

    private:
        TimePoint start;
    };
} 
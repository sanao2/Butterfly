#include "Timer.h"
#include <iostream>

int main()
{
    Time::InitTime();
    Time::Timer<struct GrowTimerTag> growTimer;

    while (true)
    {
        Time::UpdateTime();

        float delta = Time::GetDeltaTime();
        float total = Time::GetTotalTime();
        std::cout << "DeltaTime: " << delta << " | TotalTime: " << total << std::endl;

        if (growTimer.IsElapsed(5.0f))
        {
            std::cout << "작물이 성장했습니다!" << std::endl;
            growTimer.Reset(); // 다시 성장 타이머 시작
        }

        Sleep(100); // 0.1초 대기
    }

    return 0;
}

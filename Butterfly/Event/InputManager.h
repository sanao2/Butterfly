#pragma once
#include <Windows.h>
#include <array>

namespace Input
{
    template<typename DeviceType>
    class InputManager;

    sturct KeyboardDevice {};

    template<>
    class InputManager<KeyboardDevice>
    {
      public:
        static InputManager& GetInstance()
        {
          static InputManager instance;
          return instance;
        }

        void Update()
        {
          std::memcpy(prevState.data(), currState.data(), sizeof(SHORT) * 256);
          for(int i =0; i < 256; ++i)
          {
            currState[i] = GetAsyncKeyState(i);
          }
        }

        bool IsKeyDown(int vKey) const
        {
          return (currState[vKey] & 0x8000) != 0;
        }
    }

    void Update();
    bool IsKeyDown(int vKey);
    bool IsKeyPressed(int vKey);
    bool IsKeyReleased(int vKey);
}
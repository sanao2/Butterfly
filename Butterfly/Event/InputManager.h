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
    }

    void Update();
    bool IsKeyDown(int vKey);
    bool IsKeyPressed(int vKey);
    bool IsKeyReleased(int vKey);
}
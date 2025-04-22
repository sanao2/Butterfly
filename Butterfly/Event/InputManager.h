#pragma once
#include <Windows.h>
#include <array>

namespace Input
{
    constexpr int MAX_KEY_COUNT = 256;
    constexpr SHORT KEY_PRESSED_FLAG = 0x8000;

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
          std::memcpy(prevState.data(), currState.data(), sizeof(SHORT) * MAX_KEY_COUNT);
          for(int i =0; i < MAX_KEY_COUNT; ++i)
          {
            currState[i] = GetAsyncKeyState(i);
          }
        }

        bool IsKeyDown(int vKey) const
        {
          return (currState[vKey] & KEY_PRESSED_FLAG) != 0;
        }

        bool IsKeyPressed(int vKey) const
        {
          return (!(prevState[vKey] & KEY_PRESSED_FLAG) && (currState[vKey] & KEY_PRESSED_FLAG));
        }

        bool IsKeyReleased(int vKey) const
        {
          return ((prevState[vKey] & KEY_PRESSED_FLAG) && !(currState[vKey] & KEY_PRESSED_FLAG));
        }

        private:
          InputManager() = default;
          ~InputManager() = default;

          InputManager(const InputManager&) = delete;
          InputManager& oprator=(const InputManager&) = delete;

          std::array<SHORT, MAX_KEY_COUNT> prevState;
          std::array<SHORT, MAX_KEY_COUNT> currState;
    }

    using Keybard = InputManager<KeyboardDevice>;
}
#pragma once
#include "InputManager.h"

namespace Input
{
    struct KeyboardDevice {};

    template<>
    class InputManager<KeyboardDevice>
    {
    public:
        static InputManager& GetInstance(); // Keyboard GetInstance

        void Update();
        bool IsKeyDown(int vKey) const;
        bool IsKeyPressed(int vKey) const;
        bool IsKeyReleased(int vKey) const;

    private:
        InputManager() = default;
        ~InputManager() = default;

        InputManager(const InputManager&) = delete;
        InputManager& operator=(const InputManager&) = delete;

        std::array<SHORT, Input::MAX_KEY_COUNT> prevState{};
        std::array<SHORT, Input::MAX_KEY_COUNT> currState{};
    };
}
#pragma once
#include "IMoveController.h"
#include "../Event/KeyboardInputManager.h"

namespace Move
{
    class PlayerMoveController : public IMoveController
    {
    public:
        explicit PlayerMoveController(Input::InputManager<Input::KeyboardDevice>& key)
            : key(key) {}

        MoveDirection GetDirection() override
        {
            key.Update();
            if (key.IsKeyPressed(VK_RIGHT)) return MoveDirection::Right;
            if (key.IsKeyPressed(VK_LEFT))  return MoveDirection::Left;
            if (key.IsKeyPressed(VK_UP))    return MoveDirection::Up;
            if (key.IsKeyPressed(VK_DOWN))  return MoveDirection::Down;

        /*    if (key.IsKeyDown(VK_RIGHT)) return MoveDirection::Right;
            if (key.IsKeyDown(VK_LEFT)) return MoveDirection::Left;
            if (key.IsKeyDown(VK_UP)) return MoveDirection::Up;
            if (key.IsKeyDown(VK_DOWN)) return MoveDirection::Down;*/
            return MoveDirection::None;
        }

    private:
        Input::InputManager<Input::KeyboardDevice>& key;
    };
}

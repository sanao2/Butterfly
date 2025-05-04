#pragma once
#include <cmath>
#include <Windows.h>
#include "../Event/KeyboardInputManager.h"

namespace Move
{
    enum class MoveDirection { None, Left, Right, Up, Down };

    class MoveManager
    {
    public:
        //real code
        explicit MoveManager(Input::InputManager<Input::KeyboardDevice>& keyRef, RECT& rect);
        ~MoveManager();

        void MoveUpdate();
        bool IsMoving() const;

        bool GetIsMoving() const { return isMoving; }
        void SetIsMoving(bool state) { isMoving = state; }

    private:
        void MoveKeyInput();
        void MoveKeyRelease();
        void ApplyMovement(MoveDirection dir); 

    private:
        Input::InputManager<Input::KeyboardDevice>& key;
        bool isMoving = false;
        POINT movePos = {};
        RECT& playerRect;
    };
}

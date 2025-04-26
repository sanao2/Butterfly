#include "KeyboardInputManager.h"
#include <cstring>

namespace Input
{
    InputManager<KeyboardDevice>& InputManager<KeyboardDevice>::GetInstance()
    {
        static InputManager instance; // Singleton Instance Get Code 
        return instance;
    }

    void InputManager<KeyboardDevice>::Update()
    {
        //std::memcpy(prevState.data(), currState.data(), sizeof(SHORT) * MAX_KEY_COUNT);

        std::copy(currState.begin(), currState.end(), prevState.begin());

        for (int i = 0; i < MAX_KEY_COUNT; ++i)
        {
            currState[i] = GetAsyncKeyState(i);
        }
    }

    bool InputManager<KeyboardDevice>::IsKeyDown(int vKey) const  // key Button Down 
    {
        if (vKey < 0 || vKey >= Input::MAX_KEY_COUNT) return false;

        return (currState[vKey] & KEY_PRESSED_FLAG) != 0;
    }

    bool InputManager<KeyboardDevice>::IsKeyPressed(int vKey) const // key Button Pressed
    {
        if (vKey < 0 || vKey >= Input::MAX_KEY_COUNT) return false;

        return (!(prevState[vKey] & KEY_PRESSED_FLAG) && (currState[vKey] & KEY_PRESSED_FLAG));
    }

    bool InputManager<KeyboardDevice>::IsKeyReleased(int vKey) const  // Key Button Up 
    {
        return ((prevState[vKey] & KEY_PRESSED_FLAG) && !(currState[vKey] & KEY_PRESSED_FLAG));
    }

 
}

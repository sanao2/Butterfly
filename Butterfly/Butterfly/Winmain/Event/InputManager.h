#pragma once
#include <Windows.h>
#include <array>
#include "InputConstants.h"

namespace Input
{
    template<typename DeviceType>
    class InputManager;

    struct KeyboardDevice;

    using Keyboard = InputManager<KeyboardDevice>;
}

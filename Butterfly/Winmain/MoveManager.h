#pragma once

#include "Event/KeyboardInputManager.h"
using namespace Input;

class MoveManager
{
private : 
	InputManager<KeyboardDevice>& key = InputManager<KeyboardDevice>::GetInstance(); // Get KeyboardManaager Instance 

public : 
	void MoveUpdate(InputManager<KeyboardDevice>& key);
	void MoveInput(RECT& rect, InputManager<KeyboardDevice>& key);
};


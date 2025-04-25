#pragma once
#include <cmath>
#include "Event/KeyboardInputManager.h"
using namespace Input;

class MoveManager
{
private:
	InputManager<KeyboardDevice>& key = InputManager<KeyboardDevice>::GetInstance(); // Get KeyboardManaager Instance 
	RECT& rect;
	bool isMoving = false;
	POINT movePos = {};

public:
	void MoveUpdate(InputManager<KeyboardDevice>& key);
	void MoveKeyInput(InputManager<KeyboardDevice>& key, RECT& rc);
	void MoveKeyRelese(InputManager<KeyboardDevice>& key);

	bool IsMoving();

	bool GetIsMoving() { return isMoving; }
	void SetIsMoving(bool MovingState) { isMoving = MovingState; }

	MoveManager(InputManager<KeyboardDevice>& key, RECT& rc);
	~MoveManager();

};
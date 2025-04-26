#pragma once
#include <cmath>
#include <Windows.h>
#include "../Event/KeyboardInputManager.h"

class MoveManager
{
public:
	explicit MoveManager(Input::InputManager<Input::KeyboardDevice>& keyREf, RECT& rc);
	~MoveManager();

	void MoveUpdate(); // InputManager 인자를 제거하고 내부 인스턴스 사용
	bool IsMoving() const;

	bool GetIsMoving() const { return isMoving; }
	void SetIsMoving(bool state) { isMoving = state; }

private:
	void MoveKeyInput();
	void MoveKeyRelease();

private:
	Input::InputManager<Input::KeyboardDevice>& key;
	RECT& rect;
	bool isMoving = false;
	POINT movePos = {};
};

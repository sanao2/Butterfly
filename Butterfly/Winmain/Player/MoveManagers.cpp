#include "MoveManagers.h"

void MoveManager::MoveUpdate()
{
	key.Update();
	MoveKeyInput();
	MoveKeyRelease();
}

void MoveManager::MoveKeyInput()
{
	int rcWidth = rect.right - rect.left;
	int rcHeight = rect.bottom - rect.top;
	int moveSpeed = rcWidth;

	movePos = {
		(rect.left + rect.right) / 2,
		(rect.top + rect.bottom) / 2
	};

	isMoving = false;

	if (key.IsKeyPressed(VK_RIGHT))
	{
		isMoving = true;
		movePos.x += moveSpeed;
	}
	if (key.IsKeyPressed(VK_LEFT))
	{
		isMoving = true;
		movePos.x -= moveSpeed;
	}
	if (key.IsKeyPressed(VK_DOWN))
	{
		isMoving = true;
		movePos.y += moveSpeed;
	}
	if (key.IsKeyPressed(VK_UP))
	{
		isMoving = true;
		movePos.y -= moveSpeed;
	}

	rect.left = movePos.x - rcWidth / 2;
	rect.top = movePos.y - rcHeight / 2;
	rect.right = movePos.x + rcWidth / 2;
	rect.bottom = movePos.y + rcHeight / 2;
}

void MoveManager::MoveKeyRelease()
{
	if (key.IsKeyReleased(VK_LEFT) || key.IsKeyReleased(VK_RIGHT) ||
		key.IsKeyReleased(VK_UP) || key.IsKeyReleased(VK_DOWN))
	{
		isMoving = false;
	}
}

bool MoveManager::IsMoving() const
{
	return isMoving;
}

MoveManager::MoveManager(Input::InputManager<Input::KeyboardDevice>& keyRef, RECT& rc)
	: key(keyRef), rect(rc), movePos{ 0, 0 }, isMoving(false)
{
}

MoveManager::~MoveManager() = default;
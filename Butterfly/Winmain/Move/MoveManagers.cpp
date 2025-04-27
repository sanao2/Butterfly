#include "../Move/MoveManagers.h"
#include <iostream>

namespace Move
{
	void MoveManager::MoveUpdate()
	{
		key.Update();
		MoveKeyInput();
		MoveKeyRelease();
	}

	void MoveManager::MoveKeyInput()
	{
		MoveDirection dir = MoveDirection::None;

		if (key.IsKeyDown(VK_RIGHT)) dir = MoveDirection::Right;
		else if (key.IsKeyDown(VK_LEFT)) dir = MoveDirection::Left;
		else if (key.IsKeyDown(VK_UP)) dir = MoveDirection::Up;
		else if (key.IsKeyDown(VK_DOWN)) dir = MoveDirection::Down;

		ApplyMovement(dir);
	}

	void MoveManager::ApplyMovement(MoveDirection dir)
	{
		const float moveSpeed = 10.0f;
		const int rcWidth = rect.right - rect.left;
		const int rcHeight = rect.bottom - rect.top;
		
		std::cout << "[DEBUG] rect (L:" << rect.left << ", T:" << rect.top << ", R:" << rect.right << ", B:" << rect.bottom << "]" << std::endl;
		std::cout << "[DEBUG] rcWidth: " << rcWidth << " rcHeight: " << rcHeight << "\n";
		std::cout << "[DEBUG] movePos (X:" << movePos.x << ", Y:" << movePos.y << ")\n";

		switch(dir)
		{
			case MoveDirection::Left:   movePos.x -= moveSpeed; Sleep(150); isMoving = true; break;
			case MoveDirection::Right:  movePos.x += moveSpeed; Sleep(150); isMoving = true; break;
			case MoveDirection::Up:     movePos.y -= moveSpeed; Sleep(150); isMoving = true; break;
			case MoveDirection::Down:   movePos.y += moveSpeed; Sleep(150); isMoving = true; break;
			default: break;
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
}
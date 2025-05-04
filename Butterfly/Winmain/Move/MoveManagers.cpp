#include "../Move/MoveManagers.h"
#include "../Global.h"
#include <iostream>
#include "../Animation.h"

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
		const int rcWidth = playerRect.right - playerRect.left;
		const int rcHeight = playerRect.bottom - playerRect.top;
		
		std::cout << "[DEBUG] rect (L:" << playerRect.left << ", T:" << playerRect.top << ", R:" << playerRect.right << ", B:" << playerRect.bottom << "]" << std::endl;
		std::cout << "[DEBUG] rcWidth: " << rcWidth << " rcHeight: " << rcHeight << "\n";
		std::cout << "[DEBUG] movePos (X:" << movePos.x << ", Y:" << movePos.y << ")\n";

		switch(dir)
		{
			case MoveDirection::Left:  movePos.x -= moveSpeed;  g_pPlayeranimation->PlayerAnimationkeyInput(); isMoving = true; break;
			case MoveDirection::Right: movePos.x += moveSpeed;  g_pPlayeranimation->PlayerAnimationkeyInput(); isMoving = true; break;
			case MoveDirection::Up:    movePos.y -= moveSpeed;  g_pPlayeranimation->PlayerAnimationkeyInput(); isMoving = true; break;
			case MoveDirection::Down:  movePos.y += moveSpeed;  g_pPlayeranimation->PlayerAnimationkeyInput(); isMoving = true; break;
			default: break;
		}

		playerRect.left = movePos.x - rcWidth / 2;
		playerRect.top = movePos.y - rcHeight / 2;
		playerRect.right = movePos.x + rcWidth / 2;
		playerRect.bottom = movePos.y + rcHeight / 2;
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

	MoveManager::MoveManager(Input::InputManager<Input::KeyboardDevice>& keyRef, RECT& rect)
		: key(keyRef), playerRect(rect), movePos{ 0,0 }, isMoving(false)
	{
	}



	MoveManager::~MoveManager() = default;
}
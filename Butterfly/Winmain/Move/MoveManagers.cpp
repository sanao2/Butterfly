#include "../Move/MoveManagers.h"
#include "../Global.h"
#include <iostream>
#include "../Animation.h"

namespace Move
{
	void MoveManager::MoveUpdate()
	{
		key.Update();
		g_pPlayeranimation->Update();
		MoveKeyInput();
		MoveKeyRelease();
		
	}

	void MoveManager::MoveKeyInput()
	{
		MoveDirection dir = MoveDirection::None;

		if (key.IsKeyDown(VK_RIGHT)) {
			dir = MoveDirection::Right;
			SetAnimationState(PLAYER_RIGHTWALK);
		}
		else if (key.IsKeyDown(VK_LEFT)) {
			dir = MoveDirection::Left;
			SetAnimationState(PLAYER_LEFTWALK);
		}
		else if (key.IsKeyDown(VK_UP)) {
			dir = MoveDirection::Up;
			SetAnimationState(PLAYER_UPWALK);
		}
		else if (key.IsKeyDown(VK_DOWN)) {
			dir = MoveDirection::Down;
			SetAnimationState(PLAYER_DOWNWALK);
		}
		else if (dir == MoveDirection::None) return; 
		ApplyMovement(dir);
	}

	void MoveManager::ApplyMovement(MoveDirection dir)
	{
		const float moveSpeed = 10.0f;
		const int rcWidth = playerRect.Width;
		const int rcHeight = playerRect.Height;
		
		std::cout << "[DEBUG] rect (L:" << playerRect.Width << ", " << "<< playerRect.Height : " << playerRect.Height << "]" << std::endl;
		std::cout << "[DEBUG] rcWidth: " << rcWidth << " rcHeight: " << rcHeight << "\n";
		std::cout << "[DEBUG] movePos (X:" << movePos.x << ", Y:" << movePos.y << ")\n";

		switch(dir)
		{
			case MoveDirection::Left:   isMoving = true; movePos.x -= moveSpeed;  break;
			case MoveDirection::Right:  isMoving = true; movePos.x += moveSpeed;  break;
			case MoveDirection::Up:     isMoving = true; movePos.y -= moveSpeed;  break;
			case MoveDirection::Down:   isMoving = true; movePos.y += moveSpeed;  break;
			default: break;
		}

		playerRect.X = static_cast<int>(movePos.x - rcWidth / 2);
		playerRect.Y = static_cast<int>(movePos.y - rcHeight / 2);

		std::cout
			<< "[DEBUG] Rect after move: "
			<< "X=" << playerRect.X
			<< " Y=" << playerRect.Y
			<< " W=" << playerRect.Width
			<< " H=" << playerRect.Height
			<< std::endl;
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

	MoveManager::MoveManager(Input::InputManager<Input::KeyboardDevice>& keyRef, Gdiplus::Rect& rect)
		: key(keyRef), playerRect(rect), movePos{ 0,0 }, isMoving(false)
	{
	}



	MoveManager::~MoveManager() = default;
}
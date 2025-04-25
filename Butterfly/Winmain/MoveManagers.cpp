#include "MoveManagers.h"


void MoveManager::MoveUpdate(InputManager<KeyboardDevice>& key)
{
	
}

void MoveManager::MoveKeyInput(InputManager<KeyboardDevice>& key, RECT& rc)
{
	key.Update();
	int moveSpeed = 10;
	int rcWidth = rc.right - rc.left;
	int rcHeight = rc.bottom - rc.top;
	 
	movePos = {
		(rc.left + rc.right) / 2,
		(rc.top + rc.bottom) / 2 };

	if (key.IsKeyPressed(VK_RIGHT))
		movePos.x += moveSpeed;
	if (key.IsKeyPressed(VK_LEFT))
		movePos.x -= moveSpeed;
	if (key.IsKeyPressed(VK_DOWN))
		movePos.y += moveSpeed;
	if (key.IsKeyPressed(VK_UP))
		movePos.y -= moveSpeed;
	

	rc.left = movePos.x - rcWidth / 2;
	rc.top = movePos.y - rcHeight / 2;
	rc.right = movePos.x + rcWidth / 2;
	rc.bottom = movePos.y + rcHeight / 2;

}
void MoveManager::MoveKeyRelese(InputManager<KeyboardDevice>& key)
{
	int moveSpeed = 0;

	if (key.IsKeyReleased(VK_LEFT) || key.IsKeyReleased(VK_RIGHT) || key.IsKeyReleased(VK_UP) || key.IsKeyReleased(VK_DOWN))
	{
		
	}
}

bool MoveManager::IsMoving()
{
	if (isMoving == true)
	{
		return true;
	}
	else return false;
}


MoveManager::MoveManager(InputManager<KeyboardDevice>& key, RECT& rc) : key(key), rect(rc), movePos{0,0}
{
}

MoveManager::~MoveManager()
{
}
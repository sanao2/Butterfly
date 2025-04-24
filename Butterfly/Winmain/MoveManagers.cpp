#include "MoveManagers.h"


void MoveManager::MoveUpdate(InputManager<KeyboardDevice>& key)
{
	key.Update();
}

void MoveManager::MoveKeyInput(InputManager<KeyboardDevice>& key, RECT& rc)
{
	int moveSpeed = 1;
	int rcWidth = rc.right - rc.left;
	int rcHeight = rc.bottom - rc.top;
		
	POINT movePos = { (rc.right + rc.left) / 2,	(rc.top + rc.bottom) / 2 };
		
	if (key.IsKeyPressed(VK_RIGHT))
		OffsetRect(&rc, movePos.x += 1, 0);
	if (key.IsKeyPressed(VK_LEFT))
		OffsetRect(&rc, movePos.x -= 1, 0);
	if (key.IsKeyPressed(VK_DOWN))
		OffsetRect(&rc, 0, movePos.y += 1);
	if (key.IsKeyPressed(VK_UP))
		OffsetRect(&rc, 0, movePos.y -= 1);
	

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
		SetIsMoving(false);
		OffsetRect(&rect, 0, 0);
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


MoveManager::MoveManager(InputManager<KeyboardDevice>& key, RECT& rc) : key(key), rect(rc)
{
}

MoveManager::~MoveManager()
{
}
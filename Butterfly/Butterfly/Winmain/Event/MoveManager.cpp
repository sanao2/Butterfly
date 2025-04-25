#include "MoveManager.h"


void MoveManager::MoveUpdate(InputManager<KeyboardDevice>& key)
{
	key.Update(); 
}

void MoveManager::MoveKeyInput(InputManager<KeyboardDevice>& key, RECT& rc)
{
	int moveSpeed = 1;
	int rcWidth = rc.right - rc.left;
	int rcHeight = rc.bottom - rc.top;

	// 중심 좌표 계산
	POINT movePos = {(rc.right + rc.left) / 2,	(rc.top + rc.bottom) / 2};

	for (int i = 0; i <= MAX_KEY_COUNT; ++i)
	{
		if (key.IsKeyPressed(VK_RIGHT))
			OffsetRect(&rc, movePos.x += 1, 0);
		if (key.IsKeyPressed(VK_LEFT))
			movePos.x -= moveSpeed;
		if (key.IsKeyPressed(VK_UP))
			movePos.y -= moveSpeed;
		if (key.IsKeyPressed(VK_DOWN))
			movePos.y += moveSpeed;
	}
	

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
{}

MoveManager::~MoveManager()
{}




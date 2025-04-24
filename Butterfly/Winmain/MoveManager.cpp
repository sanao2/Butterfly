#include "MoveManager.h"


void MoveManager::MoveUpdate(InputManager<KeyboardDevice>& key)
{
	key.Update(); 
}


void MoveManager::MoveKeyInput(InputManager<KeyboardDevice>& key)
{
	float moveSpeed = 0.12f;

	POINT movePos = { (rect.left + rect.right) / 2  , (rect.top + rect.bottom) / 2 };

	if (key.IsKeyDown(VK_RIGHT)) // Key : Right -> Button Down && Button Pressed. 
	{
		SetIsMoving(true); 
		OffsetRect(&rect, movePos.x - 0.1, 0);		 // rect move Right  
	}
	if (key.IsKeyDown(VK_LEFT))
	{
		SetIsMoving(true);
		OffsetRect(&rect, movePos.x + 0.1, 0);		 // rect move LEFT
	}
	if (key.IsKeyDown(VK_UP)) // Key : Right -> Button Down && Button Pressed. 
	{
		SetIsMoving(true);
		OffsetRect(&rect, 0, movePos.y + 0.1);	 // rect move Up 

	}
	if (key.IsKeyDown(VK_DOWN))
	{
		OffsetRect(&rect, 0, movePos.y - 0.1);		// rect move Down

	}

	
	
}
void MoveManager::MoveKeyRelese(InputManager<KeyboardDevice>& key)
{
	if (key.IsKeyReleased(VK_RIGHT)) // Key : Right -> Button Down && Button Pressed. 
	{
		OffsetRect(&rect, 0, 0);		 // rect move Right  
	}
	if (key.IsKeyReleased(VK_LEFT))
	{
		OffsetRect(&rect, -0, 0);		 // rect move LEFT
	}
	if (key.IsKeyReleased(VK_UP)) // Key : Right -> Button Down && Button Pressed. 
	{
		OffsetRect(&rect, 0, -0);	 // rect move Up 

	}
	if (key.IsKeyReleased(VK_DOWN))
	{
		OffsetRect(&rect, 0, 0);		// rect move Down

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




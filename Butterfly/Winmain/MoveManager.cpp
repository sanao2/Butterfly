#include "MoveManager.h"


void MoveManager::MoveUpdate(InputManager<KeyboardDevice>& key)
{
	key.Update();  // InputManager Update 
}

void MoveManager::MoveInput(RECT& rect, InputManager<KeyboardDevice>& key)
{
	float moveSpeed = 0.032f;

	key.Update();
	// Rect Width / Height 
	int rcWidth = rect.right - rect.left;
	int rcHeight = rect.bottom - rect.top;

	if (key.IsKeyDown(VK_RIGHT) || key.IsKeyPressed(VK_RIGHT)) // Key : Right -> Button Down && Button Pressed. 
	{
		OffsetRect(&rect, rcWidth * moveSpeed, 0);		 // rect move Right 

	}
	if (key.IsKeyDown(VK_LEFT) || key.IsKeyPressed(VK_LEFT))
	{
		OffsetRect(&rect, -rcWidth * moveSpeed, 0);		 // rect move LEFT

	}
	if (key.IsKeyDown(VK_UP) || key.IsKeyPressed(VK_UP)) // Key : Right -> Button Down && Button Pressed. 
	{
		OffsetRect(&rect, 0, -rcHeight * moveSpeed);	 // rect move Up 
	}
	if (key.IsKeyDown(VK_DOWN) || key.IsKeyPressed(VK_DOWN))
	{
		OffsetRect(&rect, 0, rcHeight * moveSpeed);		// rect move Down
	}

}

#include "MoveManager.h"


void MoveManager::MoveUpdate(InputManager<KeyboardDevice>& key)
{
	key.Update();  // InputManager Update 
}

void MoveManager::MoveInput(RECT& rect, InputManager<KeyboardDevice>& key)
{
	int moveSpeed = 1;

	key.Update();
	// Rect Width / Height 
	int rcWidth = rect.right - rect.left;
	int rcHeight = rect.bottom - rect.top;

	if (key.IsKeyDown(VK_RIGHT)) // Key : Right -> Button Down && Button Pressed. 
	{
		OffsetRect(&rect, 1 , 0);		 // rect move Right  
		 

	}
	if (key.IsKeyDown(VK_LEFT))
	{
		OffsetRect(&rect, -1 , 0);		 // rect move LEFT
	}
	if (key.IsKeyDown(VK_UP)) // Key : Right -> Button Down && Button Pressed. 
	{
		OffsetRect(&rect, 0, -1);	 // rect move Up 
		rcWidth = 0;
		rcHeight = 0;
	}
	if (key.IsKeyDown(VK_DOWN))
	{
		OffsetRect(&rect, 0, 1 );		// rect move Down
		rcWidth = 0;
		rcHeight = 0;
	}

}


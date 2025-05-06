#include "EndScene.h"

EndScene::EndScene(Swap* _swap, int width, int height) : swap(_swap), memDC(swap->GetMemDC())
{
	if (!swap) {
		OutputDebugString(L"EndScene »ý¼ºÀÚ: swap is NULL\n");
	}
	clientSize = { width, height };
}

void EndScene::KeyInput()
{
	if (key.IsKeyDown(VK_ESCAPE) && isEndScene) {
		g_Quit = true;
	}
}

void EndScene::Update()
{
	key.Update();
}

void EndScene::EndSceneRender()
{
	PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);

	isEndScene = true;
	KeyInput();

	TextOut(memDC, clientSize.x / 2, clientSize.y / 2, L"END SCENE", 9);

	swap->SwapBuffers();
}

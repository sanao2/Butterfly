#include "EndScene.h"

EndScene::EndScene(Swap* _swap, int width, int height) : swap(_swap)
{
	memDC = swap->GetMemDC();

	clientSize = { width, height };
}

void EndScene::EndSceneRender()
{
	PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);
	TextOut(memDC, 100, 100, L"END SCENE", 9);

	swap->SwapBuffers();
}

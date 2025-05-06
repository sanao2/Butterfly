#include "EndScene.h"

EndScene::EndScene(HDC drawDC, int width, int height) : memDC(drawDC)
{
	memDC = swap->GetMemDC();

	clientSize = { width, height };
}

void EndScene::EndSceneRender()
{
	PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);
	cout << "EndScene" << endl;

}

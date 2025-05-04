#include "Render.h"
using namespace Input;

namespace renderer
{
	Render::Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height)
		: hWnd(hwnd), clientSize{ width, height },hInst(hInstance)		
	{ 
		swap = new Swap(hwnd, width, height);
		animation = new Animation(drawDC, hInstance);
	}

	Render::~Render()
	{
		DeleteDC(memDC);
		delete graphics;
		delete animation;
		delete swap;
	}

	void Render::Update()
	{
		


	}
	
	void Render::RenderScene(HINSTANCE hInst)
	{
		Time::UpdateTime();

		memDC = swap->GetMemDC();
		graphics = new Gdiplus::Graphics(memDC);

		// ȭ�� �ʱ�ȭ (����� ������� ä���)
		PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);

		animation->Render(memDC, playerRc, graphics, 0, 0, current_frame);

		// ���� �޸� DC�� ���� (swap ���� �޸� DC�� �������� �޼ҵ� �ʿ�)
		swap->SwapBuffers();

	}


	POINT Render::GetBufferSize() const
	{
		return clientSize;
	}
	

}




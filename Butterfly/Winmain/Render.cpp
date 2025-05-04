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

		// 화면 초기화 (배경을 흰색으로 채우기)
		PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);

		animation->Render(memDC, playerRc, graphics, 0, 0, current_frame);

		// 스왑 메모리 DC에 복사 (swap 내부 메모리 DC를 가져오는 메소드 필요)
		swap->SwapBuffers();

	}


	POINT Render::GetBufferSize() const
	{
		return clientSize;
	}
	

}




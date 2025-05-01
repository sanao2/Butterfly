#include "Render.h"
#include <iostream>

Render::Render(HDC drawDC, HWND hwnd, HINSTANCE hInstance, int width, int height)
                : hWnd(hwnd), clientSize{ width, height }, hInst(hInstance)
{ 
    swap = new Swap(hwnd, width, height);
	//ResMgr = new ResourceManger(drawDC, width,height); // ���ҽ� �Ŵ��� ��ü ����
    animation = new Animation(drawDC, hInstance);
}

Render::~Render()
{
    delete swap;
}

void Render::Update()
{
    swap->SwapBuffers();    // ����� -> ����Ʈ���� ����
   
}

void Render::RenderScene(HINSTANCE hInst)
{
    memDC = swap->GetMemDC();
    HBITMAP tempBitmap = CreateCompatibleBitmap(GetDC(hWnd), clientSize.x, clientSize.y);
    SelectObject(memDC, tempBitmap);
    graphics = new Gdiplus::Graphics(memDC);

    // ȭ�� �ʱ�ȭ (����� ������� ä���)
    PatBlt(memDC, 0, 0, clientSize.x, clientSize.y, WHITENESS);
 
    // ���ҽ� �ε� - �̹����� �ε��ϱ� ���� LoadImages ȣ��              
	//ResMgr->LoadImages(hInst); // ���ҽ� �Ŵ����� ���� �̹��� �ε� 
	//ResMgr->RenderImage(*graphics, 0, 0); // �̹����� �׸��� 
    
	// �ִϸ��̼� ���� �� ������
	
    // ���� �޸� DC�� ���� (swap ���� �޸� DC�� �������� �޼ҵ� �ʿ�)
    swap->SwapBuffers();

    // ���ҽ� ����
    DeleteObject(tempBitmap);
    DeleteDC(memDC);
}

POINT Render::GetBufferSize() const
{
    return clientSize;
}

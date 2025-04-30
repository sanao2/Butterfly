#include "Render.h"
#include <iostream>

Render::Render(HDC drawDC, HWND hwnd,  int width, int height)
    : hWnd(hwnd), clientSize{ width, height }
{
    swap = new Swap(hwnd, width, height);
	ResMgr = new ResourceManger(drawDC, width,height); // ���ҽ� �Ŵ��� ��ü ����
	//anim = new Animation(hwnd, width, height); // Animation ��ü ���� 
}

Render::~Render()
{
    delete swap;
}

void Render::Update()
{
    swap->SwapBuffers();    // ����� -> ����Ʈ���� ����
    //anim->Update(); // Animation Update 
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

#include "Swap.h"

Swap::Swap(HWND _hWnd, int width, int height) : hWnd(_hWnd), clientSize{ width, height }
{
    clientDC = GetDC(hWnd);
    memDC = CreateCompatibleDC(clientDC);

    backBitmap = CreateCompatibleBitmap(clientDC, width, height);
    SelectObject(memDC, backBitmap); // 메모리 DC에 비트맵 연결
}

Swap::~Swap()
{
    if (backBitmap) DeleteObject(backBitmap);
    if (memDC) DeleteDC(memDC);
    if (clientDC) ReleaseDC(hWnd, clientDC);
}

void Swap::SwapBuffers()
{
    if (isSwapping.load())
        return;

    {
        std::lock_guard<std::mutex> lock(mtx);
        BitBlt(clientDC, 0, 0, clientSize.x, clientSize.y, memDC, 0, 0, SRCCOPY); // 메모리 DC를 클라이언트 DC로 복사
    }

    needSwap.store(true);
    cv.notify_one();
}

void Swap::ResetNeedSwap()
{
    if (needSwap.load())
        needSwap.store(false);
}
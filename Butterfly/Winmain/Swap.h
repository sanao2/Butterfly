#pragma once
#include <windows.h>
#include <mutex>
#include <condition_variable>
#include <atomic>

class Swap
{
private:
    HWND hWnd;
    HDC memDC;
    HDC clientDC;
    HBITMAP backBitmap;

    std::mutex mtx;
    std::condition_variable cv;
    std::atomic<bool> needSwap{ false };
    std::atomic<bool> isSwapping{ false };

public:
    Swap(HWND hWnd, int width, int height);
    ~Swap();

    HDC GetMemDC() const { return memDC; };

    void SwapBuffers();
    void ResetNeedSwap();

    bool IsSwapping() const { return isSwapping.load(); }
    bool NeedSwap() const { return needSwap.load(); }
};
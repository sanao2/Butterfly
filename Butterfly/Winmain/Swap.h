#pragma once
#include <windows.h>
#include <stdio.h>
#include <mutex>
using std::mutex;
#include <thread>
using std::thread; 


class Swap
{
private:
	HWND						hWnd;		 // Window ID Handle
	HDC							memDC;		 //  Back Buffer DC
	HDC							clientDC;	 // Front Buffer DC
	HBITMAP						BackBitmap;  // Back Buffer Bitmap
	
	mutex						_mtx;
	thread						thread;		// Multy Thread
	std::condition_variable     _cv;
	std::atomic<bool>          isSwaping{ false };

public:
	bool GetisSwaping() { return isSwaping; } // Swaping Check
	void SetisSwaping(bool _isSwaping) { isSwaping.store(_isSwaping); } // Swaping Check
	Swap(HWND _hWnd, int w_width, int w_height) : hWnd(_hWnd)
	{
		clientDC = GetDC(_hWnd);		// Get Client DC 
		memDC = CreateCompatibleDC(clientDC);
		BackBitmap = CreateCompatibleBitmap(memDC, w_width, w_height); // Memory Create 
		SelectObject(clientDC, BackBitmap); // MemDC Memory Area Specify 
	}	
	~Swap()
	{
		//MemoryDC Delete
		DeleteObject(BackBitmap);
		DeleteDC(memDC); 
		ReleaseDC(hWnd, clientDC); 
	}

	void SwapBuffers(HWND _hWnd, int w_width, int w_height)
	{
		// Swaping Buffer 		
		if (isSwaping.load()) return; // Swaping Check 

		{
		  // Swap Second : Mutex Lock 
			std::lock_guard<std::mutex> lk(_mtx); // Only one thread can access the resource at a time 
			std::swap(memDC, clientDC); // BackBuffer and FrontBuffer Swap

		}

		_cv.notify_one();
	}
};
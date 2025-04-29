#pragma once
#include <windows.h>
#include <vector> 
#include <iostream>
#include <unordered_map>
#include <gdiplus.h>
#include "UI/timer.h"
#include "resource.h"
#pragma comment(lib, "gdiplus.lib")
using namespace std; 
using std::vector;
using std::string; 
using std::wstring; 
using::unordered_map;



enum Animstate
{ 
	PLAYER_IDLE, 
	PLAYER_RIGHTWALK,
	PLAYER_LEFTWALK, 
	PLAYER_DOWNWALK,
	PLAYER_UPWALK,
	PLAYER_USEPIKAX_RIGHT, 
	PLAYER_USEPIKAX_LEFT, 
	PLAYER_USEPIKAX_DOWN, 
	PLAYER_USEPIKAX_UP, 
	PLAYER_ANIMCOUNT
};

const wstring AnimPath = L"../Resource/";

struct ResourceInfo {
	vector<int> ImageID; 
	ResourceInfo(std::initializer_list<int> list)
		: ImageID(list) {} 
};


const unordered_map<Animstate, ResourceInfo> AnimStateFrameMap = {
	{PLAYER_IDLE, {}},
	{PLAYER_RIGHTWALK,{IDB_PLAYER_RIGHT_IDLE,IDB_PLAYER_RIGHT_ONE,
				       IDB_PLAYER_RIGHT_SECOND, IDB_PLAYER_RIGHT_THREE,
				       IDB_PLAYER_RIGHT_FOUR}},
	{ PLAYER_LEFTWALK, { IDB_LEFTWALK_ONE,IDB_LEFTWALK_SECOND,
						 IDB_PLAYER_LEFTWALK_THREE, IDB_LEFTWALK_FOUR}},
	{ PLAYER_DOWNWALK, { IDB_PLAYER_DOWNWALK_IDLE, IDB_PLAYER_DOWNWALK_ONE,
						 IDB_PLAYER_DOWNWALK_SECOND, IDB_PLAYER_DOWNWALK_THREE}},
	{ PLAYER_UPWALK, {IDB_PLAYER_UPWALK_IDLE, IDB_PLAYER_UPWALK_ONE, 
					  IDB_PLAYER_UPWALK_SECOND, IDB_PLAYER_UPWALK_THREE}},
	{ PLAYER_USEPIKAX_RIGHT, { IDB_USEPIKAX_RIGHT_ONE, IDB_USEPIKAX_RIGHT_SECOND, IDB_USEPIKAX_RIGHT_THREE}},
	{ PLAYER_USEPIKAX_LEFT, {IDB_USEPIKAX_LEFT_ONE, IDB_USEPIKAX_LEFT_SECOND }},
	{ PLAYER_USEPIKAX_DOWN, {IDB_USEPIKAX_DOWN_ONE, IDB_USEPIKAX_DOWN_SECOND}},
	{ PLAYER_USEPIKAX_UP,{IDB_USEPIKAX_UP_ONE, IDB_USEPIKAX_UP_SECOND}}
};

const int GetAnimationFrameID(Animstate animstate, size_t frameIndex)
{
	auto it = AnimStateFrameMap.find(animstate); 

	if (it == AnimStateFrameMap.end() || frameIndex >= it->second.ImageID.size())
	{
		return -1;
	}

	return it->second.ImageID[frameIndex]; // frameindex ind second Image return

}
 
class Animation
{
private:
	HWND hWnd = nullptr;
	HINSTANCE hInst = nullptr;
	HDC clientDC = nullptr; 
	HDC memDC = nullptr; 

	static Animstate currAnim;
	vector<vector<int>> frames;      // All Animation Save vector
	float DeltaTime = 0.0f;			 // 마지막 프레임 갱신 시점과의 차이(초)를 계산 → deltaTime
	float frameTime = 0.0f;			 // 애니메이션 프레임 재생 시간 
	float TotalTime = 0.0f; 
	int currFrame = 0;
	Time::Timer<> timer;

	Gdiplus::GdiplusStartupInput gsi;
	ULONG_PTR GdiplusToken = NULL;
	Gdiplus::Graphics* backDCgraphics = nullptr;

public:
	Animation(HWND hwnd, int width, int height);
	~Animation(); 
 
	void createAnimation(HINSTANCE hInst, float frameTime);
	vector<int> findAnimation(Animstate animState);

	void Initialize(); 
	void Update(); 
	void Render(); 

	void SetcurrAnimState(Animstate animstate) { currAnim = animstate; }
	Animstate GetcurrAnimState() { return currAnim; }
};

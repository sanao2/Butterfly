#pragma once
#include <windows.h>
#include <vector> 
#include <iostream>
#include <string>
#include <unordered_map>
#include "resource.h"
#include "UI/timer.h"
using namespace std; 
using std::vector;
using std::string; 
using std::wstring; 
using::unordered_map;

enum Animstate
{ 
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


const unordered_map<Animstate, ResourceInfo> AnimationMap = {
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

const int GetAnimMotionImage(Animstate animstate, size_t frameIndex)
{
	auto it = AnimationMap.find(animstate); 

	if (it == AnimationMap.end() || frameIndex >= it->second.ImageID.size())
	{
		return -1;
	}

	return it->second.ImageID[frameIndex]; // frameindex ind second Image return

}

class Animation
{
private:
	Animstate currAnim;				  // current AnimationMotion Setting 
	vector<vector<Animstate>> frame;  // All Animation Save vector

public:
	Animation(); 
	~Animation(); 
 
	void findAnimation(); 

	void Initialize(); 
	void Update(); 
	void Render(); 

	void SetcurrAnimState(Animstate animstate) { currAnim = animstate; }
	Animstate GetcurrAnimState() { return currAnim; }
};

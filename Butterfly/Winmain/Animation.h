#pragma once
#include <windows.h>
#include <vector> 
#include <iostream>
#include <string>
#include <unordered_map>
#include "resource.h"
using namespace std; 
using std::vector;
using std::string; 
using std::wstring; 
using::unordered_map;

enum Animstate
{
	PLAYER_WALK_IDLE, 
	PLAYER_RIGHTWALK,
	PLAYER_LEFTWALK, 
	PLAYER_DOWNWALK,
	PLAYER_UPWALK,
	PLAEYR_ANIMCOUNT
};

const wstring AnimPath = L"../Resource/";

//inline int GetAnimationID(Animstate Anistate)
//{
//	static int playerMotion[] = {
//		IDB_PLAYER_IDLE,
//		IDB_PLAYER_RIGHT_ONE,
//		IDB_PLAYER_RIGHT_SECOND,
//		IDB_PLAYER_RIGHT_THREE,
//		IDB_PLAYER_RIGHT_FOUR
//	};
//	if (Anistate < 0 || Anistate >= PLAEYR_ANIMCOUNT) return -1;
//
//	return playerMotion[Anistate]; 
//};
struct ResourceInfo {
	int ImageID[]; 
};

const unordered_map<Animstate, ResourceInfo> AnimationMap = {
	{PLAYER_WALK_IDLE, {IDB_PLAYER_IDLE, IDB_PLAYER_RIGHT_IDLE,
						IDB_PLAYER_RIGHT_ONE, IDB_PLAYER_RIGHT_SECOND,
						 IDB_PLAYER_RIGHT_THREE,IDB_PLAYER_RIGHT_FOUR}}
}

class Animation
{
private:
	Animstate currAnim;				  // current AnimationMotion Setting 
	vector<vector<Animstate>> frame;  // All Animation Save vector

public:
	Animation(); 
	~Animation(); 

	void frameinAnimation();
	void createAnimation(int AnimID, Animstate Anistate); 
	void findAnimation(); 

	void Initialize(); 
	void Update(); 
	void Render(); 

	void SetcurrAnimState(Animstate animstate) { currAnim = animstate; }
	Animstate GetcurrAnimState() { return currAnim; }
};

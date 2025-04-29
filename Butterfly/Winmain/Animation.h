#pragma once
#include <windows.h>
#include <vector> 
#include <iostream>
#include <string>
#include "resource.h"
using namespace std; 
using std::vector;
using std::string; 
using std::wstring; 

enum Animstate
{
	PLAYER_WALK, 
	PLAYER_PICKAX,
	PLAYER_HOE, 
	PLAYER_POT
};

const wstring AnimPath = L"../Resource/";

inline int GetAnimationID(Animstate Animstate)
{
	static int playerMotion[] = {
		IDB_PLAYER_IDLE,
		IDB_PLAYER_RIGHT_ONE,
		IDB_PLAYER_RIGHT_SECOND,
		IDB_PLAYER_RIGHT_THREE,
		IDB_PLAYER_RIGHT_FOUR
	};
	
};

class Animation
{
private:
	Animstate currAnim;				  // current AnimationMotion Setting 
	vector<vector<Animstate>> frame;  // All Animation Save vector

public:
	Animation(); 
	~Animation(); 

	void frameinAnimation();
	void createAnimation(); 
	void findAnimation(); 

	void Initialize(); 
	void Update(); 
	void Render(); 
};

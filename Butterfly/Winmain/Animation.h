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
	PLAYER_IDLE,
	PLAYER_RIGHT,
	PLAYER_LEFT,
	PLAYER_DOWN,
	PLAYER_UP
};


const wstring AnimPath = L"../Resource";

inline int GetAnimPath()
{
	static int playerPath[] = {
		IDB_PLAYER_IDLE,
		IDB_PLAYER_RIGHT_ONE,
		IDB_PLAYER_RIGHT_SECOND,
		IDB_PLAYER_RIGHT_THREE,
		IDB_PLAYER_RIGHT_FOUR
	};
	
};

class Animation
{
private : 

public : 
};

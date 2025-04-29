#pragma once
#include <windows.h>
#include <vector> 
#include <iostream>
#include <string>
#include "../Resource/resource.h" // Updated path to match typical project structure
using namespace std; 
using std::vector;
using std::string; 
using std::wstring; 

const wstring AnimPath = L"../Resource";

inline int GetAnimPath()
{
static int playerPath[] = {
	IDB_PLAYER_RIGHT_ONE, 
};
return 0; // Added return statement to fix incomplete function
}

class Animation
{
};

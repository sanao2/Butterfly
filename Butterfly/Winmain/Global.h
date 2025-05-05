#pragma once
#include <windows.h>
#include "AnimationMap.h" 
#include <map>
#include <unordered_map> // Add this line to include the unordered_map header
#include <stdexcept>
#include <vector>
#include <string>
#include <iostream>
using std::string;
using std::unordered_map;
using std::vector;

extern Animstate current_state; // current Animation State 
extern Animstate prev_state;    // Previous Animation State 

extern Animstate GetcurrentAnimationState();
extern void SetAnimationState(Animstate state);

extern Animstate GetPrevAnimationState();
extern void SetPrevAnimationState(Animstate state); 
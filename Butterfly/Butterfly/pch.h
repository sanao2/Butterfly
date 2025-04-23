#pragma once
#undef byte

#include <windows.h>
#include <stdio.h>

#include <vector>
using::std::vector;

#include "array"
using::std::array;

#include <string> 
using std::wstring;
using std::string;


#include "Input.h"
#include "Time.h"


#include <gdiplus.h>

#pragma comment(lib, "gdiplus.lib")
using namespace Gdiplus;
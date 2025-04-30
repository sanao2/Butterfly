#pragma once
#include <vector> 
#include <unordered_map>
#include "resource.h"
using std::unordered_map;
using std::vector; 


enum Animstate
{
    PLAYER_DEFAULT,
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

struct ResourceInfo {
    vector<int> ImageID;
    ResourceInfo(std::initializer_list<int> list)
        : ImageID(list) {
    }
};

extern  unordered_map<Animstate, ResourceInfo> AnimStateFrameMap;


inline const int GetAnimationFrameID(Animstate animstate, size_t frameIndex)
{
    auto it = AnimStateFrameMap.find(animstate);
    if (it == AnimStateFrameMap.end())
        return -1;

    return it->second.ImageID[frameIndex];
}
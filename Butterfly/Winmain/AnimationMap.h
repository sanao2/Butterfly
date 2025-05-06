#pragma once
#include <vector> 
#include <unordered_map>
#include "UI/Map/resource.h"
#include <stdexcept>
using std::unordered_map;
using std::vector;


enum Animstate
{
	PLAYER_DEFAULT,
	PLAYER_RIGHTWALK,
	PLAYER_LEFTWALK,
	PLAYER_DOWNWALK,
	PLAYER_UPWALK
};

struct ResourceInfo {
	vector<int> ImageID;
	ResourceInfo() = default;
	ResourceInfo(std::initializer_list<int> list)
		: ImageID(list) {}
};
extern  unordered_map<Animstate, ResourceInfo> AnimStateFrameMap;

inline const int GetAnimationFrameID(Animstate animstate, int frameIndex)
{
	auto it = AnimStateFrameMap.find(animstate);
	if (it == AnimStateFrameMap.end()) {
		throw std::runtime_error("Animstate�� AnimStateFrameMap�� �������� �ʽ��ϴ�.");
	}
	auto& vec = it->second.ImageID;
	if (frameIndex >= vec.size()) {
		throw std::out_of_range("frameIndex�� ImageID ������ ������ �ʰ��߽��ϴ�.");
	}

	return vec[frameIndex];
}


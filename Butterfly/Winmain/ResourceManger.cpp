#include "ResourceManger.h"

ResourceManger::ResourceManger(HINSTANCE hInstance) : hInst(hInstance)
{
}

ResourceManger::~ResourceManger()
{
}

void ResourceManger::Initialize()
{
	imageResource = new ImageResource();
}

void ResourceManger::LoadImages(HINSTANCE hInst)
{
}

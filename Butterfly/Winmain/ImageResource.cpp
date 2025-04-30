#include "ImageResource.h"

ImageResource::~ImageResource()
{
	if (bitmap) delete bitmap; 
}

bool ImageResource::LoadFromResource(HINSTANCE hInstance, int resourceID, const wchar_t* resourceType)
{
	HRSRC hRes = FindResource(hInstance, MAKEINTRESOURCE(resourceID), resourceType);
	if (!hRes) return false; 

	DWORD size = SizeofResource(hInstance, hRes);
	HGLOBAL hMem = LoadResource(hInstance, hRes); 
	void* pResDate = LockResource(hMem); 

	HGLOBAL hBuffer = GlobalAlloc(GMEM_MOVEABLE, size); 
	void* pBuffer = GlobalLock(hBuffer); 
	memcpy(pBuffer, pResDate, size); 

	IStream* pStream = nullptr; 
	CreateStreamOnHGlobal(hBuffer, TRUE, &pStream);
	bitmap = Gdiplus::Bitmap::FromStream(pStream);
	pStream->Release();

	GlobalUnlock(hBuffer);
	return true;

}
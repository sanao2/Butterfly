#include "ResourceManger.h"

int RESOURCE_ID = IDB_PLAYER_DOWNWALK_IDLE; 

ResourceManger::ResourceManger( HINSTANCE hInstance) : hInst(hInstance)
{											
	imageResource = new ImageResource();
	imageRenderer = new GdiPlusImageRenderer(); // Correctly references the class

	//// Gdiplus 초기화 
	//Gdiplus::GdiplusStartupInput gsi;
	//Gdiplus::GdiplusStartup(&GdiPlusToken, &gsi, nullptr);
	//graphics = new Gdiplus::Graphics(drawDC); // GDI+ 그래픽스 객체 생성
	
}

ResourceManger::~ResourceManger()
{
	//delete image; 
	
	//if (graphics) delete graphics;				// GDI+ Graphics Delete
	if (imageResource) delete imageResource;    // imageResource Delete 
	if (imageRenderer) delete imageRenderer;    // imageRenderer Delete
	//Gdiplus::GdiplusShutdown(GdiPlusToken);     // GDI+ ShoutDown
}

//void ResourceManger::LoadImages(HINSTANCE hInst)
//{
//	try {			
//
//		imageResource->LoadFromResource(hInst, RESOURCE_ID, RESOURCE_TYPE); // Load image from resource 
//	
//		
//		//image = imageResource->GetBitmap();
//		AnimationFrames.push_back(image); 
//
//		if (image == nullptr)
//		{
//			cerr << "Failed to load image resource." << endl;
//			return;
//		}
//
//	}
//	catch (const std::exception& e) {
//		std::cerr << "Error loading images: " << e.what() << std::endl;
//	}
//	if (image != nullptr)
//	{
//		cerr << "Failed to load images." << endl;
//	}
//	
//}

void ResourceManger::Render(Gdiplus::Graphics& graphics, int x, int y)
{
	imageRenderer->Render(graphics, image, x, y);
	
}

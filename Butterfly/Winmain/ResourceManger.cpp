#include "ResourceManger.h"


int RESOURCE_ID = IDB_PLAYER_DOWNWALK_IDLE;
constexpr wchar_t RESOURCE_TYPE[] = L"PNG";

ResourceManger::ResourceManger(HDC drawDC,int width, int height) 
{											
	imageResource = new ImageResource();
	imageRenderer = new GdiPlusImageRenderer(); // Correctly references the class

	// Gdiplus 초기화 
	Gdiplus::GdiplusStartupInput gsi;
	Gdiplus::GdiplusStartup(&GdiPlusToken, &gsi, nullptr);
	graphics = new Gdiplus::Graphics(drawDC); // GDI+ 그래픽스 객체 생성
	
	//animation = new Animation(drawDC, hInstance); // 애니메이션 객체 생성);
}

ResourceManger::~ResourceManger()
{
	DeleteObject(image);
	if (graphics) delete graphics;				// GDI+ Graphics Delete
	if (imageResource) delete imageResource;    // imageResource Delete 
	if (imageRenderer) delete imageRenderer;    // imageRenderer Delete
	Gdiplus::GdiplusShutdown(GdiPlusToken);     // GDI+ ShoutDown
}

void ResourceManger::LoadImages(HINSTANCE hInst)
{
	try {		

		//for (int i = 0; i < RESOURCE_ID.size(); ++i)
		//{
			//RESOURCE_ID[i] = GetAnimationFrameID(current_state, i);

			auto Res = imageResource->LoadFromResource(hInst, RESOURCE_ID, RESOURCE_TYPE);
		/*} */		
		image = imageResource->GetBitmap();
		
		if (image == nullptr)
		{
			cerr << "Failed to load image resource." << endl;
			return;
		}

	}
	catch (const std::exception& e) {
		std::cerr << "Error loading images: " << e.what() << std::endl;
	}
	if (image != nullptr)
	{
		cerr << "Failed to load images." << endl;
	}
	
}

void ResourceManger::RenderImage(Gdiplus::Graphics& graphics, int x, int y)
{
	if (image == nullptr)
	{
		cerr << "Bitmap is null." << endl;
		return;
	} 
	imageRenderer->Render(graphics, image, x, y);
}

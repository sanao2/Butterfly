#include "Map.h"
#include <ranges> // Add this include for std::views
using namespace std; 

namespace Map
{
	Object::Object(HDC drawDC, HINSTANCE hInstance, int width, int height)
	{
		imageResource = new ImageResource(); 
		imageRenderer = new GdiPlusImageRenderer();	
	}
	
	Object::~Object()
	{	
		delete imageResource; 
		delete imageRenderer; 
	}

	void Object::MapLoop()
	{
		for (auto& tile : tiles)
		{
			auto& images = tileBitmaps[tile.state]; 
			if (!images.empty()) {
				Gdiplus::Image* iamge = images[0];


			}
		}
	}

	void Object::LoadTileImages(HINSTANCE hInstance, Spritestate state) // Removed extra closing parenthesis
	{
		const auto& info = SpriteStateFrameMap[state];
		auto& imgs = tileBitmaps[state];

		for (size_t i = 0; i < info.ImageID.size(); ++i) {
			int resID = GetSpriteID(state, i);
			if (!imageResource->LoadFromResource(hInstance, resID, SPRITE_TYPE)) {
				throw std::runtime_error("이미지 로드 실패: state="
					+ std::to_string(static_cast<int>(state)) // Fixed conversion of enum to string
					+ " frame=" + std::to_string(i));
			}
			imgs.push_back(std::make_unique<Gdiplus::Image>(imageResource->GetBitmap()));
		}
	}

	void Object::TileImageRender(Gdiplus::Graphics* graphics, Gdiplus::Image* image, int x, int y)
	{
		int width = image->GetWidth(); 
		int height = image->GetHeight(); 
			imageRenderer->Render(graphics, image, width, height, x, y);
		
	}

	



}
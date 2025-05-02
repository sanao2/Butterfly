#include "Animation.h"

Animation::Animation(HDC drawDC, HINSTANCE hInstance) : hInst(hInstance), current_frame(0)
{
	this->Initialize(drawDC, hInstance); // ���ҽ� �Ŵ��� �ʱ�ȭ
	LoadeFrames(hInstance); // �ִϸ��̼� ������ �ε� 	
	timer.Reset();
}

Animation::~Animation()
{
	/*if (graphics)
	{
		delete graphics;
		graphics = nullptr;
	}*/
	
}

void Animation::Update()
{
    if (timer.IsElapsed(frameInterval)) {
    	
    	current_frame = (current_frame + 1) % this->AnimationFrames.size(); // ������ ������Ʈ
    	timer.Reset();
    }
}
void Animation::UnloadFrames()
{
	bool isLoad = this->IsLoaded(); // �ִϸ��̼��� �ε�Ǿ����� Ȯ�� 
	if (isLoad == false) return;

	for (int frameIndex = AnimationFrames.size(); frameIndex >= 0; --frameIndex)
	{
		if (AnimationFrames[frameIndex] != nullptr)
		{
			delete AnimationFrames[frameIndex];
			AnimationFrames[frameIndex] = nullptr;
		}
	}
}

void Animation::Render(HDC drawDC, Gdiplus::Graphics* graphics, int x, int y)
{
	graphics->Clear(Gdiplus::Color::White); // ����� ������� �ʱ�ȭ
	//PatBlt(drawDC, 0, 0, g_width, g_height, WHITENESS); // ȭ�� �ʱ�ȭ (����� ������� ä���) 
		// �ִϸ��̼� �������� �׸��� 
	this->RenderFrame(graphics, x, y, current_frame); // ���� �������� �׸��� 	

}

#include "Winmain.h"

void InitConsole()
{
	AllocConsole(); // 콘솔을 생성한다. 
	FILE* fp; // 파일 포인터. 
	// 파일을 CONOUT$ 이름으로 읽기 모드로 연다. 
	freopen_s(&fp, "CONOUT$", "w", stdout);
	SetConsoleTitle(L"윈도우 메시지 콘솔 로그");
	printf("콘솔 로그 시작...\n\n");

}

void UninitConsole()
{
	// 표준 출력 스트림 닫기
	fclose(stdout);
	// 콘솔 해제
	FreeConsole();
}

// WIN32 API 에러 값에 대한 실제 메세지를 출력하는 함수
void PrintLastErrorMessage()
{
	DWORD errorCode = GetLastError();  
	LPVOID lpMsgBuf;

	
	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		errorCode, 
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
		(LPSTR)&lpMsgBuf,
		0,				 
		NULL);

	if (lpMsgBuf)
	{
		printf("오류 코드: %lu\n오류 메시지: %s\n", errorCode, (char*)lpMsgBuf);
		LocalFree(lpMsgBuf); 
	}
	else
	{
		printf("오류 코드: %lu (메시지를 찾을 수 없음)\n", errorCode);
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	InitConsole();  // 콘솔 출력 초기화

	char szPath[MAX_PATH] = { 0, };

	// 버퍼 길이와 버퍼 경로를 받아서 현재 작업 디렉토리를 불러온다. 
	::GetCurrentDirectoryA(MAX_PATH, szPath);
	printf("Current Directory: %s\n", szPath);

	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WndProc;						// 윈도우 프로시저를 받아온다. 
	wc.hInstance = hInstance;						// 만들어진 프로세스를 받아온다. 
	wc.lpszClassName = g_szClassName;				// 아이디의 이름. 
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);  // 브러쉬로 변환한 Window 창의 백그라운드(배경) 을 받아온다. 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);		// 기본 커서 모양
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);		// 기본 아이콘 모양
	RegisterClass(&wc);


	MSG msg;
	while (PeekMessages(msg))
	{

		Time::UpdateTime();
		Input::Update();

	}

	//////////////////////////////////////////////////////////////////////////

	return (int)msg.wParam;
}



bool PeekMessages(MSG& msg)
{
	//PeekMassage =>  메시지를 훔쳐본다. 메시지의 존재 여부에 따라 반환 이 가능하다. true일 시 무조건 메시지가 존재.
		// 조건문이 사용 가능하다. 
		// 마지막 인자인 UNIT wRemoveMsg => 메시지 큐에서 확인한 메시지가 존재할 시에 삭제 여부 결정 파라메터.
		// (PM_REMOVE = 삭제) 
	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT) return false;

		TranslateMessage(&msg);		// 메시지를 받아서 키보드 메시지를 문자 메시지로 변환. -> 키보드 입력받은 메시지를 문자 메시지로 변환??
		DispatchMessage(&msg);		// 메시지를 윈도우 프로시저 (WndProc) 으로 전달 
	}

	return true;
}

void Winmain::Resolution(HINSTANCE hInstance, int nCmdShow, int g_width, int g_height)
{
	{
		// 원하는 크기가 조정되어 리턴
		RECT rcClient = { 0, 0, g_width, g_height }; 
		AdjustWindowRect(&rcClient, WS_OVERLAPPEDWINDOW, FALSE);  

	// 윈도우 아이디 타입으로 콘솔창을 생성 
		HWND hwnd = CreateWindow(
			g_szClassName,					 // 윈도우 클래스 이름 
			g_title,						 // 윈도우 창 제목 
			WS_OVERLAPPEDWINDOW,			 // 윈도우 스타일 
			CW_USEDEFAULT,					 // 윈도우 가로(X) 길이 
			CW_USEDEFAULT,					 // 윈도우 세로(Y) 길이 
			rcClient.right - rcClient.left,
			rcClient.bottom - rcClient.top,
			NULL, NULL, hInstance, NULL);

		g_hWnd = hwnd;

		ShowWindow(hwnd, nCmdShow);
		UpdateWindow(hwnd);

	}
}

Winmain::Winmain()
{

}

Winmain::~Winmain()
{

	//delete Main; 
}

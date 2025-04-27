#include "Global.h"  // 이제 Global.h 하나만 include하면 됨
#include "Winmain.h" // (필요하면)

#pragma comment(lib, "Msimg32.lib")	

// 타이틀, 클래스명, 사이즈
LPCTSTR g_title = TEXT("윈도우 타이틀바에 표시할 문자열");
LPCTSTR g_szClassName = TEXT("윈도우 클래스 이름");

int g_width = 1024;
int g_height = 768;

HWND g_hWnd;

HDC drawDC;
RECT rect = { 5, 5, 20, 20 };

int boxDraw()
{
    drawDC = GetDC(g_hWnd);

    PatBlt(drawDC, 0, 0, g_width, g_height, WHITENESS);
    Rectangle(drawDC, rect.left, rect.top, rect.right, rect.bottom);

    ReleaseDC(g_hWnd, drawDC); // Release 해줘야 리소스 누수 안 생김
    return S_OK;
}

void InitConsole()
{
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    SetConsoleTitle(L"윈도우 메시지 콘솔 로그");
    printf("콘솔 로그 시작...\n\n");
}

void UninitConsole()
{
    fclose(stdout);
    FreeConsole();
}

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
    InitConsole();

    char szPath[MAX_PATH] = { 0, };
    ::GetCurrentDirectoryA(MAX_PATH, szPath);
    printf("Current Directory: %s\n", szPath);

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = g_szClassName;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    RegisterClass(&wc);

    RECT rcClient = { 0, 0, (LONG)g_width, (LONG)g_height };
    AdjustWindowRect(&rcClient, WS_OVERLAPPEDWINDOW, FALSE);

    HWND hwnd = CreateWindow(
        g_szClassName,
        g_title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        rcClient.right - rcClient.left, rcClient.bottom - rcClient.top,
        NULL, NULL, hInstance, NULL);

    g_hWnd = hwnd;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    render = new Render(g_hWnd, g_width, g_height);  // Global Render 객체 생성
  

    auto& key = InputManager<KeyboardDevice>::GetInstance();    

    std::unique_ptr<Move::MoveManager> move = std::make_unique<Move::MoveManager>(key, rect);

    MSG msg;
    while (true)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        boxDraw();
        move->MoveUpdate();
		render->RenderScene(); // 렌더링 호출
		
    }

    UninitConsole();
    return (int)msg.wParam;
}
// GT_HelloWorldWin32.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("win32app");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Query Processor");

static HWND textBoxInput;
static HWND button;
static HWND textBoxOutput;

HINSTANCE hInst;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Win32 Guided Tour"),
            NULL);

        return 1;
    }

    hInst = hInstance; // Store instance handle in our global variable

    // The parameters to CreateWindow explained:
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application does not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindow(
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        540, 400,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Win32 Guided Tour"),
            NULL);

        return 1;
    }

	button = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Button"),_T("Ejecutar"),WS_CHILD | WS_VISIBLE | ES_CENTER, 10, 10,75,30,hWnd,NULL,NULL,NULL); 
	
	textBoxInput = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Edit"), NULL,WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_AUTOVSCROLL |  ES_MULTILINE, 10, 45, 500, 150, hWnd, NULL, NULL, NULL);
    
	textBoxOutput = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Edit"),TEXT("En ésta Sección se mostrarán los Resultados de las Consultas Realizadas."),WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_AUTOVSCROLL |  ES_MULTILINE | ES_READONLY ,10,200,500,150,hWnd,NULL,NULL,NULL);


    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Hello, World!");

    switch (message)
    {
		case WM_COMMAND:
			if((HWND)lParam == button)
			{               
				TCHAR* buffer = new TCHAR[150];

				GetWindowText(textBoxInput,buffer,150);

				SetWindowText(textBoxOutput,buffer);
				//AppendWindowText(textBoxOutput,buffer,150) - I haven't found such function;           
						delete [] buffer;       
			}
			break;
		case WM_PAINT:
			{
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            HBRUSH pedzel;

            pedzel = CreateSolidBrush(RGB(130,150,130));

            FillRect(hdc, &ps.rcPaint, pedzel);

            EndPaint(hWnd, &ps);
            return 0;
            }
			//hdc = BeginPaint(hWnd, &ps);

			//// Here your application is laid out.
			//// For this introduction, we just print out "Hello, World!"
			//// in the top left corner.
			//TextOut(hdc,
			//	5, 5,
			//	greeting, _tcslen(greeting));
			//// End application-specific layout section.

			//EndPaint(hWnd, &ps);
			//break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
			break;
    }

    return 0;
}
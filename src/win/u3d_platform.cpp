#include "u3d_platform.h"

HINSTANCE hInst;
HWND hWnd;

ID2D1Factory *pD2DFactory;
ID2D1HwndRenderTarget *pRT;
ID2D1SolidColorBrush *pBlackBrush;
RECT rc;

U3DContext context;

TCHAR szTitle[MAX_LOADSTRING];
TCHAR szWindowClass[MAX_LOADSTRING];

ATOM				registerWindowClass(HINSTANCE hInstance);
BOOL				instanceWindow(HINSTANCE, int);
LRESULT CALLBACK	windowHandler(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
					_In_opt_ HINSTANCE hPrevInstance,
					_In_ LPTSTR    lpCmdLine,
					_In_ int       nCmdShow){
	U3DPoint point_at = {0.0f, 0.0f, 0.0f, 1.0f};
	U3DPoint point_to = {0.0f, 0.0f, 1.0f, 1.0f};
	U3DVector up_vector = {0.0f, 1.0f, 0.0f, 0.0f};
	MSG msg;
	HRESULT hr;
	FILE *f;

	u3d_makeContext(&context, 0.0f, 1.0f / 24.0f);
	u3d_makeCamera(&context.camera, &point_at, &point_to, &up_vector, 90.0, 0.1, 1000, 400, 400);
	u3d_makeList(&context.display_list);

	u3d_listAddNode(&context.display_list, NULL);
	u3d_listAddNode(&context.display_list, NULL);
	u3d_listAddNode(&context.display_list, NULL);

	u3d_cameraExportMatrix4Camera(&context.camera);

	AllocConsole();
	f = freopen("CONOUT$", "w+t", stdout);
	printf("%s\n", "Hello");

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	wcscpy_s(szTitle, MAX_LOADSTRING, L"HH");
	wcscpy_s(szWindowClass, MAX_LOADSTRING, L"HHHH");

	registerWindowClass(hInstance);

	if(!instanceWindow (hInstance, nCmdShow)){
		return FALSE;
	}

	pD2DFactory = NULL;
	hr = D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&pD2DFactory);
	// Obtain the size of the drawing area.
	GetClientRect(hWnd, &rc);

	// Create a Direct2D render target			
	pRT = NULL;			
	hr = pD2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
			hWnd,
			D2D1::SizeU(
				rc.right - rc.left,
				rc.bottom - rc.top)
		),
		&pRT);

	pBlackBrush = NULL;
	if (SUCCEEDED(hr)){
		pRT->CreateSolidColorBrush(
			D2D1::ColorF(D2D1::ColorF::GreenYellow),
			&pBlackBrush); 
	}

	while(GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	fclose(f);
	FreeConsole();
	pRT->Release();
	pBlackBrush->Release();
	pD2DFactory->Release();

	return (int)msg.wParam;
}

ATOM registerWindowClass(HINSTANCE hInstance){
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= windowHandler;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= NULL;//LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT1));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;//MAKEINTRESOURCE(IDC_WIN32PROJECT1);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= NULL;//LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

BOOL instanceWindow(HINSTANCE hInstance, int nCmdShow){
	hInst = hInstance;

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if(!hWnd){
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

LRESULT CALLBACK windowHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	int wmId, wmEvent;
	HRESULT hr;

	switch (message){
		case WM_COMMAND:
			wmId    = LOWORD(wParam);
			wmEvent = HIWORD(wParam);
			switch (wmId){
				default:
					return DefWindowProc(hWnd, message, wParam, lParam);
				}
			break;
		case WM_PAINT:
			if(pRT != 0){
				pRT->BeginDraw();

				pRT->DrawRectangle(
					D2D1::RectF(
						rc.left + 100.0f,
						rc.top + 100.0f,
						rc.right - 100.0f,
						rc.bottom - 100.0f),
						pBlackBrush);

				hr = pRT->EndDraw();			
			}
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}



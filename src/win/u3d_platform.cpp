#include "u3d_platform.h"

HINSTANCE hInst;
HWND hWnd;

U3DContext context;
int lock = 0;

TCHAR szTitle[MAX_LOADSTRING];
TCHAR szWindowClass[MAX_LOADSTRING];

ATOM				registerWindowClass(HINSTANCE hInstance);
BOOL				instanceWindow(HINSTANCE, int);
LRESULT CALLBACK	windowHandler(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
					_In_opt_ HINSTANCE hPrevInstance,
					_In_ LPTSTR    lpCmdLine,
					_In_ int       nCmdShow){
	MSG msg;
	FILE *f;
	float vertex[] = {
		1, 1, 1, 1,
		1, -1, 1, 1,
		-1, -1, 1, 1,
		-1, 1, 1, 1,
		1, 1, -1, 1,
		1, -1, -1, 1,
		-1, -1, -1, 1,
		-1, 1, -1, 1
	};
	float a[32], b[32], c[32];
	unsigned index[] = {
		0, 1, 2,
		0, 2, 3,
		4, 5, 6,
		4, 6, 7,
		0, 1, 5,
		0, 5, 4,
		3, 2, 6,
		3, 6, 7,
		0, 4, 7,
		0, 7, 3,
		1, 5, 6,
		1, 6, 2
	};	
	U3DPoint point_at = {0.0f, 0.0f, 0.0f, 1.0f};
	U3DPoint point_to = {0.0f, 0.0f, 1.0f, 1.0f};
	U3DVector up_vector = {0.0f, 1.0f, 0.0f, 0.0f};
	U3DObject object;
	u3d_makeObject(&object, vertex, index);
	object.vertex_raw_data4world = a;
	object.vertex_raw_data4camera = b;
	object.vertex_raw_data4final = c;

	u3d_makeContext(&context, 0.0f, 1.0f / 24.0f);
	u3d_makeCamera(&context.camera, &point_at, &point_to, &up_vector, 90.0, 0.1, 1000, 962, 518);
	u3d_makeList(&context.display_list);

	u3d_listAddNode(&context.display_list, &object);

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

	u3d_renderInit(hWnd);

	while(GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	fclose(f);
	FreeConsole();

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
			if(0 == lock){
				lock = 1;
				u3d_contextEnterFrame(&context);
				lock = 0;
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



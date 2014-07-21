#ifndef U3D_RENDER_H
#define U3D_RENDER_H

#include <windows.h>

#include <d2d1.h>
#include <d2d1_1.h>


void u3d_renderInit(HWND hWnd);

#ifdef __cplusplus
extern "C" {
#endif

	void u3d_renderDrawLine();
	
#ifdef __cplusplus
}
#endif

#endif

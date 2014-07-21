#ifndef U3D_RENDER_H
#define U3D_RENDER_H

#include <windows.h>

#include <d2d1.h>
#include <d2d1_1.h>


#ifdef __cplusplus
extern "C" {
#endif


void u3d_renderInit(HWND hWnd);
void u3d_renderDrawLine(float p0x, float p0y, float p1x, float p1y);


#ifdef __cplusplus
}
#endif

#endif

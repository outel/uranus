#include "u3d_render.h"

#ifdef __cplusplus
extern "C" {
#endif


static ID2D1Factory *d2dFactory;
static ID2D1HwndRenderTarget *render_target;
static ID2D1SolidColorBrush *black_brush;
static RECT rc;

void u3d_renderInit(HWND hWnd){
	HRESULT hr;

	d2dFactory = NULL;
	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &d2dFactory);

	GetClientRect(hWnd, &rc);

	render_target = NULL;			
	hr = d2dFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
			hWnd,
			D2D1::SizeU(
				rc.right - rc.left,
				rc.bottom - rc.top)
		),
		&render_target);

	black_brush = NULL;
	if (SUCCEEDED(hr)){
		render_target->CreateSolidColorBrush(
			D2D1::ColorF(D2D1::ColorF::GreenYellow),
			&black_brush); 
	}
}

void u3d_renderDrawLine(){
	// D2D1_POINT_2F p0 = {p0x, p0y};
	// D2D1_POINT_2F p1 = {p1x, p1y};

	if(render_target != NULL){
		render_target->BeginDraw();

		//render_target->DrawLine(p0, p1, black_brush, 0.1f);

		render_target->EndDraw();
	}
}


#ifdef __cplusplus
}
#endif

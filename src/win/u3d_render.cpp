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

void u3d_renderDrawLine(float *vertex_raw_data, unsigned *index_raw_data, unsigned length){
	D2D1_POINT_2F p0, p1;
	unsigned f;
	unsigned s;
	unsigned t;

	if(render_target != NULL){
		render_target->BeginDraw();

		for (unsigned i = 0; i < length; i += 3) {
			f = index_raw_data[i + 0];
			s = index_raw_data[i + 1];
			t = index_raw_data[i + 2];

			p0.x = vertex_raw_data[f * 4 + 0];
			p0.y = vertex_raw_data[f * 4 + 1];
			p1.x = vertex_raw_data[s * 4 + 0];
			p1.y = vertex_raw_data[s * 4 + 1];
			render_target->DrawLine(p0, p1, black_brush, 0.1f);
			p1.x = vertex_raw_data[t * 4 + 0];
			p1.y = vertex_raw_data[t * 4 + 1];
			render_target->DrawLine(p0, p1, black_brush, 0.1f);
			p0.x = vertex_raw_data[s * 4 + 0];
			p0.y = vertex_raw_data[s * 4 + 1];
			render_target->DrawLine(p0, p1, black_brush, 0.1f);
		}

		render_target->EndDraw();
	}
}


#ifdef __cplusplus
}
#endif

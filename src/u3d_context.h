#ifndef U3D_CONTEXT_H
#define U3D_CONTEXT_H

#include "u3d_camera.h"
#include "u3d_list.h"

typedef struct _U3DContext {
	unsigned render_type;
		
	float cumulative_time;
	float frame_rate;

	U3DCamera camera;
		
	U3DList display_list;
} U3DContext, *U3DContext_ptr;

void u3d_contextEnterFrame(U3DContext_ptr context);


#endif

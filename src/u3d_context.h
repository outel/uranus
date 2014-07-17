#ifndef U3D_CONTEXT_H
#define U3D_CONTEXT_H

#include "u3d_camera.h"
#include "u3d_setup.h"
#include "u3d_list.h"

typedef struct _U3DContext {
	unsigned render_type;
		
	number cumulative_time;
	number frame_rate;

	U3DCamera camera;
		
	U3DNode display_list;
} U3DContext, *U3DContext_ptr;

void s3d_contextRenderWire(U3DContext_ptr context, unsigned start_triangle, unsigned count_triangle);


#endif

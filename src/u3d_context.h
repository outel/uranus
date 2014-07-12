#ifndef U3D_CONTEXT_H
#define U3D_CONTEXT_H

#include "u3d_camera.h"

typedef struct _U3DContext {
	unsigned render_type;
		
	float cumulative_time;
	float frame_rate;
	
	//graphics:Graphics;

	U3DCamera camera;
		
	//head:S3DDisplayObject;
} U3DContext, *U3DContext_ptr;




#endif

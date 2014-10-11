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

U3DContext_ptr	u3d_contextCreate();
U3DContext_ptr	u3d_contextConstructDefault(U3DContext_ptr target);
U3DContext_ptr	u3d_contextConstruct(U3DContext_ptr target, float cumulative_time, float frame_rate);
U3DContext_ptr	u3d_contextDestruct(U3DContext_ptr target);
void			u3d_contextDelete(U3DContext_ptr target);


void u3d_contextEnterFrame(U3DContext_ptr context);


#endif

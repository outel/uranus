#include "u3d_context.h"

#include "win/u3d_render.h"


void u3d_contextEnterFrame(U3DContext_ptr context){
	U3DNode_ptr nxt = context->display_list.nxt;
	u3d_renderDrawLine();
}

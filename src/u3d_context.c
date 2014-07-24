#include <stdio.h>

#include "u3d_context.h"

#include "win/u3d_render.h"
#include "u3d_object.h"
#include "u3d_utils.h"



void u3d_contextEnterFrame(U3DContext_ptr context){
	U3DMatrix m_world = {
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 5.0, 1.0
	};
	U3DNode_ptr nxt = context->display_list.nxt;
	U3DObject_ptr obj;

	while(nxt != &context->display_list){
		obj = (U3DObject_ptr)nxt->data;

		u3d_utilsBatchMatrixMultiplication(obj->vertex_raw_data4world, obj->vertex_raw_data, 32, m_world.M, 4);
		
		u3d_cameraExportMatrix4Camera(&context->camera);
		u3d_utilsBatchMatrixMultiplication(obj->vertex_raw_data4camera, obj->vertex_raw_data4world, 32, context->camera.camera_matrix.M, 4);
			
		u3d_cameraExportMatrix4Projection(&context->camera);
		u3d_utilsBatchMatrixMultiplication(obj->vertex_raw_data4final, obj->vertex_raw_data4camera, 32, context->camera.projection_matrix.M, 4);
		u3d_utilsPerspectiveDivision(obj->vertex_raw_data4final, 32, 4);
			
		u3d_cameraExportMatrix4Screen(&context->camera);
		u3d_utilsBatchMatrixMultiplication(obj->vertex_raw_data4final, obj->vertex_raw_data4final, 32, context->camera.screen_matrix.M, 4);

		nxt = nxt->nxt;
	}

	u3d_renderDrawLine(obj->vertex_raw_data4final, obj->index_raw_data, 24);
}

#include <stdlib.h>

#include "u3d_object.h"
#include "u3d_init.h"
#include "u3d_matrix.h"
#include "u3d_setup.h"


U3DObject_ptr u3d_objectCreate(){
	return (U3DObject_ptr) malloc(sizeof(U3DObject));
}

U3DObject_ptr u3d_objectConstructDefault(U3DObject_ptr target){
	u3d_arrayfConstructDefault(&target->vertex_raw_data);
	u3d_arrayfConstructDefault(&target->vertex_raw_data4world);
	u3d_arrayfConstructDefault(&target->vertex_raw_data4camera);
	u3d_arrayfConstructDefault(&target->vertex_raw_data4final);

	u3d_arrayuConstructDefault(&target->index_raw_data);

	target->x = target->y = target->z = 0.0f;
	target->rx_deg = target->ry_deg = target->rz_deg = 0.0f;
	target->sx = target->sy = target->sz = 1.0f;

	u3d_matrixConstructDefault(&target->object_matrix);
	u3d_matrixConstructDefault(&target->world_matrix);

	target->object_matrix_invalid = target->world_matrix_invalid = 1;

	return target;
}

U3DObject_ptr u3d_objectDestruct(U3DObject_ptr target){
	u3d_arrayfDestruct(&target->vertex_raw_data);
	u3d_arrayfDestruct(&target->vertex_raw_data4world);
	u3d_arrayfDestruct(&target->vertex_raw_data4camera);
	u3d_arrayfDestruct(&target->vertex_raw_data4final);

	u3d_arrayuDestruct(&target->index_raw_data);

	u3d_matrixDestruct(&target->object_matrix);
	u3d_matrixDestruct(&target->world_matrix);

	return target;
}

void u3d_objectDelete(U3DObject_ptr target){
	free(target);
}

void u3d_objectCopyVertexRawData(U3DObject_ptr object, float *vertex_raw_data, unsigned raw_data_lenght){
	u3d_arrayfDestruct(&object->vertex_raw_data);
	u3d_arrayfDestruct(&object->vertex_raw_data4world);
	u3d_arrayfDestruct(&object->vertex_raw_data4camera);
	u3d_arrayfDestruct(&object->vertex_raw_data4final);

	u3d_arrayfConstruct(&object->vertex_raw_data, vertex_raw_data, raw_data_lenght);
	u3d_arrayfConstructLenght(&object->vertex_raw_data4world, raw_data_lenght);
	u3d_arrayfConstructLenght(&object->vertex_raw_data4camera, raw_data_lenght);
	u3d_arrayfConstructLenght(&object->vertex_raw_data4final, raw_data_lenght);
}

void u3d_objectCopyIndexRawData(U3DObject_ptr object, unsigned *index_raw_data, unsigned raw_data_lenght){
	u3d_arrayuDestruct(&object->index_raw_data);

	u3d_arrayuConstruct(&object->index_raw_data, index_raw_data, raw_data_lenght);
}

void u3d_objectExportMatrix4Object(U3DObject_ptr object){
	if(0 < object->object_matrix_invalid){
		U3DMatrix temp;
		u3d_matrixIdentity(&object->object_matrix);
		u3d_matrixMultiplication(&object->object_matrix, u3d_initMatrix4Rotation(&temp, object->rx_deg, object->ry_deg, object->rz_deg));
		u3d_matrixMultiplication(&object->object_matrix, u3d_initMatrix4Scale(&temp, object->sx, object->sy, object->sz));
		object->object_matrix_invalid = 0;
	}
}

void u3d_objectExportMatrix4World(U3DObject_ptr object){
	if(0 < object->world_matrix_invalid){
		U3DMatrix temp;
		u3d_matrixIdentity(&object->world_matrix);
		u3d_matrixMultiplication(&object->world_matrix, u3d_initMatrix4Translation(&temp, object->x, object->y, object->z));
		object->world_matrix_invalid = 0;
	}
}

void u3d_objectMoveTo(U3DObject_ptr object, float x, float y, float z){
	object->x = x;
	object->y = y;
	object->z = z;
	
	object->world_matrix_invalid = 1;
}

void s3d_objectRotateTo(U3DObject_ptr object, float rx_deg, float ry_deg, float rz_deg){
	object->rx_deg = rx_deg;
	object->ry_deg = ry_deg;
	object->rz_deg = rz_deg;
	
	object->object_matrix_invalid = 1;
}

void u3d_objectScaleTo(U3DObject_ptr object, float sx, float sy, float sz){
	object->sx = sx;
	object->sy = sy;
	object->sz = sz;
	
	object->object_matrix_invalid = 1;
}

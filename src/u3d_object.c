#include "u3d_object.h"
#include "u3d_init.h"
#include "u3d_matrix.h"
#include "u3d_setup.h"


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

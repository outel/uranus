#ifndef U3D_OBJECT_H
#define U3D_OBJECT_H

#include "u3d_array.h"
#include "u3d_matrix.h"


typedef struct _U3DObject {
	U3DArrayf	vertex_raw_data;
	U3DArrayf	vertex_raw_data4world;
	U3DArrayf	vertex_raw_data4camera;
	U3DArrayf	vertex_raw_data4final;

	U3DArrayu	index_raw_data;

	float		x, y, z;
	float		rx_deg, ry_deg, rz_deg;
	float		sx, sy, sz;

	U3DMatrix	object_matrix;
	unsigned	object_matrix_invalid;
		
	U3DMatrix	world_matrix;
	unsigned	world_matrix_invalid;
} U3DObject, *U3DObject_ptr;

void u3d_objectExportMatrix4Object(U3DObject_ptr object);
void u3d_objectExportMatrix4World(U3DObject_ptr object);
void u3d_objectMoveTo(U3DObject_ptr object, float x, float y, float z);
void s3d_objectRotateTo(U3DObject_ptr object, float rx_deg, float ry_deg, float rz_deg);
void u3d_objectScaleTo(U3DObject_ptr object, float sx, float sy, float sz);

#endif

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


U3DObject_ptr	u3d_objectCreate();
U3DObject_ptr	u3d_objectConstructDefault(U3DObject_ptr target);
U3DObject_ptr	u3d_objectDestruct(U3DObject_ptr target);
void			u3d_objectDelete(U3DObject_ptr target);

void u3d_objectCopyVertexRawData(U3DObject_ptr object, float *vertex_raw_data, unsigned raw_data_lenght);
void u3d_objectCopyIndexRawData(U3DObject_ptr object, unsigned *index_raw_data, unsigned raw_data_lenght);
void u3d_objectExportMatrix4Object(U3DObject_ptr object);
void u3d_objectExportMatrix4World(U3DObject_ptr object);
void u3d_objectMoveTo(U3DObject_ptr object, float x, float y, float z);
void s3d_objectRotateTo(U3DObject_ptr object, float rx_deg, float ry_deg, float rz_deg);
void u3d_objectScaleTo(U3DObject_ptr object, float sx, float sy, float sz);

#endif

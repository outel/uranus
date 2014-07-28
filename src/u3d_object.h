#ifndef U3D_OBJECT_H
#define U3D_OBJECT_H

#include "u3d_array.h"


typedef struct _U3DObject {
	U3DArrayf	vertex_raw_data;
	U3DArrayf	vertex_raw_data4world;
	U3DArrayf	vertex_raw_data4camera;
	U3DArrayf	vertex_raw_data4final;

	U3DArrayu	index_raw_data;

	float		x, y, z;
} U3DObject, *U3DObject_ptr;


#endif

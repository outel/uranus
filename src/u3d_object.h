#ifndef U3D_OBJECT_H
#define U3D_OBJECT_H


typedef struct _U3DObject {
	U3DArray4float		vertex_raw_data;
	U3DArray4float		vertex_raw_data4world;
	U3DArray4float		ertex_raw_data4camera;
	U3DArray4float		vertex_raw_data4final;

	U3DArray4unsigned	index_raw_data;

	float		x, y, z;
} U3DObject, *U3DObject_ptr;


#endif

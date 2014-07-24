#ifndef U3D_OBJECT_H
#define U3D_OBJECT_H


typedef struct _U3DObject {
	float		*vertex_raw_data;
	float		*vertex_raw_data4world;
	float		*vertex_raw_data4camera;
	float		*vertex_raw_data4final;

	unsigned	*index_raw_data;

	float		x, y, z;
} U3DObject, *U3DObject_ptr;


#endif

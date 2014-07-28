#ifndef U3D_ARRAY_H
#define U3D_ARRAY_H


typedef struct _U3DArrayf {
	float		*raw_data;
	unsigned	lenght;
} U3DArrayf, *U3DArrayf_ptr;


typedef struct _U3DArrayu {
	unsigned	*raw_data;
	unsigned	lenght;
} U3DArrayu, *U3DArrayu_ptr;


#endif

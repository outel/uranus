#ifndef U3D_ARRAY_H
#define U3D_ARRAY_H


typedef struct _U3DArray4float {
	float		*raw_data;
	unsigned	lenght;
} U3DArray4float, *U3DArray4float_ptr;




typedef struct _U3DArray4unsigned {
	unsigned	*raw_data;
	unsigned	lenght;
} U3DArray4unsigned, *U3DArray4unsigned_ptr;

#endif

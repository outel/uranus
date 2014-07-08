#ifndef U3D_MATRIX_H
#define U3D_MATRIX_H


typedef struct _U3DMatrix{
	union{
		float M[16];
	};
} U3DMatrix, *U3DMatrix_ptr;



#endif

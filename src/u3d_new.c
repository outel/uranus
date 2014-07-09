#include <stdlib.h>

#include "u3d_matrix.h"
#include "u3d_new.h"


U3DMatrix_ptr u3d_newMatrix(float raw_data[16]){
	U3DMatrix_ptr result = (U3DMatrix_ptr) malloc(sizeof(U3DMatrix));
	u3d_matrixCopyFromRawData(result, raw_data);
	return result;
}

U3DVector_ptr u3d_newVector(float x, float y, float z){
	U3DVector_ptr result = (U3DVector_ptr) malloc(sizeof(U3DVector));
	result->x = x;
	result->y = y;
	result->z = z;
	result->w = 0;
	return result;
}

U3DPoint_ptr u3d_newPoint(float x, float y, float z){
	U3DPoint_ptr result = (U3DPoint_ptr) malloc(sizeof(U3DPoint));
	result->x = x;
	result->y = y;
	result->z = z;
	result->w = 1;
	return result;
}

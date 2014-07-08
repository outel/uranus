#include <stdlib.h>

#include "u3d_new.h"
#include "u3d_utils.h"

unsigned* u3d_utilsArray4unsignedX(unsigned length){
	return (unsigned*) malloc(sizeof(unsigned) * length);
}

float* u3d_utilsArray4floatX(unsigned length){
	return (float*) malloc(sizeof(float) * length);
}

U3DVector_ptr u3d_utilsZeroVector(){
	return u3d_newVector(0.0, 0.0, 0.0);
}

U3DVector_ptr u3d_utilsRightVector(){
	return u3d_newVector(1.0, 0.0, 0.0);
}

U3DVector_ptr u3d_utilsUpVector(){
	return u3d_newVector(0.0, 1.0, 0.0);
}

U3DVector_ptr u3d_utilsFrontVector(){
	return u3d_newVector(0.0, 0.0, 1.0);
}

U3DMatrix_ptr u3d_utilsZeroMatrix(){
	float M[16] = {
		0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0
	};
	return u3d_newMatrix(M);
}

U3DMatrix_ptr u3d_utilsIdentityMatrix(){
	float M[16] = {
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0
	};
	return u3d_newMatrix(M);
}

U3DPoint_ptr u3d_utilsOriginPoint(){
	return u3d_newPoint(0.0, 0.0, 0.0);
}

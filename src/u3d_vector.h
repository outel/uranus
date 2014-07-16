﻿#ifndef U3D_VECTOR_H
#define U3D_VECTOR_H

#include "u3d_setup.h"


typedef struct _U3DVector {
	union {
		number V[4];
		struct {
			number x, y, z, w;
		};
	};
} U3DVector, *U3DVector_ptr, U3DPoint, *U3DPoint_ptr;

void	u3d_vectorAddition(U3DVector_ptr left, U3DVector_ptr right);
void	u3d_vectorAddition2Vector(U3DVector_ptr dst, U3DVector_ptr left, U3DVector_ptr right);
void	u3d_vectorCopyFromRawData(U3DVector_ptr dst, number raw_data[4]);
void	u3d_vectorCopyFromVector(U3DVector_ptr dst, U3DVector_ptr src);
void	u3d_vectorCrossProduct(U3DVector_ptr left, U3DVector_ptr right);
void	u3d_vectorCrossProduct2Vector(U3DVector_ptr dst, U3DVector_ptr left, U3DVector_ptr right);
number	u3d_vectorDotProduct(U3DVector_ptr left, U3DVector_ptr right);
number	u3d_vectorLength(U3DVector_ptr target);
void	u3d_vectorNormalize(U3DVector_ptr target);
void	u3d_vectorNormalize2Vector(U3DVector_ptr dst, U3DVector_ptr target);
void	u3d_vectorSubtraction(U3DVector_ptr left, U3DVector_ptr right);
void	u3d_vectorSubtraction2Vector(U3DVector_ptr dst, U3DVector_ptr left, U3DVector_ptr right);


#endif

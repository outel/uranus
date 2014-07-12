#ifndef U3D_UTILS_H
#define U3D_UTILS_H

#include <stdlib.h>

#include "u3d_matrix.h"
#include "u3d_vector.h"

unsigned*		u3d_utilsArray4unsignedX(unsigned length);
float*			u3d_utilsArray4floatX(unsigned length);
U3DVector_ptr	u3d_utilsZeroVector();
U3DVector_ptr	u3d_utilsRightVector();
U3DVector_ptr	u3d_utilsUpVector();
U3DVector_ptr	u3d_utilsFrontVector();
U3DMatrix_ptr	u3d_utilsZeroMatrix();
U3DMatrix_ptr	u3d_utilsIdentityMatrix();
U3DPoint_ptr	u3d_utilsOriginPoint();

#endif

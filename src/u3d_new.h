#ifndef U3D_NEW_H
#define U3D_NEW_H

#include "u3d_matrix.h"
#include "u3d_vector.h"


U3DMatrix_ptr u3d_newMatrix(float raw_data[16]);
U3DVector_ptr u3d_newVector(float x, float y, float z);
U3DPoint_ptr u3d_newPoint(float x, float y, float z);

#endif

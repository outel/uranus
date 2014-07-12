#ifndef U3D_NEW_H
#define U3D_NEW_H

#include "u3d_matrix.h"
#include "u3d_vector.h"
#include "u3d_camera.h"
#include "u3d_context.h"


U3DCamera_ptr	u3d_newCamera(U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector, float fovx, float near, float far, float view_port_width, float view_port_height);
U3DContext_ptr	u3d_newContext(float frame_rate);
U3DMatrix_ptr	u3d_newMatrix(float raw_data[16]);
U3DMatrix_ptr	u3d_newMatrix4Projection(float fovx_deg, float aspect_ratio, float near, float far);
U3DMatrix_ptr	u3d_newMatrix4Rotation(float rx_deg, float ry_deg, float rz_deg);
U3DMatrix_ptr	u3d_newMatrix4Scale(float sx, float sy, float sz);
U3DMatrix_ptr	u3d_newMatrix4Screen(float view_port_width, float  view_port_height);
U3DMatrix_ptr	u3d_newMatrix4Translation(float tx, float ty, float tz);
U3DMatrix_ptr	u3d_newMatrix4UVN(U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector);
U3DVector_ptr	u3d_newVector(float x, float y, float z);
U3DPoint_ptr	u3d_newPoint(float x, float y, float z);


#endif

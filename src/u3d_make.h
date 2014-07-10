#ifndef U3D_MAKE_H
#define U3D_MAKE_H

#include "u3d_matrix.h"
#include "u3d_vector.h"


void u3d_newMatrix(U3DMatrix_ptr target, float src_raw_data[16]);
void u3d_newMatrix4Projection(U3DMatrix_ptr target, float fovx_deg, float aspect_ratio, float near, float far);
void u3d_newMatrix4Rotation(U3DMatrix_ptr target, float rx_deg, float ry_deg, float rz_deg);
void u3d_newMatrix4Scale(U3DMatrix_ptr target, float sx, float sy, float sz);
void u3d_newMatrix4Screen(U3DMatrix_ptr target, float view_port_width, float  view_port_height);
void u3d_newMatrix4Translation(U3DMatrix_ptr target, float tx, float ty, float tz);
void u3d_newMatrix4UVN(U3DMatrix_ptr target, U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector);


#endif

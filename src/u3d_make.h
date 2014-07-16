#ifndef U3D_MAKE_H
#define U3D_MAKE_H

#include "u3d_camera.h"
#include "u3d_context.h"
#include "u3d_matrix.h"
#include "u3d_vector.h"
#include "u3d_setup.h"


void u3d_makeCamera(U3DCamera_ptr target, U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector, number fovx, number near_clip_plane, number far_clip_plane, number view_port_width, number view_port_height);
void u3d_makeContext(U3DContext_ptr target, number cumulative_time, number frame_rate);
void u3d_makeMatrix(U3DMatrix_ptr target, number src_raw_data[16]);
void u3d_makeMatrix4Projection(U3DMatrix_ptr target, number fovx_deg, number aspect_ratio, number near_clip_plane, number far_clip_plane);
void u3d_makeMatrix4Rotation(U3DMatrix_ptr target, number rx_deg, number ry_deg, number rz_deg);
void u3d_makeMatrix4Scale(U3DMatrix_ptr target, number sx, number sy, number sz);
void u3d_makeMatrix4Screen(U3DMatrix_ptr target, number view_port_width, number  view_port_height);
void u3d_makeMatrix4Translation(U3DMatrix_ptr target, number tx, number ty, number tz);
void u3d_makeMatrix4UVN(U3DMatrix_ptr target, U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector);


#endif

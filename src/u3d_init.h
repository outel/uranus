#ifndef U3D_INIT_H
#define U3D_INIT_H

#include "u3d_camera.h"
#include "u3d_context.h"
#include "u3d_matrix.h"
#include "u3d_vector.h"
#include "u3d_list.h"
#include "u3d_object.h"


U3DCamera_ptr	u3d_initCamera(U3DCamera_ptr target, U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector, float fovx, float near_clip_plane, float far_clip_plane, float view_port_width, float view_port_height);
U3DContext_ptr	u3d_initContext(U3DContext_ptr target, float cumulative_time, float frame_rate);
U3DMatrix_ptr	u3d_initMatrix(U3DMatrix_ptr target, float src_raw_data[16]);
U3DMatrix_ptr	u3d_initMatrix4Projection(U3DMatrix_ptr target, float fovx_deg, float aspect_ratio, float near_clip_plane, float far_clip_plane);
U3DMatrix_ptr	u3d_initMatrix4Rotation(U3DMatrix_ptr target, float rx_deg, float ry_deg, float rz_deg);
U3DMatrix_ptr	u3d_initMatrix4Scale(U3DMatrix_ptr target, float sx, float sy, float sz);
U3DMatrix_ptr	u3d_initMatrix4Screen(U3DMatrix_ptr target, float view_port_width, float  view_port_height);
U3DMatrix_ptr	u3d_initMatrix4Translation(U3DMatrix_ptr target, float tx, float ty, float tz);
U3DMatrix_ptr	u3d_initMatrix4UVN(U3DMatrix_ptr target, U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector);
U3DList_ptr		u3d_initList(U3DList_ptr target);
U3DObject_ptr	u3d_initObject(U3DObject_ptr target, unsigned lenght);
U3DArrayf_ptr	u3d_initArrayf(U3DArrayf_ptr target, unsigned lenght);
U3DArrayu_ptr	u3d_initArrayu(U3DArrayu_ptr target, unsigned lenght);

#endif

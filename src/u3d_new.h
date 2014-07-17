#ifndef U3D_NEW_H
#define U3D_NEW_H

#include "u3d_setup.h"

#include "u3d_matrix.h"
#include "u3d_vector.h"
#include "u3d_camera.h"
#include "u3d_context.h"
#include "u3d_list.h"


U3DCamera_ptr	u3d_newCamera(U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector, number fovx, number near_clip_plane, number far_clip_plane, number view_port_width, number view_port_height);
U3DContext_ptr	u3d_newContext(number frame_rate);
U3DMatrix_ptr	u3d_newMatrix(number raw_data[16]);
U3DMatrix_ptr	u3d_newMatrix4Projection(number fovx_deg, number aspect_ratio, number near, number far);
U3DMatrix_ptr	u3d_newMatrix4Rotation(number rx_deg, number ry_deg, number rz_deg);
U3DMatrix_ptr	u3d_newMatrix4Scale(number sx, number sy, number sz);
U3DMatrix_ptr	u3d_newMatrix4Screen(number view_port_width, number  view_port_height);
U3DMatrix_ptr	u3d_newMatrix4Translation(number tx, number ty, number tz);
U3DMatrix_ptr	u3d_newMatrix4UVN(U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector);
U3DVector_ptr	u3d_newVector(number x, number y, number z);
U3DPoint_ptr	u3d_newPoint(number x, number y, number z);
U3DNode_ptr		u3d_newList();
U3DNode_ptr		u3d_newNode();


#endif

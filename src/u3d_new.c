#include <math.h>
#include <stdlib.h>


#include "u3d_new.h"
#include "u3d_utils.h"
#include "u3d_setup.h"


U3DCamera_ptr u3d_newCamera(U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector, number fovx, number near_clip_plane, number far_clip_plane, number view_port_width, number view_port_height){
	U3DCamera_ptr result = (U3DCamera_ptr) malloc(sizeof(U3DCamera));
	u3d_vectorCopyFromVector(&result->point_at, point_at);
	u3d_vectorCopyFromVector(&result->point_to, point_to);
	u3d_vectorCopyFromVector(&result->up_vector, up_vector);
	result->fovx_deg = fovx;
	result->near_clip_plane = near_clip_plane;
	result->far_clip_plane = far_clip_plane;
	result->view_port_width = view_port_width;
	result->view_port_height = view_port_height;
	result->aspect_ratio = view_port_width / view_port_height;
	result->camera_matrix_invalid = result->projection_matrix_invalid = result->screen_matrix_invalid = 1;
	return result;
}

U3DContext_ptr	u3d_newContext(number frame_rate){
	U3DContext_ptr result = (U3DContext_ptr) malloc(sizeof(U3DContext));
	result->frame_rate = frame_rate;
	return result;
}

U3DMatrix_ptr u3d_newMatrix(number raw_data[16]){
	U3DMatrix_ptr result = (U3DMatrix_ptr) malloc(sizeof(U3DMatrix));
	u3d_matrixCopyFromRawData(result, raw_data);
	return result;
}

U3DMatrix_ptr u3d_newMatrix4Projection(number fovx_deg, number aspect_ratio, number near_clip_plane, number far_clip_plane){
	number zoom_x = 1.0 / tan(fovx_deg * DEG_2_RAD / 2.0);
	number zoom_y = aspect_ratio * zoom_x;
	number temp[16] = {
		zoom_x, 0.0, 0.0, 0.0,
		0.0, zoom_y, 0.0, 0.0,
		0.0, 0.0, (far_clip_plane + near_clip_plane)/(far_clip_plane - near_clip_plane), 1.0,
		0.0, 0.0, (-2.0 * far_clip_plane * near_clip_plane)/(far_clip_plane - near_clip_plane), 0.0
	};
	return u3d_newMatrix(temp);
}

U3DMatrix_ptr u3d_newMatrix4Rotation(number rx_deg, number ry_deg, number rz_deg){
	U3DMatrix_ptr result = (U3DMatrix_ptr) malloc(sizeof(U3DMatrix));
	u3d_matrixIdentity(result);
	
	if(0.0 != rx_deg){
		number rx_rad = rx_deg * DEG_2_RAD;
		number sx = sin(rx_rad);
		number cx = cos(rx_rad);
		U3DMatrix mtx_x = {
			1.0, 0.0, 0.0, 0.0,
			0.0, sx, -cx, 0.0,
			0.0, cx, sx, 0.0,
			0.0, 0.0, 0.0, 1.0
		};
		u3d_matrixMultiplication(result, &mtx_x);
	}
	if(0.0 != ry_deg){
		number ry_rad = ry_deg * DEG_2_RAD;
		number sy = sin(ry_rad);
		number cy = cos(ry_rad);
		U3DMatrix mtx_y = {
			sy, 0.0, cy, 0.0,
			0.0, 1.0, 0.0, 0.0,
			cy, 0.0, -sy, 0.0,
			0.0, 0.0, 0.0, 1.0
		};
		u3d_matrixMultiplication(result, &mtx_y);
	}
	if(rz_deg != 0.0){
		number rz_rad = rz_deg * DEG_2_RAD;
		number sz = sin(rz_rad);
		number cz = cos(rz_rad);
		U3DMatrix mtx_z = {
			cz, sz, 0.0, 0.0,
			-sz, cz, 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			0.0, 0.0, 0.0, 1.0
		};
		u3d_matrixMultiplication(result, &mtx_z);
	}
	
	return result;
}

U3DMatrix_ptr u3d_newMatrix4Scale(number sx, number sy, number sz){
	number temp[16] = {
		sx, 0.0, 0.0, 0.0,
		0.0, sy, 0.0, 0.0,
		0.0, 0.0, sz, 0.0,
		0.0, 0.0, 0.0, 1.0
	};
	return u3d_newMatrix(temp);
}

U3DMatrix_ptr u3d_newMatrix4Screen(number view_port_width, number  view_port_height){
	number half_width = (view_port_width - 1.0) / 2.0;
	number half_height = (view_port_height - 1.0) / 2.0;
	number temp[16] = {
		half_width, 0.0, 0.0, 0.0,
		0.0, -half_height, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		half_width, half_height, 0.0, 1.0
	};
	return u3d_newMatrix(temp);
}

U3DMatrix_ptr u3d_newMatrix4Translation(number tx, number ty, number tz){
	number temp[16] = {
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		tx, ty, tz, 1.0
	};
	return u3d_newMatrix(temp);
}

U3DMatrix_ptr u3d_newMatrix4UVN(U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector){
	U3DMatrix_ptr result = (U3DMatrix_ptr) malloc(sizeof(U3DMatrix));
	
	U3DVector n = {point_to->x - point_at->x, point_to->y - point_at->y, point_to->z - point_at->z};
	U3DVector u;
	U3DVector v;
	U3DVector t = {point_at->x, point_at->y, point_at->z, 0.0};
	U3DVector tt;

	u3d_vectorNormalize(&n);

	u3d_vectorCrossProduct2Vector(&u, up_vector, &n);
	u3d_vectorNormalize(&u);

	u3d_vectorCrossProduct2Vector(&v, &n, &u);
	
	tt.x = -u3d_vectorDotProduct(&t, &u);
	tt.y = -u3d_vectorDotProduct(&t, &v);
	tt.z = -u3d_vectorDotProduct(&t, &n);
	tt.w = 1.0;
	
	u3d_matrixCopyColumnFromVector(result, 0, &u);
	u3d_matrixCopyColumnFromVector(result, 1, &v);
	u3d_matrixCopyColumnFromVector(result, 2, &n);
	u3d_matrixCopyRowFromVector(result, 3, &tt);
	
	return result;
}

U3DVector_ptr u3d_newVector(number x, number y, number z){
	U3DVector_ptr result = (U3DVector_ptr) malloc(sizeof(U3DVector));
	result->x = x;
	result->y = y;
	result->z = z;
	result->w = 0.0;
	return result;
}

U3DPoint_ptr u3d_newPoint(number x, number y, number z){
	U3DPoint_ptr result = (U3DPoint_ptr) malloc(sizeof(U3DPoint));
	result->x = x;
	result->y = y;
	result->z = z;
	result->w = 1.0;
	return result;
}

U3DNode_ptr	u3d_newList(){
	U3DNode_ptr result = (U3DNode_ptr) malloc(sizeof(U3DNode));
	result->pre = result;
	result->nxt = result;
	return result;
}

U3DNode_ptr	u3d_newNode(){
	return (U3DNode_ptr) malloc(sizeof(U3DNode));
}

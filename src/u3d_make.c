#include <math.h>

#include "u3d_setup.h"
#include "u3d_context.h"
#include "u3d_make.h"


void u3d_makeCamera(U3DCamera_ptr target, U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector, number fovx, number near_clip_plane, number far_clip_plane, number view_port_width, number view_port_height){
	u3d_vectorCopyFromVector(&target->point_at, point_at);
	u3d_vectorCopyFromVector(&target->point_to, point_to);
	u3d_vectorCopyFromVector(&target->up_vector, up_vector);
	target->fovx_deg = fovx;
	target->near_clip_plane = near_clip_plane;
	target->far_clip_plane = far_clip_plane;
	target->view_port_width = view_port_width;
	target->view_port_height = view_port_height;
	target->aspect_ratio = view_port_width / view_port_height;
	target->camera_matrix_invalid = target->projection_matrix_invalid = target->screen_matrix_invalid = 1;
}

void u3d_makeContext(U3DContext_ptr target, number cumulative_time, number frame_rate){
	target->cumulative_time = cumulative_time;
	target->frame_rate = frame_rate;
}

void u3d_makeMatrix(U3DMatrix_ptr target, number src_raw_data[16]){
	u3d_matrixCopyFromRawData(target, src_raw_data);
}

void u3d_makeMatrix4Projection(U3DMatrix_ptr target, number fovx_deg, number aspect_ratio, number near_clip_plane, number far_clip_plane){
	number zoom_x = 1.0 / tan(fovx_deg * DEG_2_RAD / 2.0);
	number zoom_y = aspect_ratio * zoom_x;
	number temp[16] = {
		zoom_x, 0.0, 0.0, 0.0,
		0.0, zoom_y, 0.0, 0.0,
		0.0, 0.0, (far_clip_plane + near_clip_plane)/(far_clip_plane - near_clip_plane), 1.0,
		0.0, 0.0, (-2.0 * far_clip_plane * near_clip_plane)/(far_clip_plane - near_clip_plane), 0.0
	};
	u3d_matrixCopyFromRawData(target, temp);
}

void u3d_makeMatrix4Rotation(U3DMatrix_ptr target, number rx_deg, number ry_deg, number rz_deg){
	u3d_matrixIdentity(target);

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
		u3d_matrixMultiplication(target, &mtx_x);
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
		u3d_matrixMultiplication(target, &mtx_y);
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
		u3d_matrixMultiplication(target, &mtx_z);
	}
}

void u3d_makeMatrix4Scale(U3DMatrix_ptr target, number sx, number sy, number sz){
	number temp[16] = {
		sx, 0.0, 0.0, 0.0,
		0.0, sy, 0.0, 0.0,
		0.0, 0.0, sz, 0.0,
		0.0, 0.0, 0.0, 1.0
	};
	u3d_matrixCopyFromRawData(target, temp);
}

void u3d_makeMatrix4Screen(U3DMatrix_ptr target, number view_port_width, number  view_port_height){
	number half_width = (view_port_width - 1.0) / 2.0;
	number half_height = (view_port_height - 1.0) / 2.0;
	number temp[16] = {
		half_width, 0.0, 0.0, 0.0,
		0.0, -half_height, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		half_width, half_height, 0.0, 1.0
	};
	u3d_matrixCopyFromRawData(target, temp);
}

void u3d_makeMatrix4Translation(U3DMatrix_ptr target, number tx, number ty, number tz){
	number temp[16] = {
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		tx, ty, tz, 1.0
	};
	u3d_matrixCopyFromRawData(target, temp);
}

void u3d_makeMatrix4UVN(U3DMatrix_ptr result, U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector){
	U3DVector n = {point_to->x - point_at->x, point_to->y - point_at->y, point_to->z - point_at->z, 0.0};
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
}

void u3d_makeList(U3DNode_ptr target){
	target->pre = target;
	target->nxt = target;
}

#include <math.h>

#include "u3d_setup.h"
#include "u3d_context.h"
#include "u3d_init.h"


U3DCamera_ptr u3d_initCamera(U3DCamera_ptr target, U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector, float fovx, float near_clip_plane, float far_clip_plane, float view_port_width, float view_port_height){
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

	return target;
}

U3DContext_ptr u3d_initContext(U3DContext_ptr target, float cumulative_time, float frame_rate){
	target->cumulative_time = cumulative_time;
	target->frame_rate = frame_rate;

	return target;
}

U3DMatrix_ptr u3d_initMatrix(U3DMatrix_ptr target, float src_raw_data[16]){
	u3d_matrixCopyFromRawData(target, src_raw_data);

	return target;
}

U3DMatrix_ptr u3d_initMatrix4Projection(U3DMatrix_ptr target, float fovx_deg, float aspect_ratio, float near_clip_plane, float far_clip_plane){
	float zoom_x = 1.0 / tan(fovx_deg * DEG_2_RAD / 2.0);
	float zoom_y = aspect_ratio * zoom_x;
	float temp[16] = {
		zoom_x, 0.0, 0.0, 0.0,
		0.0, zoom_y, 0.0, 0.0,
		0.0, 0.0, (far_clip_plane + near_clip_plane)/(far_clip_plane - near_clip_plane), 1.0,
		0.0, 0.0, (-2.0 * far_clip_plane * near_clip_plane)/(far_clip_plane - near_clip_plane), 0.0
	};
	u3d_matrixCopyFromRawData(target, temp);

	return target;
}

U3DMatrix_ptr u3d_initMatrix4Rotation(U3DMatrix_ptr target, float rx_deg, float ry_deg, float rz_deg){
	u3d_matrixIdentity(target);

	if(0.0 != rx_deg){
		float rx_rad = rx_deg * DEG_2_RAD;
		float sx = sin(rx_rad);
		float cx = cos(rx_rad);
		U3DMatrix mtx_x = {
			1.0, 0.0, 0.0, 0.0,
			0.0, sx, -cx, 0.0,
			0.0, cx, sx, 0.0,
			0.0, 0.0, 0.0, 1.0
		};
		u3d_matrixMultiplication(target, &mtx_x);
	}
	if(0.0 != ry_deg){
		float ry_rad = ry_deg * DEG_2_RAD;
		float sy = sin(ry_rad);
		float cy = cos(ry_rad);
		U3DMatrix mtx_y = {
			sy, 0.0, cy, 0.0,
			0.0, 1.0, 0.0, 0.0,
			cy, 0.0, -sy, 0.0,
			0.0, 0.0, 0.0, 1.0
		};
		u3d_matrixMultiplication(target, &mtx_y);
	}
	if(rz_deg != 0.0){
		float rz_rad = rz_deg * DEG_2_RAD;
		float sz = sin(rz_rad);
		float cz = cos(rz_rad);
		U3DMatrix mtx_z = {
			cz, sz, 0.0, 0.0,
			-sz, cz, 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			0.0, 0.0, 0.0, 1.0
		};
		u3d_matrixMultiplication(target, &mtx_z);
	}

	return target;
}

U3DMatrix_ptr u3d_initMatrix4Scale(U3DMatrix_ptr target, float sx, float sy, float sz){
	float temp[16] = {
		sx, 0.0, 0.0, 0.0,
		0.0, sy, 0.0, 0.0,
		0.0, 0.0, sz, 0.0,
		0.0, 0.0, 0.0, 1.0
	};
	u3d_matrixCopyFromRawData(target, temp);

	return target;
}

U3DMatrix_ptr u3d_initMatrix4Screen(U3DMatrix_ptr target, float view_port_width, float  view_port_height){
	float half_width = (view_port_width - 1.0) / 2.0;
	float half_height = (view_port_height - 1.0) / 2.0;
	float temp[16] = {
		half_width, 0.0, 0.0, 0.0,
		0.0, -half_height, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		half_width, half_height, 0.0, 1.0
	};
	u3d_matrixCopyFromRawData(target, temp);

	return target;
}

U3DMatrix_ptr u3d_initMatrix4Translation(U3DMatrix_ptr target, float tx, float ty, float tz){
	float temp[16] = {
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		tx, ty, tz, 1.0
	};
	u3d_matrixCopyFromRawData(target, temp);

	return target;
}

U3DMatrix_ptr u3d_initMatrix4UVN(U3DMatrix_ptr target, U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector){
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
	
	u3d_matrixCopyColumnFromVector(target, 0, &u);
	u3d_matrixCopyColumnFromVector(target, 1, &v);
	u3d_matrixCopyColumnFromVector(target, 2, &n);
	u3d_matrixCopyRowFromVector(target, 3, &tt);

	return target;
}

U3DList_ptr u3d_initList(U3DList_ptr target){
	target->pre = target;
	target->nxt = target;

	return target;
}

U3DObject_ptr u3d_initObject(U3DObject_ptr target, unsigned vertex_lenght){
	u3d_initArrayf(&target->vertex_raw_data4world, vertex_lenght);
	u3d_initArrayf(&target->vertex_raw_data4camera, vertex_lenght);
	u3d_initArrayf(&target->vertex_raw_data4final, vertex_lenght);

	return target;
}

U3DArrayf_ptr u3d_initArrayf(U3DArrayf_ptr target, unsigned lenght){
	target->raw_data = (float *) malloc(sizeof(float) * lenght);
	target->lenght = lenght;

	return target;
}

U3DArrayu_ptr u3d_initArrayu(U3DArrayu_ptr target, unsigned lenght){
	target->raw_data = (unsigned *) malloc(sizeof(unsigned) * lenght);
	target->lenght = lenght;
	
	return target;
}


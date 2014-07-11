#include <math.h>
#include "u3d_make.h"
#include "u3d_const.h"

void u3d_makeMatrix(U3DMatrix_ptr target, float src_raw_data[16]){
	u3d_matrixCopyFromRawData(target, src_raw_data);
}

void u3d_makeMatrix4Projection(U3DMatrix_ptr target, float fovx_deg, float aspect_ratio, float near, float far){
	float zoom_x = 1.0 / tan(fovx_deg * DEG_2_RAD / 2.0);
	float zoom_y = aspect_ratio * zoom_x;
	float temp[16] = {
		zoom_x, 0.0, 0.0, 0.0,
		0.0, zoom_y, 0.0, 0.0,
		0.0, 0.0, (far + near)/(far - near), 1.0,
		0.0, 0.0, (-2.0 * far * near)/(far - near), 0.0
	};
	u3d_matrixCopyFromRawData(target, temp);
}

void u3d_makeMatrix4Rotation(U3DMatrix_ptr target, float rx_deg, float ry_deg, float rz_deg){
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
}

void u3d_makeMatrix4Scale(U3DMatrix_ptr target, float sx, float sy, float sz){
	float temp[16] = {
		sx, 0.0, 0.0, 0.0,
		0.0, sy, 0.0, 0.0,
		0.0, 0.0, sz, 0.0,
		0.0, 0.0, 0.0, 1.0
	};
	u3d_matrixCopyFromRawData(target, temp);
}

void u3d_makeMatrix4Screen(U3DMatrix_ptr target, float view_port_width, float  view_port_height){
	float half_width = (view_port_width - 1.0) / 2.0;
	float half_height = (view_port_height - 1.0) / 2.0;
	float temp[16] = {
		half_width, 0.0, 0.0, 0.0,
		0.0, -half_height, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		half_width, half_height, 0.0, 1.0
	};
	u3d_matrixCopyFromRawData(target, temp);
}

void u3d_makeMatrix4Translation(U3DMatrix_ptr target, float tx, float ty, float tz){
	float temp[16] = {
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

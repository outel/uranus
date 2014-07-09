#include <math.h>
#include <stdlib.h>


#include "u3d_new.h"
#include "u3d_utils.h"
#include "u3d_const.h"


U3DCamera_ptr u3d_newCamera(U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector, float fovx, float near, float far, float view_port_width, float view_port_height){
	U3DCamera_ptr result = (U3DCamera_ptr) malloc(sizeof(U3DCamera));
	result->point_at = u3d_vectorCopyFromVector(u3d_utilsZeroVector(), point_at);
	result->point_to = u3d_vectorCopyFromVector(u3d_utilsZeroVector(), point_to);
	result->up_vector = u3d_vectorCopyFromVector(u3d_utilsZeroVector(), up_vector);
	result->fovx_deg = fovx;
	result->near = near;
	result->far = far;
	result->view_port_width = view_port_width;
	result->view_port_height = view_port_height;
	result->aspect_ratio = view_port_width / view_port_height;
	result->camera_matrix_invalid = result->projection_matrix_invalid = result->screen_matrix_invalid = 1;
	return result;
}

U3DMatrix_ptr u3d_newMatrix(float raw_data[16]){
	U3DMatrix_ptr result = (U3DMatrix_ptr) malloc(sizeof(U3DMatrix));
	u3d_matrixCopyFromRawData(result, raw_data);
	return result;
}

U3DMatrix_ptr u3d_newMatrix4Projection(float fovx_deg, float aspect_ratio, float near, float far){
	float zoom_x = 1.0 / tan(fovx_deg * DEG_2_RAD / 2.0);
	float zoom_y = aspect_ratio * zoom_x;
	float temp[16] = {
		zoom_x, 0.0, 0.0, 0.0,
		0.0, zoom_y, 0.0, 0.0,
		0.0, 0.0, (far + near)/(far - near), 1.0,
		0.0, 0.0, (-2.0 * far * near)/(far - near), 0.0
	};
	return u3d_newMatrix(temp);
}

U3DMatrix_ptr u3d_newMatrix4Rotation(float rx_deg, float ry_deg, float rz_deg){
	U3DMatrix_ptr result = u3d_utilsIdentityMatrix();
	
	if(0.0 != rx_deg){
		float rx_rad = rx_deg * DEG_2_RAD;
		float sx = sin(rx_rad);
		float cx = cos(rx_rad);
		float raw_x[16] = {
			1.0, 0.0, 0.0, 0.0,
			0.0, sx, -cx, 0.0,
			0.0, cx, sx, 0.0,
			0.0, 0.0, 0.0, 1.0
		};
		u3d_matrixCopyFromRawData(result, u3d_matrixMultiplicationInRawData(u3d_utilsArray4floatX(16), result->M, raw_x));
	}
	if(0.0 != ry_deg){
		float ry_rad = ry_deg * DEG_2_RAD;
		float sy = sin(ry_rad);
		float cy = cos(ry_rad);
		float raw_y[16] = {
			sy, 0.0, cy, 0.0,
			0.0, 1.0, 0.0, 0.0,
			cy, 0.0, -sy, 0.0,
			0.0, 0.0, 0.0, 1.0
		};
		u3d_matrixCopyFromRawData(result, u3d_matrixMultiplicationInRawData(u3d_utilsArray4floatX(16), result->M, raw_y));
	}
	if(rz_deg != 0.0){
		float rz_rad = rz_deg * DEG_2_RAD;
		float sz = sin(rz_rad);
		float cz = cos(rz_rad);
		float raw_z[16] = {
			cz, sz, 0.0, 0.0,
			-sz, cz, 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			0.0, 0.0, 0.0, 1.0
		};
		u3d_matrixCopyFromRawData(result, u3d_matrixMultiplicationInRawData(u3d_utilsArray4floatX(16), result->M, raw_z));
	}
	
	return result;
}

U3DMatrix_ptr u3d_newMatrix4Scale(float sx, float sy, float sz){
	float temp[16] = {
		sx, 0.0, 0.0, 0.0,
		0.0, sy, 0.0, 0.0,
		0.0, 0.0, sz, 0.0,
		0.0, 0.0, 0.0, 1.0
	};
	return u3d_newMatrix(temp);
}

U3DMatrix_ptr u3d_newMatrix4Screen(float view_port_width, float  view_port_height){
	float half_width = (view_port_width - 1.0) / 2.0;
	float half_height = (view_port_height - 1.0) / 2.0;
	float temp[16] = {
		half_width, 0.0, 0.0, 0.0,
		0.0, -half_height, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		half_width, half_height, 0.0, 1.0
	};
	return u3d_newMatrix(temp);
}

U3DMatrix_ptr u3d_newMatrix4Translation(float tx, float ty, float tz){
	float temp[16] = {
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		tx, ty, tz, 1.0
	};
	return u3d_newMatrix(temp);
}

U3DMatrix_ptr u3d_newMatrix4UVN(U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector){
	U3DMatrix_ptr result = u3d_utilsZeroMatrix();
	
	U3DVector_ptr n = u3d_newVector(point_to->x - point_at->x, point_to->y - point_at->y, point_to->z - point_at->z);
	//TODO
	//u3d_vectorNormalize(n);
	U3DVector_ptr u = u3d_vectorCrossProduct2Vector(u3d_utilsZeroVector(), up_vector, n);
	//TODO
	//u3d_vectorNormalize(u);
	U3DVector_ptr v = u3d_vectorCrossProduct2Vector(u3d_utilsZeroVector(), n, u);
	
	U3DVector_ptr t = u3d_newVector(point_at->x, point_at->y, point_at->z);
	float tx = -u3d_vectorDotProduct(t, u);
	float ty = -u3d_vectorDotProduct(t, v);
	float tz = -u3d_vectorDotProduct(t, n);
	U3DVector_ptr tt = u3d_newVector(tx, ty, tz);
	tt->w = 1;
	
	u3d_matrixCopyColumnFromVector(result, 0, u);
	u3d_matrixCopyColumnFromVector(result, 1, v);
	u3d_matrixCopyColumnFromVector(result, 2, n);
	u3d_matrixCopyRowFromVector(result, 3, tt);
	
	return result;
}

U3DVector_ptr u3d_newVector(float x, float y, float z){
	U3DVector_ptr result = (U3DVector_ptr) malloc(sizeof(U3DVector));
	result->x = x;
	result->y = y;
	result->z = z;
	result->w = 0;
	return result;
}

U3DPoint_ptr u3d_newPoint(float x, float y, float z){
	U3DPoint_ptr result = (U3DPoint_ptr) malloc(sizeof(U3DPoint));
	result->x = x;
	result->y = y;
	result->z = z;
	result->w = 1;
	return result;
}

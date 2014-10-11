#ifndef U3D_MATRIX_H
#define U3D_MATRIX_H

#include "u3d_vector.h"

#define RC00	0
#define RC01	1
#define RC02	2
#define RC03	3
#define RC10	4
#define RC11	5
#define RC12	6
#define RC13	7
#define RC20	8
#define RC21	9
#define RC22	10
#define RC23	11
#define RC30	12
#define RC31	13
#define RC32	14
#define RC33	15

typedef struct _U3DMatrix {
	union {
		float M[16];
		float RC[4][4];
		struct {
			float M00, M01, M02, M03;
			float M10, M11, M12, M13;
			float M20, M21, M22, M23;
			float M30, M31, M32, M33;
		};
	};
} U3DMatrix, *U3DMatrix_ptr;

U3DMatrix_ptr	u3d_matrixCreate();
U3DMatrix_ptr	u3d_matrixConstructDefault(U3DMatrix_ptr target);
U3DMatrix_ptr	u3d_matrixConstruct(U3DMatrix_ptr target, float src_raw_data[16]);
U3DMatrix_ptr	u3d_matrixConstruct4Projection(U3DMatrix_ptr target, float fovx_deg, float aspect_ratio, float near_clip_plane, float far_clip_plane);
U3DMatrix_ptr	u3d_matrixConstruct4Rotation(U3DMatrix_ptr target, float rx_deg, float ry_deg, float rz_deg);
U3DMatrix_ptr	u3d_matrixConstruct4Scale(U3DMatrix_ptr target, float sx, float sy, float sz);
U3DMatrix_ptr	u3d_matrixConstruct4Screen(U3DMatrix_ptr target, float view_port_width, float  view_port_height);
U3DMatrix_ptr	u3d_matrixConstruct4Translation(U3DMatrix_ptr target, float tx, float ty, float tz);
U3DMatrix_ptr	u3d_matrixConstruct4UVN(U3DMatrix_ptr target, U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector);
U3DMatrix_ptr	u3d_matrixDestruct(U3DMatrix_ptr target);
void			u3d_matrixDelete(U3DMatrix_ptr target);

void u3d_matrixCopyColumnFromRawData(U3DMatrix_ptr dst, unsigned column, float src_raw_data[4]);
void u3d_matrixCopyColumnFromVector(U3DMatrix_ptr dst, unsigned column, U3DVector_ptr src);
void u3d_matrixCopyColumnToRawData(float dst_raw_data[4], unsigned column, U3DMatrix_ptr src);
void u3d_matrixCopyColumnToVector(U3DVector_ptr dst, unsigned column, U3DMatrix_ptr src);
void u3d_matrixCopyFromMatrix(U3DMatrix_ptr dst, U3DMatrix_ptr src);
void u3d_matrixCopyFromRawData(U3DMatrix_ptr dst, float src_raw_data[16]);
void u3d_matrixCopyRowFromRawData(U3DMatrix_ptr dst, unsigned row, float src_raw_data[4]);
void u3d_matrixCopyRowFromVector(U3DMatrix_ptr dst, unsigned row, U3DVector_ptr src);
void u3d_matrixCopyRowToRawData(float dst_raw_data[4], unsigned row, U3DMatrix_ptr src);
void u3d_matrixCopyRowToVector(U3DVector_ptr dst, unsigned row, U3DMatrix_ptr src);
void u3d_matrixIdentity(U3DMatrix_ptr target);
void u3d_matrixMultiplication(U3DMatrix_ptr left, U3DMatrix_ptr right);
void u3d_matrixMultiplication2Matrix(U3DMatrix_ptr dst, U3DMatrix_ptr left, U3DMatrix_ptr right);
void u3d_matrixMultiplicationInRawData(float dst[16], float left_raw_data[16], float right_raw_data[16]);
void u3d_matrixTranspose(U3DMatrix_ptr target);
void u3d_matrixTranspose2Matrix(U3DMatrix_ptr dst, U3DMatrix_ptr src);
void u3d_matrixTransposeInRawData(float dst_raw_data[16], float src_raw_data[16]);


#endif

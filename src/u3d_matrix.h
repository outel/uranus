#ifndef U3D_MATRIX_H
#define U3D_MATRIX_H

#include "u3d_vector.h"


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

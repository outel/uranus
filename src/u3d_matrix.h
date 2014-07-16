#ifndef U3D_MATRIX_H
#define U3D_MATRIX_H

#include "u3d_vector.h"
#include "u3d_setup.h"


typedef struct _U3DMatrix {
	union {
		number M[16];
		number RC[4][4];
		struct {
			number M00, M01, M02, M03;
			number M10, M11, M12, M13;
			number M20, M21, M22, M23;
			number M30, M31, M32, M33;
		};
	};
} U3DMatrix, *U3DMatrix_ptr;

void u3d_matrixCopyColumnFromRawData(U3DMatrix_ptr dst, unsigned column, number src_raw_data[4]);
void u3d_matrixCopyColumnFromVector(U3DMatrix_ptr dst, unsigned column, U3DVector_ptr src);
void u3d_matrixCopyColumnToRawData(number dst_raw_data[4], unsigned column, U3DMatrix_ptr src);
void u3d_matrixCopyColumnToVector(U3DVector_ptr dst, unsigned column, U3DMatrix_ptr src);
void u3d_matrixCopyFromMatrix(U3DMatrix_ptr dst, U3DMatrix_ptr src);
void u3d_matrixCopyFromRawData(U3DMatrix_ptr dst, number src_raw_data[16]);
void u3d_matrixCopyRowFromRawData(U3DMatrix_ptr dst, unsigned row, number src_raw_data[4]);
void u3d_matrixCopyRowFromVector(U3DMatrix_ptr dst, unsigned row, U3DVector_ptr src);
void u3d_matrixCopyRowToRawData(number dst_raw_data[4], unsigned row, U3DMatrix_ptr src);
void u3d_matrixCopyRowToVector(U3DVector_ptr dst, unsigned row, U3DMatrix_ptr src);
void u3d_matrixIdentity(U3DMatrix_ptr target);
void u3d_matrixMultiplication(U3DMatrix_ptr left, U3DMatrix_ptr right);
void u3d_matrixMultiplication2Matrix(U3DMatrix_ptr dst, U3DMatrix_ptr left, U3DMatrix_ptr right);
void u3d_matrixMultiplicationInRawData(number dst[16], number left_raw_data[16], number right_raw_data[16]);
void u3d_matrixTranspose(U3DMatrix_ptr target);
void u3d_matrixTranspose2Matrix(U3DMatrix_ptr dst, U3DMatrix_ptr src);
void u3d_matrixTransposeInRawData(number dst_raw_data[16], number src_raw_data[16]);


#endif

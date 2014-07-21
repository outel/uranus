#include "u3d_matrix.h"
#include "u3d_setup.h"

void u3d_matrixCopyColumnFromRawData(U3DMatrix_ptr dst, unsigned column, float src_raw_data[4]){
	dst->RC[0][column] = src_raw_data[0];
	dst->RC[1][column] = src_raw_data[1];
	dst->RC[2][column] = src_raw_data[2];
	dst->RC[3][column] = src_raw_data[3];
}

void u3d_matrixCopyColumnFromVector(U3DMatrix_ptr dst, unsigned column, U3DVector_ptr src){
	u3d_matrixCopyColumnFromRawData(dst, column, src->V);
}

void u3d_matrixCopyColumnToRawData(float dst_raw_data[4], unsigned column, U3DMatrix_ptr src){
	dst_raw_data[0] = src->RC[0][column];
	dst_raw_data[1] = src->RC[1][column];
	dst_raw_data[2] = src->RC[2][column];
	dst_raw_data[3] = src->RC[3][column];
}

void u3d_matrixCopyColumnToVector(U3DVector_ptr dst, unsigned column, U3DMatrix_ptr src){
	u3d_matrixCopyColumnToRawData(dst->V, column, src);
}

void u3d_matrixCopyFromMatrix(U3DMatrix_ptr dst, U3DMatrix_ptr src){
	u3d_matrixCopyFromRawData(dst, src->M);
}

void u3d_matrixCopyFromRawData(U3DMatrix_ptr dst, float src_raw_data[16]){
	dst->M[RC00] = src_raw_data[RC00];
	dst->M[RC01] = src_raw_data[RC01];
	dst->M[RC02] = src_raw_data[RC02];
	dst->M[RC03] = src_raw_data[RC03];
	dst->M[RC10] = src_raw_data[RC10];
	dst->M[RC11] = src_raw_data[RC11];
	dst->M[RC12] = src_raw_data[RC12];
	dst->M[RC13] = src_raw_data[RC13];
	dst->M[RC20] = src_raw_data[RC20];
	dst->M[RC21] = src_raw_data[RC21];
	dst->M[RC22] = src_raw_data[RC22];
	dst->M[RC23] = src_raw_data[RC23];
	dst->M[RC30] = src_raw_data[RC30];
	dst->M[RC31] = src_raw_data[RC31];
	dst->M[RC32] = src_raw_data[RC32];
	dst->M[RC33] = src_raw_data[RC33];
}

void u3d_matrixCopyRowFromRawData(U3DMatrix_ptr dst, unsigned row, float src_raw_data[4]){
	dst->RC[row][0] = src_raw_data[0];
	dst->RC[row][1] = src_raw_data[1];
	dst->RC[row][2] = src_raw_data[2];
	dst->RC[row][3] = src_raw_data[3];
}

void u3d_matrixCopyRowFromVector(U3DMatrix_ptr dst, unsigned row, U3DVector_ptr src){
	u3d_matrixCopyRowFromRawData(dst, row, src->V);
}

void u3d_matrixCopyRowToRawData(float dst_raw_data[4], unsigned row, U3DMatrix_ptr src){
	dst_raw_data[0] = src->RC[row][0];
	dst_raw_data[1] = src->RC[row][1];
	dst_raw_data[2] = src->RC[row][2];
	dst_raw_data[3] = src->RC[row][3];
}

void u3d_matrixCopyRowToVector(U3DVector_ptr dst, unsigned row, U3DMatrix_ptr src){
	u3d_matrixCopyRowToRawData(dst->V, row, src);
}

void u3d_matrixIdentity(U3DMatrix_ptr target){
	target->M00 = 1.0f;
	target->M11 = 1.0f;
	target->M22 = 1.0f;
	target->M33 = 1.0f;

	target->M01 = 0.0f;
	target->M10 = 0.0f;

	target->M02 = 0.0f;
	target->M20 = 0.0f;

	target->M03 = 0.0f;
	target->M30 = 0.0f;

	target->M12 = 0.0f;
	target->M21 = 0.0f;

	target->M13 = 0.0f;
	target->M31 = 0.0f;

	target->M23 = 0.0f;
	target->M32 = 0.0f;
}

void u3d_matrixMultiplication(U3DMatrix_ptr left, U3DMatrix_ptr right){
	U3DMatrix temp;
	u3d_matrixMultiplication2Matrix(&temp, left, right);
	u3d_matrixCopyFromMatrix(left, &temp);
}

void u3d_matrixMultiplication2Matrix(U3DMatrix_ptr dst, U3DMatrix_ptr left, U3DMatrix_ptr right){
	dst->M00 = left->M00 * right->M00 + left->M01 * right->M10 + left->M02 * right->M20 + left->M03 * right->M30;
	dst->M01 = left->M00 * right->M01 + left->M01 * right->M11 + left->M02 * right->M21 + left->M03 * right->M31;
	dst->M02 = left->M00 * right->M02 + left->M01 * right->M12 + left->M02 * right->M22 + left->M03 * right->M32;
	dst->M03 = left->M00 * right->M03 + left->M01 * right->M13 + left->M02 * right->M23 + left->M03 * right->M33;

	dst->M10 = left->M10 * right->M00 + left->M11 * right->M10 + left->M12 * right->M20 + left->M13 * right->M30;
	dst->M11 = left->M10 * right->M01 + left->M11 * right->M11 + left->M12 * right->M21 + left->M13 * right->M31;
	dst->M12 = left->M10 * right->M02 + left->M11 * right->M12 + left->M12 * right->M22 + left->M13 * right->M32;
	dst->M13 = left->M10 * right->M03 + left->M11 * right->M13 + left->M12 * right->M23 + left->M13 * right->M33;

	dst->M20 = left->M20 * right->M00 + left->M21 * right->M10 + left->M22 * right->M20 + left->M23 * right->M30;
	dst->M21 = left->M20 * right->M01 + left->M21 * right->M11 + left->M22 * right->M21 + left->M23 * right->M31;
	dst->M22 = left->M20 * right->M02 + left->M21 * right->M12 + left->M22 * right->M22 + left->M23 * right->M32;
	dst->M23 = left->M20 * right->M03 + left->M21 * right->M13 + left->M22 * right->M23 + left->M23 * right->M33;

	dst->M30 = left->M30 * right->M00 + left->M31 * right->M10 + left->M32 * right->M20 + left->M33 * right->M30;
	dst->M31 = left->M30 * right->M01 + left->M31 * right->M11 + left->M32 * right->M21 + left->M33 * right->M31;
	dst->M32 = left->M30 * right->M02 + left->M31 * right->M12 + left->M32 * right->M22 + left->M33 * right->M32;
	dst->M33 = left->M30 * right->M03 + left->M31 * right->M13 + left->M32 * right->M23 + left->M33 * right->M33;
}

void u3d_matrixMultiplicationInRawData(float dst_raw_data[16], float left_raw_data[16], float right_raw_data[16]){
	dst_raw_data[RC00] = left_raw_data[RC00] * right_raw_data[RC00] + left_raw_data[RC01] * right_raw_data[RC10] + left_raw_data[RC02] * right_raw_data[RC20] + left_raw_data[RC03] * right_raw_data[RC30];
	dst_raw_data[RC01] = left_raw_data[RC00] * right_raw_data[RC01] + left_raw_data[RC01] * right_raw_data[RC11] + left_raw_data[RC02] * right_raw_data[RC21] + left_raw_data[RC03] * right_raw_data[RC31];
	dst_raw_data[RC02] = left_raw_data[RC00] * right_raw_data[RC02] + left_raw_data[RC01] * right_raw_data[RC12] + left_raw_data[RC02] * right_raw_data[RC22] + left_raw_data[RC03] * right_raw_data[RC32];
	dst_raw_data[RC03] = left_raw_data[RC00] * right_raw_data[RC03] + left_raw_data[RC01] * right_raw_data[RC13] + left_raw_data[RC02] * right_raw_data[RC23] + left_raw_data[RC03] * right_raw_data[RC33];

	dst_raw_data[RC10] = left_raw_data[RC10] * right_raw_data[RC00] + left_raw_data[RC11] * right_raw_data[RC10] + left_raw_data[RC12] * right_raw_data[RC20] + left_raw_data[RC13] * right_raw_data[RC30];
	dst_raw_data[RC11] = left_raw_data[RC10] * right_raw_data[RC01] + left_raw_data[RC11] * right_raw_data[RC11] + left_raw_data[RC12] * right_raw_data[RC21] + left_raw_data[RC13] * right_raw_data[RC31];
	dst_raw_data[RC12] = left_raw_data[RC10] * right_raw_data[RC02] + left_raw_data[RC11] * right_raw_data[RC12] + left_raw_data[RC12] * right_raw_data[RC22] + left_raw_data[RC13] * right_raw_data[RC32];
	dst_raw_data[RC13] = left_raw_data[RC10] * right_raw_data[RC03] + left_raw_data[RC11] * right_raw_data[RC13] + left_raw_data[RC12] * right_raw_data[RC23] + left_raw_data[RC13] * right_raw_data[RC33];

	dst_raw_data[RC20] = left_raw_data[RC20] * right_raw_data[RC00] + left_raw_data[RC21] * right_raw_data[RC10] + left_raw_data[RC22] * right_raw_data[RC20] + left_raw_data[RC23] * right_raw_data[RC30];
	dst_raw_data[RC21] = left_raw_data[RC20] * right_raw_data[RC01] + left_raw_data[RC21] * right_raw_data[RC11] + left_raw_data[RC22] * right_raw_data[RC21] + left_raw_data[RC23] * right_raw_data[RC31];
	dst_raw_data[RC22] = left_raw_data[RC20] * right_raw_data[RC02] + left_raw_data[RC21] * right_raw_data[RC12] + left_raw_data[RC22] * right_raw_data[RC22] + left_raw_data[RC23] * right_raw_data[RC32];
	dst_raw_data[RC23] = left_raw_data[RC20] * right_raw_data[RC03] + left_raw_data[RC21] * right_raw_data[RC13] + left_raw_data[RC22] * right_raw_data[RC23] + left_raw_data[RC23] * right_raw_data[RC33];

	dst_raw_data[RC30] = left_raw_data[RC30] * right_raw_data[RC00] + left_raw_data[RC31] * right_raw_data[RC10] + left_raw_data[RC32] * right_raw_data[RC20] + left_raw_data[RC33] * right_raw_data[RC30];
	dst_raw_data[RC31] = left_raw_data[RC30] * right_raw_data[RC01] + left_raw_data[RC31] * right_raw_data[RC11] + left_raw_data[RC32] * right_raw_data[RC21] + left_raw_data[RC33] * right_raw_data[RC31];
	dst_raw_data[RC32] = left_raw_data[RC30] * right_raw_data[RC02] + left_raw_data[RC31] * right_raw_data[RC12] + left_raw_data[RC32] * right_raw_data[RC22] + left_raw_data[RC33] * right_raw_data[RC32];
	dst_raw_data[RC33] = left_raw_data[RC30] * right_raw_data[RC03] + left_raw_data[RC31] * right_raw_data[RC13] + left_raw_data[RC32] * right_raw_data[RC23] + left_raw_data[RC33] * right_raw_data[RC33];
}

void u3d_matrixTranspose(U3DMatrix_ptr target){
	U3DMatrix temp;
	u3d_matrixTranspose2Matrix(&temp, target);
	u3d_matrixCopyFromMatrix(target, &temp);
}

void u3d_matrixTranspose2Matrix(U3DMatrix_ptr dst, U3DMatrix_ptr src){
	dst->M00 = src->M00;
	dst->M11 = src->M11;
	dst->M22 = src->M22;
	dst->M33 = src->M33;

	dst->M01 = src->M10;
	dst->M10 = src->M01;

	dst->M02 = src->M20;
	dst->M20 = src->M02;

	dst->M03 = src->M30;
	dst->M30 = src->M03;

	dst->M12 = src->M21;
	dst->M21 = src->M12;

	dst->M13 = src->M31;
	dst->M31 = src->M13;

	dst->M23 = src->M32;
	dst->M32 = src->M23;
}

void u3d_matrixTransposeInRawData(float dst_raw_data[16], float src_raw_data[16]){
	dst_raw_data[RC00] = src_raw_data[RC00];
	dst_raw_data[RC11] = src_raw_data[RC11];
	dst_raw_data[RC22] = src_raw_data[RC22];
	dst_raw_data[RC33] = src_raw_data[RC33];

	dst_raw_data[RC01] = src_raw_data[RC10];
	dst_raw_data[RC10] = src_raw_data[RC01];

	dst_raw_data[RC02] = src_raw_data[RC20];
	dst_raw_data[RC20] = src_raw_data[RC02];

	dst_raw_data[RC03] = src_raw_data[RC30];
	dst_raw_data[RC30] = src_raw_data[RC03];

	dst_raw_data[RC12] = src_raw_data[RC21];
	dst_raw_data[RC21] = src_raw_data[RC12];

	dst_raw_data[RC13] = src_raw_data[RC31];
	dst_raw_data[RC31] = src_raw_data[RC13];

	dst_raw_data[RC23] = src_raw_data[RC32];
	dst_raw_data[RC32] = src_raw_data[RC23];
}

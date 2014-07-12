#include "u3d_matrix.h"

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
	dst->M[0] = src_raw_data[0];
	dst->M[1] = src_raw_data[1];
	dst->M[2] = src_raw_data[2];
	dst->M[3] = src_raw_data[3];
	dst->M[4] = src_raw_data[4];
	dst->M[5] = src_raw_data[5];
	dst->M[6] = src_raw_data[6];
	dst->M[7] = src_raw_data[7];
	dst->M[8] = src_raw_data[8];
	dst->M[9] = src_raw_data[9];
	dst->M[10] = src_raw_data[10];
	dst->M[11] = src_raw_data[11];
	dst->M[12] = src_raw_data[12];
	dst->M[13] = src_raw_data[13];
	dst->M[14] = src_raw_data[14];
	dst->M[15] = src_raw_data[15];
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
	target->M00 = 1.0;
	target->M11 = 1.0;
	target->M22 = 1.0;
	target->M33 = 1.0;

	target->M01 = 0.0;
	target->M10 = 0.0;

	target->M02 = 0.0;
	target->M20 = 0.0;

	target->M03 = 0.0;
	target->M30 = 0.0;

	target->M12 = 0.0;
	target->M21 = 0.0;

	target->M13 = 0.0;
	target->M31 = 0.0;

	target->M23 = 0.0;
	target->M32 = 0.0;
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
	dst_raw_data[0] = left_raw_data[0] * right_raw_data[0] + left_raw_data[1] * right_raw_data[4] + left_raw_data[2] * right_raw_data[8] + left_raw_data[3] * right_raw_data[12];
	dst_raw_data[1] = left_raw_data[0] * right_raw_data[1] + left_raw_data[1] * right_raw_data[5] + left_raw_data[2] * right_raw_data[9] + left_raw_data[3] * right_raw_data[13];
	dst_raw_data[2] = left_raw_data[0] * right_raw_data[2] + left_raw_data[1] * right_raw_data[6] + left_raw_data[2] * right_raw_data[10] + left_raw_data[3] * right_raw_data[14];
	dst_raw_data[3] = left_raw_data[0] * right_raw_data[3] + left_raw_data[1] * right_raw_data[7] + left_raw_data[2] * right_raw_data[11] + left_raw_data[3] * right_raw_data[15];

	dst_raw_data[4] = left_raw_data[4] * right_raw_data[0] + left_raw_data[5] * right_raw_data[4] + left_raw_data[6] * right_raw_data[8] + left_raw_data[7] * right_raw_data[12];
	dst_raw_data[5] = left_raw_data[4] * right_raw_data[1] + left_raw_data[5] * right_raw_data[5] + left_raw_data[6] * right_raw_data[9] + left_raw_data[7] * right_raw_data[13];
	dst_raw_data[6] = left_raw_data[4] * right_raw_data[2] + left_raw_data[5] * right_raw_data[6] + left_raw_data[6] * right_raw_data[10] + left_raw_data[7] * right_raw_data[14];
	dst_raw_data[7] = left_raw_data[4] * right_raw_data[3] + left_raw_data[5] * right_raw_data[7] + left_raw_data[6] * right_raw_data[11] + left_raw_data[7] * right_raw_data[15];

	dst_raw_data[8] = left_raw_data[8] * right_raw_data[0] + left_raw_data[9] * right_raw_data[4] + left_raw_data[10] * right_raw_data[8] + left_raw_data[11] * right_raw_data[12];
	dst_raw_data[9] = left_raw_data[8] * right_raw_data[1] + left_raw_data[9] * right_raw_data[5] + left_raw_data[10] * right_raw_data[9] + left_raw_data[11] * right_raw_data[13];
	dst_raw_data[10] = left_raw_data[8] * right_raw_data[2] + left_raw_data[9] * right_raw_data[6] + left_raw_data[10] * right_raw_data[10] + left_raw_data[11] * right_raw_data[14];
	dst_raw_data[11] = left_raw_data[8] * right_raw_data[3] + left_raw_data[9] * right_raw_data[7] + left_raw_data[10] * right_raw_data[11] + left_raw_data[11] * right_raw_data[15];

	dst_raw_data[12] = left_raw_data[12] * right_raw_data[0] + left_raw_data[13] * right_raw_data[4] + left_raw_data[14] * right_raw_data[8] + left_raw_data[15] * right_raw_data[12];
	dst_raw_data[13] = left_raw_data[12] * right_raw_data[1] + left_raw_data[13] * right_raw_data[5] + left_raw_data[14] * right_raw_data[9] + left_raw_data[15] * right_raw_data[13];
	dst_raw_data[14] = left_raw_data[12] * right_raw_data[2] + left_raw_data[13] * right_raw_data[6] + left_raw_data[14] * right_raw_data[10] + left_raw_data[15] * right_raw_data[14];
	dst_raw_data[15] = left_raw_data[12] * right_raw_data[3] + left_raw_data[13] * right_raw_data[7] + left_raw_data[14] * right_raw_data[11] + left_raw_data[15] * right_raw_data[15];
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
	dst_raw_data[0] = src_raw_data[0];
	dst_raw_data[5] = src_raw_data[5];
	dst_raw_data[10] = src_raw_data[10];
	dst_raw_data[15] = src_raw_data[15];

	dst_raw_data[1] = src_raw_data[4];
	dst_raw_data[4] = src_raw_data[1];

	dst_raw_data[2] = src_raw_data[8];
	dst_raw_data[8] = src_raw_data[2];

	dst_raw_data[3] = src_raw_data[12];
	dst_raw_data[12] = src_raw_data[3];

	dst_raw_data[6] = src_raw_data[9];
	dst_raw_data[9] = src_raw_data[6];

	dst_raw_data[7] = src_raw_data[13];
	dst_raw_data[13] = src_raw_data[7];

	dst_raw_data[11] = src_raw_data[14];
	dst_raw_data[14] = src_raw_data[11];
}

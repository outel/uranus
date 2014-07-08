


#include "u3d_matrix.h"

U3DMatrix_ptr u3d_matrixCopyColumnFromRawData(U3DMatrix_ptr dst, unsigned column, float raw_data[4]){
	dst->RC[0][column] = raw_data[0];
	dst->RC[1][column] = raw_data[1];
	dst->RC[2][column] = raw_data[2];
	dst->RC[3][column] = raw_data[3];
	return dst;
}

U3DMatrix_ptr u3d_matrixCopyColumnFromVector(U3DMatrix_ptr dst, unsigned column, U3DVector_ptr src){
	return u3d_matrixCopyColumnFromRawData(dst, column, src->V);
}

float* u3d_matrixCopyColumnToRawData(float raw_data[4], unsigned column, U3DMatrix_ptr src){
	raw_data[0] = src->RC[0][column];
	raw_data[1] = src->RC[1][column];
	raw_data[2] = src->RC[2][column];
	raw_data[3] = src->RC[3][column];
	return raw_data;
}

U3DVector_ptr u3d_matrixCopyColumnToVector(U3DVector_ptr dst, unsigned column, U3DMatrix_ptr src){
	u3d_matrixCopyColumnToRawData(dst->V, column, src);
	return dst;
}

U3DMatrix_ptr u3d_matrixCopyFromMatrix(U3DMatrix_ptr dst, U3DVector_ptr src){
	return u3d_matrixCopyFromRawData(dst, src->V);
}

U3DMatrix_ptr u3d_matrixCopyFromRawData(U3DMatrix_ptr dst, float raw_data[16]){
	//TODO
	//s3d_raw2raw16(dst.raw_data, raw_data);
	return dst;
}

U3DMatrix_ptr u3d_matrixCopyRowFromRawData(U3DMatrix_ptr dst, unsigned row, float raw_data[4]){
	dst->RC[row][0] = raw_data[0];
	dst->RC[row][1] = raw_data[1];
	dst->RC[row][2] = raw_data[2];
	dst->RC[row][3] = raw_data[3];
	return dst;
}

U3DMatrix_ptr u3d_matrixCopyRowFromVector(U3DMatrix_ptr dst, unsigned row, U3DVector_ptr src){
	return u3d_matrixCopyRowFromRawData(dst, row, src->V);
}

float* u3d_matrixCopyRowToRawData(float raw_data[4], unsigned row, U3DMatrix_ptr src){
	raw_data[0] = src->RC[row][0];
	raw_data[1] = src->RC[row][1];
	raw_data[2] = src->RC[row][2];
	raw_data[3] = src->RC[row][3];
	return raw_data;
}

U3DVector_ptr u3d_matrixCopyRowToVector(U3DVector_ptr dst, unsigned row, U3DMatrix_ptr src){
	u3d_matrixCopyRowToRawData(dst->V, row, src);
	return dst;
}

U3DMatrix_ptr u3d_matrixIdentity(U3DMatrix_ptr target){
	//TODO
	//s3d_matrixCopyFromRawData(target, S3DConst.IDENTITY_MATRIX_RAW_DATA);
	return target;
}

U3DMatrix_ptr u3d_matrixMultiplication(U3DMatrix_ptr left, U3DMatrix_ptr right){
	//TODO
	//return u3d_matrixCopyFromRawData(left, u3d_matrixMultiplicationInRawData(S3DUtils.Vector4NumberX(16), left->M, right->M));
	return 0;
}

U3DMatrix_ptr u3d_matrixMultiplication2Matrix(U3DMatrix_ptr dst, U3DMatrix_ptr left, U3DMatrix_ptr right){
	u3d_matrixMultiplicationInRawData(dst->M, left->M, right->M);
	return dst;
}

float* u3d_matrixMultiplicationInRawData(float dst[16], float left_raw_data[16], float right_raw_data[16]){
	dst[0] = left_raw_data[0] * right_raw_data[0] + left_raw_data[1] * right_raw_data[4] + left_raw_data[2] * right_raw_data[8] + left_raw_data[3] * right_raw_data[12];
	dst[1] = left_raw_data[0] * right_raw_data[1] + left_raw_data[1] * right_raw_data[5] + left_raw_data[2] * right_raw_data[9] + left_raw_data[3] * right_raw_data[13];
	dst[2] = left_raw_data[0] * right_raw_data[2] + left_raw_data[1] * right_raw_data[6] + left_raw_data[2] * right_raw_data[10] + left_raw_data[3] * right_raw_data[14];
	dst[3] = left_raw_data[0] * right_raw_data[3] + left_raw_data[1] * right_raw_data[7] + left_raw_data[2] * right_raw_data[11] + left_raw_data[3] * right_raw_data[15];
	
	dst[4] = left_raw_data[4] * right_raw_data[0] + left_raw_data[5] * right_raw_data[4] + left_raw_data[6] * right_raw_data[8] + left_raw_data[7] * right_raw_data[12];
	dst[5] = left_raw_data[4] * right_raw_data[1] + left_raw_data[5] * right_raw_data[5] + left_raw_data[6] * right_raw_data[9] + left_raw_data[7] * right_raw_data[13];
	dst[6] = left_raw_data[4] * right_raw_data[2] + left_raw_data[5] * right_raw_data[6] + left_raw_data[6] * right_raw_data[10] + left_raw_data[7] * right_raw_data[14];
	dst[7] = left_raw_data[4] * right_raw_data[3] + left_raw_data[5] * right_raw_data[7] + left_raw_data[6] * right_raw_data[11] + left_raw_data[7] * right_raw_data[15];
	
	dst[8] = left_raw_data[8] * right_raw_data[0] + left_raw_data[9] * right_raw_data[4] + left_raw_data[10] * right_raw_data[8] + left_raw_data[11] * right_raw_data[12];
	dst[9] = left_raw_data[8] * right_raw_data[1] + left_raw_data[9] * right_raw_data[5] + left_raw_data[10] * right_raw_data[9] + left_raw_data[11] * right_raw_data[13];
	dst[10] = left_raw_data[8] * right_raw_data[2] + left_raw_data[9] * right_raw_data[6] + left_raw_data[10] * right_raw_data[10] + left_raw_data[11] * right_raw_data[14];
	dst[11] = left_raw_data[8] * right_raw_data[3] + left_raw_data[9] * right_raw_data[7] + left_raw_data[10] * right_raw_data[11] + left_raw_data[11] * right_raw_data[15];
	
	dst[12] = left_raw_data[12] * right_raw_data[0] + left_raw_data[13] * right_raw_data[4] + left_raw_data[14] * right_raw_data[8] + left_raw_data[15] * right_raw_data[12];
	dst[13] = left_raw_data[12] * right_raw_data[1] + left_raw_data[13] * right_raw_data[5] + left_raw_data[14] * right_raw_data[9] + left_raw_data[15] * right_raw_data[13];
	dst[14] = left_raw_data[12] * right_raw_data[2] + left_raw_data[13] * right_raw_data[6] + left_raw_data[14] * right_raw_data[10] + left_raw_data[15] * right_raw_data[14];
	dst[15] = left_raw_data[12] * right_raw_data[3] + left_raw_data[13] * right_raw_data[7] + left_raw_data[14] * right_raw_data[11] + left_raw_data[15] * right_raw_data[15];
	
	return dst;
}

U3DMatrix_ptr u3d_matrixTranspose(U3DMatrix_ptr target){
	//TODO
	///return u3d_matrixCopyFromRawData(target, s3d_matrixTransposeInRawData(S3DUtils.Vector4NumberX(16), target.raw_data);
	return 0;
}

U3DMatrix_ptr u3d_matrixTranspose2Matrix(U3DMatrix_ptr dst, U3DMatrix_ptr src){
	u3d_matrixTransposeInRawData(dst->M, src->M);		
	return dst;
}

float* u3d_matrixTransposeInRawData(float dst_raw_data[16], float src_raw_data[16]){
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
		
		return dst_raw_data;
}




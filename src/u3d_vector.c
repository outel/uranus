#include <math.h>

#include "u3d_vector.h"

void u3d_vectorAddition(U3DVector_ptr left, U3DVector_ptr right){
	left->x += right->x;
	left->y += right->y;
	left->z += right->z;
}

void u3d_vectorAddition2Vector(U3DVector_ptr dst, U3DVector_ptr left, U3DVector_ptr right){
	dst->x = left->x + right->x;
	dst->y = left->y + right->y;
	dst->z = left->z + right->z;
	dst->w = 0.0;
}

void u3d_vectorCopyFromRawData(U3DVector_ptr dst, float src_raw_data[4]){
	dst->V[0] = src_raw_data[0];
	dst->V[1] = src_raw_data[1];
	dst->V[2] = src_raw_data[2];
	dst->V[3] = src_raw_data[3];
}

void u3d_vectorCopyFromVector(U3DVector_ptr dst, U3DVector_ptr src){
	u3d_vectorCopyFromRawData(dst, src->V);
}

void u3d_vectorCrossProduct(U3DVector_ptr left, U3DVector_ptr right){
	float x = left->y * right->z - left->z * right->y;
	float y = left->z * right->x - left->x * right->z;
	float z = left->x * right->y - left->y * right->x;
	left->x = x;
	left->y = y;
	left->z = z;
	left->w = 0.0;
}

void u3d_vectorCrossProduct2Vector(U3DVector_ptr dst, U3DVector_ptr left, U3DVector_ptr right){
	dst->x = left->y * right->z - left->z * right->y;
	dst->y = left->z * right->x - left->x * right->z;
	dst->z = left->x * right->y - left->y * right->x;
	dst->w = 0.0;
}

float u3d_vectorDotProduct(U3DVector_ptr left, U3DVector_ptr right){
	return left->x * right->x + left->y * right->y + left->z * right->z;
}

float u3d_vectorLength(U3DVector_ptr target){
	return sqrt(target->x * target->x + target->y * target->y + target->z * target->z);
}

void u3d_vectorNormalize(U3DVector_ptr target){
	float len = u3d_vectorLength(target);
	target->x /= len;
	target->y /= len;
	target->z /= len;
}

void u3d_vectorNormalize2Vector(U3DVector_ptr dst, U3DVector_ptr target){
	float len = u3d_vectorLength(target);
	dst->x = target->x / len;
	dst->y = target->y / len;
	dst->z = target->z / len;
	dst->w = 0.0;
}

void u3d_vectorSubtraction(U3DVector_ptr left, U3DVector_ptr right){
	left->x -= right->x;
	left->y -= right->y;
	left->z -= right->z;
	left->w = 0.0;
}

void u3d_vectorSubtraction2Vector(U3DVector_ptr dst, U3DVector_ptr left, U3DVector_ptr right){
	dst->x = left->x - right->x;
	dst->y = left->y - right->y;
	dst->z = left->z - right->z;
	dst->w = 0.0;
}

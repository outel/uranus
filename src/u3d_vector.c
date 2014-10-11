#include <math.h>
#include <stdlib.h>

#include "u3d_vector.h"


U3DVector_ptr u3d_vectorCreate(){
	return (U3DVector_ptr) malloc(sizeof(U3DVector));
}

U3DVector_ptr u3d_vectorConstructDefault(U3DVector_ptr target){
	target->x = 0.0f;
	target->y = 0.0f;
	target->z = 0.0f;
	target->w = 0.0f;

	return target;
}

U3DVector_ptr u3d_vectorConstruct(U3DVector_ptr target, float x, float y, float z){
	target->x = x;
	target->y = y;
	target->z = z;
	target->w = 0.0f;

	return target;
}

U3DVector_ptr u3d_vectorDestruct(U3DVector_ptr target){
	return target;
}

void u3d_vectorDelete(U3DVector_ptr target){
	free(target);
}


U3DPoint_ptr u3d_pointCreate(){
	return (U3DPoint_ptr) malloc(sizeof(U3DPoint));
}

U3DPoint_ptr u3d_pointConstructDefault(U3DPoint_ptr target){
	target->x = 0.0f;
	target->y = 0.0f;
	target->z = 0.0f;
	target->w = 1.0f;
	
	return target;
}

U3DPoint_ptr u3d_pointConstruct(U3DPoint_ptr target, float x, float y, float z){
	target->x = x;
	target->y = y;
	target->z = z;
	target->w = 1.0f;
	
	return target;
}

U3DPoint_ptr u3d_pointDestruct(U3DPoint_ptr target){
	return target;
}

void u3d_pointDelete(U3DPoint_ptr target){
	free(target);
}

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

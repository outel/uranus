#include <math.h>

#include "u3d_vector.h"

U3DVector_ptr u3d_vectorAddition(U3DVector_ptr left, U3DVector_ptr right){
	left->V[0] += right->V[0];
	left->V[1] += right->V[1];
	left->V[2] += right->V[2];
	return left;
}

U3DVector_ptr u3d_vectorAddition2Vector(U3DVector_ptr dst, U3DVector_ptr left, U3DVector_ptr right){
	dst->V[0] = left->V[0] + right->V[0];
	dst->V[1] = left->V[1] + right->V[1];
	dst->V[2] = left->V[2] + right->V[2];
	return dst;
}

U3DVector_ptr u3d_vectorCopyFromRawData(U3DVector_ptr dst, float raw_data[4]){
	//TODO
	//s3d_raw2raw4(dst.raw_data, raw_data);
	return dst;
}

U3DVector_ptr u3d_vectorCopyFromVector(U3DVector_ptr dst, U3DVector_ptr src){
	return u3d_vectorCopyFromRawData(dst, src->V);
}

U3DVector_ptr u3d_vectorCrossProduct(U3DVector_ptr left, U3DVector_ptr right){
	float temp[4] = {0};
	temp[0] = left->V[1] * right->V[2] - left->V[2] * right->V[1];
	temp[1] = left->V[2] * right->V[0] - left->V[0] * right->V[2];
	temp[2] = left->V[0] * right->V[1] - left->V[1] * right->V[0];
	return u3d_vectorCopyFromRawData(left, temp);
}

U3DVector_ptr u3d_vectorCrossProduct2Vector(U3DVector_ptr dst, U3DVector_ptr left, U3DVector_ptr right){
	dst->V[0] = left->V[1] * right->V[2] - left->V[2] * right->V[1];
	dst->V[1] = left->V[2] * right->V[0] - left->V[0] * right->V[2];
	dst->V[2] = left->V[0] * right->V[1] - left->V[1] * right->V[0];
	return dst;
}

float u3d_vectorDotProduct(U3DVector_ptr left, U3DVector_ptr right){
	return left->V[0] * right->V[0] + left->V[1] * right->V[1] + left->V[2] * right->V[2];
}

float u3d_vectorLength(U3DVector_ptr target){
	return sqrt(target->x * target->x + target->y * target->y + target->z * target->z);
}

U3DVector_ptr u3d_vectorNormalize(U3DVector_ptr target){
	float len = u3d_vectorLength(target);
	target->V[0] /= len;
	target->V[1] /= len;
	target->V[2] /= len;
	return target;
}

U3DVector_ptr u3d_vectorNormalize2Vector(U3DVector_ptr dst, U3DVector_ptr target){
	float len = u3d_vectorLength(target);
	dst->V[0] = target->V[0] / len;
	dst->V[1] = target->V[1] / len;
	dst->V[2] = target->V[2] / len;
	return dst;
}

U3DVector_ptr u3d_vectorSubtraction(U3DVector_ptr left, U3DVector_ptr right){
	left->V[0] -= right->V[0];
	left->V[1] -= right->V[1];
	left->V[2] -= right->V[2];
	return left;
}

U3DVector_ptr u3d_vectorSubtraction2Vector(U3DVector_ptr dst, U3DVector_ptr left, U3DVector_ptr right){
	dst->V[0] = left->V[0] - right->V[0];
	dst->V[1] = left->V[1] - right->V[1];
	dst->V[2] = left->V[2] - right->V[2];
	return dst;
}

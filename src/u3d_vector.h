#ifndef U3D_VECTOR_H
#define U3D_VECTOR_H

typedef struct _U3DVector {
	union{
		float V[4];
		struct{
			float x, y, z, w;
		};
	};
} U3DVector, *U3DVector_ptr, U3DPoint, *U3DPoint_ptr;

U3DVector_ptr u3d_vectorAddition(U3DVector_ptr left, U3DVector_ptr right);
U3DVector_ptr u3d_vectorAddition2Vector(U3DVector_ptr dst, U3DVector_ptr left, U3DVector_ptr right);
U3DVector_ptr u3d_vectorCopyFromRawData(U3DVector_ptr dst, float raw_data[4]);
U3DVector_ptr u3d_vectorCopyFromVector(U3DVector_ptr dst, U3DVector_ptr src);
U3DVector_ptr u3d_vectorCrossProduct(U3DVector_ptr left, U3DVector_ptr right);
U3DVector_ptr u3d_vectorCrossProduct2Vector(U3DVector_ptr dst, U3DVector_ptr left, U3DVector_ptr right);
float u3d_vectorDotProduct(U3DVector_ptr left, U3DVector_ptr right);
float u3d_vectorLength(U3DVector_ptr target);
U3DVector_ptr u3d_vectorNormalize(U3DVector_ptr target);
U3DVector_ptr u3d_vectorNormalize2Vector(U3DVector_ptr dst, U3DVector_ptr target);
U3DVector_ptr u3d_vectorSubtraction(U3DVector_ptr left, U3DVector_ptr right);
U3DVector_ptr u3d_vectorSubtraction2Vector(U3DVector_ptr dst, U3DVector_ptr left, U3DVector_ptr right);


#endif

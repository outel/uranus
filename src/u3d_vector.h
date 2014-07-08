#ifndef U3D_VECTOR_H
#define U3D_VECTOR_H

typedef struct _U3DVector{
	union{
		float V[4];
		struct{
			float x, y, z, w;
		};
	};
} U3DVector, *U3DVector_ptr;

float u3d_vectorLength(U3DVector_ptr target);
U3DVector_ptr s3d_vectorNormalize(U3DVector_ptr target);


#endif

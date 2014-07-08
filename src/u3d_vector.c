#include <math.h>

#include "u3d_vector.h"

float u3d_vectorLength(U3DVector_ptr target){
	return sqrt(target->x * target->x + target->y * target->y + target->z * target->z);
}


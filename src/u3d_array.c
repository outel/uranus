#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#include "u3d_array.h"


U3DArrayf_ptr u3d_arrayfCreate(){
	return (U3DArrayf_ptr) malloc(sizeof(U3DArrayf));
}

U3DArrayf_ptr u3d_arrayfConstructDefault(U3DArrayf_ptr target){
	target->raw_data = NULL;
	target->lenght = 0;

	return target;
}

U3DArrayf_ptr u3d_arrayfConstruct(U3DArrayf_ptr target, float *src_raw_data, unsigned raw_data_lenght){
	target->raw_data = (float *) malloc(sizeof(float) * raw_data_lenght);
	memcpy(target->raw_data, src_raw_data, sizeof(float) * raw_data_lenght);
	target->lenght = raw_data_lenght;

	return target;
}

U3DArrayf_ptr u3d_arrayfConstructLenght(U3DArrayf_ptr target, unsigned lenght){
	target->raw_data = (float *) malloc(sizeof(float) * lenght);
	target->lenght = lenght;

	return target;
}

U3DArrayf_ptr u3d_arrayfDestruct(U3DArrayf_ptr target){
	free(target->raw_data);
	target->raw_data = NULL;
	target->lenght = 0;

	return target;
}

void u3d_arrayfDelete(U3DArrayf_ptr target){
	free(target);
}

U3DArrayu_ptr u3d_arrayuCreate(){
	return (U3DArrayu_ptr) malloc(sizeof(U3DArrayu));
}

U3DArrayu_ptr u3d_arrayuConstructDefault(U3DArrayu_ptr target){
	target->raw_data = NULL;
	target->lenght = 0;

	return target;
}

U3DArrayu_ptr u3d_arrayuConstruct(U3DArrayu_ptr target, unsigned *src_raw_data, unsigned raw_data_lenght){
	unsigned i;
	target->raw_data = (unsigned *) malloc(sizeof(unsigned) * raw_data_lenght);
	memcpy(target->raw_data, src_raw_data, sizeof(unsigned) * raw_data_lenght);
	target->lenght = raw_data_lenght;

	for (i = 0; i < raw_data_lenght; ++i){
		printf("%d\n", target->raw_data[i]);
	}

	return target;
}

U3DArrayu_ptr u3d_arrayuConstructLenght(U3DArrayu_ptr target, unsigned lenght){
	target->raw_data = (unsigned *) malloc(sizeof(unsigned) * lenght);
	target->lenght = lenght;

	return target;
}

U3DArrayu_ptr u3d_arrayuDestruct(U3DArrayu_ptr target){
	free(target->raw_data);
	target->raw_data = NULL;
	target->lenght = 0;

	return target;
}

void u3d_arrayuDelete(U3DArrayu_ptr target){
	free(target);
}

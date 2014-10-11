#ifndef U3D_ARRAY_H
#define U3D_ARRAY_H


typedef struct _U3DArrayf {
	float		*raw_data;
	unsigned	lenght;
} U3DArrayf, *U3DArrayf_ptr;

typedef struct _U3DArrayu {
	unsigned	*raw_data;
	unsigned	lenght;
} U3DArrayu, *U3DArrayu_ptr;

U3DArrayf_ptr	u3d_arrayfCreate();
U3DArrayf_ptr	u3d_arrayfConstructDefault(U3DArrayf_ptr target);
U3DArrayf_ptr	u3d_arrayfConstruct(U3DArrayf_ptr target, float *src_raw_data, unsigned raw_data_lenght);
U3DArrayf_ptr	u3d_arrayfConstructLenght(U3DArrayf_ptr target, unsigned lenght);
U3DArrayf_ptr	u3d_arrayfDestruct(U3DArrayf_ptr target);
void			u3d_arrayfDelete(U3DArrayf_ptr target);


U3DArrayu_ptr	u3d_arrayuCreate();
U3DArrayu_ptr	u3d_arrayuConstructDefault(U3DArrayu_ptr target);
U3DArrayu_ptr	u3d_arrayuConstruct(U3DArrayu_ptr target, unsigned *src_raw_data, unsigned raw_data_lenght);
U3DArrayu_ptr	u3d_arrayuConstructLenght(U3DArrayu_ptr target, unsigned lenght);
U3DArrayu_ptr	u3d_arrayuDestruct(U3DArrayu_ptr target);
void			u3d_arrayuDelete(U3DArrayu_ptr target);


#endif

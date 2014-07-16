#ifndef U3D_UTILS_H
#define U3D_UTILS_H

#include "u3d_setup.h"

void u3d_utilsBatchMatrixMultiplication(number *dst_vertex_raw_data, number * src_vertex_raw_data, unsigned src_vertex_len, number * matrix_raw_data, unsigned vertex_wide);
void u3d_utilsPerspectiveDivision(number * target, unsigned target_len, unsigned vertex_wide);


#endif

#ifndef U3D_UTILS_H
#define U3D_UTILS_H


void u3d_utilsBatchMatrixMultiplication(float *dst_vertex_raw_data, float * src_vertex_raw_data, unsigned src_vertex_len, float * matrix_raw_data, unsigned vertex_wide);
void u3d_utilsPerspectiveDivision(float * target, unsigned target_len, unsigned vertex_wide);


#endif

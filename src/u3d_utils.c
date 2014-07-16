#include <stdlib.h>

#include "u3d_new.h"
#include "u3d_utils.h"

void u3d_utilsBatchMatrixMultiplication(number *dst_vertex_raw_data, number *src_vertex_raw_data, unsigned src_vertex_len, number * matrix_raw_data, unsigned vertex_wide){
	unsigned step = vertex_wide * 4;

	unsigned row00, row01, row02, row03;
	unsigned row10, row11, row12, row13;
	unsigned row20, row21, row22, row23;
	unsigned row30, row31, row32, row33;

	number dst[16];
	unsigned i;
	for (i = 0; i < src_vertex_len; i += step) {
		row00 = i + 0 * vertex_wide + 0;
		row01 = i + 0 * vertex_wide + 1;
		row02 = i + 0 * vertex_wide + 2;
		row03 = i + 0 * vertex_wide + 3;
		
		row10 = i + 1 * vertex_wide + 0;
		row11 = i + 1 * vertex_wide + 1;
		row12 = i + 1 * vertex_wide + 2;
		row13 = i + 1 * vertex_wide + 3;
		
		row20 = i + 2 * vertex_wide + 0;
		row21 = i + 2 * vertex_wide + 1;
		row22 = i + 2 * vertex_wide + 2;
		row23 = i + 2 * vertex_wide + 3;
		
		row30 = i + 3 * vertex_wide + 0;
		row31 = i + 3 * vertex_wide + 1;
		row32 = i + 3 * vertex_wide + 2;
		row33 = i + 3 * vertex_wide + 3;
		
		
		dst[0] = src_vertex_raw_data[row00] * matrix_raw_data[0] + src_vertex_raw_data[row01] * matrix_raw_data[4] + src_vertex_raw_data[row02] * matrix_raw_data[8] + src_vertex_raw_data[row03] * matrix_raw_data[12];
		dst[1] = src_vertex_raw_data[row00] * matrix_raw_data[1] + src_vertex_raw_data[row01] * matrix_raw_data[5] + src_vertex_raw_data[row02] * matrix_raw_data[9] + src_vertex_raw_data[row03] * matrix_raw_data[13];
		dst[2] = src_vertex_raw_data[row00] * matrix_raw_data[2] + src_vertex_raw_data[row01] * matrix_raw_data[6] + src_vertex_raw_data[row02] * matrix_raw_data[10] + src_vertex_raw_data[row03] * matrix_raw_data[14];
		dst[3] = src_vertex_raw_data[row00] * matrix_raw_data[3] + src_vertex_raw_data[row01] * matrix_raw_data[7] + src_vertex_raw_data[row02] * matrix_raw_data[11] + src_vertex_raw_data[row03] * matrix_raw_data[15];
		
		dst[4] = src_vertex_raw_data[row10] * matrix_raw_data[0] + src_vertex_raw_data[row11] * matrix_raw_data[4] + src_vertex_raw_data[row12] * matrix_raw_data[8] + src_vertex_raw_data[row13] * matrix_raw_data[12];
		dst[5] = src_vertex_raw_data[row10] * matrix_raw_data[1] + src_vertex_raw_data[row11] * matrix_raw_data[5] + src_vertex_raw_data[row12] * matrix_raw_data[9] + src_vertex_raw_data[row13] * matrix_raw_data[13];
		dst[6] = src_vertex_raw_data[row10] * matrix_raw_data[2] + src_vertex_raw_data[row11] * matrix_raw_data[6] + src_vertex_raw_data[row12] * matrix_raw_data[10] + src_vertex_raw_data[row13] * matrix_raw_data[14];
		dst[7] = src_vertex_raw_data[row10] * matrix_raw_data[3] + src_vertex_raw_data[row11] * matrix_raw_data[7] + src_vertex_raw_data[row12] * matrix_raw_data[11] + src_vertex_raw_data[row13] * matrix_raw_data[15];
		
		dst[8] = src_vertex_raw_data[row20] * matrix_raw_data[0] + src_vertex_raw_data[row21] * matrix_raw_data[4] + src_vertex_raw_data[row22] * matrix_raw_data[8] + src_vertex_raw_data[row23] * matrix_raw_data[12];
		dst[9] = src_vertex_raw_data[row20] * matrix_raw_data[1] + src_vertex_raw_data[row21] * matrix_raw_data[5] + src_vertex_raw_data[row22] * matrix_raw_data[9] + src_vertex_raw_data[row23] * matrix_raw_data[13];
		dst[10] = src_vertex_raw_data[row20] * matrix_raw_data[2] + src_vertex_raw_data[row21] * matrix_raw_data[6] + src_vertex_raw_data[row22] * matrix_raw_data[10] + src_vertex_raw_data[row23] * matrix_raw_data[14];
		dst[11] = src_vertex_raw_data[row20] * matrix_raw_data[3] + src_vertex_raw_data[row21] * matrix_raw_data[7] + src_vertex_raw_data[row22] * matrix_raw_data[11] + src_vertex_raw_data[row23] * matrix_raw_data[15];
		
		dst[12] = src_vertex_raw_data[row30] * matrix_raw_data[0] + src_vertex_raw_data[row31] * matrix_raw_data[4] + src_vertex_raw_data[row32] * matrix_raw_data[8] + src_vertex_raw_data[row33] * matrix_raw_data[12];
		dst[13] = src_vertex_raw_data[row30] * matrix_raw_data[1] + src_vertex_raw_data[row31] * matrix_raw_data[5] + src_vertex_raw_data[row32] * matrix_raw_data[9] + src_vertex_raw_data[row33] * matrix_raw_data[13];
		dst[14] = src_vertex_raw_data[row30] * matrix_raw_data[2] + src_vertex_raw_data[row31] * matrix_raw_data[6] + src_vertex_raw_data[row32] * matrix_raw_data[10] + src_vertex_raw_data[row33] * matrix_raw_data[14];
		dst[15] = src_vertex_raw_data[row30] * matrix_raw_data[3] + src_vertex_raw_data[row31] * matrix_raw_data[7] + src_vertex_raw_data[row32] * matrix_raw_data[11] + src_vertex_raw_data[row33] * matrix_raw_data[15];
		
		dst_vertex_raw_data[row00] = dst[0];
		dst_vertex_raw_data[row01] = dst[1];
		dst_vertex_raw_data[row02] = dst[2];
		dst_vertex_raw_data[row03] = dst[3];
		
		dst_vertex_raw_data[row10] = dst[4];
		dst_vertex_raw_data[row11] = dst[5];
		dst_vertex_raw_data[row12] = dst[6];
		dst_vertex_raw_data[row13] = dst[7];
		
		dst_vertex_raw_data[row20] = dst[8];
		dst_vertex_raw_data[row21] = dst[9];
		dst_vertex_raw_data[row22] = dst[10];
		dst_vertex_raw_data[row23] = dst[11];
		
		dst_vertex_raw_data[row30] = dst[12];
		dst_vertex_raw_data[row31] = dst[13];
		dst_vertex_raw_data[row32] = dst[14];
		dst_vertex_raw_data[row33] = dst[15];
	}
}

void u3d_utilsPerspectiveDivision(number * target, unsigned target_len, unsigned vertex_wide){
	unsigned i;
	for (i = 0; i < target_len; i += vertex_wide) {
		target[i + 0] /= target[i + 3];
		target[i + 1] /= target[i + 3];
		target[i + 2] /= target[i + 3];
		target[i + 3] /= target[i + 3];
	}
}



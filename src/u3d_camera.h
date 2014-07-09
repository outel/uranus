#ifndef U3D_CAMERA_H
#define U3D_CAMERA_H

#include "u3d_vector.h"
#include "u3d_matrix.h"


typedef struct _U3DCamera {
	U3DPoint_ptr point_at;
	U3DPoint_ptr point_to;
	U3DVector_ptr up_vector;

	float fovx_deg;
	float near;
	float far;
	float view_port_width;
	float view_port_height;
	float aspect_ratio;
	float tx;
	float ty;
	float tz;
	float rx_deg;
	float ry_deg;
	float rz_deg;

	U3DMatrix_ptr camera_matrix;
	unsigned camera_matrix_invalid;
		
	U3DMatrix_ptr projection_matrix;
	unsigned projection_matrix_invalid;
		
	U3DMatrix_ptr screen_matrix;
	unsigned screen_matrix_invalid;
} U3DCamera, *U3DCamera_ptr;

U3DMatrix_ptr u3d_cameraExportMatrix4Camera(U3DCamera_ptr camera);
U3DMatrix_ptr u3d_cameraExportMatrix4Projection(U3DCamera_ptr camera);
U3DMatrix_ptr u3d_cameraExportMatrix4Screen(U3DCamera_ptr camera);
void u3d_cameraResetViewPort(U3DCamera_ptr camera, float view_port_width, float view_port_height);
void u3d_cameraRotation(U3DCamera_ptr camera, float rx_deg, float ry_deg, float rz_deg);
void u3d_cameraTranslation(U3DCamera_ptr camera, float tx, float ty, float tz);


#endif

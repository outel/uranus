#ifndef U3D_CAMERA_H
#define U3D_CAMERA_H

#include "u3d_vector.h"
#include "u3d_matrix.h"
#include "u3d_setup.h"



typedef struct _U3DCamera {
	U3DPoint	point_at;
	U3DPoint	point_to;
	U3DVector	up_vector;

	number		fovx_deg;
	number		near_clip_plane;
	number		far_clip_plane;
	number		view_port_width;
	number		view_port_height;
	number		aspect_ratio;
	number		tx;
	number		ty;
	number		tz;
	number		rx_deg;
	number		ry_deg;
	number		rz_deg;

	U3DMatrix	camera_matrix;
	unsigned	camera_matrix_invalid;
		
	U3DMatrix	projection_matrix;
	unsigned	projection_matrix_invalid;
		
	U3DMatrix	screen_matrix;
	unsigned	screen_matrix_invalid;
} U3DCamera, *U3DCamera_ptr;

void u3d_cameraExportMatrix4Camera(U3DCamera_ptr camera);
void u3d_cameraExportMatrix4Projection(U3DCamera_ptr camera);
void u3d_cameraExportMatrix4Screen(U3DCamera_ptr camera);
void u3d_cameraResetViewPort(U3DCamera_ptr camera, number view_port_width, number view_port_height);
void u3d_cameraRotation(U3DCamera_ptr camera, number rx_deg, number ry_deg, number rz_deg);
void u3d_cameraTranslation(U3DCamera_ptr camera, number tx, number ty, number tz);

#endif

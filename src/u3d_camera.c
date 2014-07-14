
#include "u3d_camera.h"
#include "u3d_make.h"



void u3d_cameraExportMatrix4Camera(U3DCamera_ptr camera){
	if(0 < camera->camera_matrix_invalid){
		U3DMatrix temp;
		u3d_makeMatrix4UVN(&camera->camera_matrix, &camera->point_at, &camera->point_to, &camera->up_vector);
		
		u3d_makeMatrix4Translation(&temp, camera->tx, camera->ty, camera->tz);
		u3d_matrixMultiplication(&camera->camera_matrix, &temp);

		u3d_makeMatrix4Rotation(&temp, camera->rx_deg, camera->ry_deg, camera->rz_deg);
		u3d_matrixMultiplication(&camera->camera_matrix, &temp);
		
		camera->camera_matrix_invalid = 0;
	}
}

void u3d_cameraExportMatrix4Projection(U3DCamera_ptr camera){
	if(0 < camera->projection_matrix_invalid){
		u3d_makeMatrix4Projection(&camera->projection_matrix, camera->fovx_deg, camera->aspect_ratio, camera->near_clip_plane, camera->far_clip_plane);
		
		camera->projection_matrix_invalid = 0;
	}
}

void u3d_cameraExportMatrix4Screen(U3DCamera_ptr camera){
	if(0 < camera->screen_matrix_invalid){
		u3d_makeMatrix4Screen(&camera->screen_matrix, camera->view_port_width, camera->view_port_height);
		
		camera->screen_matrix_invalid = 0;
	}
}

void u3d_cameraResetViewPort(U3DCamera_ptr camera, float view_port_width, float view_port_height){
	camera->view_port_width = view_port_width;
	camera->view_port_height = view_port_height;
	camera->aspect_ratio = view_port_width / view_port_height;
	
	camera->projection_matrix_invalid = camera->screen_matrix_invalid = 1;
}

void u3d_cameraRotation(U3DCamera_ptr camera, float rx_deg, float ry_deg, float rz_deg){
	camera->rx_deg = -rx_deg;
	camera->ry_deg = -ry_deg;
	camera->rz_deg = -rz_deg;
	
	camera->camera_matrix_invalid = 1;
}

void u3d_cameraTranslation(U3DCamera_ptr camera, float tx, float ty, float tz){
	camera->tx = -tx;
	camera->ty = -ty;
	camera->tz = -tz;
	
	camera->camera_matrix_invalid = 1;
}









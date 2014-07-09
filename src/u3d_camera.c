
#include "u3d_camera.h"
#include "u3d_new.h"


U3DMatrix_ptr u3d_cameraExportMatrix4Camera(U3DCamera_ptr camera){
	if(0 < camera->camera_matrix_invalid){
		camera->camera_matrix = u3d_newMatrix4UVN(camera->point_at, camera->point_to, camera->up_vector);
		
		u3d_matrixMultiplication(camera->camera_matrix, u3d_newMatrix4Translation(camera->tx, camera->ty, camera->tz));
		u3d_matrixMultiplication(camera->camera_matrix, u3d_newMatrix4Rotation(camera->rx_deg, camera->ry_deg, camera->rz_deg));
		
		camera->camera_matrix_invalid = 0;
	}
	return camera->camera_matrix;
}

U3DMatrix_ptr u3d_cameraExportMatrix4Projection(U3DCamera_ptr camera){
	if(0 < camera->projection_matrix_invalid){
		camera->projection_matrix = u3d_newMatrix4Projection(camera->fovx_deg, camera->aspect_ratio, camera->near, camera->far);
		
		camera->projection_matrix_invalid = 0;
	}
	return camera->projection_matrix;
}

U3DMatrix_ptr u3d_cameraExportMatrix4Screen(U3DCamera_ptr camera){
	if(0 < camera->screen_matrix_invalid){
		camera->screen_matrix = u3d_newMatrix4Screen(camera->view_port_width, camera->view_port_height);
		
		camera->screen_matrix_invalid = 0;
	}
	return camera->screen_matrix;
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









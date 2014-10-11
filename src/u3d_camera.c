#include <stdlib.h>

#include "u3d_camera.h"


U3DCamera_ptr u3d_cameraCreate(){
	return (U3DCamera_ptr) malloc(sizeof(U3DCamera));
}

U3DCamera_ptr u3d_cameraConstructDefault(U3DCamera_ptr target){
	u3d_pointConstruct(&target->point_at, 0.0f, 0.0f, 0.0f);
	u3d_pointConstruct(&target->point_to, 0.0f, 0.0f, 1.0f);
	u3d_vectorConstruct(&target->up_vector, 0.0f, 1.0f, 0.0f);

	target->fovx_deg = 90.0f;
	target->near_clip_plane = 0.1f;
	target->far_clip_plane = 1000.0f;
	target->view_port_width = 16.0f * 50.0f;
	target->view_port_height = 9.0f * 50.0f;
	target->aspect_ratio = 16.0f / 9.0f;

	u3d_matrixConstructDefault(&target->camera_matrix);
	u3d_matrixConstructDefault(&target->projection_matrix);
	u3d_matrixConstructDefault(&target->screen_matrix);

	target->camera_matrix_invalid = target->projection_matrix_invalid = target->screen_matrix_invalid = 1;

	return target;
}

U3DCamera_ptr u3d_cameraConstruct(U3DCamera_ptr target, U3DPoint_ptr point_at, U3DPoint_ptr point_to, U3DVector_ptr up_vector, float fovx, float near_clip_plane, float far_clip_plane, float view_port_width, float view_port_height){
	u3d_pointConstruct(&target->point_at, point_at->x, point_at->y, point_at->z);
	u3d_pointConstruct(&target->point_to, point_to->x, point_to->y, point_to->z);
	u3d_vectorConstruct(&target->up_vector, up_vector->x, up_vector->y, up_vector->z);

	target->fovx_deg = fovx;
	target->near_clip_plane = near_clip_plane;
	target->far_clip_plane = far_clip_plane;
	target->view_port_width = view_port_width;
	target->view_port_height = view_port_height;
	target->aspect_ratio = view_port_width / view_port_height;

	u3d_matrixConstructDefault(&target->camera_matrix);
	u3d_matrixConstructDefault(&target->projection_matrix);
	u3d_matrixConstructDefault(&target->screen_matrix);

	target->camera_matrix_invalid = target->projection_matrix_invalid = target->screen_matrix_invalid = 1;

	return target;
}

U3DCamera_ptr u3d_cameraDestruct(U3DCamera_ptr target){
	u3d_pointDestruct(&target->point_at);
	u3d_pointDestruct(&target->point_to);
	u3d_vectorDestruct(&target->up_vector);

	u3d_matrixDestruct(&target->camera_matrix);
	u3d_matrixDestruct(&target->projection_matrix);
	u3d_matrixDestruct(&target->screen_matrix);

	return target;
}

void u3d_cameraDelete(U3DCamera_ptr target){
	free(target);
}

void u3d_cameraExportMatrix4Camera(U3DCamera_ptr camera){
	if(0 < camera->camera_matrix_invalid){
		U3DMatrix temp;
		u3d_initMatrix4UVN(&camera->camera_matrix, &camera->point_at, &camera->point_to, &camera->up_vector);
		
		u3d_initMatrix4Translation(&temp, camera->x, camera->y, camera->z);
		u3d_matrixMultiplication(&camera->camera_matrix, &temp);

		u3d_initMatrix4Rotation(&temp, camera->rx_deg, camera->ry_deg, camera->rz_deg);
		u3d_matrixMultiplication(&camera->camera_matrix, &temp);
		
		camera->camera_matrix_invalid = 0;
	}
}

void u3d_cameraExportMatrix4Projection(U3DCamera_ptr camera){
	if(0 < camera->projection_matrix_invalid){
		u3d_initMatrix4Projection(&camera->projection_matrix, camera->fovx_deg, camera->aspect_ratio, camera->near_clip_plane, camera->far_clip_plane);
		
		camera->projection_matrix_invalid = 0;
	}
}

void u3d_cameraExportMatrix4Screen(U3DCamera_ptr camera){
	if(0 < camera->screen_matrix_invalid){
		u3d_initMatrix4Screen(&camera->screen_matrix, camera->view_port_width, camera->view_port_height);
		
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

void u3d_cameraTranslation(U3DCamera_ptr camera, float x, float y, float z){
	camera->x = -x;
	camera->y = -y;
	camera->z = -z;
	
	camera->camera_matrix_invalid = 1;
}









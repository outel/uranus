#include <math.h>
#include <stdlib.h>

#include "u3d_new.h"


U3DCamera_ptr u3d_newCamera(){
	return (U3DCamera_ptr) malloc(sizeof(U3DCamera));
}

U3DContext_ptr u3d_newContext(){
	return (U3DContext_ptr) malloc(sizeof(U3DContext));
}

U3DMatrix_ptr u3d_newMatrix(){
	return (U3DMatrix_ptr) malloc(sizeof(U3DMatrix));
}

U3DVector_ptr u3d_newVector(){
	return (U3DVector_ptr) malloc(sizeof(U3DVector));
}

U3DPoint_ptr u3d_newPoint(){
	return (U3DPoint_ptr) malloc(sizeof(U3DPoint));
}

U3DList_ptr u3d_newList(){
	return (U3DList_ptr) malloc(sizeof(U3DList));
}

U3DNode_ptr u3d_newNode(){
	return (U3DNode_ptr) malloc(sizeof(U3DNode));
}

U3DObject_ptr u3d_newObject(){
	return (U3DObject_ptr) malloc(sizeof(U3DObject));
}

U3DArrayf_ptr u3d_newArrayf(){
	return (U3DArrayf_ptr) malloc(sizeof(U3DArrayf));
}

U3DArrayu_ptr u3d_newArrayu(){
	return (U3DArrayu_ptr) malloc(sizeof(U3DArrayu));
}

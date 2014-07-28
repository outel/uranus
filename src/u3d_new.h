#ifndef U3D_NEW_H
#define U3D_NEW_H

#include "u3d_matrix.h"
#include "u3d_vector.h"
#include "u3d_camera.h"
#include "u3d_context.h"
#include "u3d_list.h"
#include "u3d_object.h"
#include "u3d_array.h"


U3DCamera_ptr	u3d_newCamera();
U3DContext_ptr	u3d_newContext();
U3DMatrix_ptr	u3d_newMatrix();
U3DVector_ptr	u3d_newVector();
U3DPoint_ptr	u3d_newPoint();
U3DList_ptr		u3d_newList();
U3DNode_ptr		u3d_newNode();
U3DObject_ptr	u3d_newObject();
U3DArrayf_ptr	u3d_newArrayf();
U3DArrayu_ptr	u3d_newArrayu();


#endif

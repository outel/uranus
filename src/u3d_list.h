#ifndef U3D_LIST_H
#define U3D_LIST_H


typedef struct _U3DNode {
	void *data;

	struct _U3DNode *pre;
	struct _U3DNode *nxt;
} U3DNode, *U3DNode_ptr, U3DList, *U3DList_ptr;

U3DList_ptr		u3d_listCreate();
U3DList_ptr		u3d_listConstructDefault(U3DList_ptr target);
U3DList_ptr		u3d_listDestruct(U3DList_ptr target);
void			u3d_listDelete(U3DList_ptr target);

void u3d_listAddNode(U3DList_ptr target, void *data);
void u3d_listDelNode(U3DList_ptr target, void *data);


#endif

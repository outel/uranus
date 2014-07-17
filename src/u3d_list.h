#ifndef U3D_LIST_H
#define U3D_LIST_H


typedef struct _U3DNode {
	void *data;

	struct _U3DNode *pre;
	struct _U3DNode *nxt;
} U3DNode, *U3DNode_ptr;

void u3d_listAddNode(U3DNode_ptr target, void *data);
void u3d_listDelNode(U3DNode_ptr target, void *data);


#endif

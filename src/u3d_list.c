#include "u3d_list.h"
#include "u3d_new.h"


void u3d_listAddNode(U3DList_ptr target, void *data){
	U3DNode_ptr node = u3d_newNode();
	node->data = data;

	node->pre = target->pre;
	target->pre->nxt = node;
	target->pre = node;
	node->nxt = target;
}

void u3d_listDelNode(U3DList_ptr target, void *data){

}


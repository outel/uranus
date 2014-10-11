#include <stdlib.h>

#include "u3d_list.h"
#include "u3d_new.h"


U3DList_ptr u3d_listCreate(){
	return (U3DList_ptr) malloc(sizeof(U3DList));
}

U3DList_ptr u3d_listConstructDefault(U3DList_ptr target){
	target->data = NULL;
	target->pre = target;
	target->nxt = target;

	return target;
}

U3DList_ptr u3d_listDestruct(U3DList_ptr target){


	return target;
}

void u3d_listDelete(U3DList_ptr target){
	free(target);
}


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


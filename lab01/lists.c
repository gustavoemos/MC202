#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define TRUE 1
#define FALSE 0

struct List{ 

	int data;
	struct List* prev;
	struct List* next;

}; typedef struct List List;

/**
insert_at:
	insert element on node of index "index"
	return: returns TRUE if succeeds and else returns FALSE
**/
int insert_at (List* head, int index) {
	List* aux;
	if (index == 0)	{
		aux = head->next;
		head->next = (List*)malloc(List);
		head->next->prev = head;
		head->next->next = aux;
		if (head->next->next != NULL){
			head->next->next->prev = head->next;
		}
		return TRUE;
	} else {
		if(head->next == NULL)
			return FALSE;

		return insert(head->next, index-1);
	}
}

/**
remove_at:
	remove element on node of index "index"
	return: returns TRUE if succeeds and else returns FALSE
**/
int remove_at (List** head, int index){
	List* aux;
	List* node = *head;
	if (index == 0)	{
		aux = node;

		if(node->prev){
			node->prev->next = node->next;	
			node->next->prev = node->prev;
		}else {
			node->next->prev = node->prev;
			*head = node->next;
		}
		free(aux);
		return TRUE;
	} else {
		if(node->next == NULL)
			return FALSE;

		return insert(node->next, index-1);
	}
}


int main(){


	return 0;
}
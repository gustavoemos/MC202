#include <stdio.h>
#include <stdlib.h>

#include <math.h>

typedef struct node{
	double number;
	struct node *next;
	struct node *prev;
} Node;

typedef struct queue{
	Node* head;
	Node* tail;
} Queue;

void push_back(Queue* queue, double number){
	if(queue->tail != NULL || queue->head != NULL){
		queue->tail->prev = malloc(sizeof(Node));
		queue->tail->prev->next = queue->tail;
		queue->tail = queue->tail->prev;
		queue->tail->prev = NULL;
		queue->tail->number = number;
	} else {
		queue->head = queue->tail = malloc(sizeof(Node));
		queue->head->next = queue->head->prev = NULL;
		queue->head->number = number;
	}
}

void pop_front(Queue* queue){
	if(queue->tail == NULL && queue->head == NULL){
		return;
	}
	if (queue->head == queue->tail){
		free(queue->head);
		queue->head = queue->tail = NULL;
	}else{
		queue->head = queue->head->prev;
		free(queue->head->next);
		queue->head->next = NULL;
	}
}

double front(Queue* queue){
	return queue->head->number;
}

void print_lista(Node* lista){
	if (lista->next != NULL){
		print_lista(lista->next);
	}
	printf("%.2lf ", lista->number);
}

double mean_queue(Queue* queue){
	Node* aux = queue->tail;
	double sum = 0;
	int size_queue = 0;

	while(aux != NULL){
		sum += aux->number;
		aux = aux->next;
		size_queue++;
	}
	//printf("MEAN = %lf, size_queue = %d\n", sum/size_queue, size_queue);
	return sum/size_queue;
}

int size_of_queue(Queue* queue){
	if(queue->tail == NULL && queue->head == NULL){
		return 0;
	}
	if (queue->head == queue->tail){
		return 1;
	}else{
		Node* aux = queue->tail;
		int size_queue = 0;

		while(aux != NULL){
			aux = aux->next;
			size_queue++;
		}
		//printf("size_queue = %d\n",size_queue);
		return size_queue;
	}
}

void reset_queue(Queue* queue){
	while(queue->head != NULL){
		pop_front(queue);
	}
}

int main(int argc, char const *argv[]){
	int K, N, espaco = 0;
	double aux;
	Queue* queue = malloc(sizeof(Queue));
	queue->head = queue->tail = NULL;

	//#define NAN 0xFFFFFFFF

	while(!feof(stdin)){
		aux = INFINITY;
		reset_queue(queue);
		if (espaco!=0){
			printf("\n");
		}
		scanf("%d", &K);
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)	{
			scanf("%lf", &aux);
			if(aux == INFINITY)
				break;
			if (size_of_queue(queue)==K){
				//printf("EU ENTREI NO IF\n");
				push_back(queue, aux);
				pop_front(queue);
				if (i<N-1){
					printf("%.1lf ", mean_queue(queue));
				}else{
					printf("%.1lf", mean_queue(queue));
				}
			}else{
				//printf("EU ENTREI NO ELSE\n");
				push_back(queue, aux);
				if (i<N-1){
					printf("%.1lf ", mean_queue(queue));
				}else{
					printf("%.1lf", mean_queue(queue));
				}

				//printf("%.1lf ", mean_queue(queue));
			}
		}
		//print_lista(queue->tail);
		espaco++;
		//printf("%d\n", size_of_queue(queue));
	}
	return 0;
}
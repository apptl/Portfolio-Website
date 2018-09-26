#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

/* Two glboal variables to store address of front and rear nodes.  */
struct Node* front = NULL;
struct Node* rear = NULL;


/* To Enqueue an integer */

void Enqueue(int x) {

	struct Node* temp =  (struct Node*)malloc(sizeof(struct Node));
	temp->data =x;
	temp->next = NULL;

	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}

	rear->next = temp;
	rear = temp;
}


/* To Dequeue an integer. */

void Dequeue() {
	struct Node* temp = front;
	if(front == NULL) {
		printf("Queue is Empty\n");
		return;
	}

	if(front == rear) {
		front = rear = NULL;
	}

	else {
		front = front->next;
	}

	free(temp);
}

int Front() {
	if(front == NULL) {
		printf("Queue is empty\n");
		return 0;
	}
	return front->data;
}

void Print() {
	struct Node* temp = front;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	Enqueue(3);
	Print();
	Enqueue(5);
	Print();
	Enqueue(7);
	Print();
	Dequeue();
	Print();
	Enqueue(9);
	Print();
}

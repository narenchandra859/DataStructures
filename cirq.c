#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int key;
}element;
element *queue;
int capacity = 1;
int front=0;
int rear=0;
void copy(element *s, element *f, element *nq)  {
	element *m, *n;
	m=s;
	n=nq;
	while(m<f) {
		*n=*m;
		m++;
		n++;	
	}
}
void queueFull() {
	element *nq;
	nq=(element*)malloc(2*capacity*sizeof(element*));
	int start;
	start=(front+1)%capacity;
	if(start<2) 
		copy(queue+start,queue+start+capacity-1,nq);
	else {
		copy(queue+start,queue+capacity,nq);
		copy(queue,queue+rear+1,nq+capacity-start);
	}
	front=capacity*2-1;
	rear=capacity-1;
	capacity*=2;
	free(queue);
	queue=nq;
}
void queueEmpty() {
	printf("\nQueue underflow\n");
	exit(0);
}
void enqueue(int item) {
	rear=(rear+1)%capacity;
	if(front==rear)
		queueFull();
	queue[rear].key=item;
}
int dequeue(){
	int c;
	if(front==rear)
		queueEmpty();
	front=(front+1)%capacity;
	c=queue[front].key;
	return c;
}
void display() {
	int  i;
	if(!(front>rear)) {
		for(i=front+1;i<=rear;i++) 
			printf("\n%d",queue[i].key);
	}
	else {
		for(i=front+1;i<capacity;i++) 
			printf("\n%d",queue[i].key);
		for(i=0;i<=rear;i++) 
			printf("\n%d",queue[i].key);
	}
}
int main() {
	queue=(element *)malloc(sizeof(element*));
	while(1) {
	int c, ele;
	printf("\nEnter\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
	scanf("%d",&c);
	switch(c) {
		case 1: {	printf("\nEnter the element to push ");
				scanf("%d",&ele);
				enqueue(ele);
			}break;
		case 2: {
				ele=dequeue();
			 	printf("\nPopped element is %d",ele);
			}break;
		case 3: {
				display();
			}break;
		case 4:exit(0);
	}
	}
}
				

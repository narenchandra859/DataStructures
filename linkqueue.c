#include<stdio.h>
#include<stdlib.h>
#define max_q 100
typedef struct {
	int key;
}element;
struct queue{
	element data;
	struct queue* link;
};
typedef struct queue* queueptr;
queueptr front[max_q];
queueptr rear[max_q];
void queueEmpty() {
	printf("\nQueue underflow \n");
	exit(0);
}
void addq(int i, element data) {	
	queueptr t;
	t=(queueptr)malloc(sizeof(queueptr));
	t->data=data;
	t->link=NULL;
	if(front[i]==NULL)
		front[i]=t;
	else
		rear[i]->link=t;
	rear[i]=t;
}
element delq(int i) {
		if(front[i]==NULL)
			queueEmpty();
		else {
			queueptr t;
			t=front[i];
			element a;
			a=t->data;
			front[i]=front[i]->link;
			free(t);
			return a;	

		}
}
void display(int i) {
		queueptr t;
		t=front[i];
		printf("\nCurrent queue : ");
		while(t!=NULL) {
			printf(" %d ",t->data.key);
			t=t->link;
		}
}
int main() {
        int i;
        int m, n;
        element c;
        while(1) {
        printf("\nEnter\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&m);
        switch(m) {
                        case 1: {
                                printf("\nEnter the queue number and then element ");
                                scanf("%d%d",&n,&c.key);
                                addq(n,c);
                                }
                                break;
                        case 2: {
                                printf("\nEnter the queue number to be dequeued from ");
                                scanf("%d",&n);
                                c=delq(n);
                                printf("\nElement removed is : %d",c.key);
                                }
                                break;
                        case 3: {
                                printf("\nEnter the queue number to be displayed ");
                                scanf("%d",&n);
                                display(n);
                                printf("\n");
                                }
                                break;
                        case 4: exit(0);
                }
        }
        return 0;
}


#include<stdio.h>
#include<stdlib.h>
typedef struct list *listptr;
typedef struct list {
	int data;
	listptr llink;
	listptr rlink;
}list;
void enqueue(listptr head, int n) {
	listptr t;
	t=(listptr)malloc(sizeof(listptr));
	t->data=n;
	t->rlink=head->rlink;
	t->llink=head;
	(head->rlink)->llink=t;
	head->rlink=t;
}
int dequeue(listptr head) {
	listptr t;
	int a;
	t=head->rlink;
	a=t->data;
	head->rlink=t->rlink;
	(t->rlink)->llink=head;
	free(t);
	return a;
}
void disp_front(listptr head) {
	listptr t;
	t=head->rlink;
	printf("\nCurrent list : ");
	while(t!=head) {
		printf("%d ",t->data);
		t=t->rlink;
	}
}
void disp_rev(listptr head) {
	listptr t;
	t=head->llink;
	printf("\nCurrent list : ");
	while(t!=head) {
		printf("%d ",t->data);
		t=t->llink;
	}
}
int main() {
	listptr h;
	h=(listptr)malloc(sizeof(listptr));
	h->data=0;
	h->rlink=h;
	h->llink=h;
        int c, i, ele;
        while(1) {
                printf("\n1.Insert\n2.Delete\n3.Display front\n4.Display reverse\n5.Exit");
                scanf("%d",&c);
                switch(c) {
                        case 1:
                                printf("\nEnter element to be entered : ");
                                scanf("%d",&ele);
                                enqueue(h,ele);
                                break;
                        case 2:
                                ele=dequeue(h);
                                printf("\nElement popped is : %d",ele);
                                break;
                        case 3:
                                disp_front(h);
                                break;
                        case 4: 
				disp_rev(h);
				break;
                        default : exit(0);
                }
        }
}


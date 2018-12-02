#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int key;
}element;
element *stack;
int capacity = 1;
int top = -1;
void stackfull() {
	int *buf=realloc(stack,2*capacity*sizeof(element));
	if(!(buf))
		exit(0);
	capacity*=2;
}
void stackEmpty() {
	printf("\nStack underflow\n");
	exit(0);
}
void push(int item) {
	if(top>=capacity-1) 
		stackfull();
	stack[++top].key=item;
}
int pop(){
	if(top==-1)
		stackEmpty();
	else
		return stack[top--].key;
}
void display() {
	int i;
	if(top==-1) {
		printf("\nStack underflow\n");
		exit(0);	
	}
	printf("\nCurrent stack is ");
	for(i=top;i>=0;i--)
		printf("\n%d",stack[i].key);
	printf("\n");
}
int main() {
	stack=(element *)malloc(sizeof(element*));
	while(1) {
	int c, ele;
	printf("\nEnter\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
	scanf("%d",&c);
	switch(c) {
		case 1: {	printf("\nEnter the element to push ");
				scanf("%d",&ele);
				push(ele);
			}break;
		case 2: {
				ele=pop();
			 	printf("\nPopped element is %d",ele);
			}break;
		case 3: {
				display();
			}break;
		case 4:exit(0);
	}
	}
}
				

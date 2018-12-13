#include<stdio.h>
#include<stdlib.h>
typedef struct tree *treeptr;
typedef struct tree {
	int data;
	treeptr rc;
	treeptr lc;
}tree;
treeptr make() {
	int x;
	printf("\nEnter the data for the node : (0 to stop) ");
	scanf("%d",&x);
	if(x==0)
		return NULL;
	treeptr p;
	p=(treeptr)malloc(sizeof(treeptr));
	p->data=x;
	printf("\nEnter left child of %d : ",p->data);
	p->lc=make();
	printf("\nEnter right child of %d : ",p->data);
	p->rc=make();
	return p;
}
void inorder(treeptr p) {
	if(p) {
	inorder(p->lc);
	printf("%d ",p->data);
	inorder(p->rc);
	}
}
int main() {
	treeptr x;
	int c;
	while(1) {
		printf("\n1.Make a tree\n2.Inorder traversal\n3.Exit\n");
		scanf("%d",&c);
		switch(c) {
			case 1: 
				x=make();
				break;
			case 2:
				printf("\nCurrent inorder : ");
				inorder(x);
			case 3:
				exit(0);
		}
	}
}

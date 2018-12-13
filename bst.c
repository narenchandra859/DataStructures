#include<stdio.h>
#include<stdlib.h>
typedef enum{false, true} boolean;
typedef struct tree *treeptr;
typedef struct tree {
	int data;
	treeptr llink;
	treeptr rlink;
}tree;
void insert(treeptr *r, int d) {
	if((*r)==NULL) {
		(*r)=(treeptr)malloc(sizeof(treeptr));
		(*r)->data=d;
		(*r)->llink=NULL;
		(*r)->rlink=NULL;
		return;
	}
	else if(d>((*r)->data))
		insert(&((*r)->rlink),d);
	else if(d<((*r)->data))
		insert(&((*r)->llink),d);
}
boolean search(treeptr r, int d) {
	if(r==NULL)
		return false;
	else if(r->data==d)
		return true;
	else if(d>(r->data))
		return search(r->rlink,d);
	else if(d<(r->data))
		return search(r->llink,d);
}
void inorder(treeptr r) {
	if(r) {
		inorder(r->llink);
		printf("%d  ",r->data);
		inorder(r->rlink);
	}
}
int main() {
	treeptr r;
	r=NULL;
	int c, d;
	while(1) {
		printf("\n1.Insert\n2.Inorder\n3.Search\n");
		scanf("%d",&c);
		switch(c) {
			case 1 :
				printf("\nEnter the data to be inserted : ");
				scanf("%d",&d);
				insert(&r,d);
				break;
			case 2 :
				printf("\nINORDER TRAVERSAL : ");
				inorder(r);
				break;
			case 3 :
				printf("\nEnter the searching element : ");
				scanf("%d",&d);
				if(search(r,d)==true)
					printf("\nData exists");
				else
					printf("\nData doesn't exist");
				break;
			default: exit(0);
		}
	}
}

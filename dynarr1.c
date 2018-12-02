#include<stdio.h>
#include<stdlib.h>
/* #define MALLOC(p,s) { if(!(p)=malloc(s)) {\
printf("Error"); \
exit(0); } } */
int i;
void input(int *p, int n)
{
	printf("\nEnter the elements ");
	for(i=0;i<n;i++)
		scanf("%d",(p+i));
}
void output(int *p, int n)
{
	printf("\nElements = ");
	for(i=0;i<n;i++)
		printf(" %d ",*(p+i));
}
int main()
{
	int n, *p;
	printf("\nEnter the size of array ");
	scanf("%d",&n);
	p=(int *)malloc(n*sizeof(int));
	input(p,n);
	output(p,n);
	return 0;
}

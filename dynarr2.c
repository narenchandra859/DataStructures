#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **p, r, c, i, j;
	printf("\nEnter the value for rows and columns ");
	scanf("%d%d",&r,&c);
	p=(int **)malloc(r*sizeof(int *));
	for(i=0;i<r;i++)
		p[i]=(int *)malloc(c*sizeof(int));
	printf("\nEnter the elements ");
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",(*(p+i)+j));
	printf("\nElements are ");
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			printf("%d",*(*(p+i)+j));
	return 0;
}

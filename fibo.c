#include<stdio.h>
void fibo(int x)
{	
	int a, b, c;
	a=0;
	b=1;
	printf("%d %d",a,b);
	while(c<x)
	{
		c=a+b;
		printf(" %d",c);
		a=b;
		b=c;
	}
}
int main()
{
	int m;
	printf("\nEnter the limit for fibonacci series ");
	scanf("%d",&m);
	fibo(m);
	return 0;
}

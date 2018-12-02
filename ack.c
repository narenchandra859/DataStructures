#include<stdio.h>
int ack(int m, int n)
{
	if(m==0)
		return n+1;
	else if(n==0)
		return ack(m-1,1);
	else
		return ack(m-1,ack(m,n-1));
}
int main()
{
	int x, y, a;
	printf("\nEnter the two numbers");
	scanf("%d%d",&x,&y);
	a=ack(x,y);
	printf("\nAckermans function output = %d",a);
	return 0;
}
	

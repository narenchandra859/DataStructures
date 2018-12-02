#include<stdio.h>
int mid;
int bs(int a[10], int high, int low, int se)
{
	mid=(high+low)/2;
	if(a[mid]==se)
	{
		return a[mid];
	}
	else if(a[mid]<se)
	{
		return bs(a,high,mid+1,se);
	}
	else if(a[mid]>se)
	{
		return bs(a,mid-1,low,se);
	}
	else
	{
		return 0;
	}
}
int main()
{
	int a[10], se, high, low, i;
	int n;
	printf("\nEnter n");
	scanf("%d",&n);

	printf("\nEnter sorted elements ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nEnter the search element ");
	scanf("%d",&se);
	high=n-1;
	low=0;
	int x;
	x=bs(a,high,low,se);
	if(x==se)
		printf("\nElement found at %d\n",mid+1);
	else
		printf("\nElement not found \n");
	return 0;
}

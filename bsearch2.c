#include<stdio.h>
int mid;
int bs(int a[10], int high, int low, int se)
{
	while(mid>0)
	{
		mid=(high+low)/2;
		if(a[mid]>se)
			high=mid-1;
		if(a[mid]<se)
			low=mid+1;
		if(a[mid]==se)
			return se;
	}
}
int main()
{
	int i, a[10], se, high, low, n;
	printf("\nEnter n");
	scanf("%d",&n);
	printf("\nEnter the sorted elements");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nEnter the search element ");
	scanf("%d",&se);
	int x;
	mid=1;
	high=4;
	low=0;
	x=bs(a, high, low, se);
	if(x==se)
		printf("\nElement found at %d\n",mid+1);
	else
		printf("\nElement not found \n");
	return 0;
}

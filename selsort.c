#include<stdio.h>
void selsort(int a[10], int n)
{
	int i, j, temp;
	int min;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i;j<n;j++)
		{
			if(a[j]<a[min]){
				min=j;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}
int main()
{
	int a[10], n, l;
	printf("\nEnter the number of elements ");
	scanf("%d",&n);
	printf("\nEnter the elements");
	for(l=0;l<n;l++)
		scanf("%d",&a[l]);
	printf("\nArray before sort ");
	for(l=0;l<n;l++){
		printf("%d ",a[l]);
	}
	selsort(a,n);
	printf("\nArray after sort ");
	for(l=0;l<n;l++)
	{
		printf("%d",a[l]);
		printf(" ");
	}
	printf("\n");
	return 0;
}
	

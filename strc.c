#include<stdio.h>
#include<string.h>
struct stud {
	char name[20];
	int roll;
}s[20];
int n, i, pos;
void input()
{
	printf("\nEnter the number of students");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the student %d data",i+1);
		printf("\nEnter name : ");
		scanf("%s",s[i].name);
		printf("\nEnter roll : ");
		scanf("%d",&s[i].roll);
	}
}
int search()
{
	printf("\nEnter the name to be searched : ");
	char x[20];
	int flag;
	flag=-1;
	scanf("%s",x);
	for(i=0;i<n;i++)
	{
		if(strcmp(s[i].name,x)==0)
		{
			flag=1;
			pos=i+1;
		}
	}
	return flag;
}
int main()
{
	int m;
	input();
	m=search();
	if(m==1)
		printf("\nName found at %d",pos);
	else
		printf("\nName not found");
	return 0;
}
		

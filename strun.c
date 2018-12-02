#include<stdio.h>
#include<string.h>
typedef union {
	char hair[20];
	char beard[20];
}id_details;
struct stu {
	int usn;
	char name[20];
	char gen[20];
	id_details id;
}s[100];
int main() {
	int n, i;
	printf("\nEnter the number of students ");
	scanf("%d",&n);	
	printf("\nEnter the student details");
	for(i=0;i<n;i++)
	{
	printf("\nFor student %d ,\n",i+1);
	printf("\nUSN : ");
	scanf("%d",&s[i].usn);
	printf("\nNAME : ");
	scanf("%s",s[i].name);
	printf("\nGEN(male or female) : ");
	scanf("%s",s[i].gen);
	if((strcmp(s[i].gen,"male"))){
		printf("\nHAIR COLOR : ");
		scanf("%s",s[i].id.hair);
	}
	else{
		printf("\nBEARD TYPE : ");
		scanf("%s",s[i].id.beard);
	}
	}for(i=0;i<n;i++)
        {
        printf("\nFor student %d ,\n",i+1);
        printf("\nUSN : %d",s[i].usn);     
        printf("\nNAME : %s",s[i].name);
        printf("\nGEN(male or female) : %s",s[i].gen);
        if((strcmp(s[i].gen,"male")))
                printf("\nHAIR COLOR : %s",s[i].id.hair);
        else
                printf("\nBEARD TYPE : %s",s[i].id.beard);
	}
	return 0;
}

	

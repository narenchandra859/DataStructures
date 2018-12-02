#include<stdio.h>
#include<string.h>
int match(char *str, char *pat) {
	int i=0,j=0;
	int start=0;
	int lens=strlen(str)-1;
	int lenp=strlen(pat)-1;
	int endmatch=lenp;
	for(i=0;endmatch<=lens;endmatch++,start++) {
		if(str[endmatch]==pat[lenp])
			for(i=start,j=0;(j<lenp)&&(str[i]==pat[j]);i++,j++);
		if(j==lenp)
			return start;
	}
	return -1;
}
int main() {
	char str[100], pattern[100];
	printf("\nEnter the string : ");
        scanf("%s",str);
        printf("\nEnter the pattern : ");
        scanf("%s",pattern);
	int n = match(str,pattern);
	if(n==-1)
		printf("\nNo match \n");
	else
		printf("\nMatch found at %d \n",n+1);
	return 0;
}

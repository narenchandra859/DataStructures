#include<stdio.h>
#include<string.h>
int f[100];
void failure(char *pat) {
	int x=0, y=0;
	f[0]=-1;
	int n = strlen(pat);
	for(x=1;x<n;x++) {
		y=f[x-1];
		while((pat[y+1]!=pat[x])&&(y>=0)) 
			y=f[y];
		if(pat[y+1]==pat[x])
			f[x]=y+1;
		else
			f[x]=-1;
	}
}
int kmp(char *st, char *pa) {
	int i=0, j=0;
	int ls=strlen(st);
	int lp=strlen(pa);
	while((i<ls)&&(j<lp)) {
		if(st[i]==pa[j]) {
			i++;
			j++;
		}
		else if(j==0)
			i++;
		else
			j=f[j-1]+1;
	}
	return ((j==lp)?(i-lp):-1);
}
int main() {
	char str[100], pattern[100];
	printf("\nEnter the string : ");
	scanf("%s",str);
	printf("\nEnter the pattern : ");
	scanf("%s",pattern);
	failure(pattern);
	if(kmp(str,pattern)==-1)
		printf("\nNo match found \n");
	else
		printf("\nMatch found at position %d \n",kmp(str,pattern)+1);
	return 0;
}


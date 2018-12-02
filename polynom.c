#include<stdio.h>
#include<stdlib.h>
#define COMPARE(a1,a2) (((a1) > (a2)) ? 1 : (((a1) == (a2)) ? 0 : -1))
typedef struct {
	float coef;
	int exp;
}poly;
poly terms[100];
int avail=0;
void attach(int expon, float coeff) {
	if(avail>=100) {
		printf("\nError! \n");
		exit(0);
	}
	terms[avail].coef=coeff;
	terms[avail].exp=expon;
	avail++;
}
void polyadd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD) {
	*startD=avail;
	float a;
	while((startA<=finishA)&&(startB<=finishB)) {
	switch((COMPARE(terms[startA].exp,terms[startB].exp))) {
		case 1 : {
				attach(terms[startA].exp,terms[startA].coef);
				startA++;
			 }break;
		case -1 : {
				attach(terms[startB].exp,terms[startB].coef);
				startB++;
			 }break;
		case 0 : {
				a=terms[startA].coef + terms[startB].coef;
				attach(terms[startA].exp,a);
				startA++;	
				startB++;
			}break;
	}
  	}
	for(;startA<=finishA;startA++)
   		attach(terms[startA].exp,terms[startA].coef);
  	for(;startB<=finishB;startB++)
   		attach(terms[startB].exp,terms[startB].coef);
 	*finishD=avail-1;
}
void display(int finish, int start) {
	int i;
	for(i=start;i<=finish;i++)
		printf("+ (%.2f x^%d)",terms[i].coef,terms[i].exp);
}
void getdata(int st, int fi) {
	int i, n;
	float m;
	for(i=st;i<=fi;i++) {
		printf("\nEnter the coefficient and exponent : ");
		scanf("%f%d",&m,&n);
		attach(n,m);
	}
}
int main() {
	int sa, fa, sizea, sb, fb, sizeb, i, sd, fd;
	printf("\nEnter the size of A and B polynomials : ");
	scanf("%d%d",&sizea,&sizeb);
	sa=0;
	fa=sizea-1;
	printf("\nEnter the A polynomial : ");
	getdata(sa,fa);
	printf("\nEnter the B polynomial : ");
	sb=sizea;
	fb=sizea+sizeb-1;
	getdata(sb,fb);
	printf("\nPolynomial A is : ");
	display(fa,sa);
	printf("\nPolynomial B is : ");	
	display(fb,sb);
	polyadd(sa,fa,sb,fb,&sd,&fd);
	printf("\nPolynomial D is : ");
	display(fd,sd);
	printf("\n");
	return 0;
}

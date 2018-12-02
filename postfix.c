#include<stdio.h>
#include<stdlib.h>
int isp[]={0,4,3,3,2,2,2,0};
int icp[]={5,4,3,3,2,2,2,0};
typedef enum {
lparen, rparen, plus, minus, times, divide, mod, eos, operand
}precedence;
typedef struct {
        precedence key;
}element;
element *stack;
int top=-1;
int capacity=1;
char expr[200];
void stackfull() {
        int *buf=realloc(stack,2*capacity*sizeof(element));
        if(!(buf))
                exit(0);
        capacity*=2;
}
void stackEmpty() {
        printf("\nStack underflow\n");
        exit(0);
}
void push(precedence item) {
        if(top>=capacity-1)
                stackfull();
        stack[++top].key=item;
}
precedence pop(){
        if(top==-1)
                stackEmpty();
        else
                return stack[top--].key;
}
void printToken(precedence tok) {
	switch(tok) {
		case plus : printf("+");
			break;
		case minus : printf("-");
			break;
		case times : printf("*");
			break;
		case divide : printf("/");
			break;
		case mod : printf("%%");
			break;
	}
}
precedence getToken(char *sym, int *n) {
        //printf("\nin gettoken ");
        *sym=expr[(*n)++];
        //printf("\b curr sym, n = %c, %d",*sym,*n);
        switch(*sym) {
                case '(' : return lparen;
                case ')' : return rparen;
                case '+' : return plus;
                case '-' : return minus;
                case '*' : return times;
                case '/' : return divide;
                case '%' : return mod;
                case '\0' : return eos;
                default :{
                        //printf("\nin default "); 
                        return operand;
                }
	}
}
void postfix() {
	char sym;
	precedence token;
	int n=0;
	top=0;
	stack[0].key=eos;
	token=getToken(&sym,&n);
	while(token!=eos) {
		if(token==operand)
			printf("%c",sym);
		else if(token==rparen) {
			while(stack[top].key!=lparen)
				printToken(pop());
			pop();
		}
		else {
			while(isp[stack[top].key]>=icp[token])
				printToken(pop());
			push(token);
		}
	token=getToken(&sym,&n);
	}
	while((token=pop())!=eos)
		printToken(token);
}
int main() {
	stack=(element *)malloc(sizeof(element *));
	printf("\nEnter the infix expression to convert to postfix ");
	scanf("%s",expr);
	printf("\n Postfix expression = ");
	postfix();
	printf("\n");
	return 0;
}


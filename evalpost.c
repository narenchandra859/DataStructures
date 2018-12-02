#include<stdio.h>
#include<stdlib.h>
typedef enum {
lparen, rparen, plus, minus, times, divide, mod, eos, operand 
}precedence;
typedef struct {
	int key;
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
void push(int item) {
        if(top>=capacity-1)
                stackfull();
        stack[++top].key=item;
}
int pop(){
        if(top==-1)
                stackEmpty();
        else
                return stack[top--].key;
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
int eval() {
	precedence token;
	char sym;
	int op1, op2, n=0;
	token=getToken(&sym,&n);
	//printf("\nafter gettoken, sym= %c, n=%d, token=%d",sym,n, token);
	while(token!=eos) {
		//printf("\nin token loop ");
		if(token==operand) 
			push(sym-'0');
		else {
			op2=pop();
			op1=pop();
			switch(token) {
				case plus : push(op1+op2);
					break;
				case minus : push(op1-op2);
					break;
				case times : push(op1*op2);
					break;
				case divide : push(op1/op2);
					break;
				case mod : push(op1%op2);
					break;
			}
		}
	token=getToken(&sym,&n);
	}
	return pop();
}
int main() {
	stack=(element *)malloc(sizeof(element*));
	int res;
	printf("\nEnter the postfix expression ");
	scanf("%s",expr);
	res=eval();
	printf("\nThe result is %d\n",res);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#define stack_init_size 100
#define stackincrease 10
typedef int status,elemtype;

typedef struct {
	elemtype *base;
	elemtype *top;
	int stacksize;
}SqStack;
status initstack(SqStack &S){
	S.base = (elemtype *)malloc(stack_init_size*sizeof(elemtype));
	if(!S.base) exit(0);
	S.top = S.base;
	S.stacksize = stack_init_size;
	return 1;
}
status push(SqStack &S,elemtype e){
	if(S.top - S.base >= stack_init_size)
	{
		S.base = (elemtype *) realloc(S.base,(stack_init_size+stackincrease)*sizeof(elemtype));
	if(!S.base) exit(0);
	S.top = S.base + S.stacksize;
	S.stacksize += stackincrease; 
	}	
	*S.top ++ = e;
 	return 1;
}
status pop(SqStack &S,elemtype &e){
	if(S.top == S.base) return 0;
	e = * --S.top;
	return 1;
} 
status isempty(SqStack &S)
{
	if(S.top - S.base == 0)return 1;
	else return 0;
}
void conversion()
{
	SqStack S;
	elemtype e;
	int N;
	initstack(S);
	scanf("%d",&N);
	while(N)
	{
		push(S,N % 8);
		N /= 8;
	}
	while(!isempty(S))
	{
		pop(S,e);
		printf("%d",e);
	}
}
main()
{
	conversion();
}







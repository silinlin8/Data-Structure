#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define stack_init_size 100
#define stackincrease 10
#define maxbuffer 10  
typedef int status;
typedef char elemtype;
typedef struct {
	elemtype *base;
	elemtype *top;
	int stacksize;
}SqStack;

//初始化栈 
status initstack(SqStack &S){
	S.base = (elemtype *)malloc(stack_init_size*sizeof(elemtype));
	if(!S.base) exit(0);
	S.top = S.base;
	S.stacksize = stack_init_size;
	return 1;
}

//入栈 
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
//出栈 
status pop(SqStack &S,elemtype &e){
	if(S.top == S.base) return 0;
	e = * --S.top;
	return 1;
} 

//栈空判断 
status isempty(SqStack &S)
{
	if(S.top - S.base == 0)return 1;
	else return 0;
}main()
{
	char c;
	elemtype d;
	SqStack S;
	initstack(S);
	printf("输入算式以 # 结束\n");
	scanf("%c",&c);
	while(c != '#')
	{
		while(c>='0'&&c<='9'||c =='.')//判断连续输入 
		{
			printf("%c",c);
			scanf("%c",&c);
			if(c<'0'||c>'9'&&c !='.')
			printf(" ");
		}
		if(c =='(')
			push(S,c);
		else if(c == ')')//遇到右括号，把左括号之前的运算全部弹出 
		{
			pop(S,d);
			while(d != '(')
			{
				printf("%c ",d);
				pop(S,d);
			}
		}
		else if(c =='+'||c == '-')//+ -运算符判断，与top值比较 top为‘（’则推入，否则先弹栈 再把+ - 入栈 
		{
			if(isempty(S))
				push(S,c);
			else
			{
			pop(S,d);
			if(d != '(')
			printf("%c ",d);
			else
			push(S,d);
			push(S,c);
			}
			
		}
		else if(c =='*'||c == '/') //* / 判断 
		{
			if(isempty(S))
				push(S,c);
			else
			{
			pop(S,d);
			if(d == '('||d =='+'||d =='-')//判断栈顶元素 
			{
				push(S,d);
				push(S,c);
			} 
			else//栈顶为 * 或 / 
			{
			printf("%c ",d);
			push(S,c);
			}
			}
		}
		if(c == '#')//在连续输入数字后如果输入# 
		break;
		scanf("%c",&c);
	 } 
	 while(!isempty(S))
	 {
	 	pop(S,d);
	 	printf("%c ",d);
	 }
} 






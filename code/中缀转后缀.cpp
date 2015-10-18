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

//��ʼ��ջ 
status initstack(SqStack &S){
	S.base = (elemtype *)malloc(stack_init_size*sizeof(elemtype));
	if(!S.base) exit(0);
	S.top = S.base;
	S.stacksize = stack_init_size;
	return 1;
}

//��ջ 
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
//��ջ 
status pop(SqStack &S,elemtype &e){
	if(S.top == S.base) return 0;
	e = * --S.top;
	return 1;
} 

//ջ���ж� 
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
	printf("������ʽ�� # ����\n");
	scanf("%c",&c);
	while(c != '#')
	{
		while(c>='0'&&c<='9'||c =='.')//�ж��������� 
		{
			printf("%c",c);
			scanf("%c",&c);
			if(c<'0'||c>'9'&&c !='.')
			printf(" ");
		}
		if(c =='(')
			push(S,c);
		else if(c == ')')//���������ţ���������֮ǰ������ȫ������ 
		{
			pop(S,d);
			while(d != '(')
			{
				printf("%c ",d);
				pop(S,d);
			}
		}
		else if(c =='+'||c == '-')//+ -������жϣ���topֵ�Ƚ� topΪ�����������룬�����ȵ�ջ �ٰ�+ - ��ջ 
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
		else if(c =='*'||c == '/') //* / �ж� 
		{
			if(isempty(S))
				push(S,c);
			else
			{
			pop(S,d);
			if(d == '('||d =='+'||d =='-')//�ж�ջ��Ԫ�� 
			{
				push(S,d);
				push(S,c);
			} 
			else//ջ��Ϊ * �� / 
			{
			printf("%c ",d);
			push(S,c);
			}
			}
		}
		if(c == '#')//�������������ֺ��������# 
		break;
		scanf("%c",&c);
	 } 
	 while(!isempty(S))
	 {
	 	pop(S,d);
	 	printf("%c ",d);
	 }
} 






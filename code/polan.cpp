#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define stack_init_size 100
#define stackincrease 10
#define maxbuffer 10
typedef int status;
typedef double elemtype;
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
main(){
	SqStack S;
	double d,e;
	char c,str[maxbuffer];
	int i = 0;
	initstack(S);
	printf("输入字符以空格隔开 #结束\n"); 
	scanf("%c",&c);
	while(c != '#'){
		while(isdigit(c) ||c == '.'){

			str[i++] = c;
			str[i] = '\0';
			if(i >= 10){ 
			printf("出错 数据过大 请重新输入\n");
			return -1;
			} 
			scanf("%c",&c);
			if(c == ' ') {
				d = atof(str);
				push(S,d);
				i = 0;
				break;
			}
		}
		
		
		switch(c){
			case '+':
				pop(S,e);
				pop(S,d);
				push(S,d+e);
				break;
			case '-':
				pop(S,e);
				pop(S,d);
				push(S,d-e);
				break;
			case '*':
				pop(S,e);
				pop(S,d);
				push(S,d*e);
				break;	
			case '/':
				pop(S,e);
				pop(S,d);
				if(e!= 0)
				push(S,d/e);
				else{			
				printf("错误 除数不能为 0");
				return -1;
			}
				break;
		}
		scanf("%c",&c);
		
	}
	pop(S,d);
	printf("最终计算结果为 %f",d);
}













#include<stdio.h>
#include<stdlib.h>
typedef int *elemtype;
void func(elemtype &p)
{
	p = (elemtype)malloc(sizeof(int));
	*p = 8;
}
main()
{
	//int a = 3;
	elemtype d = NULL;
	func(d);
	printf("%d",*d);
	
} 

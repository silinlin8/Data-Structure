#include<stdio.h> 
void print()
{
	char c;
	scanf("%c",&c);
	if(c != '#')
	{
		print();
		printf("%c ",c);
	}
}
 main()
{
	print();
} 

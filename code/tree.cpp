#include<stdio.h>
#define Max_size 100
typedef char Elemtype;
typedef struct Node
{
	int child;
	struct Node *next;
}*ChildPtr;
typedef struct
{
	Elemtype data;
	int parent;
	ChildPtr firstchild;
}CTBox;
typedef truct
{
	CTBox[Max_size];
	int r,n;      //根的位置和节点数 
}

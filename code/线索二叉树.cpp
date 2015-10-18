#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef enum
{
	Link,Thread
}PointTag;
typedef stuct BiTNOde
{
	ElemType data;
	struct BiTNOde *lchild,*rchild;
	PointTag ltag,rtag;
}BiTNode,*BiTTree;
BiTTree pre;
//以前序遍历法创建二叉树 
void createBiTTree(BiTTree &T)
{
	char c;
	scanf("%c",&c);
	if(c == ' ')
	{
		T = NULL;
	}
	else
	{
		T = (BiTTree)malloc(sizeof(BiTNode));
		T->data = c;
		T->ltag = Link;
		T->rtag = Link;
		createBiTTree(T->lchild);
		createBiTTree(T->rchild);	
	}
}

void inThreading(BiTTree T)
{
	if( T )
	{
		inTreading(T->lchild);
		if(!T->lchild)
		{
			T->ltag = Thread;
			T->lchild = pre;
		}
		if(!pre->rchild)
		{
			pre->rtag = Thread;
			pre->rchild = T;
		}
		inTreading(T->rchild);
	}
}
void inorderThreading()










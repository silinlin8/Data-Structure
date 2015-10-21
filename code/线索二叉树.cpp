#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef enum
{
	Link,Thread
}PointTag;
typedef struct BiTNOde
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
		inThreading(T->lchild);   //先序遍历左子树 
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
		pre = T; 
		inThreading(T->rchild);   //先序遍历右子树 
	}
}
void inorderThreading(BiTTree T,BiTTree &p)
{
	p = (BiTTree)malloc(sizeof(BiTNode));
	if(!p) exit(0);
	else
	{
		p->ltag = Link;
		p->rtag = Thread;
		p->rchild = p;
	}
	if(!T)
	{
		p->lchild = p;
	}
	else
	{
	
		p->lchild = T;
		pre = p;
		inThreading(T);
		pre->rchild = p;   /*最后处理工作*/ 
		pre->rtag = Thread;
		p->rchild = pre;
	}
	
}
int main()
{
	BiTTree p,T = NULL;
	createBiTTree(T);
	inorderThreading(T,p);
	return 0;
}









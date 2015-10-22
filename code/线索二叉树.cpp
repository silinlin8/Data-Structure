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

void visit(BiTTree T,ElemType c,int a,int b)//访问 
 {
 	c = T->data;
	a = T->ltag;
	b = T->rtag;
	printf("%d-%c-%d \n",a,c,b);  
 }
void inorderTraverse(BiTTree T)//检验 
{
	ElemType data;
	int a,b;
	BiTTree p = T->lchild;
	while(p != T)
	{
		while(p->ltag == Link)
			p = p->lchild;
		visit(p,data,a,b);
		while(p->rtag == Thread &&p->rchild != T)//防止进入倒数第二个结点时进入无限循环 
		{
			p = p->rchild,
			visit(p,data,a,b);
		 } 
		p = p->rchild;
	}
 } 
 
int main()
{
	BiTTree p,T = NULL;
	createBiTTree(T);
	inorderThreading(T,p);
	inorderTraverse(p);//p为第0个结点 
	return 0;
}









#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct BNode
{
	ElemType data;
	struct BNode *lchild,*rchild;	
}BNode,*BTree;

CreateTree(BTree &T)   //必须声明为指针的指针(BTree *T)或者指针的引用 (BTree &T) 因为有 NULL指针； 
{
	char c;
	scanf("%c",&c);
	if(c ==' ')
	{
		T = NULL;
	}
	else
	{
		T = (BTree)malloc(sizeof(BNode));
		(T)->data = c;
		CreateTree((T)->lchild);
		CreateTree((T)->rchild);	
	} 
 } 
 visit(ElemType data,int level)
 {
 	printf("%c 在第 %d 层\n",data,level);
 }
 PreOrderTraverse(BTree T,int level)
 {
 	if(T)
 	{
 		visit(T->data,level);
		PreOrderTraverse(T->lchild,level + 1);
		PreOrderTraverse(T->rchild,level + 1);	
	}
 }
 int main()
 {
 	int level = 1;
 	BTree T = NULL;
 	CreateTree(T);
 	PreOrderTraverse(T,level);
 	return 0;
 	
 }

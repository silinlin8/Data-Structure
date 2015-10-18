#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct BNode
{
	ElemType data;
	struct BNode *lchild,*rchild;	
}BNode,*BTree;

CreateTree(BTree &T)   //��������Ϊָ���ָ��(BTree *T)����ָ������� (BTree &T) ��Ϊ�� NULLָ�룻 
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
 	printf("%c �ڵ� %d ��\n",data,level);
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

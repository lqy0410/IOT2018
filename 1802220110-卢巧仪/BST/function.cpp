
#include "head.h"

void Insert(BiTree bt,int data)
{//关键字的插入 
	BiTree p,s,parent;
	p=bt;
	while(p)
	{
		if(data<p->data)
		{
			parent=p;
			p=p->lchild;
		}
		
		else if(data>p->data)
		{
			parent=p;
			p=p->rchild;
		}
		else
			return ;
	}
	
	s=(BiTree)malloc(sizeof(BiNode));
	s->data=data;
	s->lchild=s->rchild=NULL;
	if(s->data<parent->data)
		parent->lchild=s;
	else
		parent->rchild=s;
}
 
void InitTree(BiTree &bt,int n)
{//建立二叉排序树 
	int data,i;
	scanf("%d",&data);
	bt=(BiTree)malloc(sizeof(BiNode));
	bt->data=data;
	bt->lchild=bt->rchild=NULL;
	for(i=1;i<n;i++)
	{
		scanf("%d",&data);
		Insert(bt,data);
	}
}
 
void InOrder(BiTree bt)
{//树的中序遍历 
	if(!bt)
		return ;
 
	InOrder(bt->lchild);
	printf("%d ",bt->data);
	InOrder(bt->rchild);
}
 
int Search(BiTree bt,int key)
{
	BiTree p;
	p=bt;
	while(p)
	{
		if(key<p->data)
			p=p->lchild;
		else if(key>p->data)
			p=p->rchild;
		else
		{
			printf("数字%d查找成功。\n",key);
			return 1;
		}
	}
	printf("未找到数据%d。\n",key); 
	return 0;
}
 
void Delete_BiTree(BiTree &bt,int key)
{
	BiTree p,cur,par;
	p=bt;
	while(p){
		if(key==p->data)
			break;
		else if(key<p->data){
			par=p;
			p=p->lchild;
		}
		else{
			par=p;
			p=p->rchild;
		}	
	}
	
	if(!p){
		printf("该数据不存在.\n");
		return ;
	}
	
	if(!p->lchild)		//没有左子树 
	{
		if(p==bt)
			bt=p->rchild; 
		else if(par->lchild==p)
			par->lchild=p->rchild;
		else
			par->rchild=p->rchild;
		free(p);
	}
	
 
	else
	{
		cur=p->lchild;
		par=cur;
		while(cur->rchild)
		{
			par=cur;
			cur=cur->rchild;
		}
		
		if(par==p->lchild)			//p的左孩子没有右子树 
		{
			p->data=par->data;
			p->lchild=par->lchild;
			free(par);
		}
		else						//p的左孩子有右子树 
		{
			p->data=cur->data;
			par->rchild=cur->lchild;
			free(cur);
		}
	}
	printf("删除成功.\n");
}

 


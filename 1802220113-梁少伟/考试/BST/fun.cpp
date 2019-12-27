#include"head.h"

bool SearchBSTree(BISTree T, elemtype key, BISTree pre, BISTree& p)//////////����Ԫ��
{
	
	if (!T)
	{
		p = pre;
		return false;
	}
	
	else if (T->data == key)
	{
		p = T;
		return true;
	}
	else if (key < T->data)
	{
		pre = T;
		return  SearchBSTree(T->Lchild, key, pre, p);
	}
	else
	{
		pre = T;
		return  SearchBSTree(T->Rchild, key, pre, p);
	}
}

bool InsertNode(BISTree& T, elemtype KEY)//////////////////����Ԫ��
{
	BISTree p;
	BISTree s;
	if (!SearchBSTree(T, KEY, NULL, p))
	{
		s = (BISTree)malloc(sizeof(BISTreeNode));
		if (!s)exit(1);
		s->data = KEY;
		s->Lchild = s->Rchild = NULL;
		if (!T)
			T = s;
		else if (KEY > p->data)
			p->Rchild = s;
		else
			p->Lchild = s;
		return true;
	}
	else
	{
		return false;
	}
}

void Show(BISTree T)////��ӡ��
{
	if (T)
	{
		Show(T->Lchild);
		cout << T->data<<"  ";
		Show(T->Rchild);
	}
}
void panduan(BISTree T)/////�ж����Ƿ�Ϊ��
{
	if (T)
		cout << "����Ϊ��   " ;
	else
		cout<< "��Ϊ��   " << endl;
}
void deletdata(BISTree& q)//////ɾ������Ԫ��
{
	BISTree p;
	BISTree s;
	if (!q->Lchild)
	{
		p = q;
		q = q->Rchild;
		delete p;
	}
	if (!q->Rchild)
	{
		p = q;
		q = q->Lchild;
		delete p;
	}
	else
	{
		p = q;
		s = q->Lchild;
		while (s->Rchild)
		{
			p = s;
			s = s->Rchild;
		}
		q->data = s->data;
		if (q == p)
			q->Lchild = s->Lchild;
		else
			p->Rchild = s->Lchild;
		delete s;
	}
}

void DestroyBiTree(BISTree & T)////�ݻ���
{
	if (T) {
		if (T->Lchild)         DestroyBiTree(T->Lchild);
		if (T->Rchild)         DestroyBiTree(T->Rchild);
		free(T);
		T = NULL;
	}
}


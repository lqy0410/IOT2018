#include"stdio.h"
#include"malloc.h"
#include"iostream"
using namespace std;


typedef int elemtype;
typedef struct Node
{
	elemtype data;
	struct Node* Lchild, *Rchild;

}BISTreeNode,*BISTree;

bool SearchBSTree(BISTree T, elemtype key, BISTree pre, BISTree& p);/////���������Ƿ��и�Ԫ��
bool InsertNode(BISTree& T, elemtype KEY);//////����Ԫ��
void Show(BISTree T);////��ӡ��
void deletdata(BISTree& q);////ɾ��������Ԫ��
void DestroyBiTree(BISTree& T);/////�ݻ���
void panduan(BISTree T);////�ж����Ƿ�Ϊ��

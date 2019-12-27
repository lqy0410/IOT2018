#include"stdio.h"
#include"malloc.h"
#include"iostream"
using namespace std;


typedef int Elemtype;
typedef struct BiTNode{
	Elemtype data;
	struct BiTNode* Lchild, * Rchild;
}BiTNode ,*BiTree;



void NewTree(BiTree& T, Elemtype n);/////��ʼ��
void InsertTree(BiTree& T, Elemtype n);//////����Ԫ������
void ShowTree(BiTree& T);///////����Ԫ�صĴ�ӡ
void cengci(BiTree& Root);


typedef struct node {
	BiTree data;
	struct node* next;
}node, * QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
	int length;
}Queue;
void InitQueue(Queue& Q);//////��ʼ��
void EnQueue(Queue& Q, BiTree e);/////��Ӳ���
void DeQueue(Queue& Q, BiTree& e);//////���Ӳ���
int QueueEmpty(Queue& Q);




typedef char Elemtype1;
typedef enum PointerType{Link,THread};
typedef struct BiThrNode {
	Elemtype1 data;
	struct BiThrNode* Lchild, * Rchild; 
	PointerType LTag, RTag;
}BiThrNode,*BiThrTree;
BiThrTree Insert_BiTHrTree(BiThrTree Root);//��ʼ��
void Print_BiTHrTree(BiThrTree Root);///��ӡ

void InThreading(BiThrTree p, BiThrTree& pre);
void InOrderThreading(BiThrTree& head, BiThrTree Root);
void read(BiThrTree t);



typedef struct {
	int weight;
	int Parent;
	int Lchild;
	int Rchild;
}THNode,*HuffmanTree;

typedef char** HuffmanNode;
void Compare(HuffmanTree ht, int n, int* p, int* q);//////�Ƚϳ�������Сֵ
void CreateHuffmanTree(HuffmanTree ht,  int n, int* w);///////���������Ľ���������ʵ��
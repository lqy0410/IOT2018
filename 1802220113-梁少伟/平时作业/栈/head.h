#include<stdio.h>
#include<stdlib.h>
#include"malloc.h"
#include <stdio.h>
#include"iostream"
using namespace std;

typedef char elem;
typedef struct Node
{
	elem data;
	struct Node* next;
}List;

typedef struct stack
{
	List* top;
	int length;
}Stack;
void initStack(Stack& s);                              //��ʼ��ջ 
void Push(Stack& s, elem e);                            //��ջ 
void Pop(Stack& s);  //��ջ 
elem Get(Stack& s);                                    //ȡջ��Ԫ�� 
void showStack(Stack& s);                                  ///��ӡ
void getExp(char save[]);
void houzui(char save[], Stack& s, char m[]);
int compare(char ch, char data);



typedef struct iNode
{
	int data;
	struct iNode* next;
}iList;

typedef struct istack
{
	iList* top;
	int length;
}iStack;

void initStack_int(iStack& t);                           //��ʼ������ջ 
void Push_int(iStack& t, int a);                            //����ջ��ջ 
void Pop_int(iStack& t);                           //����ջ��ջ 
int Get_int(iStack& t);                                        //ȡ����ջ��Ԫ�� 
void Evalu(char suf[], iStack& t);
int Calcul(int a, int b, char ch);










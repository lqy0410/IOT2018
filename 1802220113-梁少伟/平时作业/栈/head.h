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
void initStack(Stack& s);                              //初始化栈 
void Push(Stack& s, elem e);                            //入栈 
void Pop(Stack& s);  //出栈 
elem Get(Stack& s);                                    //取栈顶元素 
void showStack(Stack& s);                                  ///打印
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

void initStack_int(iStack& t);                           //初始化数据栈 
void Push_int(iStack& t, int a);                            //数字栈入栈 
void Pop_int(iStack& t);                           //数字栈出栈 
int Get_int(iStack& t);                                        //取数字栈顶元素 
void Evalu(char suf[], iStack& t);
int Calcul(int a, int b, char ch);










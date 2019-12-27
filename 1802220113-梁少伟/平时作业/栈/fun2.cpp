#include"head.h"

void initStack_int(iStack& t)                               //��ʼ������ջ 
{
	t.top = NULL;
	t.length = 0;
}

void Push_int(iStack& t, int a)                            //����ջ��ջ 
{
	iList* p;
	p = (iList*)malloc(sizeof(iList));
	p->data = a;
	p->next = t.top;
	t.top = p;
	t.length++;
}


void Pop_int(iStack& t)                                    //����ջ��ջ 
{                                                      
	if (t.length == 0)                                  //���ж�ջ�Ƿ�Ϊ�� 
	{
		printf("ջΪ�գ�");
	}
	else                                               //��Ϊ�գ���ջ 
	{
		int e;
		iList* p;
		e = t.top->data;
		p = t.top;
		t.top = t.top->next;
		delete p;
		t.length--;
	}
}



int Get_int(iStack& t)                                          //ȡ����ջ��Ԫ�� 
{
	int a;
	a = t.top->data;
	Pop_int(t);
	return a;
}

void Evalu(char suf[], iStack& t)
{
	int result, change, a, b, c;
	int i = 0;
	char ch;
	do
	{
		ch = suf[i];

		if (ch >= '0' && ch <= '9')
		{
			change = ch - '0';
			Push_int(t, change);
		}

		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			a = Get_int(t);
			b = Get_int(t);
			c = Calcul(b, a, ch);
			Push_int(t, c);
		}

		i++;
	} while (suf[i] != '#');
	result = Get_int(t);
	printf("���ʽ�ļ�����Ϊ%d", result);
	printf(" \n");
}

int Calcul(int a, int b, char ch)
{
	int sum;
	if (ch == '+') return sum = a + b;
	else if (ch == '-') return sum = a - b;
	else if (ch == '*') return sum = a * b;
	else if (ch == '/') return sum = a / b;
}


















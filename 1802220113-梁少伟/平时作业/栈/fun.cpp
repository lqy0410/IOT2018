#include"head.h"
#include"stdio.h"

void initStack(Stack& s)                               //��ʼ��ջ 
{
	s.top = NULL;
	s.length = 0;
}


void Push(Stack& s, elem e)                            //��ջ 
{
	List* p;
	p = (List*)malloc(sizeof(List));
	p->data = e;
	p->next = s.top;
	s.top = p;
	s.length++;
}



void Pop(Stack& s)
{                                                      //��ջ 
	if (s.length == 0)                                 
	{
		printf("ջΪ�գ�");
	}
	else                                               //��Ϊ�գ���ջ 
	{
		elem e;
		List* p;
		e = s.top->data;
		p = s.top;
		s.top = s.top->next;
		delete p;
		s.length--;
	}
}


elem Get(Stack& s)                                          //ȡջ��Ԫ�� 
{
	elem a;
	a = s.top->data;
	Pop(s);
	return a;
}



void showStack(Stack& s)                                     ///��ӡ
{
	List* p;
	p = s.top;
	while (p != NULL)
	{
		putchar(p->data);
		p = p->next;
	}
}

void getExp(char save[])////////////
{
	char q;
	int i = 0;
	printf("������һ�����ʽ����#����:\n");
	do
	{
		cin >> q;
		save[i] = q;
		i++;
	} while (save[i - 1] != '#');
}


void houzui(char save[], Stack& s, char m[])
{
	int i = 0, j = 0;
	char ch;
	Push(s, '#');
	do
	{
		ch = save[i];

		if (ch >= '0' && ch <= '9')
		{
			m[j] = ch;
			j++;
		}

		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			if (compare(ch, s.top->data) == 1) Push(s, ch);
			else
			{
				while (compare(ch, s.top->data) == 1)
				{
					m[j] = Get(s);
					j++;
				}
				Push(s, ch);
			}
		}

		else if (ch == '(')  Push(s, ch);

		else if (ch == ')')
		{
			while (s.top->data != '(')
			{
				m[j] = Get(s);
				j++;
			}
			Pop(s);
		}

		i++;
	} while (save[i] != '#');

	while (s.top->data != '#')
	{
		m[j] = Get(s);
		j++;
	}
	m[j] = Get(s);
}


int compare(char ch, char data)
{
	if (data == '#' || data == '(')      return 1;
	else if (data == '+' && ch == '*')   return 1;
	else if (data == '+' && ch == '/')   return 1;
	else if (data == '-' && ch == '*')   return 1;
	else if (data == '-' && ch == '/')   return 1;
	else                                return 0;
}
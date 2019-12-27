#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100//��ʼ������
#define STACKINCREMENT 10//��������

typedef struct
{
	int *base;
	int *top;
	int stacksize;//��ǰջʹ�õ��������
}SqStack;

void InitStack(SqStack &S)//����һ����ջ
{
	S.base=(int*)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!S.base)
	{
	   printf("�洢����ʧ�ܣ�");
	}
	else
	{
       S.top=S.base;
	   S.stacksize=STACK_INIT_SIZE;
	   printf("����ɹ���");
	}
}

void Push(SqStack &S,int e)
{
     if(S.top-S.base>=S.stacksize)
	 {
	    S.base =(int*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(int)) ;
		if(!S.base)
			printf("�洢����ʧ�ܣ�");
		else
		{
		    S.stacksize+=STACKINCREMENT;
			S.top=S.base+S.stacksize;
		}
	 }
	 *S.top++=e;
}

void DisplayStack(SqStack &S)//��ջ�׵�ջ�������ʾջ�е�Ԫ��
{
    int *p;
	p=S.base;
	if(S.base==S.top)
		printf("��ǰջΪ��ջ��");
	else
	{
	   printf("��ǰջ��Ԫ��Ϊ��");
		   while(p!=S.top)
		   {
		     printf("%d",*p);
			 p++;

		   }
		   printf("\n");
	}

}

int StackLength(SqStack S)//�󳤶�
{
   int *p;
   p=S.base ;
   int i=0;
   while(p!=S.top)
	   p++;
       i++;
	return i;
}

void pop(SqStack &S,int &e)//��ջ
{
  if(S.top==S.base)
	  printf("����ʧ�ܣ�");
  else
  {
     e=*--S.top;
	 DisplayStack(S);
  }
}

void ClearStack(SqStack &S)//���
{
   int b;
   while(S.top!=S.base)b=*--S.top;
   if(S.top==S.base)
	   printf("˳��ջ����գ�");
}

void StackEmpty(SqStack S)//�п�
{
  if(S.top==S.base)
	  printf("˳��ջΪ�գ�");
	  else
	  printf("˳��ջ��Ϊ�գ�");
}

void DestroyStack(SqStack &S)//����
{
   S.base=NULL;
   printf("˳��ջ�����٣�");
}

void GetTop(SqStack S,int &e)//����ջ��Ԫ��
{
   if(S.top==S.base)
	   printf("����ʧ�ܣ�");
   else
   {
     printf("ջ��Ԫ��Ϊ��");
		 e=*(S.top-1);
	 printf("%d",e);
   }
}

int menu()
{
     printf("1.����һ����ջ\n");
	 printf("2.����ջ��Ԫ��\n"); 
	 printf("3.���ջ��Ԫ��\n");
     printf("4.��ջ�ĳ���\n")  ;
	 printf("5.��ջ��Ԫ��\n")  ;
	 printf("6.ɾ��ջ��Ԫ��\n") ; 
	 printf("7.����Ѵ��ڵ�ջ\n");  
	 printf("8.�ж�ջ�Ƿ�Ϊ��\n") ; 
	 printf("9.����ջ\n") ;

     SqStack S;
     int choice;
     InitStack(S);
     while(1)
	 {
        menu();
        printf("������˵���ţ�\n");
        scanf("%d",&choice);
        if(choice==9) break;
        switch(choice)
		{
           case 1: InitStack(S);
	          break;
           case 2: char a;
			       Push(S,a);
	          break;
           case 3: DisplayStack(S);
	          break;
           case 4: StackLength(S);
	          break;
           case 5: int b;
			       GetTop(S,b);
	          break;
           case 6: int c;
			       pop(S,c);
	          break;
           case 7: ClearStack(S);
	          break;
           case 8: StackEmpty(S);
	          break;
           case 9: DestroyStack(S);
	          break;

           default:printf("������󣡣���\n");
		}
	 }
    return 0;
}

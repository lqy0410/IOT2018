#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 

#define LIST_INIT_SIZE 50
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2
 

typedef int ElemType;
 
typedef struct {
    ElemType *elem; 
    int length;     
    int listsize;   
} SqList;
 

int InitList(SqList *L)
{
    
    L->elem = (ElemType *) malloc(sizeof(ElemType));
    
    if (!L->elem) return ERROR; 
    
    L->length = 0; 
    
    L->listsize = LIST_INIT_SIZE;   
   
    return OK;
}
 
// ��ȡ˳����i��Ԫ��
ElemType GetListElem(SqList *L, int i)
{
   
    if (i < 1 || i > L->length) 
        return ERROR;
    else    
        return L->elem[i-1];
}
 
// ��ѯĿ��Ԫ����˳�����λ��
int LocateListElem(SqList *L, ElemType e)
{
    int i = 1;
   
    ElemType *p = L->elem;
    
    while (*p != e && i <= L->length) 
    {
        i++;
        p++;
    }
    if (i > L->length)
        return 0;
    else
        return i;
}
 
// ��˳����i��λ�ò���Ԫ��
int InsertListElem(SqList *L, int i, ElemType e)
{
    int k;  
   
    if (i < 1 || i > L->length + 1) return ERROR;
    
    if (L->length >= L->listsize)
    {
        
        L->elem = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!L->elem) return ERROR;
       
        L->listsize += LISTINCREMENT;       
    }
    
    
    for (k = L->length - 1; k >= i - 1; k--) 
        L->elem[k + 1] = L->elem[k];        
    
    L->elem[i-1] = e;
    
    L->length++;
    
    return OK;  
}
 
// ɾ��˳����i��Ԫ��
int DeleteListElem(SqList *L, int i)
{
    int k;
    
    if (i < 1 || i >L->length) return ERROR;
    
    for (k = i; k <= L->length; k++) 
        L->elem[k-1] = L->elem[k];
    
    L->length--;
    
    return OK;
}
 
// �޸�˳����i��Ԫ��
int UpdateListElem(SqList *L, int i, ElemType e)
{
   
    if (i < 1 || i >L->length) return ERROR;
    
    L->elem[i-1] = e;
    
    return OK;
}
 
// ���˳���ȫ��Ԫ��
void PrintList(SqList *L) 
{
    int i;
    if (L->length == 0)
        printf("\n˳���Ϊ�գ�\n\n");
    else
        for (i = 1; i <= L->length; i++)
            printf("%d ", L->elem[i-1]);
    printf("\n");
}
 
int main()
{   
    int i, choice, position;  
    ElemType data, elem;  
    int isRunning = 1;
    
    SqList *pl = (SqList *)malloc(sizeof(SqList));      
    
    while(isRunning)  
    {  
        printf("======˳��������ʾ=======\n");  
        printf("1. ����һ���յ�˳���\n");  
        printf("2. ���˳����ȫ������\n");  
        printf("3. ��ѯ˳���ĳ��λ�õ�����\n");  
        printf("4. ��ѯ������˳����е�λ��\n");  
        printf("5. ��˳���ָ��λ�ò�������\n");  
        printf("6. ɾ��˳���ָ��λ�õ�����\n");  
        printf("7. ����˳���ָ��λ�õ�����\n");  
        printf("8. �˳�˳��������ʾ����\n");  
        printf("===========================\n");  
        printf("\n����1-8��ѡ�����蹦�ܺţ�");  
        scanf("%d", &choice);  
        printf("\n��ѡ��Ĺ��ܺ�Ϊ��%d\n", choice);  
  
        switch(choice)  
        {  
            case 1:
                if (InitList(pl)) 
                    printf("\n˳������ɹ���\n\n");    
                else 
                    printf("\n˳�����ʧ�ܣ�\n\n");
                system("pause");
                break;
            case 2:
                PrintList(pl);
                system("pause");
                break;
            case 3:
                printf("i=");
                scanf("%d", &i);
                elem = GetListElem(pl, i);
                if (elem) 
                    printf("L[%d]=%d\n\n", i, elem);  
                else
                    printf("�����λ�ò��Ϸ���");
                system("pause");            
                break;
            case 4:
                printf("data=");
                scanf("%d", &data);
                position = LocateListElem(pl, data);
                if (position)
                    printf("%d is at [%d] of the list.\n\n", data, position);
                else 
                   printf("%d is not in the list.\n\n", data);
                system("pause");
                break;
            case 5:
                printf("i,data=");
                scanf("%d,%d", &i, &data);
                if (InsertListElem(pl, i, data))
                    printf("\n���ݲ���ɹ���\n\n");
                else 
                    printf("\n���ݲ���ʧ�ܣ�\n\n");
                system("pause");
                break;
            case 6:
                printf("i=");
                scanf("%d", &i);
                if (DeleteListElem(pl, i))
                    printf("\n����ɾ���ɹ���\n\n");
                else
                    printf("\n����ɾ��ʧ�ܣ�\n\n");
                system("pause");
                break;
            case 7:
                printf("i,data=");
                scanf("%d,%d", &i, &data);
                if (UpdateListElem(pl, i, data))
                    printf("\n���ݸ��³ɹ���\n\n");
                else
                    printf("\n���ݸ���ʧ�ܣ�\n\n");
                system("pause");
                break;
            case 8:
                isRunning = 0;              
                break;
        }
    }
    
    printf("\nллʹ�ñ�����");
    
    return 0;
}

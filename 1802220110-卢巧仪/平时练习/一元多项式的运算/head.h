#include"stdio.h"
#include"stdlib.h"

typedef struct dxs  //����ʽ�ڵ�
{
	float coe;  //ϵ��
	int exp;   //ָ��
	struct dxs * pNext;  //ָ����
 
}DXS, * PDXS;
  
PDXS creat_dxs();   //��������ʽ
void traverse(PDXS pHead);   //��������ʽ����
PDXS add(PDXS Da, PDXS Db);  //����ʽ���
 
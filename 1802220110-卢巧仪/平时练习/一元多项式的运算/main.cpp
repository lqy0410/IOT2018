#include"head.h"

int main(void)
{
	//������ṹ��������������ʽ
	PDXS Da = creat_dxs();
    traverse(Da);
 
	PDXS Db = creat_dxs();
    traverse(Db);
 
	//����������ʽ�ļӷ�
	PDXS Dj = add(Da, Db);
	traverse(Dj);
 
	return 0;
}
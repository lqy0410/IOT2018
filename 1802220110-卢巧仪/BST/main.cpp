#include "head.h"

int main()
{
	BiTree bt;
	int n,key,selet;	
	while(1)
	{
		printf("		------------------\n");
		printf("		1����������������\n");
		printf("		2���������������\n");
		printf("		3����������\n");
		printf("		4��ɾ������\n");
		printf("		5����������\n");
		printf("		6���˳�\n"); 
		printf("		------------------\n");
		
		scanf("%d",&selet);
		switch(selet)
		{
			case 1:
				printf("�������ֵĸ���:");
				scanf("%d",&n);
				printf("������ÿ������:");
				InitTree(bt,n);
				break;
			case 2:	
				printf("����������Ϊ��");
				InOrder(bt);
				putchar('\n');
				break;
			case 3:
				printf("��������ҵĹؼ��֣�");
				scanf("%d",&key);
				Search(bt,key);
				break;
			case 4:
				printf("������ɾ���Ĺؼ��֣�");
				scanf("%d",&key);
				Delete_BiTree(bt,key);
				break;
			case 5:
				printf("������Ҫ��������ݣ�");
				scanf("%d",&key); 
				Insert(bt,key);
				printf("����ɹ�.\n");
				break;
			default:
				return 0;
		}
	}
}
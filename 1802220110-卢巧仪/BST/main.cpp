#include "head.h"

int main()
{
	BiTree bt;
	int n,key,selet;	
	while(1)
	{
		printf("		------------------\n");
		printf("		1、建立二叉排序树\n");
		printf("		2、输出中序遍历结果\n");
		printf("		3、搜索数据\n");
		printf("		4、删除数据\n");
		printf("		5、插入数据\n");
		printf("		6、退出\n"); 
		printf("		------------------\n");
		
		scanf("%d",&selet);
		switch(selet)
		{
			case 1:
				printf("输入数字的个数:");
				scanf("%d",&n);
				printf("请输入每个数字:");
				InitTree(bt,n);
				break;
			case 2:	
				printf("中序遍历结果为：");
				InOrder(bt);
				putchar('\n');
				break;
			case 3:
				printf("请输入查找的关键字：");
				scanf("%d",&key);
				Search(bt,key);
				break;
			case 4:
				printf("请输入删除的关键字：");
				scanf("%d",&key);
				Delete_BiTree(bt,key);
				break;
			case 5:
				printf("请输入要插入的数据：");
				scanf("%d",&key); 
				Insert(bt,key);
				printf("插入成功.\n");
				break;
			default:
				return 0;
		}
	}
}
#include"head.h"

int main()
{
	/*
	int option;
	int sign=1;
	Elemtype n;
	BiTree T=NULL;
	while (sign)
	{
		cout << "--------------------�˵�--------------------" << endl;
		cout << " 1.��������Ԫ��      2.���������������Ԫ�� " << endl;
		cout << " 3.��α���          4.�˳�			     " << endl;
		cout << "�����빦�ܣ�1-2���� ";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "������Ԫ�أ� ";
			cin >> n;
			InsertTree(T, n);
			break;

		case 2:
			cout << "���а����������Ϊ����>" ;
			ShowTree(T);
			cout << endl;
			break;
		case 3:
			cengci(T);
			break;
		case 4:
		    sign=0;
			break;

		}
	}*/
	/*
	BiThrTree Root;
	BiThrTree head;
	Root = (BiThrTree)malloc(sizeof(BiThrNode));
	head = (BiThrTree)malloc(sizeof(BiThrNode));
	Root = Insert_BiTHrTree(Root);
	Print_BiTHrTree(Root);
	InOrderThreading(head,Root);
	read(head);
	*/
	
	HuffmanTree ht = NULL;
	int w[6] = { 4,5,6,7,8,9};
	CreateHuffmanTree(ht,6, w);
	return 0;

}
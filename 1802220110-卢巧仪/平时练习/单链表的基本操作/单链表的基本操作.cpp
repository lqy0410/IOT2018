
#include <iostream>

#include <string.h>

#include <windows.h>



using namespace std;



typedef long DataType; //������������������



//����ѧ��������ṹ��

typedef struct node

{

	DataType data;//ѧ��ѧ��

	char   name[20];//ѧ������

	double   score;//ѧ���ɼ�����

	struct node* Next;//ָ����һ��ѧ����ָ��

}LinkList,*PLinkList;



/* ****************�����յ�����***********************/

PLinkList Create_Linklist()

{

	PLinkList PLinkListPoint;

	PLinkListPoint=new LinkList;//ΪPLinkList����һ��LinkList�Ŀռ�

	if(!PLinkListPoint)

	{

		cout<<"�����ڴ�ʧ�ܣ�"<<endl;

		return (NULL);

	}

	else

	{

		PLinkListPoint->Next=NULL;

		return (PLinkListPoint);//���ش����ڵ���Ϣ

	}

}

/* ****************ͷ�巨�������������****************/

PLinkList Create_ReverseLinkList()

{

	PLinkList H,preview;

	int NodeCount=0;

	H=new LinkList;

	if(!H)

	{

		cout<<"�����ڴ�ʧ�ܣ�"<<endl;

		return (NULL);

	}

	else

	{

		H->Next=NULL; 

	}

	cout<<"\t���������봴��������������";

	cin>>NodeCount;

	cout<<"\t\t��������������\n\t��ע��ͷ�巨����������洢���ݽ���ʵ�������෴��";



	for(int i=1;i<=NodeCount;i++)

	{	

        cout<<endl;

		preview=new LinkList;

		cout<<"����ѧ��: "; 

		cin>>preview->data; 

		cout<<"��������: "; 

		cin>>preview->name;

		cout<<"�������: "; 

		cin>>preview->score;

		preview->Next=H->Next; 

		H->Next=preview; 

	}

	return (H);

}

// ****************β�巨�������������****************/

PLinkList Create_SeqLinkList()

{  

	PLinkList H,preview,current; 

	int NodeCount=0; 

	H=new LinkList;//����һ��LinkList��ͷ���

	if(!H)

	{

		cout<<"�����ڴ�ʧ�ܣ�"<<endl;

		return (NULL);

	}

	else

    	H->Next=NULL; 

	cout<<"\t���������봴��������������";

	cin>>NodeCount;

	cout<<"\t\t��������������\n\t��ע��β�巨����,����˳����ʵ��������ͬ)";

	preview=H;            //��H����preview

	for(int i=1;i<=NodeCount;i++)

	{

        cout<<endl; 

		current=new LinkList;

		if(!current)

		{

			cout<<"����ռ�ʧ�ܣ�"<<endl;

			return (NULL);

		}

		preview->Next=current; 

		cout<<"����ѧ��:"; 

		cin>>current->data; 

		cout<<"��������:"; 

		cin>>current->name;

		cout<<"�������:";

		cin>>current->score;

		current->Next=NULL; //βΪ�ڵ�ָ���

		preview=current; 

	}

	return (H);

}



// ****************�����������****************************/

int  Destory_LinkList(PLinkList* PLinkListPoint)

{

	if(!*PLinkListPoint)

	{

		cout<<"�����ڣ�"<<endl;

		return (0);

	}

	PLinkList p=*PLinkListPoint,q;

	while(p)

	{

		q=p;

		p=p->Next;

		delete q;

	}

	return (1);

}

/*******************���µ�����*******************************/

int alter_LinkList(PLinkList PLinkListPoint, DataType DataX,float Grade)

{

	PLinkList p=PLinkListPoint;

	if(!PLinkListPoint)

	{

		cout<<"�����ڣ�"<<endl;

		return (-1);

	}

	if(p)

	{

		while(p && p->data!=DataX)

			p=p->Next;

		if(!p)

		{

			cout<<"\n\n\n\n\t\t�˱��У�û�и����ݣ�"<<endl;

			return (NULL);

		}

		p->score=Grade;//��grade��ֵ����Ӧѧ�ŵĳɼ�

		return 1;

	}

	else

	{

		cout<<"������!"<<endl;

		return (0);

	}

}

/**************ɾ��ָ��ֵ��ѧ������Ϣ********************/   

int Del_LinkList(PLinkList PLinkListPoint, DataType DataX)

{  

 //����ֵ��-1�����ڣ�1�ɹ�

	PLinkList p=PLinkListPoint->Next;

	PLinkList q,r;

	r=PLinkListPoint;

	if(!PLinkListPoint)

	{

		cout<<"�����ڣ�"<<endl;

		return (-1);

	}

	if(p)

	{

		while(p && p->data!=DataX)

		{

			p=p->Next;

			r=r->Next;//�����ҵ�ֵ��ȵ���һ���ڵ�

		}

		if(!p)

		{

			cout<<"\n\n\n\n\t\t�˱��У�û�и����ݣ�"<<endl;

			return (NULL);

		}

		q=p;

		r->Next=q->Next;

		delete q;

		return (NULL);

		

	}

	else

	{

		cout<<"������!"<<endl;

		return (0);

	}



}

/************************��Ԫ�ؼ�������**********************/

PLinkList Locate_LinkList(PLinkList PLinkListPoint ,DataType DataX)

{

	PLinkList p=PLinkListPoint;

	if(p)

	{

		while(p && p->data!=DataX)

        p=p->Next;

		if(p)

		return(p);

		else

		{

			cout<<"\n\n\n\n\t\t�˱��У�û�и����ݣ�"<<endl;

			return (NULL);

		}

             

	}

	else

	{

		cout<<"������!"<<endl;

		return (NULL);

	}

}

/********************���ò���****************************/

PLinkList Reverse_LinkList(PLinkList PLinkListPoint)

{

	if(!PLinkListPoint)

	{

		return (NULL);

	}

	PLinkList p,q;

	p=PLinkListPoint->Next;

	PLinkListPoint->Next=NULL;

	while(p)

	{

		q=p;

		p=p->Next;

		q->Next=PLinkListPoint->Next;

		PLinkListPoint->Next=q;

	}

	return (PLinkListPoint);

}

/*******************��鵥�����Ƿ�Ϊ��******************/

int CheckEmpty_LinkList(PLinkList PLinkListPoint)

{

	if(!PLinkListPoint)

		return (-1);

	if(!PLinkListPoint->Next)

		return (1);

	else

		return (0);

}

/******************** ����������******************/

void Print_LinkListData(PLinkList H)

{

	if(!H)

	{

		cout<<"�������ڣ�"<<endl;

	}

	PLinkList current=H;

	cout<<"������ĵ�����Ϊ:"<<endl; 

	cout<<"ѧ ��\t\t�� ��\t\t�� �� "<<endl;

	cout<<endl;

	current=current->Next;

	while(current)

	{

		cout<<current->data<<"\t\t"<<current->name<<"\t\t"<<current->score<<endl;;

		cout<<endl; 

		current=current->Next;

	}

	cout<<endl;

	system("pause");

}



int main()

{

	int i=-1,j=-1,choice;

	long data=0,number;

    float grade;

	PLinkList PLinkListPoint1,PLinkListPoint2;

	PLinkListPoint1=Create_Linklist();

	while(1)

	{

		system("cls");

        cout<<" **�������������ʵ��(ע�������ѡ����� 1 ���� 2 ����������)**"<<endl;

        cout<<"\t����������������-��M  E  N  U����������������-�� \n";	

		cout<<"\t��                                            ��"<<endl;

        cout<<"\t��      1.ͷ�巨�������������                ��"<<endl;

        cout<<"\t��      2.β�巨�������������                ��"<<endl;

        cout<<"\t��      3.��Ԫ�ؼ�������                      ��"<<endl;

        cout<<"\t��      4.��ѧ��ɾ��������                  ��"<<endl;

        cout<<"\t��      5.�޸�ָ��ѧ��ѧ���ĳɼ�              ��"<<endl;

        cout<<"\t��      6.�����������                        ��"<<endl;

        cout<<"\t��      7.�����������                        ��"<<endl;

        cout<<"\t��      0.�˳�����                            ��"<<endl;

        cout<<"\t��                                            ��"<<endl;

        cout<<"\t������������-����������Ҫʵ�ֵĲ���:-��������-��"<<endl;

		cout<<"\t\t\t\t";

        //cout<<"����������Ҫʵ�ֵĲ���: ";

		cin>>choice;

        system("cls");

		switch(choice)

		{

		case 1:

		case 2:

			if(choice==1)

			{

                cout<<"\n\n\t\t\t1.ͷ�巨�������������"<<endl<<endl;

				PLinkListPoint1=Create_ReverseLinkList();

				Print_LinkListData(PLinkListPoint1);

				break;

			}

			else

			{

                cout<<"\n\n\t\t\t2.β�巨�������������"<<endl<<endl;

				PLinkListPoint1=Create_SeqLinkList();

				Print_LinkListData(PLinkListPoint1);

				break;

			}  

		case 3:

			if(CheckEmpty_LinkList(PLinkListPoint1))

			{

				cout<<"\n\n\t\t\t����Ϊ�գ���ѡ�����1��2����������"<<endl;

				system("pause");

				break;

			}

            cout<<"\n\n\t\t\t3.��Ԫ�ؼ�������"<<endl<<endl;

			cout<<"��������Ҫ����ѧ����ѧ��:  ";

			cin>>j;

			PLinkListPoint2=Locate_LinkList(PLinkListPoint1,j);

			if(PLinkListPoint2)

			{

				cout<<"Ҫ���ҵ�Ԫ��Ϊ: "<<PLinkListPoint2->data<<"\t";

				cout<<PLinkListPoint2->name<<"\t";

				cout<<PLinkListPoint2->score<<endl;

			}

			j=-1;

			system("pause");

			break;

		case 4:

			if(CheckEmpty_LinkList(PLinkListPoint1))

			{

				cout<<"\n\n\t\t\t����Ϊ�գ���ѡ�����1��2����������"<<endl<<endl;

				system("pause");

				break;

			}

            cout<<"\n\n\t\t\t4.��λ��ɾ��������"<<endl<<endl;

			cout<<"����������ɾ��ѧ����ѧ�ţ�";

			cin>>i;

			if(Del_LinkList(PLinkListPoint1 , i)==1)

			{

				cout<<"ɾ���ɹ���"<<endl;

			}

			i=-1;

			Print_LinkListData(PLinkListPoint1);

			//system("pause");

			break;

		case 5:

			if(CheckEmpty_LinkList(PLinkListPoint1))

			{

				cout<<"\n\n\t\t\t����Ϊ�գ���ѡ�����1��2����������"<<endl;

				system("pause");

				break;

			}

             cout<<"\n\n\t\t\t5.�޸�ָ��ѧ��ѧ���ĳɼ�"<<endl<<endl;

             cout<<"������Ҫ�޸ĵ�ѧ����ѧ�źͳɼ�:  ";

             cin>>number>>grade;

             alter_LinkList(PLinkListPoint1,number,grade);

             Print_LinkListData(PLinkListPoint1);

			 //system("pause");

             break;

		case 6:

			if(CheckEmpty_LinkList(PLinkListPoint1))

			{

				cout<<"\n\n\t\t\t����Ϊ�գ���ѡ�����1��2����������"<<endl;

				system("pause");

				break;

			}

            cout<<"\n\n\t\t\t6.�����������"<<endl<<endl;

			Reverse_LinkList(PLinkListPoint1);

			cout<<"\t\t\t��������ɹ� ��"<<endl;

			Print_LinkListData(PLinkListPoint1);

			//system("pause");

			break;

		case 7:

			if(CheckEmpty_LinkList(PLinkListPoint1))

			{

				cout<<"\n\n\t\t\t����Ϊ�գ���ѡ�����1��2����������"<<endl<<endl;

				system("pause");

				break;

			}

            cout<<"\n\n\t\t\t7.�����������"<<endl<<endl; 

			if(Destory_LinkList(&PLinkListPoint1))

			{

				cout<<"\n\n\t\t\t���ٵ�����ɹ���"<<endl;

			}

			system("pause");

			break;

			//�˳�����

		case 0:

			exit(0);

			break;

		default:

			cout<<"\n\n\t\t\t�����������"<<endl;

			system("pause");

			break;

   }

 }

 return 0;

}
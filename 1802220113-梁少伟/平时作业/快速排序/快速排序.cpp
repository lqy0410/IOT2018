//��������
//
//���ι���
//
//�ֽ⣺��������ѡȡһ����Ԫx������x��ֵ�������黮�ֳ����������飬ʹ��ǰһ�������ÿ��Ԫ��<= x<= ��һ�������е�ÿ��Ԫ�� 
//
//       <=x  | x |  >=x
//
//�������������������еݹ�����
//
//�ϲ���ʲô������Ҫ��
//
//�ؼ��������ӹ��� 
//
//�͹鲢�����෴
//
//
//�ĸ�����
//һ����Ԫx
//����<=x������
//����>x������
//�ģ�δ���������
//
//iΪ����һ�����һ���±�
//jΪ�������ĵ�һ��Ԫ��
//i+1��j-1���������Ԫ�� 
//
//x|      <=x       |     >=x         |    ??? 
//                ��                    ��
//				i                     j 
//
//��������ĵ�Ԫ�ر�x�������������
//ֱ��j++
//��������ĵ�Ԫ�ر�xС������������
//��i++����i��Ԫ�غ�j��Ԫ�ػ�λ�ã�Ȼ��j++ 
//
//����������֮���i��x��λ�ü��� 

#include<stdio.h>


void qSort(int a[], int p, int q);
int rec_quickSort(int a[],int p,int q);
void print_qSort(int n,int a[]);

int main()
{
	int a[8] = {1,3,5,4,2,6,9,7};
	int p = 0;
	int q = 7;	
	qSort(a,p,q);
	print_qSort(7,a);
 } 
 
 
 void qSort(int a[], int p, int q)                  //��������ĺ��� 
{
	int r;
	if(p < q)
	{
		r = rec_quickSort(a,p,q);
		qSort(a,p,r);                               //�ݹ�����Լ������ϲ�� 
		qSort(a,r+1,q);
	}
}


int rec_quickSort(int a[],int p,int q)
{
	int x = a[p];
	int i = p;
	int temp;
	for(int j = p+1 ; j <= q; j++)
	{
		if(a[j] <= x)
		{
			i++;
			temp = a[i];                            //������� 
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i];
	a[i] = a[p];
	a[p] = temp;
	
	return i;
} 



void print_qSort(int n,int a[])
{
	for(int i = 0 ; i <= n ; i++)
	{
		printf("%d",a[i]);
	 } 
}

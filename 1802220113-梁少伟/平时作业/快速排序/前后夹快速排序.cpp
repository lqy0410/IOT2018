//һ�˿���������㷨�ǣ�
//1��������������i��j������ʼ��ʱ��i=0��j=N-1��
//2���Ե�һ������Ԫ����Ϊ�ؼ����ݣ���ֵ��key����key=A[0]��
//3����j��ʼ��ǰ���������ɺ�ʼ��ǰ����(j--)���ҵ���һ��С��key��ֵA[j]����A[j]��A[i]��ֵ������
//4����i��ʼ�������������ǰ��ʼ�������(i++)���ҵ���һ������key��A[i]����A[i]��A[j]��ֵ������
//5���ظ���3��4����ֱ��i=j�� (3,4���У�û�ҵ�����������ֵ����3��A[j]��С��key,4��A[i]������key��ʱ��ı�j��i��ֵ��ʹ��j=j-1��i=i+1��ֱ���ҵ�Ϊֹ���ҵ�����������ֵ�����н�����ʱ��i�� jָ��λ�ò��䡣���⣬i==j��һ����һ��������i+��j-��ɵ�ʱ�򣬴�ʱ��ѭ����������


#include<stdio.h>

void quick_sort(int a[]);
void rec_quick(int a[],int i,int j);
 
int main(){
	int a[8] = {7,3,1,9,5,4,6,8};
	quick_sort(a);
	for(int i = 0 ; i < 8 ; i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
} 

void rec_quick(int a[],int i,int j)
{
	int left = i;
	int right = j;
	int key = a[i];
	if(i < j)
	{
		while(i < j)
		{
			while(a[j] >= key && i < j)
			{
				j--;
				
			}
			
			a[i] = a[j];
			
			while(a[i] <=key && i <j)
			{
				i++;
			}
			
			a[j] = a[i];
		}
		a[i] = key;
		rec_quick(a,left,i-1);
		rec_quick(a,i+1,right);
	}
}

void quick_sort(int a[]){
	int i,j;
	i = 0; j = 7;
	rec_quick(a,i,j);
}



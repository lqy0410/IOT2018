�ֽ⣺�Ȱ�������м�ֿ����ֵ�ֻ��һ��Ԫ��

�ϲ����ϲ���ʱ���������ֽ��бȽϣ���������

�ؼ����ϲ�������

�Ϳ��������෴ 


#include<stdio.h>
#include<stdlib.h>

int comeIn(int a[],int n,int mark);
void Merge(int left, int right ,int center ,int *temArray,int a[]);
void rec_Sort(int a[],int *temArray,int left,int right);
 
int main()
{
	int left,right;
	int a[20];
	int n,j,mark,i;
	n = 0;
	n = comeIn(a,j,mark);
	int *temArray = (int *)malloc(sizeof(int) *n);
	left = 0;right = n-1;
	rec_Sort(a,temArray,left,right);

	for(i = 0;i <= n - 1;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}


int comeIn(int a[],int n,int mark)
{
	printf("������һЩ���֣�����-999�������˳����Ϊ�������ǽ�����������:\n");
	scanf("%d",&mark);
	while(mark != -999)
	{
		a[n++] = mark;
		scanf("%d",&mark);
	}
	return n;
}

void Merge(int left, int right ,int center ,int *temArray,int a[])
{
	int p,q;
	int r = 0;
	p = left;
	q = center + 1;
	while(p <= center && q <= right)
	{
		if(a[p] > a[q])
		{
			temArray[r++] = a[q++];
		}
		else
		{
			temArray[r++] = a[p++];
		}
	}
	while(p <= center)
	{
		temArray[r++] = a[p++];
	}
	while(q <= right)
	{
		temArray[r++] = a[q++];
	}
	for(int i = 0;i <= right - left;i++)
	{
		a[left + i] = temArray[i];
	}
}

void rec_Sort(int a[],int *temArray,int left,int right)
{
	int center;
	if(right > left)
	{
		center = left + (right - left) / 2;
		rec_Sort(a,temArray,left,center);
		rec_Sort(a,temArray,center + 1,right);
		Merge(left,right,center,temArray,a);
	}
}



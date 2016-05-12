#pragma once
#include <iostream>
#include <assert.h>
#include <time.h>
using namespace std;

//������(ѡ������)
void AdjustDown(int a[],int parent,int size)
{
	assert(a);
	int child = 2*parent+1;
	while(child < size)
	{
		if(child+1 < size && a[child+1] > a[child])
		{
			++child;
		}
		if(a[child] > a[parent])
		{
			swap(a[child],a[parent]);
			parent = child;
			child = 2*parent+1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int a[],int size) 
{
	assert(a);
	//����
	for(int i=(size-2)/2;i>=0;--i)
	{
		AdjustDown(a,i,size);  //�����
	}

	//ѡ�����ķŵ�ĩβ����ʣ���ҵ�����
	for(int i=0;i<size;i++)
	{
		swap(a[0],a[size-1-i]);
		AdjustDown(a,0,size-1-i);
	}
}


void TestHeapSort()
{
	int a[] = {10,16,18,12,11,13,15,17,14,19};
	int size = sizeof(a)/sizeof(a[0]);
	HeapSort(a,size);	
}




//��1000����������ǰk����

const int N = 1000;
const int K = 100;

void AdjustDown(int topK[],int parent) //��С��
{
	int child = 2*parent+1;
	while(child < K)
	{
		if(child+1 < K && topK[child+1] < topK[child])
		{
			++child;
		}
		if(topK[child] < topK[parent])
		{
			swap(topK[child],topK[parent]);
			parent = child;
			child = 2*parent+1;
		}
		else
		{
			break;
		}
	}
}
void GetTopK(int a[],int topK[])
{
	assert(a);
	int i = 0;
	for(i=0;i<K;++i) //��a��ǰK��Ԫ�ط���������
	{
		topK[i] = a[i];
	}
	for(i=(K-2)/2;i>=0;--i)//��ǰK��Ԫ�ؽ�С��
	{
		AdjustDown(topK,i);
	}
	for(i=K;i<N;++i)
	{
		if(a[i] > topK[0]) //��K��Ԫ��֮���ÿ��Ԫ�غͶѵĵ�һ��Ԫ��(��СԪ��)�Ƚ�
		{
			swap(a[i],topK[0]);//���ȵ�һ��Ԫ�ش��򽻻�
			AdjustDown(topK,0);//���¶����½�С��
		}
	}
}

void Test()
{
	int topK[K];
	int a[N];
	srand(time(0)); //���������
	for(int i=0;i<N;++i)
	{
		a[i] = rand(); //�����
	}
	GetTopK(a,topK);
	for(int i=0;i<K;i++)
	{
		cout<<topK[i]<<" ";
	}
}

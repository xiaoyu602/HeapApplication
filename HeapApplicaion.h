#pragma once
#include <iostream>
#include <assert.h>
#include <time.h>
using namespace std;

//堆排序(选择排序)
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
	//建堆
	for(int i=(size-2)/2;i>=0;--i)
	{
		AdjustDown(a,i,size);  //建大堆
	}

	//选择最大的放到末尾，从剩下找到最大的
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




//找1000个数中最大的前k个数

const int N = 1000;
const int K = 100;

void AdjustDown(int topK[],int parent) //建小堆
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
	for(i=0;i<K;++i) //将a的前K个元素放入数组中
	{
		topK[i] = a[i];
	}
	for(i=(K-2)/2;i>=0;--i)//对前K个元素建小堆
	{
		AdjustDown(topK,i);
	}
	for(i=K;i<N;++i)
	{
		if(a[i] > topK[0]) //将K个元素之后的每个元素和堆的第一个元素(最小元素)比较
		{
			swap(a[i],topK[0]);//若比第一个元素大，则交换
			AdjustDown(topK,0);//对新堆重新建小堆
		}
	}
}

void Test()
{
	int topK[K];
	int a[N];
	srand(time(0)); //随机数种子
	for(int i=0;i<N;++i)
	{
		a[i] = rand(); //随机数
	}
	GetTopK(a,topK);
	for(int i=0;i<K;i++)
	{
		cout<<topK[i]<<" ";
	}
}

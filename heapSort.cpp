#include<string>
#include<iostream>
#include "heap.h"

typedef struct Task{
	int priority;
}Task;
typedef Task DataType;
//宏函数
#define isLess(a,b) (a.priority<b.priority)

typedef struct PriorityQueue
{
	DataType* arr;	//存储元素的数组
	int size;		//当前已存储的元素个数
	int capacity;	//当前存储的容量
}PriorityQueue;

bool init(PriorityQueue &pq,DataType *orginal,int size);
bool pop(PriorityQueue &pq,DataType &value);
bool isEmpty(PriorityQueue &pq);
bool isFull(PriorityQueue &pq);
bool destroy(PriorityQueue &pq);
void HeapSort(PriorityQueue &heap);

static void build(PriorityQueue &pq);
static void buildDown(PriorityQueue &pq,int index);
//初始化堆
bool init(PriorityQueue &heap,DataType *orginal,int size)
{
	heap.arr=orginal;
	if(!heap.arr) return false;

	heap.capacity=size;
	heap.size=size;

	//若果存在数据则构建堆
	if(size>0)
	{
		memcpy(heap.arr,orginal,sizeof(heap.arr[0])*size);
		heap.size=size;
		build(heap);
	}
	return true;
}
//建堆
static void build(PriorityQueue &heap)
{
	int i;
	//从最后一个父节点开始建堆
	for(i=heap.size/2-1;i>=0;i--)
	{
		buildDown(heap,i);
	}
}
//向下建堆
static void buildDown(PriorityQueue &heap,int index)
{
	DataType cur=heap.arr[index];
	int parent,child;

	for(parent=index;(parent*2+1)<heap.size;parent=child)
	{
		child=parent*2+1;	//左子节点
		//取两个子节点中的较大节点
		if(child+1<heap.size&&isLess(heap.arr[child],heap.arr[child+1]))
		{
			child++;
		}
		//判断较大节点是否大于当前的父节点
		if(isLess(heap.arr[child],cur))
		{
			break;
		}
		else	//子节点大于父节点则交换
		{
			heap.arr[parent]=heap.arr[child];
			heap.arr[child]=cur;
		}
	}
}

//最大元素出队
bool pop(PriorityQueue &heap,DataType &value)
{
	if(isEmpty(heap)) return false;

	value=heap.arr[0];
	heap.arr[0]=heap.arr[--heap.size];
	buildDown(heap,0);
	return true;
}

//堆排序 升序排列
void HeapSort(PriorityQueue &heap)
{
	if(heap.size<1) return;
	DataType tmp;
	//把最大的换到堆的最后面
	while(heap.size>0)
	{
		tmp=heap.arr[0];
		heap.arr[0]=heap.arr[heap.size-1];
		heap.arr[heap.size-1]=tmp;
		heap.size--;
		buildDown(heap,0);
	}
}
//判断队列是否为空
bool isEmpty(PriorityQueue &pq)
{
	if(pq.size<1) return true;
	return false;
}
//判断优先队列是否为满
bool isFull(PriorityQueue &pq)
{
	if(pq.size<pq.capacity) return false;
	return true;
}
//销毁堆
bool destroy(PriorityQueue &pq)
{
	if(pq.arr) delete pq.arr;
	return true;
}
int main()
{
	PriorityQueue  hp;
	//对成员变量赋值
	DataType origVal[]={1,2,3,87,93,82,92,86,95};
	if(!init(hp,origVal,sizeof(origVal)/sizeof(origVal[0])))
	{
		fprintf(stderr,"初始化堆失败!");
		exit(-1);
	}
	for(int i=0;i<hp.size;i++)
	{
		printf("the %dth element:%d\n",i,hp.arr[i]);
	}
	printf("\n");
	
	HeapSort(hp);
	for(int j=0;j<sizeof(origVal)/sizeof(origVal[0]);j++)
	{
		printf("%d ",origVal[j]);
	}
	system("pause");
	return 0;
}
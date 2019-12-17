#include<string>
#include<iostream>
#include "heap.h"
#define DEFAULT_CAPCITY 128
typedef struct Task{
	int priority;
};
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
bool push(PriorityQueue &pq,DataType value);
bool pop(PriorityQueue &pq,DataType &value);
bool isEmpty(PriorityQueue &pq);
bool isFull(PriorityQueue &pq);
bool destroy(PriorityQueue &pq);

static void build(PriorityQueue &pq);
static void buildDown(PriorityQueue &pq,int index);
static void buildUp(PriorityQueue &pq,int index);
//初始化堆
bool init(PriorityQueue &heap,DataType *orginal,int size)
{
	int capacity=DEFAULT_CAPCITY>size?DEFAULT_CAPCITY:size;

	heap.arr=new DataType[capacity];	//动态内存分配
	if(!heap.arr) return false;

	heap.capacity=capacity;
	heap.size=0;

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

//插入元素
bool push(PriorityQueue &heap,DataType value)
{
	if(isFull(heap))
	{
		fprintf(stderr,"栈空间耗尽！\n");
		return false;
	}
	//往最后插入元素
	int index=heap.size;
	heap.arr[heap.size++]=value;
	buildUp(heap,index);
	return true;
}
//向上建堆
void buildUp(PriorityQueue &heap,int index)
{
	if(index<0||index>=heap.size)  return;

	while(index>0)
	{
		DataType temp=heap.arr[index];
		int parent=(index-1)/2;

		if(parent>=0)	//不是根节点
		{
			if(isLess(heap.arr[parent],temp))	//父节点小于当前节点
			{
				heap.arr[index]=heap.arr[parent];
				heap.arr[parent]=temp;
				index=parent;
			}
			else	//父节点大于当前节点不用交换
			{
				break;
			}
		}
		else	//是根节点
		{
			break;
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

	//插入元素
	DataType tmp={88};
	push(hp,tmp);
	for(int i=0;i<hp.size;i++)
	{
		printf("the %dth element:%d\n",i,hp.arr[i]);
	}
	printf("\n");

	//堆中元素出列
	DataType value;
	while(pop(hp,value))
	{
		printf(" %d",value.priority);
	}
	destroy(hp);
	system("pause");
	return 0;
}
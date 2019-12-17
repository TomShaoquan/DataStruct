#include<string>
#include<iostream>
#include "heap.h"

typedef struct Task{
	int priority;
}Task;
typedef Task DataType;
//�꺯��
#define isLess(a,b) (a.priority<b.priority)

typedef struct PriorityQueue
{
	DataType* arr;	//�洢Ԫ�ص�����
	int size;		//��ǰ�Ѵ洢��Ԫ�ظ���
	int capacity;	//��ǰ�洢������
}PriorityQueue;

bool init(PriorityQueue &pq,DataType *orginal,int size);
bool pop(PriorityQueue &pq,DataType &value);
bool isEmpty(PriorityQueue &pq);
bool isFull(PriorityQueue &pq);
bool destroy(PriorityQueue &pq);
void HeapSort(PriorityQueue &heap);

static void build(PriorityQueue &pq);
static void buildDown(PriorityQueue &pq,int index);
//��ʼ����
bool init(PriorityQueue &heap,DataType *orginal,int size)
{
	heap.arr=orginal;
	if(!heap.arr) return false;

	heap.capacity=size;
	heap.size=size;

	//�������������򹹽���
	if(size>0)
	{
		memcpy(heap.arr,orginal,sizeof(heap.arr[0])*size);
		heap.size=size;
		build(heap);
	}
	return true;
}
//����
static void build(PriorityQueue &heap)
{
	int i;
	//�����һ�����ڵ㿪ʼ����
	for(i=heap.size/2-1;i>=0;i--)
	{
		buildDown(heap,i);
	}
}
//���½���
static void buildDown(PriorityQueue &heap,int index)
{
	DataType cur=heap.arr[index];
	int parent,child;

	for(parent=index;(parent*2+1)<heap.size;parent=child)
	{
		child=parent*2+1;	//���ӽڵ�
		//ȡ�����ӽڵ��еĽϴ�ڵ�
		if(child+1<heap.size&&isLess(heap.arr[child],heap.arr[child+1]))
		{
			child++;
		}
		//�жϽϴ�ڵ��Ƿ���ڵ�ǰ�ĸ��ڵ�
		if(isLess(heap.arr[child],cur))
		{
			break;
		}
		else	//�ӽڵ���ڸ��ڵ��򽻻�
		{
			heap.arr[parent]=heap.arr[child];
			heap.arr[child]=cur;
		}
	}
}

//���Ԫ�س���
bool pop(PriorityQueue &heap,DataType &value)
{
	if(isEmpty(heap)) return false;

	value=heap.arr[0];
	heap.arr[0]=heap.arr[--heap.size];
	buildDown(heap,0);
	return true;
}

//������ ��������
void HeapSort(PriorityQueue &heap)
{
	if(heap.size<1) return;
	DataType tmp;
	//�����Ļ����ѵ������
	while(heap.size>0)
	{
		tmp=heap.arr[0];
		heap.arr[0]=heap.arr[heap.size-1];
		heap.arr[heap.size-1]=tmp;
		heap.size--;
		buildDown(heap,0);
	}
}
//�ж϶����Ƿ�Ϊ��
bool isEmpty(PriorityQueue &pq)
{
	if(pq.size<1) return true;
	return false;
}
//�ж����ȶ����Ƿ�Ϊ��
bool isFull(PriorityQueue &pq)
{
	if(pq.size<pq.capacity) return false;
	return true;
}
//���ٶ�
bool destroy(PriorityQueue &pq)
{
	if(pq.arr) delete pq.arr;
	return true;
}
int main()
{
	PriorityQueue  hp;
	//�Գ�Ա������ֵ
	DataType origVal[]={1,2,3,87,93,82,92,86,95};
	if(!init(hp,origVal,sizeof(origVal)/sizeof(origVal[0])))
	{
		fprintf(stderr,"��ʼ����ʧ��!");
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
#include<string>
#include<iostream>
#include "heap.h"
#define DEFAULT_CAPCITY 128
typedef struct Task{
	int priority;
};
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
bool push(PriorityQueue &pq,DataType value);
bool pop(PriorityQueue &pq,DataType &value);
bool isEmpty(PriorityQueue &pq);
bool isFull(PriorityQueue &pq);
bool destroy(PriorityQueue &pq);

static void build(PriorityQueue &pq);
static void buildDown(PriorityQueue &pq,int index);
static void buildUp(PriorityQueue &pq,int index);
//��ʼ����
bool init(PriorityQueue &heap,DataType *orginal,int size)
{
	int capacity=DEFAULT_CAPCITY>size?DEFAULT_CAPCITY:size;

	heap.arr=new DataType[capacity];	//��̬�ڴ����
	if(!heap.arr) return false;

	heap.capacity=capacity;
	heap.size=0;

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

//����Ԫ��
bool push(PriorityQueue &heap,DataType value)
{
	if(isFull(heap))
	{
		fprintf(stderr,"ջ�ռ�ľ���\n");
		return false;
	}
	//��������Ԫ��
	int index=heap.size;
	heap.arr[heap.size++]=value;
	buildUp(heap,index);
	return true;
}
//���Ͻ���
void buildUp(PriorityQueue &heap,int index)
{
	if(index<0||index>=heap.size)  return;

	while(index>0)
	{
		DataType temp=heap.arr[index];
		int parent=(index-1)/2;

		if(parent>=0)	//���Ǹ��ڵ�
		{
			if(isLess(heap.arr[parent],temp))	//���ڵ�С�ڵ�ǰ�ڵ�
			{
				heap.arr[index]=heap.arr[parent];
				heap.arr[parent]=temp;
				index=parent;
			}
			else	//���ڵ���ڵ�ǰ�ڵ㲻�ý���
			{
				break;
			}
		}
		else	//�Ǹ��ڵ�
		{
			break;
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

	//����Ԫ��
	DataType tmp={88};
	push(hp,tmp);
	for(int i=0;i<hp.size;i++)
	{
		printf("the %dth element:%d\n",i,hp.arr[i]);
	}
	printf("\n");

	//����Ԫ�س���
	DataType value;
	while(pop(hp,value))
	{
		printf(" %d",value.priority);
	}
	destroy(hp);
	system("pause");
	return 0;
}
#include<string>
#include<iostream>

#define DEFAULT_CAPCITY 128
typedef struct _Heap
{
	int* arr;	//�洢��Ԫ�ص�����
	int size;		//��ǰ�Ѵ洢��Ԫ�ظ���
	int capacity;	//��ǰ�洢������
}Heap;

static void buildHeap(Heap &heap);
bool insert(Heap &heap,int value);
bool popMax(Heap &heap,int &value);
void adjustUp(Heap &heap,int index);
static void adjustDown(Heap &heap,int index);

bool initHeap(Heap &heap,int *orginal,int size)
{
	int capacity=DEFAULT_CAPCITY>size?DEFAULT_CAPCITY:size;

	heap.arr=new int[capacity];	//��̬�ڴ����
	if(!heap.arr) return false;

	heap.capacity=capacity;
	heap.size=0;

	//�������������򹹽���
	if(size>0)
	{
		memcpy(heap.arr,orginal,sizeof(int)*size);
		heap.size=size;
		buildHeap(heap);
	}
	return true;
}

static void buildHeap(Heap &heap)
{
	int i;
	for(i=heap.size/2-1;i>=0;i--)
	{
		adjustDown(heap,i);
	}
}
static void adjustDown(Heap &heap,int index)
{
	int cur=heap.arr[index];
	int parent,child;

	for(parent=index;(parent*2+1)<heap.size;parent=child)
	{
		child=parent*2+1;	//���ӽڵ�
		//ȡ�����ӽڵ��еĽϴ�ڵ�
		if((child+1)<heap.size&&(heap.arr[child]<heap.arr[child+1]))
		{
			child++;
		}
		//�жϽϴ�ڵ��Ƿ���ڵ�ǰ�ĸ��ڵ�
		if(cur>=heap.arr[child])
		{
			break;
		}
		else
		{
			heap.arr[parent]=heap.arr[child];
			heap.arr[child]=cur;
		}
	}
}


bool insert(Heap &heap,int value)
{
	if(heap.size==heap.capacity)
	{
		fprintf(stderr,"ջ�ռ�ľ���\n");
		return false;
	}
	int index=heap.size;
	heap.arr[heap.size++]=value;
	adjustUp(heap,index);
	return true;
}

void adjustUp(Heap &heap,int index)
{
	if(index<0||index>=heap.size)  return;

	while(index>0)
	{
		int temp=heap.arr[index];
		int parent=(index-1)/2;

		if(parent>=0)
		{
			if(temp>heap.arr[parent])
			{
				heap.arr[index]=heap.arr[parent];
				heap.arr[parent]=temp;
				index=parent;
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
}

bool popMax(Heap &heap,int &value)
{
	if(heap.size<1) return false;

	value=heap.arr[0];
	heap.arr[0]=heap.arr[--heap.size];
	adjustDown(heap,0);
	return true;
}

int main()
{
	Heap  hp;
	int origVal[]={1,2,3,87,93,82,92,86,95};
	if(!initHeap(hp,origVal,sizeof(origVal)/sizeof(int)))
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
	insert(hp,99);
	for(int i=0;i<hp.size;i++)
	{
		printf("the %dth element:%d\n",i,hp.arr[i]);
	}
	printf("\n");

	//����Ԫ�س���
	int value;
	while(popMax(hp,value))
	{
		printf(" %d",value);
	}
	system("pause");
	return 0;
}
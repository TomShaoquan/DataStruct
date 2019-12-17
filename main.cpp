#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#define MaxSize 5
typedef int DataType;
using namespace std;
//定义数据结构
typedef struct Quene
{
	DataType queue[MaxSize];
	int front;		//队头指针
	int rear;		//队尾指针
}SeqQueue;

//初始化队列
void InitQueue(SeqQueue *SQ)
{
	SQ->front=SQ->rear=0;
}

//判断队列是否为空
int IsEmpty(SeqQueue *SQ)
{
	if(SQ->front==SQ->rear)
	{
		return 1;
	}
	return 0;
}

//判断队列是否为满
int IsFull(SeqQueue *SQ)
{
	if(SQ->rear==MaxSize)
	{
		return 1;
	}
	return 0;
}

//入队，将元素插入队列中
int EnterQueue(SeqQueue *SQ,DataType data)
{
	if(IsFull(SQ))
	{
		cout<<"队列已满"<<endl;
		return 0;
	}
	SQ->queue[SQ->rear]=data;
	SQ->rear++;
}


//出列
int DeleteQueue(SeqQueue *SQ,DataType *data)
{
	if(!SQ||IsEmpty(SQ))
	{
		cout<<"队列为空"<<endl;
		return 0;
	}
	if(!data) return 0;
	*data=SQ->queue[SQ->front];

	for(int i=SQ->front+1;i<SQ->rear;i++)
	{
		SQ->queue[i-1]=SQ->queue[i];
	}
	SQ->rear--;
	return 1;
}

int DeleteQueue2(SeqQueue *SQ,DataType *data)
{
	if(!SQ||IsEmpty(SQ))
	{
		cout<<"队列为空"<<endl;
		return 0;
	}
	if(!data) return 0;
	if(SQ->front==MaxSize)
	{
		cout<<"队列已到尽头"<<endl;
	}
	*data=SQ->queue[SQ->front];

	*data=SQ->queue[SQ->front];
	SQ->front=SQ->front+1;
	return 1;
}
//打印
void PrintQueue(SeqQueue *SQ)
{
	if(!SQ) return ;
	int i=SQ->front;
	while(i<SQ->rear)
	{
		cout<<SQ->queue[i]<<"\t";
		i++;
	}
	cout<<endl;
}
int  GetHead(SeqQueue *SQ,DataType *data)
{
	
	if(!SQ||IsEmpty(SQ))
	{
		cout<<"队列为空"<<endl;
	}
	return *data=SQ->queue[SQ->front];
}

 void ClearQueue(SeqQueue *SQ)
 {
	 if(!SQ) return ;
	 SQ->front=SQ->rear=0;
 }

 int GetLength(SeqQueue *SQ)
 {
	 if(!SQ) return 0;
	 return (SQ->rear)-(SQ->front);
 }
 
int main()
{
	SeqQueue *SQ=new SeqQueue;
	DataType data;
	InitQueue(SQ);

	for(int j=0;j<7;j++)
	{
		EnterQueue(SQ,j+1);
	}
	PrintQueue(SQ);
	for(int k=0;k<10;k++)
	{
		DeleteQueue2(SQ,&data);
		cout<<"出队元素："<<data<<endl;
	}
	GetHead(SQ,&data);
	cout<<data<<endl;
	PrintQueue(SQ);
	cout<<"元素个数"<<GetLength(SQ)<<endl;
	ClearQueue(SQ);
	system("pause");
	return 0;
}
#include"queue.h"

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
	if((SQ->rear+1)%MaxSize==SQ->front)
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
	SQ->rear=(SQ->rear+1)%MaxSize;	//队尾指针循环后移一位
	return 1;
}


//出列
int DeleteQueue(SeqQueue *SQ,DataType *data)
{
	if(!SQ||IsEmpty(SQ))
	{
		cout<<"队列为空"<<endl;
		return 0;
	}
	*data=SQ->queue[SQ->front];
	SQ->front=(SQ->front+1)%MaxSize;
	
	return 1;
}


//打印
void PrintQueue(SeqQueue *SQ)
{
	if(!SQ) return ;
	int i=SQ->front;
	while(i!=SQ->rear)
	{
		cout<<SQ->queue[i]<<"\t";
		i=(i+1)%MaxSize;
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
	 return (SQ->rear-SQ->front+MaxSize)%MaxSize;
 }

 void desQueue(SeqQueue *SQ)
 {

 }
 

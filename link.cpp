#include<iostream>
#include<stdlib.h>

using namespace std;

#define MaxSize 5
typedef int DataType;

typedef struct QNode	//节点
{
	DataType data;
	struct QNode *next;  //和自己相同类型的结构
}QNode;

typedef QNode * QueuePtr;

typedef struct Queue
{
	int length;			//队列长度
	QueuePtr front;		//队头指针
	QueuePtr rear;		//队尾指针
}LinkQueue;

//初始化队列
void InitQueue(LinkQueue* LQ)
{
	if(!LQ) return ;
	LQ->length=0;
	LQ->front=LQ->rear=NULL;
}

//判断是否为空
int IsEmpty(LinkQueue* LQ)
{
	if(!LQ) return 0;
	if(LQ->front==NULL)
	{
		return 1;
	}
	return 0;
}

int IsFull(LinkQueue* LQ)
{
	if(!LQ) return 0;
	if(LQ->length==MaxSize)
	{
		return 1;
	}
	return 0;
}

//入队
int EnterQueue(LinkQueue* LQ,DataType data)
{
	if(!LQ) return 0;
	if(IsFull(LQ))
	{
		cout<<"无法插入元素"<<data<<"队列已满"<<endl;
		return 0;
	}

	QNode *qNode=new QNode;
	qNode->data=data;
	qNode->next=NULL;

	if(IsEmpty(LQ))		//空队列
	{
		LQ->front=LQ->rear=qNode;
	}
	else 
	{
		LQ->rear->next=qNode;	//在队列尾部插入节点
		LQ->rear=qNode;			//队尾指向新插入的节点
	}
	LQ->length++;
}

//出队
int DeleteQueue(LinkQueue *LQ,DataType* data)
{
	QNode* temp=NULL;
	if(!LQ||IsEmpty(LQ)) 
	{
		cout<<"队列为空"<<endl;
		return 0;
	}
	if(!data) return 0;
	temp=LQ->front;

	LQ->front=temp->next;
	if(!LQ->front) LQ->rear=NULL;  //对头出列后不存在其他元素

	*data=temp->data;
	LQ->length--;

	delete temp;
}

void PrintQueue(LinkQueue* LQ)
{
	QueuePtr tmp;
	if(!LQ) return;
	if(LQ->front->next==NULL)
	{
		cout<<"队列为空"<<endl;
		return;
	}
	tmp=LQ->front;
	while(tmp)
	{
		cout<<tmp->data<<"\t";
		tmp=tmp->next;
	}
	cout<<endl;
}

int GetHead(LinkQueue* LQ,DataType* data)
{
	if(!LQ||IsEmpty(LQ))
	{
		cout<<"队列为空"<<endl;
		return 0;
	}
	if(!data) return 0;
	*data=LQ->front->data;
	return 1;
}

void ClearQueue(LinkQueue* LQ)
{
	QueuePtr tmp;
	if(!LQ) return;
	while(LQ->front)
	{
		tmp=LQ->front->next;
		delete LQ->front;
		LQ->front=tmp;
	}
	LQ->front=LQ->rear=0;
	LQ->length=0;
}

int GetLength(LinkQueue* LQ)
{
	if(LQ) return 0;
	return LQ->length;
}


int main()
{
	LinkQueue* LQ=new LinkQueue;
	DataType data=-1;

	InitQueue(LQ);

	for(int i=0;i<7;i++)
	{
		EnterQueue(LQ,i);
	}
	cout<<"队列中的元素"<<GetLength(LQ)<<endl;
	PrintQueue(LQ);
	cout<<endl;

	if(DeleteQueue(LQ,&data))
	{
		cout<<"出队元素是"<<data<<endl;
	}
	else
	{
		cout<<"出队失败"<<endl;
	}

	PrintQueue(LQ);

	cout<<endl;

	cout<<"清空队列"<<endl;
	ClearQueue(LQ);
	PrintQueue(LQ);
	system("pause");
	return 0;
}
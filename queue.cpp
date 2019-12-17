#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<assert.h>

using namespace std;

#define MaxSize 1000

typedef struct QNode	//任务节点的结构
{
	int					id;					//数据
	void				(*handler)(void);		//数据
	struct QNode*		next;			//和自己相同类型的结构
}QNode;

typedef QNode * QueuePtr;

typedef struct Queue
{
	int			length;			//队列长度
	QueuePtr	front;		//队头指针
	QueuePtr	rear;		//队尾指针
}LinkQueue;


QueuePtr thread_task_alloc()
{
	QNode* task;

	task=(QNode* )calloc(1,sizeof(QNode));
	if(task==NULL)
		return NULL;
	return task;
}
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
int EnterQueue(LinkQueue* LQ,QNode* node)
{
	if(!LQ||!node) return 0;
	if(IsFull(LQ))
	{
		cout<<"无法插入元素"<<node->id<<"队列已满"<<endl;
		return 0;
	}

	node->next=NULL;

	if(IsEmpty(LQ))		//空队列
	{
		LQ->front=LQ->rear=node;
	}
	else 
	{
		LQ->rear->next=node;	//在队列尾部插入节点
		LQ->rear=node;			//队尾指向新插入的节点
	}
	LQ->length++;
}

//出队
QNode* DeleteQueue(LinkQueue *LQ)
{
	QNode* temp=NULL;
	if(!LQ||IsEmpty(LQ)) 
	{
		cout<<"队列为空"<<endl;
		return 0;
	}

	temp=LQ->front;

	LQ->front=temp->next;//头节点指向后一位
	if(!LQ->front) LQ->rear=NULL;  //对头出列后不存在其他元素

	
	LQ->length--;

	return temp;
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
		cout<<setw(4)<<tmp->id;
		tmp=tmp->next;
	}
	cout<<endl;
}

int GetLength(LinkQueue* LQ)
{
	if(LQ) return 0;
	return LQ->length;
}

void task1()
{
	cout<<"肚子好饿哦！"<<endl;
}
void task2()
{
	cout<<"我要吃饭了"<<endl;
}
int main()
{
	LinkQueue* LQ=new LinkQueue;
	QNode* task=NULL;

	InitQueue(LQ);

	//任务1入队
	task=thread_task_alloc();
	task->id=1;
	task->handler=&task1;
	EnterQueue(LQ,task);

	//任务2入队
	task=thread_task_alloc();
	task->id=2;
	task->handler=&task2;
	EnterQueue(LQ,task);

	cout<<"队列中的元素"<<GetLength(LQ)<<endl;
	PrintQueue(LQ);
	cout<<endl;
	//执行任务
	while((task=DeleteQueue(LQ)))
	{
		task->handler();
		delete task;
	}

	delete LQ;
	system("pause");
	return 0;
}

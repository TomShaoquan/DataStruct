#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<assert.h>

using namespace std;

#define MaxSize 1000

typedef struct QNode	//����ڵ�Ľṹ
{
	int					id;					//����
	void				(*handler)(void);		//����
	struct QNode*		next;			//���Լ���ͬ���͵Ľṹ
}QNode;

typedef QNode * QueuePtr;

typedef struct Queue
{
	int			length;			//���г���
	QueuePtr	front;		//��ͷָ��
	QueuePtr	rear;		//��βָ��
}LinkQueue;


QueuePtr thread_task_alloc()
{
	QNode* task;

	task=(QNode* )calloc(1,sizeof(QNode));
	if(task==NULL)
		return NULL;
	return task;
}
//��ʼ������
void InitQueue(LinkQueue* LQ)
{
	if(!LQ) return ;
	LQ->length=0;
	LQ->front=LQ->rear=NULL;
}

//�ж��Ƿ�Ϊ��
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

//���
int EnterQueue(LinkQueue* LQ,QNode* node)
{
	if(!LQ||!node) return 0;
	if(IsFull(LQ))
	{
		cout<<"�޷�����Ԫ��"<<node->id<<"��������"<<endl;
		return 0;
	}

	node->next=NULL;

	if(IsEmpty(LQ))		//�ն���
	{
		LQ->front=LQ->rear=node;
	}
	else 
	{
		LQ->rear->next=node;	//�ڶ���β������ڵ�
		LQ->rear=node;			//��βָ���²���Ľڵ�
	}
	LQ->length++;
}

//����
QNode* DeleteQueue(LinkQueue *LQ)
{
	QNode* temp=NULL;
	if(!LQ||IsEmpty(LQ)) 
	{
		cout<<"����Ϊ��"<<endl;
		return 0;
	}

	temp=LQ->front;

	LQ->front=temp->next;//ͷ�ڵ�ָ���һλ
	if(!LQ->front) LQ->rear=NULL;  //��ͷ���к󲻴�������Ԫ��

	
	LQ->length--;

	return temp;
}

void PrintQueue(LinkQueue* LQ)
{
	QueuePtr tmp;
	if(!LQ) return;
	if(LQ->front->next==NULL)
	{
		cout<<"����Ϊ��"<<endl;
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
	cout<<"���Ӻö�Ŷ��"<<endl;
}
void task2()
{
	cout<<"��Ҫ�Է���"<<endl;
}
int main()
{
	LinkQueue* LQ=new LinkQueue;
	QNode* task=NULL;

	InitQueue(LQ);

	//����1���
	task=thread_task_alloc();
	task->id=1;
	task->handler=&task1;
	EnterQueue(LQ,task);

	//����2���
	task=thread_task_alloc();
	task->id=2;
	task->handler=&task2;
	EnterQueue(LQ,task);

	cout<<"�����е�Ԫ��"<<GetLength(LQ)<<endl;
	PrintQueue(LQ);
	cout<<endl;
	//ִ������
	while((task=DeleteQueue(LQ)))
	{
		task->handler();
		delete task;
	}

	delete LQ;
	system("pause");
	return 0;
}

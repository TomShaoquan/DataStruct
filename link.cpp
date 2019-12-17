#include<iostream>
#include<stdlib.h>

using namespace std;

#define MaxSize 5
typedef int DataType;

typedef struct QNode	//�ڵ�
{
	DataType data;
	struct QNode *next;  //���Լ���ͬ���͵Ľṹ
}QNode;

typedef QNode * QueuePtr;

typedef struct Queue
{
	int length;			//���г���
	QueuePtr front;		//��ͷָ��
	QueuePtr rear;		//��βָ��
}LinkQueue;

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
int EnterQueue(LinkQueue* LQ,DataType data)
{
	if(!LQ) return 0;
	if(IsFull(LQ))
	{
		cout<<"�޷�����Ԫ��"<<data<<"��������"<<endl;
		return 0;
	}

	QNode *qNode=new QNode;
	qNode->data=data;
	qNode->next=NULL;

	if(IsEmpty(LQ))		//�ն���
	{
		LQ->front=LQ->rear=qNode;
	}
	else 
	{
		LQ->rear->next=qNode;	//�ڶ���β������ڵ�
		LQ->rear=qNode;			//��βָ���²���Ľڵ�
	}
	LQ->length++;
}

//����
int DeleteQueue(LinkQueue *LQ,DataType* data)
{
	QNode* temp=NULL;
	if(!LQ||IsEmpty(LQ)) 
	{
		cout<<"����Ϊ��"<<endl;
		return 0;
	}
	if(!data) return 0;
	temp=LQ->front;

	LQ->front=temp->next;
	if(!LQ->front) LQ->rear=NULL;  //��ͷ���к󲻴�������Ԫ��

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
		cout<<"����Ϊ��"<<endl;
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
		cout<<"����Ϊ��"<<endl;
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
	cout<<"�����е�Ԫ��"<<GetLength(LQ)<<endl;
	PrintQueue(LQ);
	cout<<endl;

	if(DeleteQueue(LQ,&data))
	{
		cout<<"����Ԫ����"<<data<<endl;
	}
	else
	{
		cout<<"����ʧ��"<<endl;
	}

	PrintQueue(LQ);

	cout<<endl;

	cout<<"��ն���"<<endl;
	ClearQueue(LQ);
	PrintQueue(LQ);
	system("pause");
	return 0;
}
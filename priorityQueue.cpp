#include<iostream>
#include<stdlib.h>

using namespace std;

#define MaxSize 5
typedef int DataType;

typedef struct QNode	//节点
{
	int priority;
	DataType data;
	struct QNode *next;  //和自己相同类型的结构
}QNode;

typedef QNode* QueuePtr;

typedef struct Queue
{
	int length;			//队列长度
	QueuePtr front;		//队头指针
	QueuePtr rear;		//队尾指针
}LinkQueue;

/*
*	初始化队列
*	@param LQ 保存队列元素的结构
*	return 无
*/
void InitQueue(LinkQueue* LQ)
{
	if(!LQ) return ;
	LQ->length=0;
	LQ->front=LQ->rear=NULL;
}
/*
*	判断队列是否为空
*	@param LQ 保存队列元素的结构
*	return 1 if empty else return 0
*/
int IsEmpty(LinkQueue* LQ)
{
	if(!LQ) return 0;
	if(LQ->front==NULL)
	{
		return 1;
	}
	return 0;
}
/*
*	判断队列是否满
*	@param LQ 保存队列元素的结构
*	return 1 if full else return 0
*/
int IsFull(LinkQueue* LQ)
{
	if(!LQ) return 0;
	if(LQ->length==MaxSize)
	{
		return 1;
	}
	return 0;
}

/*
*	入队一个元素data
*	@param LQ 保存队列元素的结构
*	@param data 要插入的元素
*	return 1 if empty else return 0
*/
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

/*
*	出队一个元素data
*	@param LQ 保存队列元素的结构
*	@param data 要出队的元素
*	return 1 if success else return 0
*/
int DeleteQueue(LinkQueue *LQ,DataType* data)
{
	QNode **prev=NULL,*prev_node=NULL;
	QNode* last=NULL,*tmp=NULL; 
	if(!LQ||IsEmpty(LQ)) 
	{
		cout<<"队列为空"<<endl;
		return 0;
	}
	if(!data) return 0;
	prev=&(LQ->front);
	printf("第一个节点的优先级：%d\n",(*prev)->priority);
	last=LQ->front;
	tmp=last->next;
	if(!LQ->front) LQ->rear=NULL;  //对头出列后不存在其他元素

	while(tmp)
	{
		if(tmp->priority>(*prev)->priority)
		{
			printf("抓到一个更大优先级的节点[priority:%d]",tmp->priority);
			prev=&(last->next);
			prev_node=last;
		}
		last=tmp;
		tmp=tmp->next;
	}

	*data=(*prev)->data;
	tmp=*prev;
	*prev=(*prev)->next;
	delete tmp;
	
	LQ->length--;
	return 1;
}
/*
*	打印队列元素的值
*	@param LQ 保存队列元素的结构
*	return 无
*/
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
/*
*	得到对头的元素
*	@param LQ 保存队列元素的结构
*	@param  _in_ data 要出队的元素
*	return 1 if success else return 0
*/
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
/*
*	释放内存
*	@param LQ 保存队列元素的结构
*	return 无
*/
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
/*
*	得到队列长度
*	@param LQ 保存队列元素的结构
*	return 无
*/
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
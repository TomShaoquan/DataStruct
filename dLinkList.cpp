#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

//每个节点保存相同类型的数据
typedef struct LinkNode
{
	int data;
	struct LinkNode* prev;
	struct LinkNode* next;
}LinkNode,LinkList;

//初始化链表
bool InitList(LinkList* &L)
{
	L=new LinkNode;

	if(!L) return false;

	L->next=NULL;
	L->prev=NULL;
	L->data=-1;
	return true;
}

//前插法
bool ListInsert_front(LinkList* &L,LinkNode *node)
{
	if(!L||!node) return false;
	if(L->next)  L->next->prev=node;//插第一个的时候
	node->next=L->next;
	node->prev=L;
	L->next=node;

	return true;
}

//尾插法
bool ListInsert_back(LinkList* &L,LinkNode *node)
{
	LinkNode *last=NULL;

	if(!L||!node) return false;

	last=L;
	//找到最后节点
	while(last->next) last=last->next;

	node->prev=last;
	node->next=NULL;
	last->next=node;

	return true;
}

bool Link_GetElem(LinkList* &L,int i,int &e)
{
	int index;
	LinkList *p;
	if(!L||!L->next) return false;

	p=L->next;
	index=1;
	while(p&&index<i)
	{
		p=p->next;
		index++;
	}
	if(!p||index>i)
	{
		return false;//i值不合法
	}
	e=p->data;
	return true;
}
//单链表的输出
void LinkPrint(LinkList* &L)
{
	LinkNode* p;
	if(!L)
	{
		cout<<"链表为空"<<endl;
		return ;
	}
	p=L;
	while(p->next)
	{//从头接点之后打印
		cout<<p->next->data<<"\t";
		p=p->next;
	}
	cout<<endl;
	//逆向打印
	/*cout<<"逆向打印"<<endl;
	while(p)
	{
		cout<<p->data<<"\t";
		p=p->prev;
	}*/
}
//指定位置插入节点
bool LinkInsert(LinkList* &L,int i,int &e)
{
	if(!L) return false;
	if(i<1) return false;

	int j=0;
	LinkList *p,*s;

	p=L;

	while(p&&j<i)//查找位置为i的节点
	{
		p=p->next;//找到要插入的位置
		j++;
	}

	if(!p ||j!=i)
	{
		cout<<"不存在节点"<<i<<endl;
		return false;
	}
	s=new LinkNode;//生成新节点
	s->data=e;

	s->next=p;
	s->prev=p->prev;

	p->prev->next=s;
	p->prev=s;
	
	
	return true;
}
//按值查找
bool Link_FindElem(LinkList *L,int e,int &index)
{
	LinkList *p;
	p=L->next;
	index=1;
	if(!L||!L->next)
	{
		index=0;
		return false;
	}
	while(p&&p->data!=e)
	{
		p=p->next;
		index++;
	}
	if(!p) return false;//查无此值
	return true;
}
//单链表的删除
bool LinkDelete(LinkList* &L,int i)
{
	LinkList *p,*q;
	int index=0;
	p=L;
	if(!L||!L->next) return false;
	while((p->next)&&index<i-1)
	{
		p=p->next;
		index++;
	}
	//节点不存在
	if(!p->next||index>i-1)
		return false;
	p->prev->next=p->next;
	p->next->prev=p->prev;
	
	delete q;
	return true;
}
void LinkDestroy(LinkList* &L)
{
	LinkList *p=L;
	cout<<"销毁链表"<<endl;
	while(p)
	{
		L=L->next;
		cout<<"删除元素："<<p->data<<endl;
		delete p;
		p=L;
	}
}

int main666()
{
	LinkList *L=NULL;//头
	LinkNode *s;//节点
	//1.初始化一个空链表
	InitList(L);

	//2.使用前插法插入数据
	int n;
	cout<<"请输入插入元素个数：";
	cin>>n;
	cout<<"请依次输入元素："<<endl;

	while(n>0)
	{
		s=new LinkNode;
		cin>>s->data;
		ListInsert_back(L,s);
		n--;
	}
	LinkPrint(L);
	for(int j=0;j<3;j++)
	{
		int i,x;
		cout<<"请输入要插入元素的位置和元素："<<endl;
		cin>>i>>x;
		if(LinkInsert(L,i,x))
		{
			cout<<"插入成功"<<endl;
		}
		else 
		{
			cout<<"插入失败"<<endl;
		}
		LinkPrint(L);
	}
	//3.单链表的输出
	system("pause");
	return 0;
}

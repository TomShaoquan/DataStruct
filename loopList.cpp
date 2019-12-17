#include<iostream>
#include<string>
#include<stdio.h>
#include "star.h"
using namespace std;

//每个节点保存相同类型的数据
typedef struct LinkNode
{
	int data;
	struct LinkNode* next;
}LinkNode,LinkList;
int main2222()
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
	//3.单链表的输出
	LinkPrint(L);
#if 0

	//5.任意位置插入元素
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
	int element=0;
	if(Link_GetElem(L,2,element))
		cout<<"获取第二个元素成功："<<element<<endl;
	else
		cout<<"获取第二个元素失败"<<endl;

	//6.单链表根据位置获取元素
	int index=0;
	if(Link_FindElem(L,10,index))
	{
		cout<<"查找的元素存在"<<index<<endl;
	}
	else
	{
		cout<<"查找的元素不存在"<<endl;
	}
#endif 
	if(LinkDelete(L,2))
	{
		cout<<"删除元素成功"<<endl;
		LinkPrint(L);
	}
	else 
	{
		cout<<"删除元素失败"<<endl;
	}
	LinkDestroy(L);
	system("pause");
	return 0;
}
//初始化链表
bool InitList(LinkList* &L)
{
	L=new LinkNode;

	if(!L) return false;

	L->next=NULL;
	L->data=-1;
	return true;
}

//前插法
bool ListInsert_front(LinkList* &L,LinkNode *node)
{
	if(!L||!node) return false;

	node->next=L->next;
	L->next=node;
	return true;
}

//后插法
bool ListInsert_back(LinkList* &L,LinkNode *node)
{
	LinkNode *last=NULL;

	if(!L||!node) return false;

	last=L;
	while(last->next) last=last->next;

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
	LinkNode* P=NULL;
	if(!L) return;
	P=L->next;

	while(P)
	{
		cout<<P->data<<"\t";
		P=P->next;
	}
	cout<<endl;
}
//指定位置插入节点
bool LinkInsert(LinkList* &L,int i,int &e)
{
	if(!L) return false;
	int j=0;
	LinkList *p,*s;

	p=L;

	while(p&&j<i-1)//查找位置为i-1的节点
	{
		p=p->next;
		j++;
	}

	if(!p ||j>i-1)
	{
		return false;
	}
	s=new LinkNode;//生成新节点
	s->data=e;
	s->next=p->next;
	p->next=s;
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
	if(!p->next||index>i-1)
		return false;
	q=p->next;
	p->next=q->next;
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

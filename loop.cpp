#include<iostream>
#include<stdlib.h>
#include "loop.h"
using namespace std;

//初始化
bool LinkInit(LinkList* L)
{
	L=new LinkList;
	if(!L) return false;
	L->data=-1;
	L->next=NULL;
	return true;
}
bool ListInsert_back(LinkList* &L,LinkNode* node)
{
	LinkNode* last=NULL;
	if(!L||!node) return  false;

	if(L==L->next)//空的循环链表
	{
		node->next=L;
		L->next=node;
	}
	else
	{
		last=L->next;
		while(last->next!=L) last=last->next;

		node->next=L;
		last->next=node;
	}
	return true;

}

bool LinkPrint(LinkList* L)
{
	LinkNode* p=NULL;
	if(!L) return false;
	p=L->next;
	while(p)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
	cout<<endl;
	return true;
}

int main()
{
	LinkList *L=NULL;//头
	LinkNode *s;//节点
	if(LinkInit(L))
	{
		cout<<"初始化链表成功"<<endl;
	}
	else 
	{
		cout<<"初始化链表失败"<<endl;
		exit(-1);
	}

	int i=0;
	while((++i)<=10)
	{
		s=new LinkNode;
		s->data=i;
		s->next=NULL;
		if(ListInsert_back(L,s))
		{
			cout<<"插入成功"<<endl;
		}
		else 
		{
			cout<<"插入失败"<<endl;
		}
	}
	cout<<"尾插法"<<endl;

	system("pause");
	return 0;
}
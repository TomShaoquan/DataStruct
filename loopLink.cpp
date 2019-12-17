#include<iostream>
#include<stdlib.h>
#include "loopLink.h"
using namespace std;

//初始化
bool LinkInit(LinkList* &L)//指针引用
{
	L=new LinkList;//创建一个新的链表
	if(!L) return false;
	L->data=-1;
	L->next=L;//头节点指向自己
	return true;
}
//尾插法
bool ListInsert_back(LinkList* &L,LinkNode* node)
{
	LinkNode* last=NULL;
	if(!L||!node) return  false;

	if(L==L->next)//空的循环链表，头节点保存的是自己
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

void LinkPrint(LinkList* L)
{
	LinkNode* p=NULL;
	if(!L||L==L->next) 
	{
		cout<<"链表为空"<<endl;
			return ;
	}
	p=L->next;
	while(p!=L)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
	cout<<endl;
}


bool Joseph(LinkList* &L,int interval)
{
	LinkList *p,*q;
	int i=0,j=0;
	int times=0,num=0;
	p=L;
	if(!L||p->next==L)
	{
		cout<<"链表为空"<<endl;
		return false;
	}
	if(interval<1)
	{
		cout<<"报数口令不能小于1"<<endl;
		return false;
	}

	do
	{
		i+=interval;
		while(p->next)
		{
			if(p->next!=L) j++;
			if(j>=i) break;
			p=p->next;

		}
		times++;
		q=p->next;
		num=q->data;
		if(times==5)
			cout<<"第五个出圈的编号是："<<num<<endl;
		printf("cur:%d  last:%d   next:%d\n",q->data,p->data,q->next->data);
		p->next=q->next;
		delete q;//释放被删除节点的空间
		LinkPrint(L);

	}while(L->next!=L);
}
int main()
{
	LinkList *L=NULL;//头，初始化要传二级指针
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
	//LinkPrint(L);
	//cout<<"尾插法"<<endl;
	Joseph(L,9);
	system("pause");
	return 0;
}
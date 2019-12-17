#include<iostream>
#include<stdlib.h>
#include "loopLink.h"
using namespace std;

//��ʼ��
bool LinkInit(LinkList* &L)//ָ������
{
	L=new LinkList;//����һ���µ�����
	if(!L) return false;
	L->data=-1;
	L->next=L;//ͷ�ڵ�ָ���Լ�
	return true;
}
//β�巨
bool ListInsert_back(LinkList* &L,LinkNode* node)
{
	LinkNode* last=NULL;
	if(!L||!node) return  false;

	if(L==L->next)//�յ�ѭ������ͷ�ڵ㱣������Լ�
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
		cout<<"����Ϊ��"<<endl;
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
		cout<<"����Ϊ��"<<endl;
		return false;
	}
	if(interval<1)
	{
		cout<<"���������С��1"<<endl;
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
			cout<<"�������Ȧ�ı���ǣ�"<<num<<endl;
		printf("cur:%d  last:%d   next:%d\n",q->data,p->data,q->next->data);
		p->next=q->next;
		delete q;//�ͷű�ɾ���ڵ�Ŀռ�
		LinkPrint(L);

	}while(L->next!=L);
}
int main()
{
	LinkList *L=NULL;//ͷ����ʼ��Ҫ������ָ��
	LinkNode *s;//�ڵ�
	if(LinkInit(L))
	{
		cout<<"��ʼ������ɹ�"<<endl;
	}
	else 
	{
		cout<<"��ʼ������ʧ��"<<endl;
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
			cout<<"����ɹ�"<<endl;
		}
		else 
		{
			cout<<"����ʧ��"<<endl;
		}
	}
	//LinkPrint(L);
	//cout<<"β�巨"<<endl;
	Joseph(L,9);
	system("pause");
	return 0;
}
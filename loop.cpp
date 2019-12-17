#include<iostream>
#include<stdlib.h>
#include "loop.h"
using namespace std;

//��ʼ��
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

	if(L==L->next)//�յ�ѭ������
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
	LinkList *L=NULL;//ͷ
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
	cout<<"β�巨"<<endl;

	system("pause");
	return 0;
}
#include<iostream>
#include<string>
#include<stdio.h>
#include "star.h"
using namespace std;

//ÿ���ڵ㱣����ͬ���͵�����
typedef struct LinkNode
{
	int data;
	struct LinkNode* next;
}LinkNode,LinkList;
int main2222()
{
	LinkList *L=NULL;//ͷ
	LinkNode *s;//�ڵ�
	//1.��ʼ��һ��������
	InitList(L);

	//2.ʹ��ǰ�巨��������
	int n;
	cout<<"���������Ԫ�ظ�����";
	cin>>n;
	cout<<"����������Ԫ�أ�"<<endl;

	while(n>0)
	{
		s=new LinkNode;
		cin>>s->data;
		ListInsert_back(L,s);
		n--;
	}
	//3.����������
	LinkPrint(L);
#if 0

	//5.����λ�ò���Ԫ��
	for(int j=0;j<3;j++)
	{
		int i,x;
		cout<<"������Ҫ����Ԫ�ص�λ�ú�Ԫ�أ�"<<endl;
		cin>>i>>x;
		if(LinkInsert(L,i,x))
		{
			cout<<"����ɹ�"<<endl;
		}
		else 
		{
			cout<<"����ʧ��"<<endl;
		}
		LinkPrint(L);
	}
	int element=0;
	if(Link_GetElem(L,2,element))
		cout<<"��ȡ�ڶ���Ԫ�سɹ���"<<element<<endl;
	else
		cout<<"��ȡ�ڶ���Ԫ��ʧ��"<<endl;

	//6.���������λ�û�ȡԪ��
	int index=0;
	if(Link_FindElem(L,10,index))
	{
		cout<<"���ҵ�Ԫ�ش���"<<index<<endl;
	}
	else
	{
		cout<<"���ҵ�Ԫ�ز�����"<<endl;
	}
#endif 
	if(LinkDelete(L,2))
	{
		cout<<"ɾ��Ԫ�سɹ�"<<endl;
		LinkPrint(L);
	}
	else 
	{
		cout<<"ɾ��Ԫ��ʧ��"<<endl;
	}
	LinkDestroy(L);
	system("pause");
	return 0;
}
//��ʼ������
bool InitList(LinkList* &L)
{
	L=new LinkNode;

	if(!L) return false;

	L->next=NULL;
	L->data=-1;
	return true;
}

//ǰ�巨
bool ListInsert_front(LinkList* &L,LinkNode *node)
{
	if(!L||!node) return false;

	node->next=L->next;
	L->next=node;
	return true;
}

//��巨
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
		return false;//iֵ���Ϸ�
	}
	e=p->data;
	return true;
}
//����������
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
//ָ��λ�ò���ڵ�
bool LinkInsert(LinkList* &L,int i,int &e)
{
	if(!L) return false;
	int j=0;
	LinkList *p,*s;

	p=L;

	while(p&&j<i-1)//����λ��Ϊi-1�Ľڵ�
	{
		p=p->next;
		j++;
	}

	if(!p ||j>i-1)
	{
		return false;
	}
	s=new LinkNode;//�����½ڵ�
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}
//��ֵ����
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
	if(!p) return false;//���޴�ֵ
	return true;
}
//�������ɾ��
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
	cout<<"��������"<<endl;
	while(p)
	{
		L=L->next;
		cout<<"ɾ��Ԫ�أ�"<<p->data<<endl;
		delete p;
		p=L;
	}
}

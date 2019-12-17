#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

//ÿ���ڵ㱣����ͬ���͵�����
typedef struct LinkNode
{
	int data;
	struct LinkNode* prev;
	struct LinkNode* next;
}LinkNode,LinkList;

//��ʼ������
bool InitList(LinkList* &L)
{
	L=new LinkNode;

	if(!L) return false;

	L->next=NULL;
	L->prev=NULL;
	L->data=-1;
	return true;
}

//ǰ�巨
bool ListInsert_front(LinkList* &L,LinkNode *node)
{
	if(!L||!node) return false;
	if(L->next)  L->next->prev=node;//���һ����ʱ��
	node->next=L->next;
	node->prev=L;
	L->next=node;

	return true;
}

//β�巨
bool ListInsert_back(LinkList* &L,LinkNode *node)
{
	LinkNode *last=NULL;

	if(!L||!node) return false;

	last=L;
	//�ҵ����ڵ�
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
		return false;//iֵ���Ϸ�
	}
	e=p->data;
	return true;
}
//����������
void LinkPrint(LinkList* &L)
{
	LinkNode* p;
	if(!L)
	{
		cout<<"����Ϊ��"<<endl;
		return ;
	}
	p=L;
	while(p->next)
	{//��ͷ�ӵ�֮���ӡ
		cout<<p->next->data<<"\t";
		p=p->next;
	}
	cout<<endl;
	//�����ӡ
	/*cout<<"�����ӡ"<<endl;
	while(p)
	{
		cout<<p->data<<"\t";
		p=p->prev;
	}*/
}
//ָ��λ�ò���ڵ�
bool LinkInsert(LinkList* &L,int i,int &e)
{
	if(!L) return false;
	if(i<1) return false;

	int j=0;
	LinkList *p,*s;

	p=L;

	while(p&&j<i)//����λ��Ϊi�Ľڵ�
	{
		p=p->next;//�ҵ�Ҫ�����λ��
		j++;
	}

	if(!p ||j!=i)
	{
		cout<<"�����ڽڵ�"<<i<<endl;
		return false;
	}
	s=new LinkNode;//�����½ڵ�
	s->data=e;

	s->next=p;
	s->prev=p->prev;

	p->prev->next=s;
	p->prev=s;
	
	
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
	//�ڵ㲻����
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
	cout<<"��������"<<endl;
	while(p)
	{
		L=L->next;
		cout<<"ɾ��Ԫ�أ�"<<p->data<<endl;
		delete p;
		p=L;
	}
}

int main666()
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
	LinkPrint(L);
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
	//3.����������
	system("pause");
	return 0;
}

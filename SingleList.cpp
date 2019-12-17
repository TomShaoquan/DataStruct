#include"SingleList.h"


//��ʼ������
bool InitList(LinkList* &listHead)
{
	listHead=new LinkNode;
	if(!listHead) return false;
	listHead->next=NULL;
	return true;
}

/*
	ǰ�巨����һ���ڵ�
	@param Head ͷ�ڵ�ָ��
	@param node  Ҫ����Ľڵ��ָ��
	�ɹ�����true ���򷵻�false
**/
bool ListInsert_front(LinkList* &Head,LinkNode *node)
{
	if(!Head||!node) return false;

	//��ͷ�ڵ㽻��λ��
	node->next=Head->next;
	Head->next=node;

	return true;
}

/*
	β�巨����һ���ڵ�
	@param Head ͷ�ڵ�ָ��
	@param node  Ҫ����Ľڵ��ָ��
	�ɹ�����true ���򷵻�false
**/
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


/*
	����λ�ò���һ���ڵ�
	@param L ͷ�ڵ�ָ��
	@param i �����λ��
	@param e �����Ԫ��
	�ɹ�����true ���򷵻�false
**/
bool LinkInsert(LinkList* &L,int i,int e)
{
	LinkNode *p,*s;
	if(!L) return false;
	p=L;
	int j=0;
	while(p&&j<i-1)//j==i-1ʱ����
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
	{
		return false;
	}
	s=new LinkNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}

/*
	������Ĵ�ӡ���
	@param  ͷ�ڵ�ָ��
	�޷���ֵ
**/
void ListPrint(LinkList* &L)
{
	LinkNode *p;
	if(!L) return ;
	p=L->next;
	while(p)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
	cout<<endl;
}
//������Ĳ���
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
	if(!p)
	{
		index=0;
		return false;
	}
	return true;
}
//�������ɾ��
bool LinkDelete(LinkList* &listHead,int i)
{
	LinkList *p,*q;
	
	int index=0;
	p=listHead;
	if(!listHead||!listHead->next)		//ͷ�ڵ㲻���ڻ�������Ϊ��
	{
		return false;
	}
	while(p->next&&index<i-1)		//�ҵ�Ҫɾ���Ľڵ��ǰһ��
	{
		p=p->next;
		index++;
	}
	if(!p->next||index>i-1)		//���Ҫɾ���Ľڵ�Ϊ�ջ����ҵ���ɾ��λ����Ҫɾ����λ��֮��
	{
		return false;
	}
	q=p->next;
	p->next=q->next;
	delete q;
	q=NULL;
	return true;
}
//bool LinkDelete(LinkList *head,LinkNode* node)
//{
//	LinkNode *tmp,*del;
//	del=head;
//	if(!head->next||!node) return false;
//	while(del!=node)	//�ҵ�Ҫɾ���ڵ�
//	{
//		tmp=del;
//		del=del->next;
//	}
//	tmp->next=node->next;
//	delete del;
//	return true;
//}
//�����������
bool LinkDestroy(LinkList* &L)
{
	LinkList *p=L;
	while(p)
	{
		L=L->next;
		cout<<"ɾ��Ԫ�أ�"<<p->data<<endl;
		delete p;
		p=L;
	}
	return true;
}
int main()
{ 
	LinkList *L,*s;
	InitList(L);

	int n;
	cout<<"����������Ԫ�ظ�����"<<endl;
	cin>>n;
	while(n>0)
	{
		s=new LinkNode;
		cin>>s->data;
		//ListInsert_front(L,s);
		ListInsert_back(L,s);
		n--;
	}
	ListPrint(L);
	
	if(!LinkDelete(L,3))
	{
		cout<<"ɾ��Ԫ��ʧ��"<<endl;
		getchar();
		return 0;
	}
	
	ListPrint(L);

	//LinkDestroy(L);
	
	system("pause");
	return 0;
}
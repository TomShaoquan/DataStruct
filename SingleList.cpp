#include"SingleList.h"


//初始化链表
bool InitList(LinkList* &listHead)
{
	listHead=new LinkNode;
	if(!listHead) return false;
	listHead->next=NULL;
	return true;
}

/*
	前插法插入一个节点
	@param Head 头节点指针
	@param node  要插入的节点的指针
	成功返回true 否则返回false
**/
bool ListInsert_front(LinkList* &Head,LinkNode *node)
{
	if(!Head||!node) return false;

	//和头节点交换位置
	node->next=Head->next;
	Head->next=node;

	return true;
}

/*
	尾插法插入一个节点
	@param Head 头节点指针
	@param node  要插入的节点的指针
	成功返回true 否则返回false
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
	任意位置插入一个节点
	@param L 头节点指针
	@param i 插入的位置
	@param e 插入的元素
	成功返回true 否则返回false
**/
bool LinkInsert(LinkList* &L,int i,int e)
{
	LinkNode *p,*s;
	if(!L) return false;
	p=L;
	int j=0;
	while(p&&j<i-1)//j==i-1时结束
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
	单链表的打印输出
	@param  头节点指针
	无返回值
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
//单链表的查找
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
//单链表的删除
bool LinkDelete(LinkList* &listHead,int i)
{
	LinkList *p,*q;
	
	int index=0;
	p=listHead;
	if(!listHead||!listHead->next)		//头节点不存在或者链表为空
	{
		return false;
	}
	while(p->next&&index<i-1)		//找到要删除的节点的前一个
	{
		p=p->next;
		index++;
	}
	if(!p->next||index>i-1)		//如果要删除的节点为空或者找到的删除位置在要删除的位置之后
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
//	while(del!=node)	//找到要删除节点
//	{
//		tmp=del;
//		del=del->next;
//	}
//	tmp->next=node->next;
//	delete del;
//	return true;
//}
//单链表的销毁
bool LinkDestroy(LinkList* &L)
{
	LinkList *p=L;
	while(p)
	{
		L=L->next;
		cout<<"删除元素："<<p->data<<endl;
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
	cout<<"请输入插入的元素个数："<<endl;
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
		cout<<"删除元素失败"<<endl;
		getchar();
		return 0;
	}
	
	ListPrint(L);

	//LinkDestroy(L);
	
	system("pause");
	return 0;
}
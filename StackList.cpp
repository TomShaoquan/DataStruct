#include<iostream>
#include<assert.h>

using namespace std;

typedef int DataType;

//保存栈元素的节点  双向链表的节点
typedef struct stackNode
{
	DataType elems;			//数据域 要保存的元素承载于数据域
	struct stackNode* next;		//指针域
	struct stackNode* front;	//
}stackNode;
//栈只有一个
typedef struct Stack
{
	stackNode *top;			//栈顶指针(指向最后的节点)
	stackNode *base;		//栈底指针(指向头结点)
}Stack;


//初始化
bool initStack(Stack &s)
{
	//用链表来保存栈中的元素
	stackNode *head=new stackNode;
	head->elems=0;
	head->front=NULL;
	head->next=NULL;
	if(head)
	{
		s.base=head;		//指向头结点
		s.top=s.base;
	}
	return true;
}
//入栈  (插入元素)
bool pushStack(Stack &s,DataType e)
{

	stackNode *node=new stackNode;
	node->elems=e;
	node->next=NULL;		//后一个
	node->front=s.top;		//前一个

	if(s.base==s.top) //元素插入
	{
		s.base->next=node;
		s.top=node;
	}
	//尾部链接插入的节点
	s.top->next=node;
	//top指向刚才插入的节点,即下一个节点
	s.top=node;
	return true;
}

//得到栈顶元素
bool popStack(Stack &s,DataType &tmp)
{
	if(s.top==s.base)
		return false;

	tmp=s.top->elems;
	s.top=s.top->front;		//指向前一个
	return true;
}

//销毁栈  释放掉的内存就不能再去访问
void desStack(Stack &s)
{
	stackNode *tmp,*del;
	tmp=s.base;
	while(tmp!=NULL)
	{
		del=tmp;
		tmp=tmp->next;
		delete del;	
	}
	assert(tmp==NULL);
}
using namespace std;
int main()
{
	Stack s;
	int n,e,i,tmp;
	i=1;
	initStack(s);

	cout<<"请输入入栈元素个数:";
	cin>>n;
	while(n>0)
	{	
		cout<<"请输入第"<<i<<"个:";
		cin>>e;
		pushStack(s,e);
		n--;
		i++;
	}

	cout<<"元素依次出栈:"<<endl;
	while(s.base!=s.top)
	{
		popStack(s,tmp);
		cout<<tmp<<"\t";
	}
	cout<<endl;
	desStack(s);
	system("pause");
	return 0;
}
	
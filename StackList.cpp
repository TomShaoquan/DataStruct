#include<iostream>
#include<assert.h>

using namespace std;

typedef int DataType;

//����ջԪ�صĽڵ�  ˫������Ľڵ�
typedef struct stackNode
{
	DataType elems;			//������ Ҫ�����Ԫ�س�����������
	struct stackNode* next;		//ָ����
	struct stackNode* front;	//
}stackNode;
//ջֻ��һ��
typedef struct Stack
{
	stackNode *top;			//ջ��ָ��(ָ�����Ľڵ�)
	stackNode *base;		//ջ��ָ��(ָ��ͷ���)
}Stack;


//��ʼ��
bool initStack(Stack &s)
{
	//������������ջ�е�Ԫ��
	stackNode *head=new stackNode;
	head->elems=0;
	head->front=NULL;
	head->next=NULL;
	if(head)
	{
		s.base=head;		//ָ��ͷ���
		s.top=s.base;
	}
	return true;
}
//��ջ  (����Ԫ��)
bool pushStack(Stack &s,DataType e)
{

	stackNode *node=new stackNode;
	node->elems=e;
	node->next=NULL;		//��һ��
	node->front=s.top;		//ǰһ��

	if(s.base==s.top) //Ԫ�ز���
	{
		s.base->next=node;
		s.top=node;
	}
	//β�����Ӳ���Ľڵ�
	s.top->next=node;
	//topָ��ղŲ���Ľڵ�,����һ���ڵ�
	s.top=node;
	return true;
}

//�õ�ջ��Ԫ��
bool popStack(Stack &s,DataType &tmp)
{
	if(s.top==s.base)
		return false;

	tmp=s.top->elems;
	s.top=s.top->front;		//ָ��ǰһ��
	return true;
}

//����ջ  �ͷŵ����ڴ�Ͳ�����ȥ����
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

	cout<<"��������ջԪ�ظ���:";
	cin>>n;
	while(n>0)
	{	
		cout<<"�������"<<i<<"��:";
		cin>>e;
		pushStack(s,e);
		n--;
		i++;
	}

	cout<<"Ԫ�����γ�ջ:"<<endl;
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
	
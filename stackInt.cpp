#include<Windows.h>
#include<iostream>
#include<stdio.h>

#define MaxSize 128

typedef int ElemType;
//��ҵ
typedef struct SqStack
{
	int top;
	ElemType *base;
}SqStack;



//��ʼ��
bool initStack(SqStack &S)
{
	S.base=new ElemType[MaxSize];
	if(!S.base)
		return false;
	S.top=0;
	return true;
}
//��ջ
bool PushStack(SqStack &S,ElemType e)
{
	if(S.top==MaxSize-1)
		return false;
	*(S.base+S.top)=e;
	S.top++;
	return true;
}

//��ջ  
bool PopStack(SqStack &S,ElemType &e)	//ɾ����ջ��Ԫ���ݴ��ڱ���e��
{
	if(S.top==0)	//ջ��
	{
		return false;
	}
	S.top--;
	e=*(S.base+S.top);
	return true;
}

bool GetTop(SqStack &S,ElemType &e)
{
	if(S.top!=0){
		e=*(S.base+S.top);	//����ջ��Ԫ��
		return true;
	}else{
		return false;
	}
}

int GetSize(SqStack &S)
{
	return S.top;
}

bool IsEmpty(SqStack &S)
{
	if(S.top==0){
		return true;
	}else{

		return false;
	}
}

void DestroyStack(SqStack &S)
{
	if(S.base){
		delete S.base;
		S.base=NULL;
		S.top=NULL;
	}
}
using namespace std;

int main()
{
	
	SqStack S;
	int n,m,x;
	ElemType e;
	m=1;
	initStack(S);
	cout<<"��������ջ��Ԫ�ظ�����";
	cin>>n;

	while(n>0)
	{
		cout<<"�������"<<m<<"����ջ��Ԫ��:";
		cin>>x;
		PushStack(S,x);
		n--;
		m++;
	}

	//Ԫ�س�ջ
	cout<<"Ԫ�س�ջ��"<<endl;
	while(!IsEmpty(S))
	{
		PopStack(S,e);
		cout<<e<<"\t";
	}
	cout<<endl;
	system("pause");
	return 0;
}


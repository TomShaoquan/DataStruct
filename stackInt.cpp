#include<Windows.h>
#include<iostream>
#include<stdio.h>

#define MaxSize 128

typedef int ElemType;
//作业
typedef struct SqStack
{
	int top;
	ElemType *base;
}SqStack;



//初始化
bool initStack(SqStack &S)
{
	S.base=new ElemType[MaxSize];
	if(!S.base)
		return false;
	S.top=0;
	return true;
}
//入栈
bool PushStack(SqStack &S,ElemType e)
{
	if(S.top==MaxSize-1)
		return false;
	*(S.base+S.top)=e;
	S.top++;
	return true;
}

//出栈  
bool PopStack(SqStack &S,ElemType &e)	//删除的栈顶元素暂存在变量e中
{
	if(S.top==0)	//栈空
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
		e=*(S.base+S.top);	//访问栈顶元素
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
	cout<<"请输入入栈的元素个数：";
	cin>>n;

	while(n>0)
	{
		cout<<"请输入第"<<m<<"个入栈的元素:";
		cin>>x;
		PushStack(S,x);
		n--;
		m++;
	}

	//元素出栈
	cout<<"元素出栈："<<endl;
	while(!IsEmpty(S))
	{
		PopStack(S,e);
		cout<<e<<"\t";
	}
	cout<<endl;
	system("pause");
	return 0;
}


#include<Windows.h>
#include<iostream>
#include<stdio.h>
#include "stack.h"

/*
*	初始化栈 为栈分配内存
*	@param S 保存栈元素的结构
*/
bool initStack(SqStack &S)
{
	S.base=new ElemType[MaxSize];
	if(!S.base)
		return false;
	S.top=S.base;
	return true;
}
/*	元素入栈
*	@param S 保存栈的结构
	@param e 入栈元素
	return true or false
**/
bool PushStack(SqStack &S,ElemType e)
{
	if(S.top-S.base==MaxSize)
		return false;
	*S.top=e;
	S.top++;
	return true;
}

/*
*	元素出栈
*	@param S  保存栈的结构
*	@param e  出栈的栈顶元素暂存在变量e中
*	return true or false
*/ 
bool PopStack(SqStack &S,ElemType &e)
{
	if(S.base==S.top)	//栈空
	{
		return false;
	}
	S.top--;
	e=*S.top;
	return true;
}

/*
*	判断栈是否为空
*	@param S  保存栈的结构
*	return true if is empty else return false
*/
bool IsEmpty(SqStack &S)
{
	if(S.top==S.base){
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



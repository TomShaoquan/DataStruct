
#include "rankList.h"
/*
	初始化顺序表
	@param  L	保存顺序表的结构
	if success true else return false
*/
bool initList(SqList &L)
{
	L.elems = new dataType[MAX_SIZE];
	if (!L.elems)	return false;		//存储分配失败
	L.length = 0;
	L.size = MAX_SIZE;
	return true;
}

/*
顺序表插入元素
@param  L	保存顺序表的结构
@param e    要插入的元素
if success true else return false
*/
bool listAppend(SqList &L, dataType  e)
{
	if (L.length == MAX_SIZE)		return false;	//存储已满
	L.elems[L.length] =e;
	L.length++;
	return true;

}

/*
顺序表删除元素
@param  L	保存顺序表的结构
@param i     要删除的元素索引值
if success true else return false
*/
bool listDelete(SqList& L, int i)
{
	if (i<0 || i>L.length)	return false;	//不合法

	if (i == L.length - 1)	//删除最后一个元素
	{
		L.length--;
		return true;
	}

	for (int  j=i; j< L.length; j++)
	{
		L.elems[j] = L.elems[j + 1];

	}

	L.length--;
	return true;

}
/*
顺序表查看指定元素
@param  L	保存顺序表的结构
@param i     要查看的元素索引值
@param e     传入参数，用于保存查看的元素
if success true else return false
*/
bool getElem(SqList& L, int i, dataType& e)
{
	if (i<1 || i>L.length)	return false;

	e = L.elems[i - 1];

	return true;
}

/*
顺序表更改指定元素
@param  L	保存顺序表的结构
@param i     要更改的元素索引值
@param e     更改后的元素
if success true else return false
*/
bool alterElem(SqList& L, int i, dataType& e)
{
	if (i<1 || i>L.length)	return false;

	L.elems[i - 1] = e;

	return true;
}
/*
顺序表释放内存
@param  L	保存顺序表的结构
无返回值
*/
void destroyList(SqList& L)
{
	if (L.elems)
		delete[] L.elems;

	L.length = 0;
	L.size = 0;
}

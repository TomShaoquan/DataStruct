
#include "rankList.h"
/*
	��ʼ��˳���
	@param  L	����˳���Ľṹ
	if success true else return false
*/
bool initList(SqList &L)
{
	L.elems = new dataType[MAX_SIZE];
	if (!L.elems)	return false;		//�洢����ʧ��
	L.length = 0;
	L.size = MAX_SIZE;
	return true;
}

/*
˳������Ԫ��
@param  L	����˳���Ľṹ
@param e    Ҫ�����Ԫ��
if success true else return false
*/
bool listAppend(SqList &L, dataType  e)
{
	if (L.length == MAX_SIZE)		return false;	//�洢����
	L.elems[L.length] =e;
	L.length++;
	return true;

}

/*
˳���ɾ��Ԫ��
@param  L	����˳���Ľṹ
@param i     Ҫɾ����Ԫ������ֵ
if success true else return false
*/
bool listDelete(SqList& L, int i)
{
	if (i<0 || i>L.length)	return false;	//���Ϸ�

	if (i == L.length - 1)	//ɾ�����һ��Ԫ��
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
˳���鿴ָ��Ԫ��
@param  L	����˳���Ľṹ
@param i     Ҫ�鿴��Ԫ������ֵ
@param e     ������������ڱ���鿴��Ԫ��
if success true else return false
*/
bool getElem(SqList& L, int i, dataType& e)
{
	if (i<1 || i>L.length)	return false;

	e = L.elems[i - 1];

	return true;
}

/*
˳������ָ��Ԫ��
@param  L	����˳���Ľṹ
@param i     Ҫ���ĵ�Ԫ������ֵ
@param e     ���ĺ��Ԫ��
if success true else return false
*/
bool alterElem(SqList& L, int i, dataType& e)
{
	if (i<1 || i>L.length)	return false;

	L.elems[i - 1] = e;

	return true;
}
/*
˳����ͷ��ڴ�
@param  L	����˳���Ľṹ
�޷���ֵ
*/
void destroyList(SqList& L)
{
	if (L.elems)
		delete[] L.elems;

	L.length = 0;
	L.size = 0;
}

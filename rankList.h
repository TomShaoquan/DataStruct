# ifndef _RANKLIST_H_
#define _RANKLIST_H_

#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

#define MAX_SIZE 100			//˳��������

//����ѧ����Ϣ�Ľṹ
typedef struct studentInfo
{
	unsigned int stuNumber;		//ѧ��
	string   name;				//����
	string  sex;				//�Ա�
	int birthYear;				//�������
	int ChinScore;				//���ķ���
	int mathScore;				//��ѧ����
	int EnglishScore;			//Ӣ�����
	int totalScore;				//�ܷ�

}stuInfo;

typedef stuInfo  dataType;
typedef struct
{
	dataType*  elems;			//˳������ַ
	int length;				//˳���ĳ���
	int size;				//˳���ռ�
}SqList;

//˳���Ľӿ�
bool initList(SqList &L);
bool listAppend(SqList &L, dataType  e);
bool listDelete(SqList& L, int i);
bool getElem(SqList& L, int i, dataType& e);
bool alterElem(SqList& L, int i, dataType& e);
void destroyList(SqList& L);

#endif
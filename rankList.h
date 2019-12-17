# ifndef _RANKLIST_H_
#define _RANKLIST_H_

#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

#define MAX_SIZE 100			//顺序表的容量

//保存学生信息的结构
typedef struct studentInfo
{
	unsigned int stuNumber;		//学号
	string   name;				//姓名
	string  sex;				//性别
	int birthYear;				//出生年份
	int ChinScore;				//语文分数
	int mathScore;				//数学分数
	int EnglishScore;			//英语分数
	int totalScore;				//总分

}stuInfo;

typedef stuInfo  dataType;
typedef struct
{
	dataType*  elems;			//顺序表基地址
	int length;				//顺序表的长度
	int size;				//顺序表空间
}SqList;

//顺序表的接口
bool initList(SqList &L);
bool listAppend(SqList &L, dataType  e);
bool listDelete(SqList& L, int i);
bool getElem(SqList& L, int i, dataType& e);
bool alterElem(SqList& L, int i, dataType& e);
void destroyList(SqList& L);

#endif
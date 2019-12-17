#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#define MaxSize 5

typedef int DataType;
using namespace std;
//定义数据结构
typedef struct Quene
{
	DataType queue[MaxSize];
	int front;		//队头指针
	int rear;		//队尾指针
}SeqQueue;

//初始化队列
void InitQueue(SeqQueue *SQ);
//判断队列是否为空
int IsEmpty(SeqQueue *SQ);

//判断队列是否为满
int IsFull(SeqQueue *SQ);

//入队，将元素插入队列中
int EnterQueue(SeqQueue *SQ,DataType data);

//入队，将元素插入队列中
int EnterQueue(SeqQueue *SQ,DataType data);

//出列
int DeleteQueue(SeqQueue *SQ,DataType *data);

//打印
void PrintQueue(SeqQueue *SQ);

int  GetHead(SeqQueue *SQ,DataType *data);

void ClearQueue(SeqQueue *SQ);

int GetLength(SeqQueue *SQ);

void desQueue(SeqQueue *SQ);
#endif 
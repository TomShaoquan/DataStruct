#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#define MaxSize 5

typedef int DataType;
using namespace std;
//�������ݽṹ
typedef struct Quene
{
	DataType queue[MaxSize];
	int front;		//��ͷָ��
	int rear;		//��βָ��
}SeqQueue;

//��ʼ������
void InitQueue(SeqQueue *SQ);
//�ж϶����Ƿ�Ϊ��
int IsEmpty(SeqQueue *SQ);

//�ж϶����Ƿ�Ϊ��
int IsFull(SeqQueue *SQ);

//��ӣ���Ԫ�ز��������
int EnterQueue(SeqQueue *SQ,DataType data);

//��ӣ���Ԫ�ز��������
int EnterQueue(SeqQueue *SQ,DataType data);

//����
int DeleteQueue(SeqQueue *SQ,DataType *data);

//��ӡ
void PrintQueue(SeqQueue *SQ);

int  GetHead(SeqQueue *SQ,DataType *data);

void ClearQueue(SeqQueue *SQ);

int GetLength(SeqQueue *SQ);

void desQueue(SeqQueue *SQ);
#endif 
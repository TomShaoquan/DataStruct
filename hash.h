#include<stdio.h>
#include<Windows.h>
/*****************************
*							 *
*	��ϣ������㷨ʵ��       *
*							 *
******************************/
#define DEFAULT_SIZE 16		//��ϣ���Ĭ�ϴ�С Ͱ��ֻ��
typedef struct _listNode
{
	struct _listNode* next;
	int key;
	void* data;
}listNode;

typedef listNode*		List;//һ��ָ�����
typedef listNode*       Element;//Ԫ��ָ�����

typedef struct _HashTable
{
	int		TableSize;
	List*   Thelists;//����ָ��
}HashTable;
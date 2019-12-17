#include<stdio.h>
#include<Windows.h>
/*****************************
*							 *
*	哈希链表的算法实现       *
*							 *
******************************/
#define DEFAULT_SIZE 16		//哈希表的默认大小 桶的只数
typedef struct _listNode
{
	struct _listNode* next;
	int key;
	void* data;
}listNode;

typedef listNode*		List;//一级指针变量
typedef listNode*       Element;//元素指针变量

typedef struct _HashTable
{
	int		TableSize;
	List*   Thelists;//二级指针
}HashTable;
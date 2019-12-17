#include<iostream>

using namespace std;
//自定义数据类型
typedef struct LinkNode
{
	int data;
	struct LinkNode* next;
}LinkList,LinkNode;


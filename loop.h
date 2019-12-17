#ifndef _STAT_H_
#define _STAT_H_
//每个节点保存相同类型的数据
typedef struct LinkNode
{
	int data;
	struct LinkNode* next;
}LinkNode,LinkList;

bool InitList(LinkList* &L);
bool ListInsert_front(LinkList* &L,LinkNode *node);
bool ListInsert_back(LinkList* &L,LinkNode *node);
bool Link_GetElem(LinkList* &L,int i,int &e);
bool LinkInsert(LinkList* &L,int i,int &e);
bool Link_FindElem(LinkList *L,int e,int &index);
bool LinkDelete(LinkList* &L,int i);
void LinkPrint(LinkList* &L);
void LinkDestroy(LinkList* &L);
#endif
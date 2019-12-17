#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct LinkNode
{
	int data;
	struct LinkNode *next;
}LinkNode,LinkList;

//Á´±í½Ó¿Ú
bool InitList(LinkList* &listHead);
bool ListInsert_front(LinkList* &Head,LinkNode *node);
bool ListInsert_back(LinkList* &L,LinkNode *node);
bool LinkInsert(LinkList* &L,int i,int e);
void ListPrint(LinkList* &L);
bool Link_FindElem(LinkList *L,int e,int &index);
bool LinkDelete(LinkList* &listHead,int i);
bool LinkDestroy(LinkList* &L);

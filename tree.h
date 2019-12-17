#ifndef TREE_H
#define TREE_H
#include"stack.h"
/*
*	插入一个节点
*	@param root 保存根节点地址的指针
*	@param node 插入的节点
*	rerurn true if sucess else return false
*/
bool InsertBtree(Bnode** root,Bnode *node);

/*
*	找到root节点下最大的节点
*	@param root 根节点指针
*/
int findMax(Btree *root);

/*
	递归调用删除节点
	@param root 根节点指针
	@param key  要删除的值
	@param  _in_ deleteNode 要删除的节点指针
	return 
**/
Btree* DeleteNode(Btree* root,int key,Bnode* &deletedNode);

/*循环的方式查找节点
*	@param root 
*	@param e 
*/
Bnode* queryByLoop(Bnode* root,DataType e);

/*	递归的方式查找节点
	@param root 根节点
	@param e  要查找的元素
*/
Bnode* queryByRec(Btree *root,DataType e);

/*
*	递归实现前序遍历
	@param root 根节点指针
	return 无
*/
void PreOrderRec(Btree *root);

/*	
*	前序遍历
*	@param root 根节点指针
*	
*/
void PreOrder(Btree* root);

void FloorPrint(Bnode* root); //层序遍历
#endif
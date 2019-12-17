#ifndef TREE_H
#define TREE_H
#include"stack.h"
/*
*	����һ���ڵ�
*	@param root ������ڵ��ַ��ָ��
*	@param node ����Ľڵ�
*	rerurn true if sucess else return false
*/
bool InsertBtree(Bnode** root,Bnode *node);

/*
*	�ҵ�root�ڵ������Ľڵ�
*	@param root ���ڵ�ָ��
*/
int findMax(Btree *root);

/*
	�ݹ����ɾ���ڵ�
	@param root ���ڵ�ָ��
	@param key  Ҫɾ����ֵ
	@param  _in_ deleteNode Ҫɾ���Ľڵ�ָ��
	return 
**/
Btree* DeleteNode(Btree* root,int key,Bnode* &deletedNode);

/*ѭ���ķ�ʽ���ҽڵ�
*	@param root 
*	@param e 
*/
Bnode* queryByLoop(Bnode* root,DataType e);

/*	�ݹ�ķ�ʽ���ҽڵ�
	@param root ���ڵ�
	@param e  Ҫ���ҵ�Ԫ��
*/
Bnode* queryByRec(Btree *root,DataType e);

/*
*	�ݹ�ʵ��ǰ�����
	@param root ���ڵ�ָ��
	return ��
*/
void PreOrderRec(Btree *root);

/*	
*	ǰ�����
*	@param root ���ڵ�ָ��
*	
*/
void PreOrder(Btree* root);

void FloorPrint(Bnode* root); //�������
#endif
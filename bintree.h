#ifndef __BINTREE_H__
#define __BINTREE_H__

#include<iostream>
#include<cstring>
#include<cassert>
#include<queue>

using namespace std;

typedef char DataType;

struct TreeNode {

    DataType data;    /* node data */

    struct TreeNode *leftPtr;   /* pointer to left subtree */

    struct TreeNode *rightPtr;  /* pointer to right subtree */
};

typedef struct TreeNode TreeNode;

typedef TreeNode * pTreeNode;

void CreateBinTree(pTreeNode *Tree);//����������

void InitTreeNode(pTreeNode *Tree);//��ʼ��

void PreOrderPrint(pTreeNode Tree);//�������

void MidOrderPrint(pTreeNode Tree);//�������

void PostOrderPrint(pTreeNode Tree);//��������

void FloorPrint(pTreeNode Tree);//�������

void FloorPrint_QUEUE(pTreeNode &Tree);//�������_����ʵ��

#endif
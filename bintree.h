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

void CreateBinTree(pTreeNode *Tree);//创建二叉树

void InitTreeNode(pTreeNode *Tree);//初始化

void PreOrderPrint(pTreeNode Tree);//先序遍历

void MidOrderPrint(pTreeNode Tree);//中序遍历

void PostOrderPrint(pTreeNode Tree);//后续遍历

void FloorPrint(pTreeNode Tree);//层序遍历

void FloorPrint_QUEUE(pTreeNode &Tree);//层序遍历_队列实现

#endif
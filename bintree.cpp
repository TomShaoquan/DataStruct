#include"bintree.h"

void InitTreeNode(pTreeNode *Tree)
{
    *Tree = NULL;
}

void CreateBinTree(pTreeNode *Tree)
{
    DataType ch;
    ch = getchar();
    if (ch == '#')
    {
        *Tree = NULL;
    }
    else
    {
        *Tree = (pTreeNode)malloc(sizeof(pTreeNode));

        if (NULL == (*Tree))
        {
            exit(0);
        }
        else
        {
            (*Tree)->data = ch;
            (*Tree)->leftPtr = NULL;
            (*Tree)->rightPtr = NULL;
            CreateBinTree(&(*Tree)->leftPtr);
            CreateBinTree(&(*Tree)->rightPtr);
        }
    }
}


void PreOrderPrint(pTreeNode Tree)
{
    if (!Tree)
    {
        return;
    }
    cout << Tree->data << " → ";
    PreOrderPrint(Tree->leftPtr);
    PreOrderPrint(Tree->rightPtr);
}

void MidOrderPrint(pTreeNode Tree)//中序遍历
{
    if (NULL != Tree)
    {
        PreOrderPrint(Tree->leftPtr);
        cout << Tree->data << " → ";
        PreOrderPrint(Tree->rightPtr);
    }
}

void PostOrderPrint(pTreeNode Tree)//后续遍历
{
    if (NULL != Tree)
    {
        PreOrderPrint(Tree->leftPtr);
        PreOrderPrint(Tree->rightPtr);
        cout << Tree->data << " → ";
    }
}

void FloorPrint(pTreeNode Tree)  //层序遍历
{
    pTreeNode temp[100];   //创建pTreeNode指针类型的指针数组
    int in = 0;
    int out = 0;

    temp[in++] = Tree;  //先保存二叉树根节点 

    while (in > out)
    {
        if (temp[out])
        {
            cout << temp[out]->data << " → ";
            temp[in++] = temp[out]->leftPtr;
            temp[in++] = temp[out]->rightPtr;
        }
        out++;
    }
}

void FloorPrint_QUEUE(pTreeNode &Tree) //层序遍历_队列实现
{
    queue < pTreeNode> q;
    if (Tree != NULL)
    {
        q.push(Tree);   //根节点进队列
    }

    while (q.empty() == false)  //队列不为空判断
    {
        cout << q.front()->data << " → "; 

        if (q.front()->leftPtr != NULL)   //如果有左孩子，leftChild入队列
        {
            q.push(q.front()->leftPtr);   
        }

        if (q.front()->rightPtr != NULL)   //如果有右孩子，rightChild入队列
        {
            q.push(q.front()->rightPtr);
        }
        q.pop();  //已经遍历过的节点出队列
    }
}
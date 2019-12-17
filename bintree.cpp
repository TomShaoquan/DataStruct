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
    cout << Tree->data << " �� ";
    PreOrderPrint(Tree->leftPtr);
    PreOrderPrint(Tree->rightPtr);
}

void MidOrderPrint(pTreeNode Tree)//�������
{
    if (NULL != Tree)
    {
        PreOrderPrint(Tree->leftPtr);
        cout << Tree->data << " �� ";
        PreOrderPrint(Tree->rightPtr);
    }
}

void PostOrderPrint(pTreeNode Tree)//��������
{
    if (NULL != Tree)
    {
        PreOrderPrint(Tree->leftPtr);
        PreOrderPrint(Tree->rightPtr);
        cout << Tree->data << " �� ";
    }
}

void FloorPrint(pTreeNode Tree)  //�������
{
    pTreeNode temp[100];   //����pTreeNodeָ�����͵�ָ������
    int in = 0;
    int out = 0;

    temp[in++] = Tree;  //�ȱ�����������ڵ� 

    while (in > out)
    {
        if (temp[out])
        {
            cout << temp[out]->data << " �� ";
            temp[in++] = temp[out]->leftPtr;
            temp[in++] = temp[out]->rightPtr;
        }
        out++;
    }
}

void FloorPrint_QUEUE(pTreeNode &Tree) //�������_����ʵ��
{
    queue < pTreeNode> q;
    if (Tree != NULL)
    {
        q.push(Tree);   //���ڵ������
    }

    while (q.empty() == false)  //���в�Ϊ���ж�
    {
        cout << q.front()->data << " �� "; 

        if (q.front()->leftPtr != NULL)   //��������ӣ�leftChild�����
        {
            q.push(q.front()->leftPtr);   
        }

        if (q.front()->rightPtr != NULL)   //������Һ��ӣ�rightChild�����
        {
            q.push(q.front()->rightPtr);
        }
        q.pop();  //�Ѿ��������Ľڵ������
    }
}
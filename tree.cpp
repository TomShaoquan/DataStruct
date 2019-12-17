#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"tree.h"

using namespace std;



#define MAX_NODE 1024	//�������Ԫ����


#define isLess(a,b) (a<b)
#define isEqual(a,b) (a==b)


/*
*	����һ���ڵ�
*	@param root ������ڵ��ַ��ָ��
*	@param node ����Ľڵ�
*	rerurn true if sucess else return false
*/
bool InsertBtree(Bnode** root,Bnode *node)
{
	Bnode *tmp=NULL;
	Bnode *parent=NULL;
	
	if(!node)	//�ڴ����ʧ��
	{
		return false;
	}
	else
	{
		node->lchild=NULL;
		node->rchild=NULL;
	}

	if(*root)
	{//���ڵ㲻Ϊ�� ��2�ν���
		tmp=*root;
	}else
	{//��һ�ν���
		*root=node;	//���ڵ㱻����
		return true;
	}

	//�ҵ�Ҫ�����λ�õĸ��ڵ�
	while(tmp!=NULL)//ֱ��tmp Ϊ��  ��һ�ν�����ѭ��
	{
		parent=tmp;	//���游�ڵ�
		if(isLess(node->data,tmp->data))
		{
			tmp=tmp->lchild;	//С ������
		}
		else
		{
			tmp=tmp->rchild;	//�� ������
		}

	}

	if(isLess(node->data,parent->data))
	{//�ҵ���λ���в���
		parent->lchild=node;
	}
	else
	{
		parent->rchild=node;

	}
	return true;
}
/*
*	�ҵ�root�ڵ������Ľڵ�
*	@param root ���ڵ�ָ��
*/
int findMax(Btree *root)
{
	if(root->rchild==NULL)
	{
		return root->data;
	}
	return findMax(root->rchild);
}

/*
	�ݹ����ɾ���ڵ�
	@param root ���ڵ�ָ��
	@param key  Ҫɾ����ֵ
	@param  _in_ deleteNode Ҫɾ���Ľڵ�ָ��
	return 
**/
Btree* DeleteNode(Btree* root,int key,Bnode* &deletedNode)
{
	if(root==NULL)  return NULL; //û���ҵ��ڵ�

	if(root->data>key)	//1.�������
	{
		root->lchild=DeleteNode(root->lchild,key,deletedNode);
		return root;
	}

	if(root->data<key) //2.���ұ���
	{
		root->rchild=DeleteNode(root->rchild,key,deletedNode);
		return root;
	}

	deletedNode=root;
	/*3.Ҫɾ���Ľڵ�==�ҵĵĽڵ�*/
	//a.ɾ���ڵ㲻���������ֽڵ� ֱ��ɾ��
	if(root->lchild==NULL && root->rchild==NULL) return NULL;

	//b.ɾ���ڵ�ֻ�������ӽڵ� ֱ�������ӽڵ�ȡ��ɾ���ڵ�
	if(root->lchild==NULL&&root->rchild!=NULL) return root->rchild;

	//c.ɾ���ڵ�ֻ�������ӽڵ� ֱ�������ӽڵ�ȡ��ɾ���ڵ�
	if(root->lchild!=NULL&&root->rchild==NULL) return root->lchild;

	//d.ɾ���ڵ���������ӽڵ�
	int val=findMax(root->lchild);
	root->data=val;
	root->lchild=DeleteNode(root->lchild,val,deletedNode);

	return root;
}


/*ѭ���ķ�ʽ���ҽڵ�
*	@param root 
*	@param e 
*/
Bnode* queryByLoop(Bnode* root,DataType e)
{
	while(root!=NULL&& !isEqual(root->data,e)){

		if(isLess(e,root->data)){
			root=root->lchild;
		}else{
			root=root->rchild;
		}
	}
	return root;
}

/*	�ݹ�ķ�ʽ���ҽڵ�
	@param root ���ڵ�
	@param e  Ҫ���ҵ�Ԫ��
*/
Bnode* queryByRec(Btree *root,DataType e)
{
	if(root==NULL||isEqual(root->data,e))
	{
		return root;
	}
	else if(isLess(e,root->data))
	{
		queryByRec(root->lchild,e);
	}
	else
	{
		return queryByRec(root->rchild,e);
	}

}

/*
*	�ݹ�ʵ��ǰ�����
	@param root ���ڵ�ָ��
	return ��
*/
void PreOrderRec(Btree *root)
{
	if(root==NULL)
	{
		return;
	}
	printf("-%d-",root->data);
	PreOrderRec(root->lchild);
	PreOrderRec(root->rchild);

}
/*	
*	ǰ�����
*	@param root ���ڵ�ָ��
*	
*/
void PreOrder(Btree* root)
{
	Bnode cur;
	if(root==NULL)
	{
		return;
	}
	SqStack stack;
	initStack(stack);
	PushStack(stack,*root);

	while(!(IsEmpty(stack)))
	{
		PopStack(stack,cur);
		printf("-%d-",cur.data);

		if(cur.rchild!=NULL)	//���ӽڵ�����ջ
		{
			PushStack(stack,*(cur.rchild));
		}

		if(cur.lchild!=NULL)  //���ֽڵ����ջ
		{
			PushStack(stack,*(cur.lchild));
		}
	}
	//�ͷ��ڴ�
	DestroyStack(stack);
}

void FloorPrint(Bnode* root)  //�������
{
    Bnode* temp[100];   //����pTreeNodeָ�����͵�ָ������
    int in = 0;
    int out = 0;

    temp[in] = root;  //�ȱ�����������ڵ� 
	in++;

    while (in > out)
    {
        if (temp[out])
        {
            //cout << temp[out]->data << " �� ";
            temp[in] = temp[out]->lchild;
			in++;
            temp[in] = temp[out]->rchild;
			in++;
        }
        out++;
    }
	for(int i=0;i<out;i++)
	{
		cout << temp[i]->data << " �� ";
	}
}


/**
 * Create a Media Player object from a Media
 *
 * \param p_md the media. Afterwards the p_md can be safely
 *        destroyed.
 * \return a new media player object, or NULL on error.
 */
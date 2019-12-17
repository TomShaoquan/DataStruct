#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"tree.h"

using namespace std;



#define MAX_NODE 1024	//保存最大元素数


#define isLess(a,b) (a<b)
#define isEqual(a,b) (a==b)


/*
*	插入一个节点
*	@param root 保存根节点地址的指针
*	@param node 插入的节点
*	rerurn true if sucess else return false
*/
bool InsertBtree(Bnode** root,Bnode *node)
{
	Bnode *tmp=NULL;
	Bnode *parent=NULL;
	
	if(!node)	//内存分配失败
	{
		return false;
	}
	else
	{
		node->lchild=NULL;
		node->rchild=NULL;
	}

	if(*root)
	{//根节点不为空 即2次进来
		tmp=*root;
	}else
	{//第一次进来
		*root=node;	//根节点被更改
		return true;
	}

	//找到要插入的位置的父节点
	while(tmp!=NULL)//直到tmp 为空  第一次进来不循环
	{
		parent=tmp;	//保存父节点
		if(isLess(node->data,tmp->data))
		{
			tmp=tmp->lchild;	//小 左子树
		}
		else
		{
			tmp=tmp->rchild;	//大 右子树
		}

	}

	if(isLess(node->data,parent->data))
	{//找到空位进行插入
		parent->lchild=node;
	}
	else
	{
		parent->rchild=node;

	}
	return true;
}
/*
*	找到root节点下最大的节点
*	@param root 根节点指针
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
	递归调用删除节点
	@param root 根节点指针
	@param key  要删除的值
	@param  _in_ deleteNode 要删除的节点指针
	return 
**/
Btree* DeleteNode(Btree* root,int key,Bnode* &deletedNode)
{
	if(root==NULL)  return NULL; //没有找到节点

	if(root->data>key)	//1.往左边找
	{
		root->lchild=DeleteNode(root->lchild,key,deletedNode);
		return root;
	}

	if(root->data<key) //2.往右边找
	{
		root->rchild=DeleteNode(root->rchild,key,deletedNode);
		return root;
	}

	deletedNode=root;
	/*3.要删除的节点==找的的节点*/
	//a.删除节点不存在左右字节点 直接删除
	if(root->lchild==NULL && root->rchild==NULL) return NULL;

	//b.删除节点只存在右子节点 直接用右子节点取代删除节点
	if(root->lchild==NULL&&root->rchild!=NULL) return root->rchild;

	//c.删除节点只存在左子节点 直接用左子节点取代删除节点
	if(root->lchild!=NULL&&root->rchild==NULL) return root->lchild;

	//d.删除节点存在左右子节点
	int val=findMax(root->lchild);
	root->data=val;
	root->lchild=DeleteNode(root->lchild,val,deletedNode);

	return root;
}


/*循环的方式查找节点
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

/*	递归的方式查找节点
	@param root 根节点
	@param e  要查找的元素
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
*	递归实现前序遍历
	@param root 根节点指针
	return 无
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
*	前序遍历
*	@param root 根节点指针
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

		if(cur.rchild!=NULL)	//右子节点先入栈
		{
			PushStack(stack,*(cur.rchild));
		}

		if(cur.lchild!=NULL)  //左字节点后入栈
		{
			PushStack(stack,*(cur.lchild));
		}
	}
	//释放内存
	DestroyStack(stack);
}

void FloorPrint(Bnode* root)  //层序遍历
{
    Bnode* temp[100];   //创建pTreeNode指针类型的指针数组
    int in = 0;
    int out = 0;

    temp[in] = root;  //先保存二叉树根节点 
	in++;

    while (in > out)
    {
        if (temp[out])
        {
            //cout << temp[out]->data << " → ";
            temp[in] = temp[out]->lchild;
			in++;
            temp[in] = temp[out]->rchild;
			in++;
        }
        out++;
    }
	for(int i=0;i<out;i++)
	{
		cout << temp[i]->data << " → ";
	}
}


/**
 * Create a Media Player object from a Media
 *
 * \param p_md the media. Afterwards the p_md can be safely
 *        destroyed.
 * \return a new media player object, or NULL on error.
 */
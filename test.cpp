#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"tree.h"


int main()
{
	int test[]={19,7,25,5,11,15,21,61};
	Bnode *root=NULL,*node=NULL;

	node=new Bnode;	//动态内存分配
	node->data=test[0];
	InsertBtree(&root,node);	//插入根节点(第一个节点)

	for(int i=1;i<sizeof(test)/sizeof(test[0]);i++)
	{
		node =new Bnode;
		node->data=test[i];
		if(InsertBtree(&root,node)){
			printf("节点%d插入成功\n",node->data);
		}else{
			
		}
	}

	printf("\n");

	printf("前序遍历的结果：\n");
	//PreOrderRec(root);
	PreOrder(root);

	printf("层序遍历的结果：\n");
	FloorPrint(root);

	Bnode* deletedNode=NULL;
	DeleteNode(root,14,deletedNode);
	if(deletedNode)   delete deletedNode;

	printf("\n");
	printf("二叉树删除节点,节点14%s\n",deletedNode!=NULL?"删除成功":"删除不成功");
	
	//二叉树查找节点
	Bnode* node1=queryByRec(root,20);
	printf("搜索二叉树,节点20%s\n",node1!=NULL?"存在":"不存在");

	Bnode* node2=queryByRec(root,21);
	printf("搜索二叉树,节点21%s\n",node2!=NULL?"存在":"不存在");

	system("pause");
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"tree.h"


int main()
{
	int test[]={19,7,25,5,11,15,21,61};
	Bnode *root=NULL,*node=NULL;

	node=new Bnode;	//��̬�ڴ����
	node->data=test[0];
	InsertBtree(&root,node);	//������ڵ�(��һ���ڵ�)

	for(int i=1;i<sizeof(test)/sizeof(test[0]);i++)
	{
		node =new Bnode;
		node->data=test[i];
		if(InsertBtree(&root,node)){
			printf("�ڵ�%d����ɹ�\n",node->data);
		}else{
			
		}
	}

	printf("\n");

	printf("ǰ������Ľ����\n");
	//PreOrderRec(root);
	PreOrder(root);

	printf("��������Ľ����\n");
	FloorPrint(root);

	Bnode* deletedNode=NULL;
	DeleteNode(root,14,deletedNode);
	if(deletedNode)   delete deletedNode;

	printf("\n");
	printf("������ɾ���ڵ�,�ڵ�14%s\n",deletedNode!=NULL?"ɾ���ɹ�":"ɾ�����ɹ�");
	
	//���������ҽڵ�
	Bnode* node1=queryByRec(root,20);
	printf("����������,�ڵ�20%s\n",node1!=NULL?"����":"������");

	Bnode* node2=queryByRec(root,21);
	printf("����������,�ڵ�21%s\n",node2!=NULL?"����":"������");

	system("pause");
	return 0;
}
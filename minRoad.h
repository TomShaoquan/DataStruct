#include<iostream>
using namespace std;

#define MaxSize 1024

//Ҫ����Ļ�������
typedef struct EdgeNode	//�ߵĽڵ�
{
	int adjvex;	       //�ڽӶ�����
	int weight;
	struct EdgeNode* next;//��һ����
}EdgeNode;

typedef struct _VertexNode{	//����
	char data;			//�������� 
	struct EdgeNode* first;	//ָ���ڽӵ�һ����
}VertexNode,AdjList;

typedef struct _AdjListGraph{
	AdjList* adjlist;
	int vex;	//������
	int edge;	//����
}AdjListGraph;
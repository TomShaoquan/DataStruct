#include<iostream>
using namespace std;

#define MaxSize 1024

//要保存的基本数据
typedef struct EdgeNode	//边的节点
{
	int adjvex;	       //邻接顶点编号
	int weight;
	struct EdgeNode* next;//下一条边
}EdgeNode;

typedef struct _VertexNode{	//顶点
	char data;			//顶点数据 
	struct EdgeNode* first;	//指向邻接第一条边
}VertexNode,AdjList;

typedef struct _AdjListGraph{
	AdjList* adjlist;
	int vex;	//顶点数
	int edge;	//边数
}AdjListGraph;
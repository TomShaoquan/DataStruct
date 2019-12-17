#include"road.h"
#include<queue>

bool visited[MaxSize];
/*
	图的初始化
	@param G 保存图的结构
	无返回值
*/
void Init(AdjListGraph& G)
{
	G.adjlist=new AdjList[MaxSize];
	G.edge=0;
	G.vex=0;
	memset(visited,0,MaxSize);
}

/*
	获取元素在图中的位置
	@param G 保存图的结构
	@param c  要查的字符（顶点）
	return -1 表示不存在,否则返回顶点的编号
*/
int Location(AdjListGraph& G,char c)
{
	for(int i=0;i<G.vex;i++)
	{
		if(G.adjlist[i].data==c)
		{
			return i;
		}
	}
	return -1;
}

/*
	图的创建
	@param G 保存图的结构
	无返回值
*/
void Create(AdjListGraph& G)
{
	cout<<"请输入该图的顶点数及边数："<<endl;
	cin>>G.vex>>G.edge;

	cout<<"请输入相关顶点:"<<endl;
	for(int i=0;i<G.vex;i++)
	{
		cin>>G.adjlist[i].data;
		G.adjlist[i].first=NULL;
	}

	char v1=0,v2=0;
	int i1,i2;
	//int weight=0;
	cout<<"请输入相关联的顶点："<<endl;
	for(int j=0;j<G.edge;j++)
	{
		cin>>v1>>v2;
		i1=Location(G,v1);
		i2=Location(G,v2);

		if(i1 !=-1 && i2 !=-1)
		{
			//两两结成一对
			EdgeNode* temp=new EdgeNode;
			temp->adjvex=i2;
			temp->weight=0;
			temp->next=G.adjlist[i1].first;
			G.adjlist[i1].first=temp;
		}
	}
}

/*
	对图上的顶点进行深度遍历
	@param G 保存图的结构
	@param i 顶点在图中的位置数组索引值
	无返回值
*/
void DFS(AdjListGraph& G,int i)
{
	if(visited[i]) return;	//递归调用的出口

	int next=-1;
	cout<<G.adjlist[i].data<<" ";
	visited[i]=true;
	EdgeNode* temp=G.adjlist[i].first;
	if(temp)
	{
		next=temp->adjvex; //邻接顶点
		temp=temp->next;
		if(visited[next]==false)
		{
			//递归调用
			DFS(G,next);
		}
	}
}

int min_weights=0x7FFFFFFF;
/*
	对所有的顶点进行深度遍历
	@param G 保存图的结构
	无返回值
*/
void DFS_Main(AdjListGraph& G)
{
	for(int i=0;i<G.vex;i++)
	{
		if(visited[i]==false)
		{
			DFS(G,i);
		}
	}
}

/*
	对所有的顶点进行广度遍历
	@param G 保存图的结构
	@param i 顶点在图中的数组下标
	无返回值
*/
void BFS(AdjListGraph& G,int i)
{
	queue<int> q;
	int cur=-1;
	int index=-1;

	q.push(i);

	while(!q.empty())
	{
		cur=q.front();
		if(visited[cur]==false)
		{
			cout<<G.adjlist[cur].data<<"  ";
			visited[cur]=true;
		}
		q.pop();

		EdgeNode* temp=G.adjlist[cur].first;

		while(temp!=NULL)
		{
			index=temp->adjvex;
			temp=temp->next;
			q.push(index);
		}
	}


}
/*
	对图上所有顶点进行广度遍历
	@param G 保存图的结构
	无返回值
*/
void BFS_Main(AdjListGraph& G)
{
	for(int i=0;i<G.vex;i++)
	{
		if(visited[i]==false)
		{
			BFS(G,i);
		}
	}
}
int main()
{
	AdjListGraph G;
	Init(G);

	//创建图
	Create(G);

	//遍历图
	BFS_Main(G);

	system("pause");
	return 0;
}
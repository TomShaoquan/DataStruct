#include"road.h"
#include<queue>

bool visited[MaxSize];
/*
	ͼ�ĳ�ʼ��
	@param G ����ͼ�Ľṹ
	�޷���ֵ
*/
void Init(AdjListGraph& G)
{
	G.adjlist=new AdjList[MaxSize];
	G.edge=0;
	G.vex=0;
	memset(visited,0,MaxSize);
}

/*
	��ȡԪ����ͼ�е�λ��
	@param G ����ͼ�Ľṹ
	@param c  Ҫ����ַ������㣩
	return -1 ��ʾ������,���򷵻ض���ı��
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
	ͼ�Ĵ���
	@param G ����ͼ�Ľṹ
	�޷���ֵ
*/
void Create(AdjListGraph& G)
{
	cout<<"�������ͼ�Ķ�������������"<<endl;
	cin>>G.vex>>G.edge;

	cout<<"��������ض���:"<<endl;
	for(int i=0;i<G.vex;i++)
	{
		cin>>G.adjlist[i].data;
		G.adjlist[i].first=NULL;
	}

	char v1=0,v2=0;
	int i1,i2;
	//int weight=0;
	cout<<"������������Ķ��㣺"<<endl;
	for(int j=0;j<G.edge;j++)
	{
		cin>>v1>>v2;
		i1=Location(G,v1);
		i2=Location(G,v2);

		if(i1 !=-1 && i2 !=-1)
		{
			//�������һ��
			EdgeNode* temp=new EdgeNode;
			temp->adjvex=i2;
			temp->weight=0;
			temp->next=G.adjlist[i1].first;
			G.adjlist[i1].first=temp;
		}
	}
}

/*
	��ͼ�ϵĶ��������ȱ���
	@param G ����ͼ�Ľṹ
	@param i ������ͼ�е�λ����������ֵ
	�޷���ֵ
*/
void DFS(AdjListGraph& G,int i)
{
	if(visited[i]) return;	//�ݹ���õĳ���

	int next=-1;
	cout<<G.adjlist[i].data<<" ";
	visited[i]=true;
	EdgeNode* temp=G.adjlist[i].first;
	if(temp)
	{
		next=temp->adjvex; //�ڽӶ���
		temp=temp->next;
		if(visited[next]==false)
		{
			//�ݹ����
			DFS(G,next);
		}
	}
}

int min_weights=0x7FFFFFFF;
/*
	�����еĶ��������ȱ���
	@param G ����ͼ�Ľṹ
	�޷���ֵ
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
	�����еĶ�����й�ȱ���
	@param G ����ͼ�Ľṹ
	@param i ������ͼ�е������±�
	�޷���ֵ
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
	��ͼ�����ж�����й�ȱ���
	@param G ����ͼ�Ľṹ
	�޷���ֵ
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

	//����ͼ
	Create(G);

	//����ͼ
	BFS_Main(G);

	system("pause");
	return 0;
}
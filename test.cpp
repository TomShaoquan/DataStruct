
#include"queue.h"

int main()
{
	SeqQueue *SQ=new SeqQueue;
	DataType data;
	InitQueue(SQ);

	for(int j=0;j<7;j++)
	{
		EnterQueue(SQ,j+1);
	}
	PrintQueue(SQ);
	for(int k=0;k<10;k++)
	{
		DeleteQueue(SQ,&data);
		cout<<"����Ԫ�أ�"<<data<<endl;
	}
	GetHead(SQ,&data);
	cout<<data<<endl;
	PrintQueue(SQ);
	cout<<"Ԫ�ظ���"<<GetLength(SQ)<<endl;

	//���
	for(int j=0;j<4;j++)
	{
		EnterQueue(SQ,10+j);
	}
	PrintQueue(SQ);
	ClearQueue(SQ);
	delete SQ;
	system("pause");
	return 0;
}
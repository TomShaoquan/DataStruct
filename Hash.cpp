#include"hash.h"

/*
	����keyֵ������������λHashͰ��λ��
	@param key ��ֵ 
	@param TableSize ��ϣ��Ĵ�С
	����ֵ ��ϣ�������ֵ
*/
int Hash(int key,int TableSize)
{
	return (key%TableSize);
}

/*	��ʼ����ϣ��
	@param TableSize ��ϣ���С
	ʧ�ܷܰ���NULL,�ɹ����ر����ϣ��Ľṹ
*/
HashTable* InitHash(int TableSize)
{
	int i=0;
	HashTable*  hTable=NULL;

	if(TableSize<=0)
		TableSize=DEFAULT_SIZE;
	/*ΪHashͰ�����ڴ�ռ� ����Ϊһ��ָ������*/
	hTable=(HashTable *)malloc(sizeof(HashTable));
	if(!hTable)
	{
		printf("HashTable malloc error");
		free(hTable);
		return NULL;
	}
	hTable->TableSize=TableSize;
	//ΪHashͰ�����ڴ�ռ�
	hTable->Thelists=(List *)malloc(sizeof(List) * TableSize);
	if(NULL==hTable->Thelists)
	{
		printf("HashTable malloc error\n");
		free(hTable);
		return NULL;
	}
	//ΪHash Ͱ��Ӧ��ָ�������ʼ������ڵ�
	for(i=0;i<TableSize;i++)
	{
		hTable->Thelists[i]=(listNode * )malloc(sizeof(listNode));
		if(NULL==hTable->Thelists[i])
		{
			printf("HashTable malloc error\n");
			free(hTable->Thelists);
			free(hTable);
			return NULL;
		}
		else
		{
			memset(hTable->Thelists[i],0,sizeof(listNode));
		}
	}
	return hTable;
}

/*
	�ӹ�ϣ���и��ݼ�ֵ����Ԫ��
	@param HashTable ��ϣ��ṹ
	@param key ��ֵ
	����ֵ �ǿ� ���� key ֵ�Ľڵ�ָ��,ΪNULL��ʾû�иü�ֵ
*/
Element Find(HashTable *HashTable,int key)
{
	int i=0;
	List L=NULL;
	Element e=NULL;
	i=Hash(key,HashTable->TableSize);
	L=HashTable->Thelists[i];
	e=L->next;
	while(e!=NULL && e->key!= key)
	{
		e=e->next;
	}
	return e;
}
/*
*	��ϣ�����Ԫ�أ�Ԫ��Ϊ��ֵ��
	@param HashTable ��ϣ��ṹ
	@param key   ��
	@param value ֵ
	�޷���ֵ
*/
void Insert(HashTable* HashTable,int key,void* value)
{
	Element e=NULL,tmp=NULL;
	List L=NULL;
	e=Find(HashTable,key);

	if(NULL==e)
	{
		tmp=(Element)malloc(sizeof(listNode));
		if(NULL==tmp)
		{
			printf("malloc error\n");
			return;
		}
		//ǰ�巨
		L=HashTable->Thelists[Hash(key,HashTable->TableSize)];//�����һ��

		tmp->data=value;
		tmp->key=key;
		tmp->next=L->next;
		L->next=tmp;
	}
	else
	{
		printf("the key already exist\n");
	}

}

/*
	��ϣ��ɾ��Ԫ�أ�Ԫ��Ϊ��ֵ��
	@param HashTable ��ϣ��ṹ
	@param key ��ֵ
	����ֵ ��
*/
void Delete(HashTable *HashTable,int key)
{
	Element e=NULL,last=NULL;
	List L=NULL;
	int i=Hash(key,HashTable->TableSize);
	L=HashTable->Thelists[i];

	last=L;
	e=L->next;
	while(e!=NULL && key!=key)
	{
		last=e;
		e=e->next;
	}
	if(e)	//�����ֵ�Դ���
	{
		last->next=e->next;
		free(e);
	}
}

/*
	��ϣ������ȡ����
	@param e Ҫ��ȡ��Ԫ��
	������ȡ������
**/
void* Retrieve(Element e)
{
	return e ? e->data :  NULL;
}
int main()
{
	//ָ������
	char *elems[]={"�仨","С��","����ʦ"};
	int i=0;

	HashTable *HashTable=NULL;
	//��ʼ��31�ű�
	HashTable=InitHash(31);
	
	Insert(HashTable,1,elems[0]);
	Insert(HashTable,2,elems[1]);
	Insert(HashTable,3,elems[2]);

	Delete(HashTable,1);

	for(int i=0;i<4;i++)
	{
		Element e=Find(HashTable,i);
		if(e)
		{
			printf("%s\n",(const char *)Retrieve(e));
		}
		else
		{
			printf("Not found [key:%d]\n",i);
		}
	}
	system("pause");
	return 0;
}
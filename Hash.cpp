#include"hash.h"

/*
	根据key值计算索引，定位Hash桶的位置
	@param key 键值 
	@param TableSize 哈希表的大小
	返回值 哈希表的索引值
*/
int Hash(int key,int TableSize)
{
	return (key%TableSize);
}

/*	初始化哈希表
	@param TableSize 哈希表大小
	失败败返回NULL,成功返回保存哈希表的结构
*/
HashTable* InitHash(int TableSize)
{
	int i=0;
	HashTable*  hTable=NULL;

	if(TableSize<=0)
		TableSize=DEFAULT_SIZE;
	/*为Hash桶分配内存空间 ，其为一个指针数组*/
	hTable=(HashTable *)malloc(sizeof(HashTable));
	if(!hTable)
	{
		printf("HashTable malloc error");
		free(hTable);
		return NULL;
	}
	hTable->TableSize=TableSize;
	//为Hash桶分配内存空间
	hTable->Thelists=(List *)malloc(sizeof(List) * TableSize);
	if(NULL==hTable->Thelists)
	{
		printf("HashTable malloc error\n");
		free(hTable);
		return NULL;
	}
	//为Hash 桶对应的指针数组初始化链表节点
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
	从哈希表中根据键值查找元素
	@param HashTable 哈希表结构
	@param key 键值
	返回值 非空 包含 key 值的节点指针,为NULL表示没有该键值
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
*	哈希表插入元素，元素为键值对
	@param HashTable 哈希表结构
	@param key   键
	@param value 值
	无返回值
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
		//前插法
		L=HashTable->Thelists[Hash(key,HashTable->TableSize)];//保存第一个

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
	哈希表删除元素，元素为键值对
	@param HashTable 哈希表结构
	@param key 键值
	返回值 无
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
	if(e)	//如果键值对存在
	{
		last->next=e->next;
		free(e);
	}
}

/*
	哈希表中提取数据
	@param e 要提取的元素
	返回提取的数据
**/
void* Retrieve(Element e)
{
	return e ? e->data :  NULL;
}
int main()
{
	//指针数组
	char *elems[]={"翠花","小芳","苍老师"};
	int i=0;

	HashTable *HashTable=NULL;
	//初始化31张表
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
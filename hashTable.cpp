					/*****************************
					*							 *
					*	哈希表-顺序表算法实现    *
					*							 *
					******************************/
#include<stdio.h>
#include<Windows.h>

#define DEFAULE_SIZE 16		//哈希表的大小
#define BUCKET_SIZE 8		//哈希桶的大小
//哈希元素
typedef struct _hashElem
{
	int		key;
	void*	data;
}hashElem;
//哈希桶
typedef struct _SqList
{
	hashElem**   elems;		//顺序表的基地址
	int			 length;			//顺序表的长度
	int			 size;
}SqList;

typedef struct _hashTable
{
	int			  tableSize;
	SqList**	  bucket;		//保存一级指针
}hashTable;

/*
	找到键值对应的索引值
	@param hashTable 存储哈希表的结构
	@param key 键
	返回索引值
*/
int hash(hashTable* hashTable,int key)
{
	return (key%hashTable->tableSize);
}

/*
	初始化哈希表
	@param tableSize 哈希表大小
	返回存储哈希表的指针
**/
hashTable* initHash(int tableSize)
{
	hashTable* hTable=NULL;
	hTable=new hashTable;

	if(tableSize<=0)
		tableSize=DEFAULE_SIZE;

	hTable->tableSize=tableSize;

	//为Hash桶分配内存空间
	hTable->bucket=new SqList*[tableSize];		
	if(hTable==NULL)
	{
		printf("hashTable malloc error\n");
		delete[] hTable;
		return NULL;
	}

	//为Hash 桶对应的指针数组初始化
	//hashElem*  e=NULL;
	SqList*    tmp=NULL;
	for(int i=0;i<tableSize;i++)
	{
		
		//动态内存分配返回的是地址  数组名称就是地址
		tmp=hTable->bucket[i]=new SqList;

		if(tmp==NULL)
		{
			printf("hashTable malloc error\n");
			delete[] hTable->bucket[i];
			return NULL;
		}
		tmp->size=BUCKET_SIZE;
		tmp->length=0;
		tmp->elems=new hashElem*[tmp->size];
		if(tmp->elems==NULL)
		{
			printf("hashTable malloc error\n");
			delete[] tmp->elems;
			return NULL;
		}
		//为每一个一级指针变量分配内存
		for(int k=0;k<tmp->size;k++)
		{
			tmp->elems[k]=new hashElem;
			memset(tmp->elems[k],0,sizeof(hashElem));
		}
	}
	return hTable;
}
/*
	根据键值查找元素
	@param hashTable 存储哈希表的结构
	@param key 键值
	返回NULL表示表中不存在该键值，找到返回存储该键值的结构的指针
*/

hashElem* findKey(hashTable* hashTable,int key)
{
	int i=0;
	hashElem* e=NULL;
	i=hash(hashTable,key);

	SqList* tmp=NULL;
	tmp=hashTable->bucket[i];

	for(int j=0;j<tmp->length;j++)
	{
		e=tmp->elems[j];
		if(e->key==key)
		{
			break;
		}
		else
		{
			e=NULL;
		}
	}
	return e;
}
/*
	哈希表的插入键值对
	@param hashTable 哈希表结构
	@param key 键
	@param vulue  值
*/
bool insert(hashTable* hashTable,int key,void* value)
{
	hashElem* e=NULL;
	e=findKey(hashTable,key);
	if(e)	//已经存在
	{
		printf("要插入的键值对已存在\n");
		return false;
	}
	else
	{
		int i=0;
		hashElem* tmp=new hashElem;
		tmp->data=value;
		tmp->key=key;
		SqList*    L=NULL;

		i=hash(hashTable,key);
		L=hashTable->bucket[i];
		L->elems[L->length]=tmp;
		L->length++;
	}
	return true;
}
/*
	删除哈希表中指定的键值对
	@param hashTable 哈希表结构
	@param key 键
	成功返回true else return false;
*/
bool hashDelete(hashTable* hashTable,int key)
{
	hashElem* e=NULL;
	e=findKey(hashTable,key);
	if(e)
	{
		int i=0;
		i=hash(hashTable,key);
		SqList* tmp=NULL;
		tmp=hashTable->bucket[i];
		hashElem* del=NULL;
		int j;
		for(j=0;j<tmp->length;j++)
		{
			del=tmp->elems[j];
			if(del->key==key)
				break;
		}
		//删除的是最后一个
		if(tmp->length==j)
		{
			delete del;
			tmp->length--;
			return true;
		}
		//所有元素依次往前移
		for(int k=j;k<tmp->length;k++)
		{
			tmp->elems[k]=tmp->elems[k+1];
		}
		delete del;
		tmp->length--;
	}
	else
	{
		return false;
	}
}
/*
	销毁哈希表
	@param hashTable 哈希表结构
*/
bool hashDestroy(hashTable* hashTable)
{
	SqList* tmp=NULL;
	for(int i=0;i<hashTable->tableSize;i++)
	{
		tmp=hashTable->bucket[i];
		//销毁Hash桶中的顺序表
		for(int j=0;j<tmp->length;j++)
		{
			delete tmp->elems[j];
		}
		delete tmp;
	}
	delete hashTable;
	return true;
}
int main()
{
	char*  elems[]={"翠花","如花","西施"};
	hashTable* hashTable;
	hashTable=initHash(31);

	insert(hashTable,0,elems[0]);
	insert(hashTable,1,elems[1]);
	insert(hashTable,2,elems[2]);

	hashElem* e=NULL;
	for(int i=0;i<5;i++)
	{
		e=findKey(hashTable,i);
		if(e)	//返回不为空
		{
			printf("%s\n",(const char* )e->data);
		}
		else
		{
			printf("Not found [key:%d]\n",i);
		}
	}
	hashDelete(hashTable,1);
	printf("\n\n删除后:\n");
	for(int i=0;i<5;i++)
	{
		e=findKey(hashTable,i);
		if(e)	//返回子不为空
		{
			printf("%s\n",(const char* )e->data);
		}
		else
		{
			printf("Not found [key:%d]\n",i);
		}
	}

	//销毁哈希表
	hashDestroy(hashTable);
	system("pause");
	return 0;
}
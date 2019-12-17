					/*****************************
					*							 *
					*	��ϣ��-˳����㷨ʵ��    *
					*							 *
					******************************/
#include<stdio.h>
#include<Windows.h>

#define DEFAULE_SIZE 16		//��ϣ��Ĵ�С
#define BUCKET_SIZE 8		//��ϣͰ�Ĵ�С
//��ϣԪ��
typedef struct _hashElem
{
	int		key;
	void*	data;
}hashElem;
//��ϣͰ
typedef struct _SqList
{
	hashElem**   elems;		//˳���Ļ���ַ
	int			 length;			//˳���ĳ���
	int			 size;
}SqList;

typedef struct _hashTable
{
	int			  tableSize;
	SqList**	  bucket;		//����һ��ָ��
}hashTable;

/*
	�ҵ���ֵ��Ӧ������ֵ
	@param hashTable �洢��ϣ��Ľṹ
	@param key ��
	��������ֵ
*/
int hash(hashTable* hashTable,int key)
{
	return (key%hashTable->tableSize);
}

/*
	��ʼ����ϣ��
	@param tableSize ��ϣ���С
	���ش洢��ϣ���ָ��
**/
hashTable* initHash(int tableSize)
{
	hashTable* hTable=NULL;
	hTable=new hashTable;

	if(tableSize<=0)
		tableSize=DEFAULE_SIZE;

	hTable->tableSize=tableSize;

	//ΪHashͰ�����ڴ�ռ�
	hTable->bucket=new SqList*[tableSize];		
	if(hTable==NULL)
	{
		printf("hashTable malloc error\n");
		delete[] hTable;
		return NULL;
	}

	//ΪHash Ͱ��Ӧ��ָ�������ʼ��
	//hashElem*  e=NULL;
	SqList*    tmp=NULL;
	for(int i=0;i<tableSize;i++)
	{
		
		//��̬�ڴ���䷵�ص��ǵ�ַ  �������ƾ��ǵ�ַ
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
		//Ϊÿһ��һ��ָ����������ڴ�
		for(int k=0;k<tmp->size;k++)
		{
			tmp->elems[k]=new hashElem;
			memset(tmp->elems[k],0,sizeof(hashElem));
		}
	}
	return hTable;
}
/*
	���ݼ�ֵ����Ԫ��
	@param hashTable �洢��ϣ��Ľṹ
	@param key ��ֵ
	����NULL��ʾ���в����ڸü�ֵ���ҵ����ش洢�ü�ֵ�Ľṹ��ָ��
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
	��ϣ��Ĳ����ֵ��
	@param hashTable ��ϣ��ṹ
	@param key ��
	@param vulue  ֵ
*/
bool insert(hashTable* hashTable,int key,void* value)
{
	hashElem* e=NULL;
	e=findKey(hashTable,key);
	if(e)	//�Ѿ�����
	{
		printf("Ҫ����ļ�ֵ���Ѵ���\n");
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
	ɾ����ϣ����ָ���ļ�ֵ��
	@param hashTable ��ϣ��ṹ
	@param key ��
	�ɹ�����true else return false;
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
		//ɾ���������һ��
		if(tmp->length==j)
		{
			delete del;
			tmp->length--;
			return true;
		}
		//����Ԫ��������ǰ��
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
	���ٹ�ϣ��
	@param hashTable ��ϣ��ṹ
*/
bool hashDestroy(hashTable* hashTable)
{
	SqList* tmp=NULL;
	for(int i=0;i<hashTable->tableSize;i++)
	{
		tmp=hashTable->bucket[i];
		//����HashͰ�е�˳���
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
	char*  elems[]={"�仨","�绨","��ʩ"};
	hashTable* hashTable;
	hashTable=initHash(31);

	insert(hashTable,0,elems[0]);
	insert(hashTable,1,elems[1]);
	insert(hashTable,2,elems[2]);

	hashElem* e=NULL;
	for(int i=0;i<5;i++)
	{
		e=findKey(hashTable,i);
		if(e)	//���ز�Ϊ��
		{
			printf("%s\n",(const char* )e->data);
		}
		else
		{
			printf("Not found [key:%d]\n",i);
		}
	}
	hashDelete(hashTable,1);
	printf("\n\nɾ����:\n");
	for(int i=0;i<5;i++)
	{
		e=findKey(hashTable,i);
		if(e)	//�����Ӳ�Ϊ��
		{
			printf("%s\n",(const char* )e->data);
		}
		else
		{
			printf("Not found [key:%d]\n",i);
		}
	}

	//���ٹ�ϣ��
	hashDestroy(hashTable);
	system("pause");
	return 0;
}
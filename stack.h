
#define MaxSize 128
typedef int DataType;

typedef struct Bnode{
	DataType data;
	struct Bnode *lchild,*rchild;	//指向左右孩子的节点
}Bnode,Btree;

typedef Bnode ElemType;

typedef struct SqStack{

	ElemType* base;		//栈底指针
	ElemType* top;		//栈顶指针
}SqStack;

bool initStack(SqStack &S);
bool PushStack(SqStack &S,ElemType e);
bool PopStack(SqStack &S,ElemType &e);
bool IsEmpty(SqStack &S);
void DestroyStack(SqStack &S);
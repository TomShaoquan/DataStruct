#include"bintree.h"

void test()
{
    pTreeNode T;
    InitTreeNode(&T);

    CreateBinTree(&T);  //创建一个二叉树

    cout << "前序遍历:" << endl;
    PreOrderPrint(T);    //前序遍历

    cout << "\n中序遍历:" << endl;
    MidOrderPrint(T);   //中序遍历

    cout << "\n后序遍历:" << endl;
    PostOrderPrint(T);   //后续遍历

    cout << "\n层序遍历:" << endl;
    FloorPrint(T);

    cout << "\n层序遍历——Queue:" << endl;
    FloorPrint_QUEUE(T);
}

int main(void)
{
    test();
    return 0;
}
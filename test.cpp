#include"bintree.h"

void test()
{
    pTreeNode T;
    InitTreeNode(&T);

    CreateBinTree(&T);  //����һ��������

    cout << "ǰ�����:" << endl;
    PreOrderPrint(T);    //ǰ�����

    cout << "\n�������:" << endl;
    MidOrderPrint(T);   //�������

    cout << "\n�������:" << endl;
    PostOrderPrint(T);   //��������

    cout << "\n�������:" << endl;
    FloorPrint(T);

    cout << "\n�����������Queue:" << endl;
    FloorPrint_QUEUE(T);
}

int main(void)
{
    test();
    return 0;
}
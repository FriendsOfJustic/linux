
#include "BinarySearchTree.h"

void test1()
{
    BinarySearchTree<int> s;
    int a[] = {5, 3, 4, 1, 7, 8, 2, 6, 0, 9};

    for (auto &e : a)
    {
        s.insert(e);
    }

    /*  s.InOrder();

     // s.Erase(2);
     s.Erase(5);
     s.InOrder(); */

    for (auto &e : a)
    {
        s.Erase(e);
        s.InOrder();
    }
}

void test2()
{
    BinarySearchTree<int> s;
    int a[] = {5, 3, 4, 1, 7, 8, 2, 6, 0, 9};

    for (auto &e : a)
    {
        s.insert_R(e);
    }
    s.InOrder();

    /*  s.Erase(2);
     s.Erase(5);
     s.InOrder();  */

    for (auto &e : a)
    {
        s.Erase_R(e);
        s.InOrder();
    }
}
int main()
{
    test2();

    return 0;
}
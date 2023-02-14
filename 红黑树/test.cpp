#include <vector>
#include "RedBlackTree.h"
using namespace std;
int main()
{
    sht::RBTree<int, int> t;
    vector<int> v = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
    /* t.insert(make_pair(4, 0));

    t.insert(make_pair(2, 0));

    t.insert(make_pair(6, 0));
    t.insert(make_pair(1, 0)); */

    for (auto &e : v)
    {
        t.insert(make_pair(e, 0));
    }
    t.BFS();
}
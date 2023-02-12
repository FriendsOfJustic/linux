
#include "AVLTree.h"
#include <vector>

using namespace std;

int main()
{
    sht::AVLTree<int, int> s;
    vector<int> v = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};

    for (auto &e : v)
    {
        s.insert(make_pair(e, 0));
        s.BFS();
    }

    /* s.insert(make_pair(4, 0));
    s.BFS();
    s.insert(make_pair(2, 0));
    s.BFS(); */
    /* s.insert(make_pair(3, 0));
    s.BFS(); */
}
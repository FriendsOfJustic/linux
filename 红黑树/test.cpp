#include <vector>
#include "RedBlackTree.h"
#include <random>
#include <ctime>

using namespace std;
#define TESTNUMBER 1000

void make_random(vector<int> &num)
{
    srand(time(nullptr));

    for (int i = 0; i < TESTNUMBER; i++)
    {
        num.push_back(random());
    }
    return;
}
int main()
{
    sht::RBTree<int, int> t;
    vector<int> v = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
    vector<int> v2 = {16, 3, 7, 11, 9, 26, 18, 14, 15};
    /* t.insert(make_pair(4, 0));

    t.insert(make_pair(2, 0));

    t.insert(make_pair(6, 0));
    t.insert(make_pair(1, 0)); */

    vector<int> test;

    make_random(test);
    for (auto &e : test)
    {
        t.insert(make_pair(e, 0));
    }
    t.BFS();
    t.IsBalnace();
}
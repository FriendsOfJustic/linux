#include "map.h"
#include <iostream>
using namespace std;
int main()
{
    sht::map<int, int> m;
    vector<int> v = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
    /*  for (auto e : v)
     {
         m.insert(make_pair(e, 0));
     }
     m.BFS(); */

    /* auto it = m.begin();

    while (it != m.end())
    {
        cout << it->first << endl;
        ++it;
    } */

    /*  auto it = m.begin();
     sht::map<int, int>::const_iterator is = m.begin();
     // is->first++;

     cout << it->first << endl;
     // it->first++;
     it->second++;
     ++it;
     --it;
     cout << it->first << endl; */

    m.insert(make_pair(1, 0));
    m.insert(make_pair(2, 0));
    m.insert(make_pair(3, 0));
    m.insert(make_pair(4, 0));
    auto it = m.insert(make_pair(1, 0));

    if (it.second == false)
    {
        cout << "插入失败" << endl;
        cout << (it.first)->first << endl;
    }
}
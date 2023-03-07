#include "map.h"
#include <iostream>
using namespace std;
int main()
{
    sht::map<int, int> m;
    vector<int> v = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
    for (auto e : v)
    {
        m.insert(make_pair(e, 0));
    }

    //sht::map<int, int>::const_iterator it = m.begin();
    //sht::map<int, int>::iterator is = m.begin();
    sht::map<int, int>::const_iterator it=m.begin();

    m.BFS();
    //+this	0x0075fc10 {p = 0x00000000 < NULL > }	sht::RBTreeiterator<std::pair<int const, int>, std::pair<int const, int> const*, std::pair<int const, int> const&>*
    //+		*this	{p=0x00000000 <NULL> }	sht::RBTreeiterator<std::pair<int const ,int>,std::pair<int const ,int> const *,std::pair<int const ,int> const &>

    /* auto it = m.begin();

    while (it != m.end())
    {
        cout << it->first << endl;
        ++it;
    } */

    //auto it = m.begin();
    //sht::map<int, int>::const_iterator is = m.begin();
    //// is->first++;

    //cout << it->first << endl;
    //// it->first++;
    //it->second++;
    //++it;
    //--it;
    //cout << it->first << endl;
   /* m.insert(make_pair(1, 0));
    m.insert(make_pair(2, 0));
    m.insert(make_pair(3, 0));
    m.BFS();
    auto it=m.insert(make_pair(1, 0));*/


    /*m[1]++;
    m[2]++;
    m[3]++;
    m[4]++;*/


    //sht::map<int, int>::const_iterator it = m.begin();

    m.BFS();
    

}
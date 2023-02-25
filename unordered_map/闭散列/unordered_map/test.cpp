

#include "unordered_map.h"

#include <iostream>

using namespace std;

int main()
{
    sht::unordered_map<string, int> m;
    vector<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> s2 = {9, 19, 29, 39, 49, 59, 2};
    vector<string> s3 = { "西瓜","苹果","梨子","大便","小便" };
    for (auto &e : s3)
    {
        m.insert(make_pair(e, 0));
    }

    auto it = m.find("大便");
    if (it == nullptr)
        cout << "没有找到" << endl;
    else
        cout << "找到";// << (it->val).first << endl;
    // m.insert(make_pair(10, 0));

    // sht::HashNode<int, int> *p = m.find(make_pair(19, 0));
    // cout << (p->val).first << endl;
}
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    /* int a;
    while (cin >> a)
    {
        int cur = 0;
        int max = 0;
        int flag = 0;
        for (int i = 0; i < 32; i++)
        {
            if (flag == 0)
            {
                if (a & 1)
                {
                    flag = 1;
                    cur++;
                }
            }
            else
            {
                if ((a & 1) == 0)
                {
                    if (cur > max)
                        max = cur;
                    cur = 0;
                    flag = 0;
                }
                else
                {
                    cur++;
                }
            }
            a = a >> 1;
        }
        return max;
    } */

    // 统计水果出现的次数
    /* string arr[] = {"苹果", "西瓜", "香蕉", "草莓", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉"};
    ;

    // map
    map<string, int> m;
    for (auto e : arr)
    {
        auto it = m.insert(make_pair(e, 1));
        if (it.second == false)
        {
            auto is = m.find(e);
            is->second++;
        }
    } */

    /*  greater<int> com;
     vector<int> s = {1, 22, 3, 4, 5, 6, 8, 45};
     priority_queue<int, vector<int>, greater<int>> st;
     for (const auto &e : s)
     {
         st.push(e);
     }
     cout << st.top() << endl; */

    /* void rotateleft(Node* parent)
    {
        Node *p = parent->father;

        Node *p1 = parent->right;

        Node *p2 = p1->left;

        p1->left = parent;
        parent->father = p1;
        parent->right = p2;
        if(p2)
        p2->father = parent;

        p1->father = p;

        parent->bf = 0;

    } */

    void RotateR(Node * parent)
    {
        Node *pparent = parent->_parent;
        Node *subL = parent->left;
        Node *subLR = subL->right;

        parent->left = subLR;
        if (subLR)
            subLR->_parent = parent;

        subL->right = parent;
        prent->_parent = subL;

        if (pparent)
        {
            if (pparnt->left == parent)
            {
                pparent->left = subL;
                subL->_parnet = pparent;
            }
            else
            {
                pparent->right = subL;
                subL->_parnet = pparent;
            }
        }
        else
        {
            subL->_parent = pparent;
            root = subL;
        }

        subL->bf = 0;
        parent->bf = 0;
    }
}

#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;
class Solution {
public:

    vector<string> cin_cal()
    {
        vector<string> r;
        char c = ' ';
        while (c != '\n')
        {
            string tmp;
            cin >> tmp;
            r.push_back(tmp);
            cin.get(c);
        }

        return r;

    }
    int priorityJudge(string stacktop, string x)//判断优先级，如果操作符小于栈顶返回1 ,如果大于返回0
    {
        if (stacktop[1] > x[1])
        {
            return 1;
        }
        else if (stacktop[1] < x[1])
        {
            return 0;
        }
        else
        {
            if ((x[0] == '+' || x[0] == '-') && (stacktop[0] == '*' || stacktop[0] == '/'))
                return 1;
            if ((x[0] == '*' || x[0] == '/') && (stacktop[0] == '+' || stacktop[0] == '-'))
                return 0;
            return stacktop[0] - x[0];
        }
    }
    vector<string> fun(vector<string>& x) //中缀 到 后缀表达式
    {

        stack<string> p;  //用来运算的栈
        vector<string> result;
        int ret = 0;
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i].size() == 1 && (x[i][0] == '+' || x[i][0] == '-' || x[i][0] == '*' || x[i][0] == '/' || x[i][0] == '(' || x[i][0] == ')'))
            {
                if (x[i][0] == '(')
                {
                    ret++;
                    continue;
                }
                else if (x[i][0] == ')')
                {
                    ret--;
                    continue;
                }
                else if (p.empty())
                {
                    string n;
                    if (ret)
                    {
                        n.push_back(x[i][0]);
                        n.push_back(ret);
                    }
                    else
                    {
                        n.push_back(x[i][0]);
                        n.push_back(ret);
                    }
                    p.push(n);
                    continue;
                }




                if (priorityJudge(p.top(), x[i]))//判断优先级，如果操作符小于栈顶返回1 ,如果大于返回0
                {
                    char a = p.top()[0];
                    string b;
                    b.push_back(a);
                    result.push_back(b);
                    p.pop();
                    i--;
                }
                else  // 优先级大于 栈顶的
                {
                    string n;
                    if (ret)
                    {
                        n.push_back(x[i][0]);
                        n.push_back(ret);
                    }
                    else
                    {
                        n.push_back(x[i][0]);
                        n.push_back(ret);
                    }
                }


            }
            else
            {
                result.push_back(x[i]);
            }

        }

        while (p.empty() == false)
        {
            string b;
            b.push_back(p.top()[0]);
            result.push_back(b);
            p.pop();
        }
        return result;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> v;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i].size() == 1)
            {
                if (tokens[i][0] == '+')
                {
                    int a = v.top();
                    v.pop();
                    int b = v.top();
                    v.pop();

                    v.push(a + b);
                    continue;

                }
                else if (tokens[i][0] == '-')
                {
                    int a = v.top();
                    v.pop();
                    int b = v.top();
                    v.pop();

                    v.push(b - a);
                    continue;

                }
                else if (tokens[i][0] == '*')
                {
                    int a = v.top();
                    v.pop();
                    int b = v.top();
                    v.pop();

                    v.push(a * b);
                    continue;
                }
                else if (tokens[i][0] == '/')
                {
                    int a = v.top();
                    v.pop();
                    int b = v.top();
                    v.pop();

                    v.push(b / a);
                    continue;
                }

            }
            v.push(stoi(tokens[i]));


        }
        return v.top();

    }

    void Calculator()
    {
        vector<string> p = cin_cal();
        vector<string> ret = fun(p);
        cout << evalRPN(ret);
    }
};

int main()
{
    Solution s;
    s.Calculator();
}

#include <iostream>

using namespace std;

int main()
{
    int a;
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
    }
}
#define _CRT_SECURE_NO_WARNINGS 1


#include"priority__queue.h"
using namespace std;
int main()
{
	sht::priority__queue<int, std::vector<int>> v;

	v.push(10);
	v.push(1234);
	v.push(2314);
	v.push(123);
	v.push(1420);
	v.push(124140);
	v.push(1032);

	v.push(120);
	
	v.pop();
	cout << v.top() << endl;

}
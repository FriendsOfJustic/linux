#define _CRT_SECURE_NO_WARNINGS 1
#include"unordered_map.h"
#include<iostream>

using namespace std;
//void test1()
//{
//	sht::unordered_map<int, int> m;
//	vector<int> s1 = { 1,2,3,4,5,6,7,8,9,10 };
//	vector<int> s2 = { 1,11,21,31,41,51,61,71,81,91,101,111 };
//	for (auto& e : s2)
//	{
//		m.insert(make_pair(e, 0));
//	}
//
//	m.insert(make_pair(11, 0));
//
//
//	auto it = m.find(11);
//}
//
//
void test2()
{
	sht::unordered_map<string, int> m;
	vector<string> s = { "西瓜","苹果","香蕉","大便","猕猴桃","桃子","咖啡","王一鸣","魏子涵","袁德宝","周敬轩" };

	for (auto& e : s)
	{
		m.insert(make_pair(e, 0));
	}
}


void test3()
{
	sht::unordered_map<string, int> m;
	vector<string> s = { "西瓜","苹果","香蕉","大便","猕猴桃","桃子","咖啡","王一鸣","魏子涵","袁德宝","周敬轩" };

	for (auto& e : s)
	{
		m.insert(make_pair(e, 0));
	}

	auto it = m.begin();
	
	
	while (it != m.end())
	{
		cout << (*it).first << endl;
		++it;
	}

}


void test4()
{
	sht::unordered_map<string, int> m;
	vector<string> s = { "西瓜","苹果","香蕉","大便","猕猴桃","桃子","咖啡","王一鸣","魏子涵","袁德宝","周敬轩" };

	for (auto e : s)
	{
		m[e]++;
	}


	auto it = m.begin();


	while (it != m.end())
	{
		cout << (*it).first << endl;
		++it;
	}

}


int main()
{
	//test2();

	test4();

}
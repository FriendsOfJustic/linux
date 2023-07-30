#define _CRT_SECURE_NO_WARNINGS 1



#include"BTree.h"
#include<iostream>
#include<vector>
using namespace std;
#include<random>
#include<time.h>
#include<set>
int main()
{
	sht::BTree<int, 3> t;

	vector<int> s;//= { 53,139,75,49,145,36,101,33,78,146 ,180,33,199,50,52,43,41,22,10,9,8,7 };
	srand((unsigned int)time(NULL));
	set<int> st;
	for (int i = 0; i < 1000; i++)
	{
		int k = rand() % 1000;
		st.insert(k);
	}
	cout << "������������" << st.size() << endl;
	//��С��1000���Ĳ��ظ���������������
	for (auto e : st)
		s.push_back(e);

	//�������߼�
	for (int i=0;i<s.size();i++)
	{
		t.insert(s[i]);
		cout << t.is_Btree() << endl;
	}
	cout << "______________________________" << endl;
	//���ɾ���߼�
	for (int i = s.size()-1; i >= 0; i--)
	{
		t.erase(s[i]);
		cout << t.is_Btree() << endl;
	}
}
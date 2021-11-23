#include<iostream>

#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v;
	v.reserve(10);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	
	vector<int>::iterator it = find(v.begin(), v.end(), 3);

	vector<int>::iterator before = v.begin();
	v.insert(it, 20);

  
	vector<int>::iterator after=v.begin();
	*it = 30;

	vector<int>::iterator is = v.begin();
	while (is != v.end())
	{
		cout << *is << " ";
		is++;
	}
	cout << endl;
	return 0;

}

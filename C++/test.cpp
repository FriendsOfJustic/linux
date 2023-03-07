#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;
//
//inline int fun(int x, int y);
//inline int fun(int x, int y)
//{
//	return x + y;
//}
//
//int add(int x, int y)
//{
//	return x + y;
//}
////int add(int x, int y=0)
////{
////	return x + y;
////}
////
////double add(int x, int y)
////{
////	return x + y;
////}
//
//double add(double x, double y)
//{
//	return x + y;
//}
//
//long add(long x, long y)
//{
//	return x + y;
//}
//




//
//int main()
//{
//	/*int a = 10;
//	int& b = a;
//	printf("%p\n", &a);
//	printf("%p\n", &b);*/
//
//	/*int a = 10;
//	int b = 20;
//	int& r = a;
//	int& ra = b;
//	int& r;*/
//
//	//int& a = 10;   //错误的，常量必须要加const
//	//const int& b = 10;
//	//int& c = b;    //错误的，常量必须要加const
//	//const int& d = b;
//
//
//
//
//	//const int p = 20;
//	//const int& ps = p;   //这里因为p是const类型，他的引用就必须是const类型，p和ps都无法修改
//
//
//
//
//
//
//	//int x = 20;
//	//const int& y = x;
//
//	//x = 30;
//	//y = 40;//const限制了y的权限，所以引用y是不可以修改的
//
//
//
//	int a = 1;
//	double b = 2;
//
//
//	const int& c = b;
//
//}

//
//void swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//
//int& count()
//{
//	static int n = 0;
//	n++;
//	return n;
//}
//
//int& add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = add(1, 2);
//	printf("hello world\n");
//	cout << ret << endl;
//	return 0;
//}



//int cube1(int x)
//{
//	x *= x * x;
//	return x;
//
//}


//
//int cube1(int& x)
//{
//	return x * x * x;
//
//}
//
//int cube2(const int& x)
//{
//	return x * x * x;
//
//}
//
//
//int main()
//{
//	/*int x1 = 3;
//	int x2 = 3;
//	cout << cube1(x1) << endl;
//	cout<<"x1:" << x1 << endl;*/
//
//
//	/*cout << cube2(x2) << endl;
//	cout << "x2:" << x2 << endl;*/
//
//	int x1 = 3;
//	//cout << cube1(x1 + 1) << endl;
//	cout << cube2(x1 + 1) << endl;
//}


//
//int add(const int& x)
//{
//	return x * x;
//}
//
//int main()
//{
//	cout<<fun(1, 2);
//	return 0;
//}


//
//#define fun(x)  x*x*x
//
////int main()
////{
////	int arry[] = { 1,2,3,4,5,6 };
////
////	for (auto& e : arry)
////	{
////		e *= 2;
////	}
////	for (auto e : arry)
////	{
////		cout << e << " ";
////	}
////}
//
//
//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//
//
//void f(int* x)
//{
//	cout << "f(int *x)" << endl;
//}
//
//int main()
//{
//	f(0);
//	f(NULL);
//}

//
//struct Student
//{
//	void SetStudentInfo(const char* s, int a)
//	{
//		strcpy(name, s);
//		age = a;
//
//	}
//	void print()
//	{
//		cout << name << "    " << age << endl;
//	}
//	char name[20];
//	int age;
//};
//
//class Student
//{
//public:
//	void SetStudentInfo(const char* s, int a);
//	void print();
//	char name[20];
//	int age;
//};
//
//void Student::SetStudentInfo(const char* s, int a)
//{
//	strcpy(name, s);
//	age = a;
//
//}
//void Student::print()
//{
//	cout << name << "    " << age << endl;
//}
//
//class A
//{
//public:
//	void f2();
//};
//
//
//class B
//{};
//
//int main()
//{
//
//	cout << sizeof(Student) << endl;
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//
//	/*Student s;
//	s.SetStudentInfo("Peter", 20);
//	s.print();
//	return 0;*/
//
//}

//
//class classname
//{
//
//	//类的体：由成员函数 和 成员变量 组成
//
//};//注意这里的分号
//
//
//
//class Data
//{
//public:
//	void print()
//	{
//		cout << "year: " << _year << " month: " << _month << " day: " << _day << endl;
//	}
//
//
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Data d1;
//	Data d2;
//	d1.SetDate(2021, 10, 12);
//	d2.SetDate(2020, 10, 12);
//}

//
//
//class A
//{
//public:
//	void printA()
//	{
//		cout << _a << endl;
//	}
//
//	void show()
//	{
//		cout << "show()" << endl;
//	}
//private:
//	int _a;
//};
//
//
//int main()
//{
//	A* p = nullptr;
//	p->printA();
//	p->show();
//}

//
//
//class stack
//{
//public:
//	stack(int capacity=4)
//	{
//		a = (int*)malloc(capacity * sizeof(int));
//		assert(a);
//		_capacity = capacity;
//		_sz = 0;
//	}
//	~stack()
//	{
//		if (a)
//		{
//			free(a);
//			a = NULL;
//			_capacity = 0;
//			_sz = 0;
//		}
//	}
//
//private:
//	int* a;
//	int _capacity;
//	int _sz;
//};
//
//int main()
//{
//	stack a;
//	return 0;
//}

//
//class String
//{
//public:
//	String(const char *str="jack ma")
//	{
//		p = (char*)malloc((strlen(str)+1) * sizeof(char));
//		strcpy(p, str);
//	}
//
//	~String()
//	{
//		if (p)
//		{
//			free(p);
//			p = NULL;
//		}
//
//	}
//private:
//	char* p;
//};
//
//class Person
//{
//public:
//	Person(int age = 20)
//	{
//		_age = age;
//	}
//private:
//	int _age;
//	String name;
//
//};
//
//int main()
//{
//	Person a1;
//	return 0;
//}

//
//class Data
//{
//public:
//
//	Data(int year = 0, int month = 1, int day = 1) 
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	/*Data(const Data& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//	}*/
//
//
//	void print()
//	{
//		cout  << endl << _year << endl << _month << endl << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Data d1(2021, 1, 1);
//	Data d2(d1);
//	d2.print();
//	return 0;
//}


//
//class stack
//{
//public:
//	stack(int capacity=4)
//	{
//		a = (int*)malloc(capacity * sizeof(int));
//		assert(a);
//		_capacity = capacity;
//		_sz = 0;
//	}
//	~stack()
//	{
//		if (a)
//		{
//			free(a);
//			a = NULL;
//			_capacity = 0;
//			_sz = 0;
//		}
//	}
//
//private:
//	int* a;
//	int _capacity;
//	int _sz;
//};
//
//class String
//{
//public:
//	String(const char *str="jack ma")
//	{
//		p = (char*)malloc((strlen(str)+1) * sizeof(char));
//		strcpy(p, str);
//	}
//
//	~String()
//	{
//		if (p)
//		{
//			free(p);
//			p = NULL;
//		}
//
//	}
//
//
//private:
//	char* p;
//};
//
//
//
//class Data
//{
//public:
//	Data(int year = 0, int month = 1, int day = 1)  //构造函数
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Data(const Data& d)  //拷贝构造函数
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	bool operator==(const Data& d)
//	{
//		if (_year == d._year && _month == d._month && _day == d._day)
//			return true;
//		else
//			return false;
//	}
//
//	Data& operator=(const Data& d)     //赋值运算符重载函数
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		
//		return *this;
//	}
//
//	void print()
//	{
//		cout  << endl << _year << endl << _month << endl << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	/*String s1("love");
//	String s2(s1);*/
//
//
//	Data d1(2021, 10, 12);
//	Data d2;
//	Data d3(d1);
//	Data d4;
//
//	/*d4 = d2 = d1;
//
//	d4.print();
//	d2.print();*/
//	/*cout << (d1 == d2) << endl << (d1 == d3) << endl;*/
//
//
//	d2 =d4= d1;
//	d4.print();
//	d2.print();
//
//
//
//
//
//
//
//
//	return 0;
//}
//
////Date& Date::operator-=(int day)
////{
////	_day -= day;
////	while (_day<=0)
////	{
////		_month--;
////		if (_month < 1)
////		{
////			_year--;
////			_month = 12;
////		}
////		_day += getmonth(_year, month);
////	}
////
////	return *this;
////}
//	
//
//

//
//class B
//{
//public:
//	B(int x=1,int y=2)
//	{
//		_x = x;
//		_y = y;
//
//		cout << "构造B()" << endl;
//	}
//
//
//	const B& operator=(const B& d1)
//	{
//		_x = d1._x;
//		_y = d1._y;
//
//		return *this;
//	}
//private:
//	int _x;
//	int _y;
//
//};
//
//class A
//{
//public:
//	A()
//	{
//		//cout << "A()" << endl;
//	}
//
//
//	~A()
//	{
//		//cout << "~A()" << endl;
//	}
//
//	A(const A& d)
//	{
//		cout << "拷贝" << endl;
//	}
//
//	A& operator = (const A& a)
//	{
//		cout << "=" << endl;
//		//_a = a._a;
//		return *this;
//	}
//
//private:
//	int _a;
//};
//A fun(A a)
//{
//	return a;
//}
//
//void  fun1(A a)
//{
//
//}
//int main()
//{
//	A a1;
//	A a2 = fun(a1);
//
//
//	//A a3(fun(a2));
//
//
//	//a() a() 
//
//}
//
//

	

//
//
//
//#include<iostream>
//#include<stdio.h>
//using namespace std;
//
//class Date
//{
//public:
//    int GetMonthDay(int year, int month);
//
//    Date(int year = 0, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//
//    }
//    int fun();
//
//    bool operator>(const Date& d);
//
//    Date& operator++();
//    int _year;
//    int _month;
//    int _day;
//};
//int Date::GetMonthDay(int year, int month)
//{
//    static int a[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
//    if (month == 2)
//    {
//        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//            return 29;
//        else
//            return 28;
//    }
//    else
//        return a[month - 1];
//}
//
//bool Date::operator>(const Date& d)
//{
//    if (_year > d._year)
//        return true;
//    if (_year == d._year && _month > d._month)
//        return true;
//    if (_year == d._year && _month == d._month && _day > d._day)
//        return true;
//    return false;
//}
//Date& Date::operator++()  //前置加加
//{
//    _day += 1;
//    if (_day > GetMonthDay(_year, _month))
//    {
//        _day -= GetMonthDay(_year, _month);
//        _month++;
//        if (_month > 12)
//        {
//            _year++;
//            _month = 1;
//        }
//    }
//    return *this;
//}
//
//
//
//int Date::fun()
//{
//    int count = 0;
//    while (_month > 1)
//    {
//        count += GetMonthDay(_year, _month);
//        _month--;
//    }
//    count += _day;
//    return count;
//}
//
//
//int main()
//{
//    Date d;
//    scanf("%d %d %d", &d._year, &d._month, &d._day);
//
//    int ret = d.fun();
//    cout << ret << endl;
//    return 0;
//}
//
//
//
//
//
//
//
//





//
//class A
//{
//public:
//	A()
//		:_a(0)
//	{}
//private:
//	int _a;
//};
//
//class B
//{
//private:
//	int _b;
//	A _aa;
//};
//
//
//int main()
//{
//	B bb;
//
//	return 0;
//}

//
//class A
//{
//public:
//	A* operator&()
//	{
//		return this;
//	}
//
//
//	const A* operator&()const
//	{
//		return this;
//	}
//};

//
//int main()
//{
//	A a;
//	printf("%p", &a);
//	return 0;
//}



//
//class A
//{
//	friend void  square(A& a);
//public:
//	A(int x=1)
//		:_a1(x)
//	{
//		count++;
//	}
//
//	static int Get_count()
//	{
//		return count;
//	}
//
//private:
//	int _a1;
//	static int count;
//};
//
//void  square(A& a)
//{
//	a._a1 *= 2;
//}
//
//int A::count = 0;
//
//int main()
//{
//	A a1(1);
//	
//	square(a1);
//
//	cout << A::Get_count() << endl;;
//	return 0;
//}





//
//class A
//{
//public:
//	A(int x = 1)
//		:_a1(x)
//	{
//	}
//
//	class B
//	{
//	public:
//		B(int b=1)
//		{
//			_b1 = b;
//		}
//	private:
//		int _b1;
//	};
//
//	
//private:
//	int _a1;
//};
//
//
//
//int main()
//{
//	A a1;
//	//B b1;
//	A::B b1;
//}





//
//class A
//{
//public:
//	A(int x=1)
//		:_a1(x)
//	{
//		cout << "A()" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//private:
//	int _a1;
//};
//
//A a;
//int main()
//{
//	A b;
//	A c;
//
//	static A d;
//}


//
//class A
//{
//public:
//	A(int a=100,int b=200)
//		:_a(a)
//		,_b(b)
//	{
//
//	}
//private:
//	int _a;
//	int _b;
//};
//
//
//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//
//
//	A* p2 = new A[3];
//
//
//	free(p1);
//	delete p2;
//}


//
//int main()
//{
//	char a[] = "安徽";
//
//	a[1] = -79;
//	cout << a << endl;
//
//
//	a[3] = -44;
//	cout << a << endl;
//
//}

//
//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        string news;
//
//        auto end1 = num1.end() - 1;
//        auto end2 = num2.end() - 1;
//
//        int size1 = num1.size();
//        int size2 = num2.size();
//
//        int ret = 0;
//
//        while (size1>0 || size2>0)
//        {
//            int a = 0, b = 0;
//            if (size1 > 0)
//            a = *end1 - '0';
//            if (size2 > 0)
//            b = *end2 - '0';
//            int c = a + b + ret;
//            ret = 0;
//
//            if (a + b > 9)
//            {
//                ret = 1;
//                c -= 10;
//            }
//
//            news.push_back('0' + c);
//            size1--;
//            size2--;
//            if (size1>0)
//                end1--;
//            if (size2>0)
//                end2--;
//        }
//        if (ret == 1)
//            news.push_back('1');
//        reverse(news.begin(), news.end());
//        return news;
//
//    }
//};
//
//int main()
//{
//    int m = 2;
//    Solution* p = new Solution[m];
//    /*Solution s;
//    string s1("99");
//    string s2("9");
//    cout << s.addStrings(s1, s2) << endl;
//    return 0;*/
//}

//
//
//#include<iostream>
//using namespace std;
//
//class date
//{
//public:
//    date(int year = 0, int month = 0, int day = 0, int add = 0)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//        , _add(add)
//    {
//
//    }
//
//    int GetMonthDay(int year, int month)
//    {
//        static int a[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
//        if (month == 2)
//        {
//            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//                return 29;
//            else
//                return 28;
//        }
//        else
//            return a[month - 1];
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//    int _add;
//
//};
//
//
//int main()
//{
//    /*int m;
//    cin >> m;
//    date* p = new date[m];*/
//    int a = 2;
//    printf("%.2d", a);
//
//
//}

//
//
//template<class T,typename K>
//void fun(T x, K y)
//{
//
//}
//int main()
//{
//
//}

//
//﻿int main(int argc, char* argv[])
//
//{
//
//	string strText = "How are you?";
//
//	string strSeparator = " ";
//
//	string strResult;
//
//	int size_pos = 0;
//
//	int size_prev_pos = 0;
//
//	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//
//	{
//
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//
//		cout << strResult << " ";
//
//		size_prev_pos = ++size_pos;
//
//	}
//
//	if (size_prev_pos != strText.size())
//
//	{
//
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//
//		cout << strResult << " ";
//
//	}
//
//	cout << endl;
//
//	return 0;
//
//}
//

//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//    char* p = NULL;
//    while (scanf("%s", p) != EOF)
//    {
//        string s(p);
//        int pos = -1;
//        int arr[26] = { 0 };
//        for (int i = 0; i < s.size(); i++)
//        {
//            arr[s[i] - 'a']++;
//        }
//
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (arr[s[i] - 'a'] == 1)
//            {
//                pos = i;
//                break;
//            }
//        }
//
//        if (pos == -1)
//            cout << pos << endl;
//        else
//            cout << s[pos] << endl;
//
//    }
//}

//
//class Solution {
//public:
//    int StrToInt(string str) {
//        int cur = str.size() - 1;
//        int  sum = 0;
//
//        while (cur >= 0)
//        {
//            if (!((str[cur] >= '0' && str[cur] <= '9') || ((str[cur] == '+' || str[cur] == '-') && cur == 0)))
//            {
//                return 0;
//            }
//            if (str[cur] >= '0' && str[cur] <= '9')
//            {
//                int temp = str[cur] - '0';
//                temp *= 10;
//                sum += temp;
//            }
//            else
//            {
//                if (str[cur] == '-')
//                    sum = 0 - sum;
//            }
//            cur--;
//
//        }
//        return sum;
//    }
//};
//int main()
//{
//    string s("+16");
//    Solution s1;
//    cout<<s1.StrToInt(s);
//
//}





//
//
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//    string s;
//    cin >> s;
//    int ret = s.rfind(" ");
//
//    if (ret == string::npos)
//        cout << s.size();
//    else
//    {
//        string temp = s.substr(ret, s.size() - ret);
//
//        cout << temp.size();
//    }
//    return 0;
//
//}

//
//class Solution {
//public:
//    string add(string n1, string n2)
//    {
//        int end1 = n1.size()-1;
//        int end2 = n2.size()-1;
//        int ret = 0;
//        string s;
//
//        while (end1>=0 || end2>=0)
//        {
//            int a = 0;
//            if (end1 >= 0)
//            a = n1[end1] - '0';
//
//            int b = 0;
//            if (end2 >= 0)
//            b = n2[end2] - '0';
//
//            int c = a + b + ret;
//
//            ret = 0;
//
//            if (c > 9)
//            {
//                c -= 10;
//                ret = 1;
//            }
//
//            s.push_back(c + '0');
//            if(end1>=0)
//            end1--;
//
//            if(end2>=0)
//            end2--;
//        }
//
//        if(ret==1)
//            s.push_back('1');
//
//
//        reverse(s.begin(), s.end());
//
//        return s;
//
//    }
//    string multiply(string num1, string num2) {
//
//        string cout("0");
//        string sum("0");
//
//
//        while (cout != num1)
//        {
//            sum=add(sum, num2);
//            cout=add(cout, "1");
//        }
//
//        return sum;
//
//
//    }
//};
//
//class Solution {
//public:
//    string reverseStr(string s, int k) {
//        int num = s.size();
//        int head = 0;
//
//
//
//        while (num > 0)
//        {
//            if (num < k)
//            {
//                reverse(s.end() - num, s.end());
//                num = -1;
//
//            }
//            else if (num < 2 * k)
//            {
//                reverse(s.end() - num, s.end() - num + k);
//                break;
//            }
//
//            if (num >= 2 * k)
//            {
//                reverse(s.begin() + head, s.begin() + k);
//                head += 2 * k;
//                num -= 2 * k;
//            }
//        }
//        return s;
//
//    }
//};
//
//int main()
//{
//    Solution s;
//    cout<<s.reverseStr("krmyfshbspcgtesxnnljhfursyissjnsocgdhgfxubewllxzqhpasguvlrxtkgatzfybprfmmfithphckksnvjkcvnsqgsgosfxc",20);
//}
//
//// krmyfshbspcgtesxnnlj  hfursyissjnsocgdhgfx  ubewllxzqhpasguvlrxt kgatzfybprfmmfithphc kksnvjkcvnsqgsgosfxc"
////"jlnnxsetgcpsbhsfymrk  hfursyissjnsocgdhgfx  ubewllxzqhpasguvlrxt kgatzfybprfmmfithphc cxfsogsgqsnvckjvnskk"
////"jlnnxsetgcpsbhsfymrk  hfursyissjnsocgdhgfx  txrlvugsaphqzxllwebu kgatzfybprfmmfithphc cxfsogsgqsnvckjvnskk" yuq
//           

//
//
//void resize(size_t n, char ch = '\0')
//{
//	if (n > _size)
//	{
//		if (n > _capacity)
//		{
//			reserve(n);
//		}
//		memset(_str + _size,ch, n - _size);
//	}
//
//	_size = n;
//
//
//}


//
//int main()
//{
//	string s("hello");
//}

//
//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        string news;
//
//        auto end1 = num1.end() - 1;
//        auto end2 = num2.end() - 1;
//
//        int size1 = num1.size();
//        int size2 = num2.size();
//
//        int ret = 0;
//
//        while (size1 > 0 || size2 > 0)
//        {
//            int a = 0, b = 0;
//            if (size1 > 0)
//                a = *end1 - '0';
//            if (size2 > 0)
//                b = *end2 - '0';
//            int c = a + b + ret;
//            ret = 0;
//
//            if (c > 9)
//            {
//                ret = 1;
//                c -= 10;
//            }
//
//            news.push_back('0' + c);
//            size1--;
//            size2--;
//            if (size1 > 0)
//                end1--;
//            if (size2 > 0)
//                end2--;
//        }
//
//        if (ret == 1)
//            news.push_back('1');
//
//        reverse(news.begin(), news.end());
//        return news;
//
//    }
//    string multiply(string num1, string num2) {
//        int size1 = num1.size();
//        int size2 = num2.size();
//        string s("0");
//
//        for (int i = size1 - 1; i >= 0; i--)
//        {
//            int a = num1[i] - '0';
//            int ret = 0;
//            string t;
//            for (int j = size2 - 1; j >= 0; j--)
//            {
//                int b = num2[j] - '0';
//
//                int c = a * b + ret;
//
//                ret = 0;
//                if (c > 9)
//                {
//                    ret = c / 10;
//                    c %= 10;
//                }
//                t.push_back(c + '0');
//
//
//            }
//            if (ret != 0)
//            {
//                t.push_back(ret + '0');
//            }
//            reverse(t.begin(), t.end());
//            for (int x = size1 - 1; x > i; x--)
//            {
//                t.push_back('0');
//            }
//            s=addStrings(t, s);
//
//        }
//        return s;
//
//    }
//};
//
//
//int main()
//{
//    Solution s;
//    string a("123");
//    string b("456");
//    cout<<s.multiply(a, b);
//}
//
//
//int main()
//{
//
//	
//	string s("hello");
//	s.resize(20);
//	s[19] = '9';
//	cout << s << endl;
//		/*char p2[10] = "bit";
//		char* p = p1;
//		swap(p1, p2);
//		cout << p << endl;*/
//		return 0;
//	
//}

//class Solution {
//public:
//    int firstUniqChar(string s) {
//        vector<int> v(26, 0);
//
//        auto cur = s.begin();
//        while (cur != s.end())
//        {
//            v[*cur - 'a']++;
//            cur++;
//        }
//
//        cur = s.begin();
//
//        while (cur != s.end())
//        {
//            if (v[*cur - '0'] == 1)
//                return cur - s.begin();
//            cur++;
//        }
//        return -1;
//
//
//
//    }
//};

//
//
//class Solution {
//public:
//    void replaceSpace(char* str, int length) {
//        int count = 0;
//
//        for (int i = 0; i < length; i++)
//        {
//            if (str[i] == ' ')
//                count++;
//        }
//        int newsize = length + 2 * count;
//
//        str[newsize] = str[length];
//
//        int i = newsize - 1;
//        int j = length - 1;
//
//        while (j >= 0)
//        {
//            if (str[j] == ' ')
//            {
//                str[i] = '0';
//                str[i - 1] = '2';
//                str[i - 2] = '%';
//                str -= 3;
//                j--;
//            }
//            else {
//                str[i] = str[j];
//                i--;
//                j--;
//            }
//        }
//
//    }
//};
//
//
//int main()
//{
//    Solution s;
//    char p[14] = "hello world";
//    s.replaceSpace(p, 11);
//    
//
//
//}


//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        int i = 0;
//        while (i != nums.size() - 1)
//        {
//            if (!(nums[i] == nums[i + 1] &&  nums[i + 1] = nums[i + 2]))
//                return nums[i];
//        }
//
//        return nums[i];
//
//
//    }
//};

//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        int i = 0;
//        while (i != nums.size() - 1)
//        {
//            int a = (nums[i] == nums[i + 1]);
//            int b = (nums[i + 1] = nums[i + 2]);
//            if (!(a && b))
//                return nums[i];
//            i += 3;
//        }
//
//        return nums[i];
//
//
//    }
//};
//
//class Solution {
//public:
//    vector<int> singleNumber(vector<int>& nums) {
//        int i = 0;
//        for (auto e : nums)
//        {
//            i = i ^ e;
//        }
//
//        int num = 1;
//
//        while (num)
//        {
//            if ((num & i))
//                break;
//
//            num << 1;
//        }
//
//        vector<int> v(2, 0);
//        for (auto e : nums)
//        {
//            if (e & num)
//                v[0] = v[0] ^ e;
//            else
//                v[1] ^= 3;
//
//        }
//        return v;
//
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> v({ 1,2,1,3,2,5 });
//    cout << s.singleNumber << endl;
//
//
//	/*vector<int> nums(10, 0);
//    int i = 0;
//
//	      while (1)
//        {
//            if (!(nums[i] == nums[i + 1] &&  nums[i + 1] = nums[i + 2]))
//                return nums[i];
//        }*/
//
//
//
//}

//class Solution {
//public:
//    bool isfull(vector<int> x, vector<string> v, string digits)
//    {
//        for (int i = 0; i < x.size(); i++)
//        {
//            if (x[i] != v[digits[i] - '2'].size()-1)
//                return false;
//        }
//
//        return true;
//
//    }
//
//    void add(vector<int>& count, vector<string> v, string digits)
//    {
//        count[count.size() - 1]++;
//
//        int ret = 0;
//        for (int i = count.size() - 1; i >= 0; i--)
//        {
//            count[i] += ret;
//            ret = 0;
//
//            if (count[i] >= v[digits[i] - '2'].size())
//            {
//                count[i] = 0;
//                ret = 1;
//            }
//        }
//
//    }
//    vector<string> letterCombinations(string digits) {
//        vector<string> v = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//        vector<int> count(digits.size(), 0);
//
//
//        vector<string> result;
//
//
//        while (!isfull(count, v, digits))
//        {
//
//            string tmp;
//            for (int i = 0; i < count.size(); i++)
//            {
//                tmp.push_back(v[digits[i] - '2'][count[i]]);
//            }
//            result.push_back(tmp);
//
//            add(count, v, digits);
//        }
//        string tmp;
//        for (int i = 0; i < count.size(); i++)
//        {
//            tmp.push_back(v[digits[i] - '2'][count[i]]);
//        }
//        result.push_back(tmp);
//
//        return result;
//
//
//
//
//
//    }
//};
//
//int main()
//{
//    Solution s;
//
//    string v("234");
//
//    vector<string> reult=s.letterCombinations(v);
//
//}


//hello






int main()
{
	vector<int> i;

	i.reserve(10);
	i.push_back(1);
	i.push_back(2);
	i.push_back(3);
	i.push_back(4);
	i.push_back(5);

	auto v = i.begin()+1;

	v=i.insert(v, 200);

	*v = 10;


	auto begin = i.begin();
	while (begin!= i.end())
	{
		cout << *begin << " ";
		begin++;
	}

	return 0;

}
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
////	int arry{] = { 1,2,3,4,5,6 };
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
//	char name{20];
//	int age;
//};
//
//class Student
//{
//public:
//	void SetStudentInfo(const char* s, int a);
//	void print();
//	char name{20];
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







//
//int main()
//{
//	vector<int> i;
//
//	i.reserve(10);
//	i.push_back(1);
//	i.push_back(2);
//	i.push_back(3);
//	i.push_back(4);
//	i.push_back(5);
//
//	auto v = i.begin()+1;
//
//	v=i.insert(v, 200);
//
//	*v = 10;
//
//
//	auto begin = i.begin();
//	while (begin!= i.end())
//	{
//		cout << *begin << " ";
//		begin++;
//	}
//
//	return 0;
//
//}

//
//int main()
//
//{
//
//	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };
//
//	int n = sizeof(ar) / sizeof(int);
//
//	vector<int> v(ar, ar + n);
//
//	vector<int>::iterator it = v.begin();
//
//	while (it != v.end())
//
//	{
//
//		if (*it != 0)
//
//			cout << *it;
//
//		else
//
//			v.erase(it);
//
//		it++;
//
//	}
//
//	return 0;
//
//}

//
//
//int main()
//{
//	/*const char* a = "abc";
//	char b[] = "abc";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//
//	free(ptr1);*/
//
//
//	int* ptr = new int;
//	int* ptr1 = new int(5);
//	int* ptr2 = new int[10];
//
//	cout << *ptr << endl;
//
//	delete ptr;
//	delete ptr1;
//	delete[] ptr2;
//


//void* operator new (size_t t);
//void* operator new[] (size_t t);
//void operator delete (void* p);
//void operator delete[] (void * p);

//
//class A
//{
//public:
//	static int _c;
//	A(int x=0)
//		:_b(x)
//	{
//		//cout << "构造函数" << endl;
//		_a = new int[5];
//
//	}
//
//	void* operator new(size_t t)
//	{
//
//		//cout << "调用 operator new" << endl;
//		A* p = (A*)::operator new(t);
//		_c++;
//		return p;
//	}
//
//	void operator delete(void* p)
//	{
//		//cout << "调用 operator delete" << endl;
//		::operator delete(p);
//		_c--;
//	}
//
//	~A()
//	{
//		//cout << "析构函数" << endl;
//		free(_a);
//		_a = NULL;
//
//	}
//private:
//	int* _a;
//	int _b;
//};
//
//int A::_c = 0;
//
//
//int main()
//{
//	/*A* p = new A(1);
//	delete p;*/
//	A* ps1 = new A(1);
//	A* ps2 = new A(2);
//	A* ps3 = new A(3);
//	A* ps4 = new A(4);
//	A* ps5 = new A(5);
//	A* ps6 = new A(6);
//	A* ps7 = new A(7);
//
//	
//
//	delete ps1;
//	delete ps2;
//	delete ps3;
//	delete ps4;
//	delete ps5;
//	delete ps6;
//	cout << A::_c << endl;
//
//	new(place_address) type(initializer_list);
//	new(place_address) type;
//}

//
//int main()
//{
//	/*string s = "hello";
//	s.reserve(100);
//	cout << s.capacity() << endl;*/
//
//
//	//int* p = (int*)malloc(sizeof(int) * 10);
//	
//	/*int* p = new int[10];
//
//	for (int i = 0; i < 10; i++)
//	{
//		new(p+i) int(5);
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << p[i] << " ";
//	}*/
//
//
//
//
//}



//
//
//
//class A
//{
//public:
//	static int _c;
//	A(int x=0)
//		:_b(x)
//	{
//		//cout << "构造函数" << endl;
//		_a = new int[5];
//	}
//
//	void* operator new(size_t t)
//	{
//		//cout << "调用 operator new" << endl;
//		A* p = (A*)::operator new(t);
//		_c++;
//		return p;
//	}
//
//	void operator delete(void* p)
//	{
//		//cout << "调用 operator delete" << endl;
//		::operator delete(p);
//		_c--;
//	}
//
//	~A()
//	{
//		//cout << "析构函数" << endl;
//		free(_a);
//		_a = NULL;
//	}
//private:
//	int* _a;
//	int _b;
//};
//
//
//
//int A::_c = 0;
//
//int main()
//{
//	A a;
//	A* p = new A;
//
//
//	delete p;
//	
//}

//
//#include<algorithm>
//
//
//
//struct listNode
//{
//	int val;
//	listNode* next;
//};
//
//int average(int* a, int n)
//{
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += a[i];
//
//	}
//	return sum;
//}
//
//
//int average(struct listNode* a)
//{
//	int sum = 0;
//	for (struct listNode *i=a;i != NULL; i=i->next)
//	{
//		sum += i->val;
//	}
//	return sum;
//
//
//}
//
//int main()
//{
//
//}


//
//
//int main()
//{
//	vector<int> v({ 1,2,3,4,5,6 });
//	vector<int>::iterator it = find(v.begin(), v.end(), 4);
//	reverse(v.begin(), it);
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//		e++;
//
//	}
//}


#include<stack>
#include<string>

//class Solution {
//public:
//    int evalRPN(vector<string>& tokens) {
//        stack<int> v;
//        for (int i = 0; i < tokens.size(); i++)
//        {
//            if (tokens[i] <= '9' && tokens[i] >= '0')
//            {
//                v.push_back(tokens[i] - '0');
//            }
//            else
//            {
//                if (tokens[i] == '+')
//                {
//                    int a = v.top();
//                    v.pop();
//                    int b = v.top();
//                    v.pop();
//
//                    v.push_back(a + b);
//
//                }
//                else if (tokens[i] == '-')
//                {
//                    int a = v.top();
//                    v.pop();
//                    int b = v.top();
//                    v.pop();
//
//                    v.push_back(b - a);
//
//                }
//                else if (tokens[i] == '*')
//                {
//                    int a = v.top();
//                    v.pop();
//                    int b = v.top();
//                    v.pop();
//
//                    v.push_back(a * b);
//                }
//                else if (tokens[i] == '/')
//                {
//                    int a = v.top();
//                    v.pop();
//                    int b = v.top();
//                    v.pop();
//
//                    v.push_back(b / a);
//                }
//            }
//        }
//
//    }
//};

//class Solution {
//public:
//    
//    vector<string> cin_cal()
//    {
//        vector<string> r;
//        char c=' ';
//        while (c != '\n')
//        {
//            string tmp;
//            cin >> tmp;
//            r.push_back(tmp);
//            cin.get(c);
//        }
//
//        return r;
//
//    }
//    int priorityJudge(string stacktop,string x)//判断优先级，如果操作符小于栈顶返回1 ,如果大于返回0
//    {
//        if (stacktop[1] > x[1])
//        {
//            return 1;
//        }
//        else if(stacktop[1] < x[1])
//        {
//            return 0;
//        }
//        else
//        {
//            if ((x[0] == '+' || x[0] == '-') && (stacktop[0] == '*' || stacktop[0] == '/'))
//                return 1;
//            if ((x[0] == '*' || x[0] == '/') && (stacktop[0] == '+' || stacktop[0] == '-'))
//                return 0;
//            return stacktop[0] - x[0];
//        }
//    }
//    vector<string> fun(vector<string>& x) //中缀 到 后缀表达式
//    {
//     
//        stack<string> p;  //用来运算的栈
//        vector<string> result;
//        int ret = 0;
//        for (int i = 0; i < x.size(); i++)
//        {
//            if (x[i].size() == 1 && (x[i][0] == '+' || x[i][0] == '-' || x[i][0] == '*' || x[i][0] == '/' || x[i][0] == '(' || x[i][0] == ')'))
//            {
//                if (x[i][0] == '(')
//                {
//                    ret ++;
//                    continue;
//                }
//                else if (x[i][0] == ')')
//                {
//                    ret --;
//                    continue;
//                }
//                else if (p.empty())
//                {
//                    string n;
//                    if (ret)
//                    {
//                        n.push_back(x[i][0]);
//                        n.push_back(ret);
//                    }
//                    else
//                    {
//                        n.push_back(x[i][0]);
//                        n.push_back(ret);
//                    }
//                    p.push(n);
//                    continue;
//                }
//
//
//                
//
//                if (priorityJudge(p.top(),x[i]))//判断优先级，如果操作符小于栈顶返回1 ,如果大于返回0
//                {
//                    char a = p.top()[0];
//                    string b;
//                    b.push_back(a);
//                    result.push_back(b);
//                    p.pop();
//                    i--;
//                }
//                else  // 优先级大于 栈顶的
//                {
//                    string n;
//                    if (ret)
//                    {
//                        n.push_back(x[i][0]);
//                        n.push_back(ret);
//                    }
//                    else
//                    {
//                        n.push_back(x[i][0]);
//                        n.push_back(ret);
//                    }
//                }
//
//
//            }
//            else
//            {
//                result.push_back(x[i]);
//            }
//
//        }
//
//        while (p.empty() == false)
//        {
//            string b;
//            b.push_back(p.top()[0]);
//            result.push_back(b);
//            p.pop();
//        }
//        return result;
//    }
//    int evalRPN(vector<string>& tokens) {
//        stack<int> v;
//        for (int i = 0; i < tokens.size(); i++)
//        {
//            if (tokens[i].size() == 1)
//            {
//                if (tokens[i][0] == '+')
//                {
//                    int a = v.top();
//                    v.pop();
//                    int b = v.top();
//                    v.pop();
//
//                    v.push(a + b);
//                    continue;
//
//                }
//                else if (tokens[i][0] == '-')
//                {
//                    int a = v.top();
//                    v.pop();
//                    int b = v.top();
//                    v.pop();
//
//                    v.push(b - a);
//                    continue;
//
//                }
//                else if (tokens[i][0] == '*')
//                {
//                    int a = v.top();
//                    v.pop();
//                    int b = v.top();
//                    v.pop();
//
//                    v.push(a * b);
//                    continue;
//                }
//                else if (tokens[i][0] == '/')
//                {
//                    int a = v.top();
//                    v.pop();
//                    int b = v.top();
//                    v.pop();
//
//                    v.push(b / a);
//                    continue;
//                }
//
//            }
//            v.push(stoi(tokens[i]));
//
//
//        }
//        return v.top();
//
//    }
//
//    void Calculator()
//    {
//        vector<string> p=cin_cal();
//        vector<string> ret=fun(p);
//        cout<<evalRPN(ret);
//    }
//};
//
//int main()
//{
//    Solution s;
//    s.Calculator();
//}
//




//class Solution {
//public:
//    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//        stack<int> v;
//        int j = 0;
//        for (int i = 0; i < pushV.size(); i++)
//        {
//            v.push(pushV[i]);
//            while (j < popV.size() && v.top() == popV[j])
//            {
//                v.pop();
//                j++;
//            }
//        }
//    
//
//        return v.empty();
//    }
//};
//int main()
//{
//    /*vector<int> v1({ 1,2,3,4,5 });
//    vector<int> v2({ 4,5,3,2,1 });
//
//    Solution s;
//
//
//    cout<<s.IsPopOrder(v1, v2);*/
//
//
//
//    vector<string> c({"(","(","2","+","1",")","*","3",")","*","3"});
//
//    Calculator s;
//    vector<string> p=s.cin_cal();
//    vector<string> ret=s.fun(p);
//    cout<<s.evalRPN(ret);
//
//}

//void adjustdown(int parent)
//{
//    int child = 2 * parent + 1;
//    while (child < _con.size())
//    {
//        child = 2 * parent + 1;
//        if (child+1<_con.size() && _con[child] > _con[child + 1])
//        {
//            swap(&_con[child], &_con[child + 1]);
//        }
//
//        if (_con[parent] < _con[child])
//        {
//            swap(&_con[parent], &_con[child]);
//            parent = child;
//        }
//        else
//            break;
//    }
//}
//
//class Solution {
//public:
//    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//        int j = 0;
//        stack<int> p;
//        for (int i = 0; i < pushV.size(); i++)
//        {
//            p.push(pushV[i]);
//            while (!p.empty() && p.top() == popV[j])
//            {
//                p.pop();
//                j++;
//            }
//
//        }
//        return p.empty();
//
//
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector<int> v1 = { 1,2,3,4,5 };
//    vector<int> v2 = { 4,5,3,2,1 };
//    s.IsPopOrder(v1, v2);
//
//}

//
//
//#include<queue>
//class MyStack {
//public:
//    MyStack() {
//
//    }
//
//    void push(int x) {
//        n1.push(x);
//
//
//    }
//
//    int pop() {
//        if (n1.empty())
//            return -1;
//
//        while (n1.size() != 1)
//        {
//            n2.push(n1.front());
//            n1.pop();
//       }
//        int a = n1.back();
//        n1.pop();
//        while (!n2.empty())
//        {
//            n1.push(n2.front());
//            n2.pop();
//        }
//        return a;
//
//    }
//
//
//
//    int top() {
//        return n1.back();
//
//    }
//
//    bool empty() {
//        return n1.empty();
//
//    }
//
//    queue<int> n1;
//    queue<int> n2;
//};
//int main()
//{
//    MyStack s;
//    s.push(1);
//    s.push(2);
//    cout<<s.pop()<<endl;
//    cout << s.top() << endl;
//}

#include<queue>

//
//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        
//        priority_queue<int, std::vector<int> ,greater<int> > p;
//
//        for (int i = 0; i < k; i++)
//        {
//            p.push(nums[i]);
//        }
//
//        for (int i = k; i < nums.size(); i++)
//        {
//            if (nums[i] > p.top())
//            {
//                p.pop();
//                p.push(nums[i]);
//            }
//        }
//
//        return p.top();
//
//    }
//};
//
//
//int main()
//{
//    Solution s;
//}

//vector<int> v1 = { 1,2,3,4 };
//vector<int> v1 = { 1,2,3,4 };
//}
//
//template<class T>
//void Swap(T& a, T& b)
//{
//	a.swap(b);
//}

//
//template<>
//void Swap<vector<int>>(vector<int>& a, vector<int>& b)
//{
//	a.swap(b);
//}

//template<>
//bool isequal<const char* const>(const char* const  &left, const char* const &right)
//{
//
//}

//template<>
//void Swap(vector<int>& a, vector<int>& b)
//{
//	a.swap(b);
//}
//
//int main()
//{
//
//
//
//}

//int main()
//{
//	double b = 3.1415926;
//	const int& a = b;
//
//	cout << a << endl;
//
//}
//
//
//template<class T>
//void Swap(T& a,T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//template<class T1,class T2>
//void Swap(T1& a, T2& b)
//{
//	T1 temp = a;
//	a = b;
//	b = temp;
//}
//
//
//
//void Swap(int & a, int & b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Swap(double& a, double& b)
//{
//	double temp = a;
//	a = b;
//	b = temp;
//}
//
//
//template<class T>
//T Add(T a, T b)
//{
//	return a + b;
//}
//
//
//int main()
//{
//	int a = 3;
//	int b = 2;
//	//double c = 3.14;
//
//	Swap(a, b);
//	Swap<int>(a, b);
//
//
//



	//Add(a, b);
	////Add(a, c);  这种事错误的，编译器无法推演出类型T到底是什么
	//Add(a, (int)c);


	//Add<int>(a, c);
	//Add<double>(a, c);

	/*Swap(a, c);*/

	/*double c = 3.14;
	double d = 4.5;
	Swap<double>(c, d);*/
//}


//template<class T1,class T2,.....>
//class 类名
//{
//	//类成员
//};


//template<class T>
//class A
//{
//public:
//	A();
//	~A();
//
//	void fun1()
//	{
//		cout << "类内定义" << endl;
//
//	}
//	void fun2();
//private:
//	T a;
//};
//
//template<class T>
//void A<T>::fun2()
//{
//	cout << "类外定义" << endl;
//}


//#include"fun.h"


//template<class T>
//void Swap(T& a,T& b)
//{
//
//	b = temp
//}
//
//int main()
//{
//	printf("hello world!\n");
//	return 0;
//
//}
//
//
//
//class Solution {
//public:
//    bool Find(int target, vector<vector<int> > array) 
//    {
//        
//        if (array.size() == 1 && array[0].size() == 0)
//            return false;
//        int i = array[0].size() - 1;
//        int j = array.size() - 1;
//        while (array[0][i] > target || array[j][0] > target)
//        {
//            if (array[0][i] > target)
//                i--;
//            if (array[j][0] > target)
//                j--;
//        }
//
//        for (int x = 0; x <= j; x++)
//        {
//            for (int y = 0; y <= i; y++)
//            {
//                if (target == array[x][y])
//                {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//};


//
//
//class Solution {
//public:
//    void replaceSpace(char* str, int length) {
//        int count = 0;
//        for (int i = 0; i < length; i++)
//        {
//            if (str[i] == ' ')
//                count++;
//        }
//        char* newstr = new char[length + 2 * count + 1];
//        int i = 0, j = 0;
//        for (i = 0, j = 0; i < length; i++, j++)
//        {
//            if (str[i] == ' ')
//            {
//                newstr[j++] = '%';
//                newstr[j++] = '2';
//                newstr[j] = '0';
//            }
//            else
//            {
//                newstr[j] = str[i];
//            }
//        }
//        newstr[j] = '\0';
//        str = newstr;
//
//    }
//};
//int main()
//{
//    Solution s;
//    char p[] = "hello world";
//    s.replaceSpace(p, 11);
//    cout << p << endl;
//}



//
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(const int x) :
//        val(x), next(NULL) {
//    }
//};
//
//class Solution {
//public:
//    ListNode* deleteDuplication(ListNode* head) {
//        while (head->val == head->next->val)
//        {
//            while (head->val == head->next->val)
//            {
//                head = head->next;
//            }
//            head = head->next;
//        }
//        ListNode* n1 = head;
//        ListNode* n2 = NULL;
//        ListNode* n3 = NULL;
//        if (n1->next)
//            n2 = head->next;
//        else
//            return n1;
//        if (n2->next)
//            n3 = n2->next;
//
//        while (n3)
//        {
//            if (n3->val != n2->val)
//            {
//                n3 = n1->next;
//                n2 = n2->next;
//                n1 = n1->next;
//            }
//            else
//            {
//                while (n3 && n3->val == n2->val)
//                {
//                    n3 = n3->next;
//                }
//                n1->next = n3;
//                n2 = n3;
//                if (n3)
//                    n3 = n3->next;
//            }
//        }
//        return head;
//
//
//    }
//};
//
//int main()
//{
//    ListNode n1(1);
//    ListNode n2(2);
//    ListNode n3(3);
//    ListNode n4(3);
//    ListNode n5(4);
//    ListNode n6(4);
//    ListNode n7(5);
//
//    n1.next = &n2;
//    n2.next = &n3;
//    n3.next = &n4;
//    n4.next = &n5;
//    n5.next = &n6;
//    n6.next = &n7;
//
//    Solution s;
//    s.deleteDuplication(&n1);
//
//
//

//}

//
//
//#include<deque>
//struct TreeNode {
//    int val;
//    struct TreeNode *left;
//    struct TreeNode *right;
//    TreeNode(int x) :
//            val(x), left(NULL), right(NULL) {
//    }
//};
//class Solution {
//public:
//    void fun(vector<vector<int>>& v, deque<int>& q, TreeNode* root, int expectNumber, int sum)
//    {
//        if (root == NULL)
//            return;
//        
//        if (sum == expectNumber && root->left == NULL && root->right == NULL)
//        {
//            vector<int> tmp;
//            deque<int> t(q);
//            while (!t.empty())
//            {
//                tmp.push_back(t.front());
//                t.pop_front();
//            }
//            v.push_back(tmp);
//        }
//        else
//        {
//            if (root->left != NULL)
//            {
//                q.push_back((root->left->val));
//                fun(v, q, root->left, expectNumber, sum + (root->left->val));
//
//                q.pop_back();
//            }
//
//            if (root->right == NULL)
//                return;
//            q.push_back(root->right->val);
//            fun(v, q, root->right, expectNumber, sum + (root->right->val));
//        }
//    }
//    vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
//        vector<vector<int>> v;
//        int sum = root->val;
//        deque<int> q;
//        q.push_front(root->val);
//        fun(v, q, root, expectNumber, sum);
//        return v;
//
//    }
//};
//
//
//int main()
//{
//    TreeNode n1(10);
//    TreeNode n2(5);
//    TreeNode n3(12);
//    TreeNode n4(4);
//    TreeNode n5(7);
//
//    n1.left = &n2;
//    n1.right = &n3;
//    n2.left = &n4;
//    n2.right = &n5;
//
//    Solution s;
//    vector<vector<int>> v;
//    v=s.FindPath(&n1, 22);
//
//}

//
//
//class Solution {
//public:
//    bool ifexit(vector<string>& r, string& str)
//    {
//        int ret = 1;
//        for (int i = 0; i < r.size(); i++)
//        {
//            if (str == r[i])
//                ret = 0;
//        }
//        if (ret)
//            return true;
//        else
//            return false;
//    }
//    void fun(vector<string>& r, vector<int> v, string& str)
//    {
//        if (v.size() == str.size())
//        {
//            string tmp;
//            for (int i = 0; i < str.size(); i++)
//            {
//                tmp.push_back(str[v[i]]);
//            }
//            if(ifexit(r,str))
//            r.push_back(tmp);
//            return;
//        }
//
//        for (int i = 0; i < str.size(); i++)
//        {
//            int ret = 1;
//            for (int j = 0; j < v.size(); j++)
//            {
//                if (v[j] == i)
//                    ret = 0;
//            }
//            if (ret) //入待定集合
//            {
//                v.push_back(i);
//                fun(r, v, str);
//                v.pop_back();
//            }
//        }
//    }
//    vector<string> Permutation(string str) {
//        vector<int> v;
//        vector<string> res;
//        fun(res, v, str);
//        return res;
//
//    }
//    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//        
//        priority_queue<int,vector<int>,greater<int>> p;
//        vector<int> result;
//        int i = 0;
//        while (k--)
//        {
//            p.push(input[i++]);
//        }
//
//        while (i < input.size())
//        {
//            if (input[i] > p.top())
//            {
//                p.pop();
//                p.push(input[i]);
//            }
//            i++;
//        }
//
//        while (p.empty())
//        {
//            result.push_back(p.top());
//            p.pop();
//        }
//        return result;
//
//
//    }
//    string longestPalindrome(string s) {
//        int i = 1;
//        int maxl = 1;
//        int maxr = 1;
//
//        for (; i < s.size(); i++)
//        {
//            int left = i - 1;
//            int right = i + 1;
//
//            while (left >= 0 && right <= s.size() && s[left] == s[right])
//            {
//                left--;
//                right++;
//            }
//            if (right - left - 1 > maxr - maxl)
//            {
//                maxl = left + 1;
//                maxr = right - 1;
//            }
//        }
//        string result;
//        while (maxl <= maxr)
//        {
//            result.push_back(s[maxl++]);
//        }
//        return result;
//    }
//};
//
//int main()
//{
//   /* string p("aab");
//    vector<int> s1 = { 4,5,1,6,2,7,3,8 };*/
//    string p("ababd");
//    Solution s;
//    vector<string> result;
//    s.longestPalindrome(p);
//    
//}


//
//class Solution {
//public:
//    vector<int> countBits(int n) {
//        int high = 0;
//        vector<int> v(n + 1);
//        v[0] = 0;
//        for (int i = 1; i < n + 1; i++)
//        {
//            if ((high & (high - 1)) == 0)
//                high = i;
//
//            v[i] = v[i - high] + 1;
//        }
//        return v;
//    }
//    void fun(stack<char> st, string s, vector<string>& result, int n)
//    {
//        if (n == 0 && st.empty()) //就是所有肯都已经入栈了，这时就要做判断了！
//        {
//            result.push_back(s);
//            return;
//        }
//
//        if (st.empty())
//            st.push('(');
//        fun(st, s + '(', result, --n);
//        st.pop();
//
//        if (st.top() == '(')
//            st.pop();
//        else
//            return;
//        fun(st, s + ')', result, --n);
//    }
//    vector<string> generateParenthesis(int n) {
//        string s;
//        vector<string> result;
//        stack<char> st;
//        fun(st, s, result, n);
//
//        return result;
//
//    }
//};
//
////#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std;
//bool istrue(int left, int right, string& s) //删除左边字符
//{
//    int ret = 1;
//    while (left < right)
//    {
//        if (s[left] != s[right])
//        {
//            ret = 0;
//            break;
//        }
//        left++;
//        right--;
//
//
//    }
//    return ret;
//}
//int main()
//{
//    vector<string> v;
//
//    int num = 0;
//    cin >> num;
//    for (int i = 0; i < num; i++)
//    {
//        string s;
//        cin >> s;
//        v.push_back(s);
//    }
//
//    for (int i = 0; i < num; i++)  //string v[i]
//    {
//        int left = 0;
//        int right = v[i].size() - 1;
//
//        while (left < right)
//        {
//            while (left < right && v[i][left] == v[i][right])
//            {
//                left++;
//                right--;
//            }
//
//            if (left == right)
//            {
//                cout << "-1" << endl;
//                break;
//            }
//            else
//            {
//                if (istrue(left + 1, right, v[i]))
//                {
//                    cout << left << endl;
//                    continue;
//                }
//                else
//                {
//                    cout << right << endl;
//                    continue;
//                }
//            }
//
//        }
//    }
//    return 0;
//
//}
//
//class Solution {
//public:
//    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
//        int a = data[0];
//        for (int i = 1; i < data.size(); i++)
//        {
//            a = a ^ data[i];
//        }
//
//        int b = a & (a - 1);
//
//        vector<int> n1;
//        vector<int> n2;
//
//        for (int i = 0; i < data.size(); i++)
//        {
//            if ((data[i] & b) == 0)
//                n1.push_back(data[i]);
//            else
//                n2.push_back(data[i]);
//        }
//        *num1 = n1[0];
//        for (int i = 1; i < n1.size(); i++)
//        {
//            *num1 = *num1 ^ n1[i];
//        }
//        *num2 = n2[0];
//        for (int i = 1; i < n2.size(); i++)
//        {
//            *num2 = *num2 ^ n2[i];
//        }
//        cout << *num1 << "       "<<*num2 << endl;
//
//    }
//};
//int main()
//{
//    vector<int> v({ 2,4,3,6,3,2,5,5 });
//    Solution s;
//    int a = 0, b = 0;
//    s.FindNumsAppearOnce(v, &a, &b);
//}

//
//string LeftRotateString(string str, int n) {
//
//    for (int i = 0; i < n; i++)
//    {
//        char tmp = str[0];
//        int j = 1;
//        for (j = 1; j < str.size(); j++)
//        {
//            str[j - 1] = str[j];
//        }
//        str[j] = tmp;
//    }
//    return str;
//
//}
//int main()
//{
//	string s("abc123");
//	LeftRotateString(s, 3);
//
//	cout << s << endl;
//
//}

//
//class Solution {
//public:
//    int minimumTotal(vector<vector<int> >& triangle) {
//        if (triangle.size() == 0)
//            return 0;
//
//        for (int i = 1; i < triangle.size(); i++)
//        {
//            for (int j = 0; j <=i; j++)
//            {
//                if (j == 0)
//                    triangle[i][j] += triangle[i - 1][j];
//                else if (j == i )
//                    triangle[i][j] += triangle[i - 1][j-1];
//                else
//                    triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
//            }
//        }
//
//        int min = triangle[triangle.size()-1][0];
//        for (int i = 0; i < triangle.size(); i++)
//            if (triangle[triangle.size()-1][i] < min)
//                min = triangle[triangle.size()-1][i];
//        return min;
//
//
//    }
//};
//int main()
//{
//    vector<vector<int>> n({ {20},{30,40},{60,50,70},{40,10,80,30} });
//
//    Solution s;
//    cout<<s.minimumTotal(n);
//}

//
//class Solution {
//public:
//    /**
//     *
//     * @param m int整型
//     * @param n int整型
//     * @return int整型
//     */
//    void fun(int sum, int m, int n, int& count)
//    {
//        if (sum == 0)
//        {
//            count++;
//            return;
//        }
//
//        if (m > 0)
//            fun(sum - 1, m - 1, n, count);
//        if (n > 0)
//            fun(sum - 1, m, n - 1, count);
//    }
//    int uniquePaths(int m, int n) {
//        // write code here
//        int count = 0;
//        fun(m + n - 2, m - 1, n - 1, count);
//        return count;
//    }
//};
//class Solution {
//public:
//    /**
//     *
//     * @param m int整型
//     * @param n int整型
//     * @return int整型
//     */
//    int uniquePaths(int m, int n) {
//        // write code here
//        vector<vector<int>> v;
//        v.resize(1);
//        v[0].push_back(0);
//
//        for (int i = 0; i < m; i++)
//        {
//
//            for (int j = 0; j < n; j++)
//            {
//                if (i == 0 && j == 0)
//                    v[i].push_back(0);
//                else if (i == 0)
//                    v[i].push_back(v[i][j - 1] + 1);
//                else if (j == 0)
//                    v[i].push_back(v[i - 1][j] + 1);
//                else
//                    v[i].push_back(v[i][j - 1] + v[i - 1][j] + 2);
//            }
//            v.push_back(vector<int>());
//        }
//        return v[m - 1][n - 1];
//    }
//};
//int main()
//{
//    Solution s;
//    cout<<s.uniquePaths(1, 2);
//}

//
//class Solution {
//public:
//    /**
//     *
//     * @param grid int整型vector<vector<>>
//     * @return int整型
//     */
//    int minPathSum(vector<vector<int> >& grid) {
//        // write code here
//        int row = grid.size();
//        int col = grid[0].size();
//
//        for (int i = 0; i < row; i++)
//        {
//            for (int j = 0; j < col; j++)
//            {
//                if (i - 1 >= 0 && j - 1 >= 0)
//                {
//                    if (grid[i - 1][j] < grid[i][j - 1])
//                        grid[i][j] += grid[i - 1][j];
//                    else
//                        grid[i][j] += grid[i][j - 1];
//                }
//                if (i - 1 >= 0)
//                    grid[i][j] += grid[i - 1][j];
//                if (j - 1 >= 0)
//                    grid[i][j] += grid[i][j - 1];
//            }
//        }
//        return grid[row - 1][col - 1];
//
//    }
//};
//class Solution {
//public:
//    /**
//     *
//     * @param grid int整型vector<vector<>>
//     * @return int整型
//     */
//    void fun(vector<vector<int> >& v, int col, int row, int& min, int sum)
//    {
//        if (col == 0 && row == 0)
//        {
//            sum += v[row][col];
//            if (sum < min)
//                min = sum;
//            return;
//        }
//
//        if (col > 0)
//            fun(v, col - 1, row, min, sum + v[row][col - 1]);
//        if (row > 0)
//            fun(v, col, row - 1, min, sum + v[row - 1][col]);
//    }
//    int minPathSum(vector<vector<int> >& grid) {
//        // write code here
//        if (grid.size() == 0)
//            return 0;
//        int sum = grid[grid.size() - 1][grid[0].size() - 1];
//        int min = 0;
//        for (int i = 0; i < grid.size(); i++)
//            min += grid[i][0];
//        for (int i = 1; i < grid[0].size(); i++)
//            min += grid[grid.size() - 1][i];
//        fun(grid, grid[0].size()-1, grid.size() - 1, min, 0);
//        return min;
//    }
//};
//
//int main()
//{
//    vector<vector<int>> v({ { 1,2 }, { 5,6 }, {1,1 } });
//    Solution s;
//    s.minPathSum(v);
//}



//class Solution {
//public:
//    int maxProduct(vector<int>& nums) {
//        if (nums.size() < 1)
//            return 0;
//        int size = nums.size();
//        int* result = new int[size];
//        result[0] = nums[0];
//        for (int i = 1; i > nums.size(); i++)
//        {
//            if (nums[i] * result[i - 1] > result[i - 1])
//                result[i] = nums[i] * result[i - 1];
//            else
//                result[i] = nums[i];
//
//        }
//        int max = result[0];
//        for (int i = 0; i < nums.size(); i++)
//            if (result[i] > max)
//                max = result[i];
//
//        return max;
//
//    }
//};


/*class Solution {
public:
    int max_a(int a, int b, int c)
    {
        int max = a;
        if (b > max)
            max = b;
        if (c > max)
            max = c;
        return max;
    }
    int min_a(int a, int b, int c)
    {
        int min = a;
        if (b < min)
            min = b;
        if (c < min)
            min = c;
        return min;
    }
    int maxProduct(vector<int>& nums) {
        if (nums.size() < 1)
            return 0;
        int size = nums.size();
        int* max = new int[size];
        int* min = new int[size];
        max[0] = nums[0];
        min[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            min[i] = max_a(nums[i], nums[i] * max[i - 1], nums[i] * min[i - 1]);
            max[i] = min_a(nums[i], nums[i] * max[i - 1], nums[i] * min[i - 1]);
        }
        int result = max[0];
        for (int i = 0; i < nums.size(); i++)
            if (max[i] > result)
                result = max[i];
        return result;

    }
}*/;
//int main()
//{
//    vector<int> v({ 2,3,-2,4 });
//    Solution s;
//    cout<<s.maxProduct(v);
//}



//class Solution {
//public:
//    int getMaxLen(vector<int>& nums) {
//        vector<int> n1; //自增参考数组
//        vector<int> n2;  // 
//        n1.push_back(0);
//        n2.push_back(0);
//        int ret = 1;
//        for (int i = 1; i < nums.size() + 1; i++)
//        {
//            if (nums[i - 1] == 0)
//            {
//                n1.push_back(0);
//                n2.push_back(0);
//                ret = 1;
//            }
//
//            if (nums[i - 1] > 0)
//            {
//                n1.push_back(n1[i - 1] + 1);
//                n2.push_back(n2[i - 1] + 1);
//            }
//
//            if (nums[i - 1] < 0)
//            {
//                if (ret == 1)
//                {
//                    n2.push_back(0);
//                    n1.push_back(n1[i - 1] + 1);
//                }
//                else
//                {
//                    n2.push_back(n1[i - 1] + 1);
//                    n1.push_back(n1[i - 1] + 1);
//                }
//                ret *= -1;
//            }
//        }
//        int max = n2[0];
//        for (int i = 0; i < n2.size(); i++)
//            if (n2[i] > max)
//                max = n2[i];
//
//        return max;
//
//
//    }
//};
//int main()
//{
//    vector<int> v({ -16,0,-5,2,2,-13,11,8 });
//    Solution s;
//    cout<<s.getMaxLen(v);
//}

//
//class Solution {
//public:
//    int choose_max(int a, int b, int c)
//    {
//        int max = a;
//        if (b > max)
//            max = b;
//        if (c > max)
//            max = c;
//        return max;
//    }
//    int maxProfit(vector<int>& prices) {
//        vector<int> result;
//        vector<int> min;
//        result.push_back(0);
//        min.push_back(prices[0]);
//        for (int i = 1; i < prices.size(); i++)
//        {
//            result.push_back(choose_max(0, prices[i] - min[i - 1], result[i - 1]));
//            if (prices[i] < min[i - 1])
//                min.push_back(prices[i]);
//        }
//
//        int max = result[0];
//        for (int i = 0; i < result.size(); i++)
//            if (result[i] > max)
//                max = result[i];
//        return max;
//    }
//};
//
//int main()
//{
//    vector<int> v({ 7,1,5,3,6,4 });
//    Solution s;
//    cout<<s.maxProfit(v);
//}

//
//
//class Solution {
//public:
//    int choose_max(int a, int b, int c)
//    {
//        int max = a;
//        if (b > max)
//            max = b;
//        if (c > max)
//            max = c;
//        return max;
//    }
//    int maxProfit(vector<int>& prices) {
//        int max = 0;
//        int min = prices[0];
//        int ret = 0;
//        for (int i = 1; i < prices.size(); i++)
//        {
//            if (max < choose_max(0, prices[i] - min, max))
//                max = choose_max(0, prices[i] - min + max, max);
//            if (max == prices[i] - min + max)
//                ret = 1;
//            if (prices[i] < min || ret == 1)
//            {
//                min = prices[i];
//                ret = 0;
//            }
//        }
//        return max;
//    }
//};
//
//int main()
//{
//    vector<int> v({ 7,1,5,3,6,4 });
//}
//
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        if (nums.size() == 1)
//            return nums[0];
//
//        if (nums.size() == 2)
//            return max(nums[0], nums[1]);
//
//        if (nums.size() == 3)
//            return max(nums[3], max(nums[0], nums[1]));
//
//        int head_in1 = nums[1];
//        int head_in2 = max(nums[1], nums[2]);
//        int head_in3 = 0;
//        for (int i = 3; i < nums.size() - 2; i++)
//        {
//            head_in3 = max(head_in1 + nums[i], head_in2);
//            head_in1 = head_in2;
//            head_in2 = head_in3;
//        }
//
//        int head_out1 = nums[0];
//        int head_out2 = max(nums[0], nums[1]);
//        int head_out3 = 0;
//
//        for (int i = 2; i < nums.size() - 1; i++)
//        {
//            head_out3 = max(head_out1 + nums[i], head_out2);
//            head_out1 = head_out2;
//            head_out2 = head_out3;
//        }
//
//        if (nums.size() == 4)
//            head_in3 = head_in1;
//        if (nums.size() == 5)
//            head_in3 = head_in2;
//
//        return max(head_in3 + nums[nums.size() - 1], head_out3);
//    }
//};
//
//int main()
//{
//    vector<int> v({ 1,2,3,1 });
//    Solution s;
//    cout<<s.rob(v);
//}

//
//class Solution {
//public:
//    bool search(vector<string>& wordDict, string& tmp)
//    {
//        int ret = 0;
//        for (int i = 0; i < wordDict.size(); i++)
//            if (tmp == wordDict[i])
//            {
//                ret = 1;
//                break;
//            }
//        return ret;
//    }
//    bool wordBreak(string s, vector<string>& wordDict) {
//        vector<int> begin;
//        begin.push_back(0);
//
//        for (int i = 0; i < s.size(); i++)
//        {
//            for (int j = 0; j < begin.size(); j++)
//            {
//                auto start = s.begin() + begin[j];
//                auto end = s.begin() + i + 1;
//                string tmp(start, end);
//                if (search(wordDict, tmp))
//                {
//                    begin.push_back(i+1);
//                    break;
//                }
//            }
//        }
//
//        if (begin[begin.size() - 1] == s.size() )
//            return true;
//
//        return false;
//    }
//};
//
//int main()
//{
//    vector<string> w({ "leet", "code" });
//    string v("leetcode");
//    Solution s;
//    cout<<s.wordBreak(v, w);
//}


//
//class Solution {
//public:
//    /**
//     *
//     * @param s string字符串
//     * @return int整型
//     */
//    int finds(int begin, int end, string& s)
//    {
//        while (begin < end)
//        {
//            if (s[begin] != s[end])
//                return 0;
//            begin++;
//            end--;
//        }
//        return 1;
//    }
//    int minCut(string s) {
//        // write code here
//        vector<int> v;
//        v.push_back(0);
//
//        for (int i = 1; i < s.size(); i++)
//        {
//            vector<int> tmp;
//            for (int j = 0; j <= i; j++)
//            {
//                if (finds(j, i, s))
//                {
//                    if(j)
//                        tmp.push_back(1 + v[j - 1]);
//                    else 
//                        tmp.push_back(0);
//                }
//            }
//            if (tmp.size() == 0)
//                v.push_back(v[i - 1] + 1);
//            else
//            {
//                int min = tmp[0];
//                for (int n = 0; n < tmp.size(); n++)
//                    if (tmp[n] < min)
//                        min = tmp[n];
//                v.push_back(min);
//            }
//        }
//        return v[v.size() - 1];
//    }
//};
//
//int main()
//{
//    string s("abbab");
//    Solution v;
//    cout<<v.minCut(s);
//}

//
//
//#include<stdio.h>
//#include<string.h>
//#include<sys/wait.h>
//#include<stdlib.h>
//#include<unistd.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//#include<sys/types.h>
//
//
//#define SIZE 256
//#define A 10
//
//void redirect(int ret, char* d)
//{
//    int i = 0;
//    while (d[i + 1] != '\0')
//        i++;
//    d[i] = '\0';
//    int fd;
//    if (ret == 1)
//        fd = open(d, O_CREAT | O_WRONLY, 0700);
//    if (ret == 2)
//        fd = open(d, O_CREAT | O_WRONLY | O_APPEND, 0700);
//
//    dup2(fd, 1);
//
//}
//
//
//int judg(char* p, char** d)
//{
//    int ret = 0;
//    int i = 0;
//    while (p[i] != '\0')
//    {
//        if (p[i] == '>')
//        {
//            ret = 1;
//            p[i] = '\0';
//            if (p[i + 1] == '>')
//            {
//                i++;
//                ret = 2;
//            }
//            break;
//        }
//        i++;
//    }
//    while (p[++i] == ' ');
//    *d = p + i;
//    return ret;
//}
//
//
//
//
//int main()
//{
//    char mycmd[SIZE];
//    char* args[A];
//    while (1)
//    {
//        printf("[tmp ^_^ @VM-16-7-centos ~]$ ");
//        fgets(mycmd, SIZE, stdin);
//        //printf("%s",mycmd);
//        char* d = NULL;
//        int jud = 0;
//        jud = judg(mycmd, &d);
//        printf("%s", d);
//        args[0]=strtok(mycmd," ");
//        int i=1;
//        while(args[i-1])
//        {
//          args[i++]=strtok(NULL," ");
//        }
//        args[i-2][strlen(args[i-2])-1]='\0';
//        //if(args[i-1]==NULL)
//        //  printf("hekko");
//        //for(int j=0;j<i;j++)
//        //{
//        //  printf("%s\n",args[j]);
//        //}
//        int ret=fork();
//        if(ret==0)
//        {
//          if(jud)
//            redirect(jud,d);
//          execvp(args[0],args);
//          exit(0);
//        }
//        else
//        {
//          int status=0;
//          int result=waitpid(-1,&status,0);
//          if((status & 0x7f)==0)
//          {
//            printf("正常退出");
//            printf("   退出码为：%d\n",status>>8);
//          }else
//          {
//            printf("\n非正常退出！");
//            printf("      错误信号是：%d\n",status & 0x7f);
//          }
//
//        }
//    }
//    return 0;
//}



//
//
//
//
//class Solution {
//public:
//    int maxScoreSightseeingPair(vector<int>& values) {
//        int result = values[1] + values[0] - 1;
//        int max2 = max(values[0], values[1] + 1);
//        for (int i = 2; i < values.size(); i++)
//        {
//            if (values[i] + i > max2)
//                max2 = values[i] + i;
//
//            if (max2 + values[i] - i > result)
//                result = max2 + values[i] - i;
//        }
//        return result;
//    }
//};
//int main()
//{
//    vector<int> v({ 8, 1, 5, 2, 6 });
//    Solution s;
//    s.maxScoreSightseeingPair(v);
//}



//
//
//
//class Solution {
//public:
//    int numberOfArithmeticSlices(vector<int>& nums) {
//        if (nums.size() < 3)
//            return 0;
//        int sub = nums[1] - nums[0];
//        int len = 2;
//        vector<int> v;
//
//        for (int i = 2; i < nums.size(); i++)
//        {
//            if ((nums[i] - nums[i - 1]) == sub)
//            {
//                len++;
//            }
//            else
//            {
//                if (len != 2)
//                    v.push_back(len);
//                sub = nums[i] - nums[i - 1];
//                len = 2;
//            }
//
//        }
//        if (len != 2)
//            v.push_back(len);
//
//        if (v.size() == 0)
//            return 0;
//
//        int max = v[0];
//        for (int i = 0; i < v.size(); i++)
//        {
//            if (v[i] > max)
//                max = v[i];
//        }
//
//        vector<int> tmp({ 0,0,1 });
//        for (int i = 3; i < max; i++)
//        {
//            tmp.push_back(tmp[i - 1] + i - 1);
//        }
//
//        int result = 0;
//        for (int i = 0; i < v.size(); i++)
//        {
//            result += tmp[v[i] - 1];
//        }
//        return result;
//    }
//};
//
//int main()
//{
//    vector<int> v({ 1,2,3,4 });
//    Solution s;
//    s.numberOfArithmeticSlices(v);
//    
//}


//
//class Solution {
//public:
//    int numDecodings(string s) {
//        vector<int> v;
//        if (s[0] == '0')
//            return 0;
//        else
//            v.push_back(1);
//        for (int i = 1; i < s.size(); i++)
//        {
//            int cur = s[i] - '0';
//            int prev = s[i - 1] - '0';
//            if (cur == 0)
//            {
//                if (i > 1)
//                {
//                    if (prev < 3 && prev > 0)
//                        v.push_back(v[i - 2]);
//                    else
//                        v.push_back(0);
//                }
//                else
//                {
//                    if (prev == 0)
//                        v.push_back(0);
//                    else
//                        v.push_back(1);
//                }
//            }
//            else if (prev == 0)
//            {
//                v.push_back(v[i - 1]);
//            }
//            else if (prev * 10 + cur > 26)
//            {
//                v.push_back(v[i - 1]);
//            }
//            else
//            {
//                if (i > 1)
//                    v.push_back(v[i - 1] + v[i - 2]);
//                else
//                    v.push_back(v[i - 1] + 1);
//            }
//
//        }
//        return v[v.size() - 1];
//    }
//};

//
//class Solution {
//public:
//    int tmax(int a, int b, int c)
//    {
//        int max = a;
//        if (b > max)
//            max = b;
//        if (c > max)
//            max = c;
//        return max;
//    }
//    int nthUglyNumber(int n) {
//        vector<int> v;
//        v.push_back(1);
//        int a = 0;
//        int b = 0;
//        int c = 0;
//        for (int i = 0; i < n; i++)
//        {
//            int ret = tmax(2 * v[a], 3 * v[b], 5 * v[c]);
//            if (2 * v[a] == ret)
//                a++;
//            if (3 * v[b] == ret)
//                b++;
//            if (5 * v[c] == ret)
//                c++;
//
//            v.push_back(ret);
//
//        }
//        return v[v.size() - 1];
//    }
//};

//
//class Solution {
//public:
//    int tmin(int a, int b, int c)
//    {
//        int max = a;
//        if (b < max)
//            max = b;
//        if (c < max)
//            max = c;
//        return max;
//    }
//    int minFallingPathSum(vector<vector<int>>& matrix) {
//        vector<int> v(matrix[0]);
//        for (int i = 1; i < matrix.size(); i++)
//        {
//            vector<int> tmp;
//            for (int j = 0; j < matrix[0].size(); j++)
//            {
//                if (j == 0)
//                    tmp.push_back(min(v[0], v[1]));
//                else if (j == matrix[0].size() - 1)
//                    tmp.push_back(min(v[j], v[j - 1]));
//                else
//                    tmp.push_back(tmin(v[j - 1], v[j], v[j + 1]));
//            }
//            v = tmp;
//        }
//        int min = v[0];
//        for (int i = 0; i < v.size(); i++)
//            if (v[i] < min)
//                min = v[i];
//
//        return min;
//
//    }
//};
//
//
//int main()
//{
//    vector<vector<int>> v({ {2, 1, 3},{6, 5, 4},{7, 8, 9} });
//    Solution vs;
//    vs.minFallingPathSum(v);
//}
//
//
//#include<unistd.h>

//
//class A
//{
//public:
//    ~A()
//    {
//        cout << "~A()" << endl;
//    }
//private:
//    int _a;
//};
//
//
//class B: public A
//{
//public:
//    ~B()
//    {
//        cout << "~B()" << endl;
//    }
//private:
//    int _b;
//};
//
//
//class C : virtual public A
//{
//public:
//    int _c;
//};
//
//class D : public B,public C
//{
//public:
//    int _d;
//};
//
//
//int main()
//{
//   /* D d;
//    d.B::_a = 1;
//    d.C::_a = 2;
//    d._b = 3;
//    d._c = 4;
//    d._d = 5;*/
//    A* p1 = new A;   //重点理解这一段代码！！！！！！！！！！！！！！！！
//    A* p2 = new B;
//    B* p3 = new B;
//
//    delete p1;
//    delete p2;
//
//}


//
//
//class A
//{
//public:
//   /* ~A()
//    {
//        cout << "~A()" << endl;
//    }*/
//    A(int x)
//        :_a(x)
//        ,_pa(NULL)
//    {
//        _pa = new int[10];
//    }
//
//    virtual void fuck()
//    {
//        cout << "A fuck you !" << endl;
//    }
//
//    void add()
//    {
//        cout << "this is add!" << endl;
//    }
//private:
//    int _a;
//    int *_pa;
//};
//
//
//class B : public A
//{
//public:
//   /* ~B()
//    {
//        cout << "~B()" << endl;
//    }*/
//    B(int x)
//        :_b(x)
//        ,A(4)
//    {
//    };
//
//    void fuck()
//    {
//        cout << "B fuck you too!" << endl;
//    }
//private:
//    int _b;
//};
//
//void  func(A p)
//{
//    p.fuck();
//}
//
//
//int main()
//{
//    A a(1);
//    func(a);
//
//    B b(2);
//    func(b);
//}


//
//
//class A
//{
//public:
//    virtual void fun1() { cout << "this is fun1" << endl; }
//    virtual void fun2() { cout << "this is fun2" << endl; }
//
//};
//
//class B:public A
//{
//public:
//    virtual void fun1() { cout << "rewrite this is fun1" << endl; }
//    virtual void fun3() { cout << "this is fun3" << endl; }
//    virtual void fun4() { cout << "this is fun4" << endl; }
//};
//
////void print(void(*p)())
////{
////}
//
//int main()
//{
//    A a;
//    printf("%p\n", (void(*)())(*(int*)&a));
//    printf("%p", &a);
//    B b;
//}
//
//



//class E
//{
//    int e;
//public:
//    E() { cout << "E" << endl; }
//    E(const char* s)
//        :e(1)
//    {
//        cout << s << endl;
//    }
//    ~E() {}
//};
//
//
//class F
//{
//    int ef;
//public:
//    F() { cout << "F" << endl; }
//    ~F() {}
//};
//
//class A:public F
//{
//    int a;
//public:
//
//    A(const char* s)
//        :a(1)
//    {
//        cout << s << endl;
//    }
//    ~A() {}
//};
//
//
//class B :virtual public A//, virtual public E
//{
//    int b;
//public:
//    B(const char* s1, const char* s2)
//        :A(s1)
//        ,b(2)
//    {
//        cout << s2 << endl;
//    }
//};
//
//
//class C : virtual public A       //virtual public E,
//{
//    int c;
//public:
//    C(const char* s1, const  char* s2)
//        :A(s1)
//        ,c(3)
//    {
//        cout << s2 << endl;
//    }
//
//};
//
//class D :public C, public B
//{
//public:
//    D(const char* s1, const  char* s2, const  char* s3, const  char* s4)
//        :B(s1, s2)
//        , C(s1, s3)
//        , A(s1)
//    {
//        cout << s4 << endl;
//    }
//};
//
//
//int main()
//{
//    D* p = new D("class A", "class B", "class C", "class D");
//    delete p;
//    return 0;
//}





//
//class A          //构造函数的调用顺序
//{
//public:
//    A()
//    {
//        cout << "A" << endl;
//    }
//
//};
//
//class B
//{
//public:
//    B(int x)
//        :b(x)
//    {}
//
//private:
//    int b;
//};
//
//
//class C
//{
//public:
//    C(int x=1)
//        :c(x)
//    {}
//private:
//    int c;
//};
//
//class D : public A,public B
//{
//public:
//    D();
//    D(int x)
//        :
//        d(4)
//        ,B(3)
//    {
//        cout << "D constructor" << endl;
//    }
//
//private:
//    int d;
//    C _c;
//};
//
//int main()
//{
//    D d(1);
//}
//

//
//class A
//{
//public:
//    A()
//    {
//        cout << "A()" << endl;
//    }
//
//    ~A()
//    {
//        cout << "~A()" << endl;
//    }
//};
//
//
//class B :public A
//{
//public:
//    B()
//    {
//        cout << "B()" << endl;
//    }
//
//    ~B()
//    {
//        cout << "~B()" << endl;
//    }
//};
//
//int main()
//{
//    B a;
//}



//
//class person
//{
//public:
//    void fun()
//    {
//        cout << "this is person" << endl;
//    }
//protected:
//    string name = "peter";
//    int _age = 18;
//};
//
//
//class student:public person
//{
//public:
//    void fun()
//    {
//        cout << "this is student" << endl;
//    }
//private:
//    int stuid;
//};
//
//
//int main()
//{
//    student s;
//    s.fun();
//    s.person::fun();
//    /*person p1 = s;
//    person* p2 = &s;
//    person& p3 = s;*/
//}


//
//class person
//{
//public:
//    person();
//    person(string s)
//        :name(s)
//    {
//        cout << "person" << endl;
//        count++;
//    };
//
//    person(person& p)
//        :name(p.name)
//    {};
//
//    person& operator=(person& p)
//    {
//        name = p.name;
//        return *this;
//    }
//    ~person()
//    {
//        cout << "~person" << endl;
//    }
//    static int count;
//protected:
//    string name;
//};
//
//int person::count = 0;
//
//class student :public person
//{
//public:
//    student(string s, int n)
//        :person(s)
//        , stuid(n)
//    {
//        cout << "student" << endl;
//        count++;
//    };
//
//    student(student& s)
//        :person(s)
//    {
//        stuid = s.stuid;
//    }
//
//    student& operator=(student& s)
//    {
//        person::operator=(s);
//        stuid = s.stuid;
//        return *this;
//    }
//
//    ~student()
//    {
//        //person::~person();
//        cout << "~student" << endl;
//    }
//
//
//
//private:
//    int stuid;
//};
//
//int main()
//{
//   // student s("sht",191);
//   /* person p = s;
//    student s2(s);*/
//    person s1("jack");
//    student s2("tony", 10);
//    student s3("henry", 20);
//    cout << s3.count << endl;
//
//}


//class person
//{
//public:
//    person();
//    person(string s)
//        :name(s)
//    {
//        count++;
//    };
//    static int count;
//protected:
//    string name;
//};
//
//int person::count = 0;
//
//class student :public person
//{
//public:
//    student(string s, int n)
//        :person(s)
//        , stuid(n)
//    {};
//private:
//    int stuid;
//};
//
//int main()
//{
//    // student s("sht",191);
//    /* person p = s;
//     student s2(s);*/
//    person s1("jack");
//    student s2("tony", 10);
//    student s3("henry", 20);
//    cout << s3.count << endl;
//
//}

//
//
//class A
//{
//public:
//    int a;
//};
//
//
//class B :public A//virtual public A
//{
//public:
//    int b;
//};
//
//class C : public A//virtual public A
//{
//public:
//    int c;
//};
//
//
//class D : public B,public C
//{
//public:
//    int d;
//};
//
//
//int main()
//{
//    B b;
//    b.a = 1;
//    b.b = 2;
//   /* D d;
//    d.B::a = 1;
//    d.C::a = 10;
//    d.b = 2;
//    d.c = 3;
//    d.d = 4;*/
//
//}
//
//
//class B :public A
//{
//
//};
//
//class B
//{
//    A a;
//};


//
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//    int num;
//    vector<int> p;
//    cin >> num;
//    if (num < 3)
//    {
//        printf("1");
//        return 0;
//    }
//    int prev = 0;
//    int cur = 0;
//    for(int i=0;i<num;i++)
//    {
//        cin >> cur;
//        p.push_back(cur);
//        if (p.size() == 1)
//        {
//            prev = p[0];
//            continue;
//        }
//        if (prev == p[p.size() - 1])
//            p.pop_back();
//        prev = p[p.size() - 1];
//    }
//
//    if (p.size() < 3)
//    {
//        cout << "1" << endl;
//        return 0;
//    }
//    int count = 1;
//    int flag = 0;
//    if (p[0] < p[1])
//        flag = 1;
//    for (int i = 2; i < p.size(); i++)
//    {
//        if ((p[i] > p[i - 1] && flag == 0) | (p[i] < p[i - 1] && flag == 1))
//        {
//            count++;
//            if (i != p.size() - 1)
//            {
//                if (p[i] > p[i + 1])
//                    flag = 0;
//                else
//                    flag = 1;
//                i++;
//            }
//
//        }
//    }
//    cout << count << endl;
//    return 0;
//}

//
//#include<iostream>
//#include<stack>
//using namespace std;
//int main()
//{
//    stack<char> st;
//    stack<char> word;
//    string s;
//    getline(cin,s);
//
//    for (int i = 0; i < s.size(); i++)
//    {
//        st.push(s[i]);
//    }
//
//    while (st.size())
//    {
//        if (st.top() == ' ')
//        {
//            cout << st.top();
//            st.pop();
//        }
//        while (st.size() && st.top() != ' ' )
//        {
//            word.push(st.top());
//            st.pop();
//        }
//        while (!word.empty())
//        {
//            cout << word.top();
//            word.pop();
//        }
//    }
//    cout << '\0' << endl;
//}

//
//#include<iostream>
//#include<stack>
//
//using namespace std;
//
//int main()
//{
//    int a, b;
//    stack<char> st;
//    cin >> a;
//    cin >> b;
//    while (a / b)
//    {
//        if ((a % b) < 10)
//            st.push((a % b) + '0');
//        else
//            st.push((a % b) - 10 + 'A');
//        a /= b;
//    }
//    if (a % b < 10)
//        st.push(a % b + '0');
//    else
//        st.push(a % b - 9 + 'A');
//    while (!st.empty())
//    {
//        cout << st.top();
//        st.pop();
//    }
//    return 0;
//
//
//
//}

//
//
//class A
//{
//public:
//    void fun(int t)
//    {
//        printf("hello world!");
//        return;
//    }
//};
//
//class B : public A
//{
//public:
//    void fun()
//    {
//        printf("...........");
//        return;
//
//    }
//};
//
//
//int main()
//{
//    B b;
//    b.A::fun(100);
//
//}


//
//class A
//{
//public:
//    A()
//    {
//    }
//
//    A(int x)
//        :_a(x)
//    {}
//
//    int _a;
//};
//
//class B:virtual public A
//{
//public:
//    B(int x)
//        :_b(x)
//    {}
//
//    int _b;
//};
//
//class C :virtual public A
//{
//public:
//    C(int x)
//        :_c(x)
//    {
//
//    }
//
//
//    int _c;
//};
//
//
//class D : virtual public B, virtual public C
//{
//public:
//    D(int x, int y, int z)
//        :A(x)
//        , B(y)
//        , C(z)
//    {
//
//    }
//};
//
//
//int main()
//{
//    D d(1, 2, 3);
//}

//
//class A {
//public:
//    ~A()
//    {
//        cout << "A" << endl;
//    }
//};
//
//class B :public A
//{
//public:
//    ~B()
//    {
//        A::~A();
//        cout << "B" << endl;
//    }
//
//};
//
//
//int main()
//{
//    B b;
//
//}



//
//int main()
//{
//    string s = "hello";
//    cout << s.size();
//}


//
//#include<iostream>
//
//using namespace std;
//int main()
//{
//    string a, b;
//    cin >> a;
//    cin >> b;
//    int count = 0;
//    string s;
//    for (int i = 0; i < a.size() + 1; i++)
//    {
//        string sum = a;
//        sum.insert(i, b);
//        int left = 0;
//        int right = sum.size()-1;
//        int flag = 1;
//        while (left < right)
//        {
//            if (sum[left] != sum[right])
//            {
//                flag = 0;
//                break;
//            }
//            left++;
//            right--;
//        }
//        if (flag)
//            count++;
//    }
//    cout << count << endl;
//    return 0;
//}



//
//#include<iostream>
//using namespace std;
//int main()
//{
//    int n;
//    cin >> n;
//    vector<int> p;
//    for (int i = 0; i < n; i++)
//    {
//        int a;
//        cin >> a;
//        p.push_back(a);
//    }
//
//    int n1 = p[0], n2;
//    int max = p[0];
//    for (int i = 1; i < n; i++)
//    {
//        if (p[i] < 0)
//        {
//            n2 = 0;
//        }
//        else
//        {
//            if (n1 > 0)
//                n2 = p[i] + n1;
//            else
//                n2 = p[i];
//        }
//        n1 = n2;
//        if (n1 > max)
//            max = n1;
//    }
//    cout << max << endl;
//    return 0;
//}



//
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//    int col, row;
//    cin >> col;
//    cin >> row;
//    vector<vector<int>> result;
//    for (int i = 0; i < row; i++)
//    {
//        vector<int> v;
//        for (int j = 0; j < col; j++)
//        {
//            if (i > 1 && j > 1)
//            {
//                if (v[j - 2] == 0 && result[i - 2][j] == 0)
//                    v.push_back(1);
//                else
//                    v.push_back(0);
//            }
//            else if (i > 1)
//            {
//                if (result[i - 2][j] != 0)
//                    v.push_back(0);
//                else
//                    v.push_back(1);
//            }
//            else if (j > 1)
//            {
//                if (v[j - 2] != 0)
//                    v.push_back(0);
//                else
//                    v.push_back(1);
//            }
//            else
//            {
//                v.push_back(1);
//            }
//        }
//        result.push_back(v);
//    }
//    int sum = 0;
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            sum += result[i][j];
//        }
//    }
//    cout << sum << endl;
//    return 0;
//}

//

//class Person
//{
//public:
//    virtual void print()
//    {
//        cout << "全价买票" << endl;
//    }
//};
//
//
//class Student:public Person
//{
//public:
//    void print()
//    {
//        cout << "半价买票" << endl;
//    }
//    virtual void fun3()
//    {
//        cout << "fun3()" << endl;
//    }
//};
//
//class Soldier:public Person
//{
//public:
//    void print()
//    {
//        cout << "排队优先，全价买票" << endl;
//    }
//
//};
//
//
//void buyticket(Person s)
//{
//    s.print();
//}
//
//int main()
//{
//    Person s1;
//    Student s2;
//    Soldier s3;
//    Student s4;
//    buyticket(s1);
//    buyticket(s2);
//    buyticket(s3);
//}
//
////
////void print()
////{
////    cout << "hello" << endl;
////}
////
////int main()
////{
////    void* p = print;
////    (*p)();
////
////}


//
//class A{};
//class B :public A {};


//
//
//class Person
//{
//public:
//    virtual ~Person()
//    {
//        cout << "~Person()" << endl;
//    }
//};
//
//
//class Student:public Person
//{
//public:
//    virtual ~Student()
//    {
//        cout << "~Student()" << endl;
//    }
//};
//
//int main()
//{
//    Person* p1 = new Person;
//    Person* p2 = new Student;
//
//    delete p1;
//    delete p2;
//}


//
//int main()
//{
//    BSTreeNodde* leftcur = cur->left;
//    BSTreeNodde* rightcur = cur->right;
//
//    while (leftcur->right != NULL)
//    {
//
//    }
//
//
//
//}

//
//class A
//{
//public:
//    virtual void fun()=0  {}
//};
//
//class B :public A
//{
//public:
//    B(int x=0)
//        :_b(x)
//    {
//    }
//    //virtual void fun() { cout << "over write" << endl; }
//    /*virtual void Drive() { cout << "B" << endl; }*/
//private:
//    int _b;
//};
//
//int main()
//{
//    B b;
//}

//class A
//{
//public:
//    virtual void fun1()
//    {
//        cout << "A::fun1()" << endl;
//    }
//    virtual void fun2()
//    {
//        cout << "A::fun2()" << endl;
//    }
//};
//
//
//class B :public A
//{
//    void fun1()
//    {
//        cout << "B::fun1()" << endl;
//    }
//    void fun2()
//    {
//        cout << "B::fun2()" << endl;
//    }
//    virtual void fun3()
//    {
//        cout << "B::fun3()" << endl;
//    }
//};
//
//int main()
//{
//    A a;
//    B b;
//    int* pa = (int *)(*(int*)&a);
//    int* pb = (int *)(*(int*)&b);
//
//    printf("类A的虚函数表地址是：%p\n", pa);
//    int i = 0;
//    while (*pa != 0)
//    {
//        printf("vfp[%d]的地址是：%p  函数执行结果是： ", i++, *pa);
//        ((void (*)())(*pa))();
//        pa++;
//    }
//
//    cout << endl;
//
//    printf("类B的虚函数表地址是：%p\n", pb);
//    i = 0;
//    while (*pb != 0)
//    {
//        printf("vfp[%d]的地址是：%p  函数执行结果是： ", i++, *pb);
//        ((void (*)())(*pb))();
//        pb++;
//    }
//    return 0;
//}

//
//class A
//{
//public:
//    virtual void fun1() { cout << "A::fun1()" << endl; }
//    virtual void fun2() { cout << "A::fun2()" << endl; }
//};
//
//
//class B /*:public A*/
//{
//public:
//    void fun1() { cout << "B::fun1()" << endl; }
//    virtual void fun3() { cout << "B::fun3()" << endl; }
//    virtual void fun4() { cout << "B::fun4()" << endl; }
//
//};
//
//
//class C :public A, public B
//{
//public:
//    virtual void fun5() { cout << "C::fun5()" << endl; }
//};
//
//
//
//void function(A& s)
//{
//    s.fun1();
//}
//
//void function(A* s)
//{
//    s->fun1();
//}
//
//void function_false(A s)
//{
//    s.fun1();
//}
//
//
//int main()
//{
//    A a;
//    B b;
//
//    printf("打印a对象的虚表：\n");
//    int* pa =(int *)*(int*)&a;
//    int i = 0;
//    while (*pa != NULL)
//    {
//        printf("a虚函数表vfptr[%d]：%p   函数运行结果：",i++,*pa);
//        ((void(*)()) (*pa))();
//        pa++;
//    }
//
//    printf("\n");
//
//    printf("打印b对象的虚表：\n");
//    int* pb = (int*)*(int*)&b;
//    i = 0;
//    while (*pb != NULL)
//    {
//        printf("a虚函数表vfptr[%d]：%p   函数运行结果：", i++, *pb);
//        ((void(*)()) (*pb))();
//        pb++;
//    }
//
//  /*  printf("a对象的虚表地址：%p\n", *(int*)&a);
//    printf("b对象的虚表地址：%p\n", *(int*)&b);
//
//
//    A* p1 = &b;
//    A& p2 = b;
//    A p3 = b;
//
//    printf("p1对象的虚表地址：%p\n", *(int*)p1);
//    printf("p2对象的虚表地址：%p\n", *(int*)&p2);
//    printf("p3对象的虚表地址：%p\n", *(int*)&p3);*/
//
//    /*cout << "function(A& s)" << endl;
//    function(a);
//    function(b);
//
//    cout << endl << "function(A* s)" << endl;
//    function(&a);
//    function(&b);
//
//    cout << endl << "function_false(A s)" << endl;
//    function_false(a);
//    function_false(b);*/
//
//    //cout << sizeof(a) << endl;
//}

//
//
//class A
//{
//public:
//    virtual void fun1() { cout << "A::fun1()" << endl; }
//    virtual void fun2() { cout << "A::fun2()" << endl; }
//    void fun3() { cout << "A::fun3" << endl; }
//private:
//    char a;
//    int b;
//};
//
//
//class B :public A
//{
//public:
//    void fun1() { cout << "B::fun1()" << endl; }
//    virtual void fun4() { cout << "B::fun4()" << endl; }
//    virtual void fun5() { cout << "B::fun5()" << endl; }
//
//};
//
//int main()
//{
//    A a;
//    B b;
//
//    printf("打印a对象的虚表：\n");
//    int* pa = (int*)*(int*)&a;  //(int*)&a拿到的是对象a的前四个字节的地址，该地址解引用就是虚表的地址，最后将改地址强转成int*类型，这是为了下面pa++跳过四个字节
//    int i = 0;
//    while (*pa != NULL)
//    {
//        printf("a虚函数表vfptr[%d]：%p   函数运行结果：", i++, *pa);
//        ((void(*)()) (*pa))();  //这里要把函数的地址强转成函数指针类型才能调用函数
//        pa++;
//    }
//
//    printf("\n");
//
//    printf("打印b对象的虚表：\n");
//    int* pb = (int*)*(int*)&b;
//    i = 0;
//    while (*pb != NULL)
//    {
//        printf("a虚函数表vfptr[%d]：%p   函数运行结果：", i++, *pb);
//        ((void(*)()) (*pb))();
//        pb++;
//    }
//}



//
//
//
//class A
//{
//public:
//    virtual void fun1() { cout << "A::fun1()" << endl; }
//    virtual void fun2() { cout << "A::fun2()" << endl; }
//};
//
//
//class B /*:public A*/
//{
//public:
//    void fun1() { cout << "B::fun1()" << endl; }
//    virtual void fun3() { cout << "B::fun3()" << endl; }
//    virtual void fun4() { cout << "B::fun4()" << endl; }
//
//};
//
//
//class C :public A, public B
//{
//public:
//    virtual void fun5() { cout << "C::fun5()" << endl; }
//};
//
//int main()
//{
//    C c;
//
//    printf("打印C对象的基类A虚表：\n");
//    int* pa = (int*)*(int*)&c;
//    int i = 0;
//    while (*pa != NULL)
//    {
//        printf("a虚函数表vfptr[%d]：%p   函数运行结果：", i++, *pa);
//        ((void(*)()) (*pa))();
//        pa++;
//    }
//
//    printf("\n");
//
//    printf("打印C对象的基类B虚表：\n");
//    int* pb = (int*)*(int*)((B*)&c);
//    while (*pb != NULL)
//    {
//        printf("a虚函数表vfptr[%d]：%p   函数运行结果：", i++, *pb);
//        ((void(*)()) (*pb))();
//        pb++;
//    }
//}

//
//class Base1 { public: int _b1; };
//class Base2 { public: int _b2; };
//class Derive:public Base1,public Base2 { public: int _d; };
//
//int main()
//{
//    Derive d;
//    Base1* p1 = &d;
//    Base2* p2 = &d;
//    Derive* p3 = &d;
//    return 0;
//}

//
//#include<iostream>
//using namespace std;
//int main()
//{
//
//    int n;
//    while (cin >> n)
//    {
//        int count = 0;
//        int a = 0;
//        int b = 5;
//        int c = 6;
//        int d = 1;
//        int m = 10;
//        while (d <= n || a <= n || b <= n || c <= n)
//        {
//            if (a / m != 0)
//                m *= 10;
//            if (a <= n && (a * a) % m == a)
//            {
//                count++;
//                cout << a << endl;
//            }
//
//            if (d <= n && (d * d) % m == d)
//            {
//                count++;
//                cout << d << endl;
//            }
//
//            if (b <= n && (b * b) % m == b)
//            {
//                count++;
//                cout << b << endl;
//            }
//
//            if (c <= n && (c * c) % m == c)
//            {
//                count++;
//                cout << c << endl;
//            }
//
//            c += 10;
//            a += 10;
//            b += 10;
//            d += 10;
//        }
//        cout << count << endl;
//    }
//    return 0;
//}

//
//
//
//#include<iostream>
//
//using namespace std;
//
//class A
//{
//public:
//    virtual void fun1() { cout << "A::fun1" << endl; }
//    virtual void fun2() { cout << "A::fun2" << endl; }
//    void fun3() { cout << "A::fun3" << endl; }
//private:
//    char a;
//    int b;
//};
//
//class B
//{
//public:
//    void fun1() { cout << "B::fun1" << endl; }
//    virtual void fun4() { cout << "B::fun4" << endl; }
//    virtual void fun5() { cout << "B::fun5" << endl; }
//
//};
//
//
//int main()
//{
//    A a;
//    int *p=(int*)(*(int*)&a);
//
//    while(*p != NULL)
//    {
//      ((void(*)())(*p))();
//      p++;
//    }
//    B b;
//
//}



//
//class Solution {
//public:
//    TreeNode* deleteNode(TreeNode* root, int key) {
//        if (root == NULL)
//            return nullptr;
//
//        if (root->left == NULL && root->right == NULL && root->val == key)
//            return nullptr;
//
//        TreeNode* cur = root;
//        TreeNode* parent = cur;
//
//        while (cur)
//        {
//            if (cur->val > key)
//            {
//                parent = cur;
//                cur = cur->left;
//            }
//            else if (cur->val < key)
//            {
//                parent = cur;
//                cur = cur->right;
//            }
//            else
//            {
//                if (cur->left == NULL || cur->right == NULL)
//                {
//                    if (cur == parent)
//                    {
//                        if (cur->right == NULL)
//                            return cur->left;
//                        else
//                            return cur->right;
//                    }
//                    if (cur->right == NULL)
//                    {
//                        if (parent->left == cur)
//                            parent->left = cur->left;
//                        else
//                            parent->right = cur->left;
//                    }
//                    else if (cur->left == NULL)
//                    {
//                        if (parent->left == cur)
//                            parent->left = cur->right;
//                        else
//                            parent->right = cur->right;
//                    }
//
//                }
//                else
//                {
//                    TreeNode* tmp = cur->right;
//                    TreeNode* father = cur;
//                    while (tmp->left)
//                    {
//                        father = tmp;
//                        tmp = tmp->left;
//                    }
//
//                    if (father == cur)
//                        cur->right = tmp->right;
//                    else
//                        father->left = tmp->right;
//
//                    cur->val = tmp->val;
//                }
//                return root;
//            }
//        }
//        return root;
//    }
//};
//
//void RotateL(Node* parent)
//{
//    Node* cur = parent->right;
//    Node* sub = cur->left;
//
//    cur->left = parent;
//    parent->right = sub;
//
//    if (sub)
//        sub->parent = cur;
//
//    if (parent->parent == NULL)
//    {
//        cur->parent == NULL;
//        root = cur;
//    }
//    else
//    {
//        Node* ppNode = parent->parent;
//        if (ppNode->left == parent)
//        {
//            ppNode->left = cur;
//        }
//        else
//        {
//            ppNode->right = cur;
//        }
//        cur->parent = ppNode;
//    }
//    parent->parent = cur;
//
//
//    parent->bf = cur->bf = 0;
//}

//template<class T,typename K,size_t N>
//class A
//{
//public:
//    A()
//        :a(T())
//        , b(K())
//    {
//
//    }
//private:
//    T a;
//    K b;
//};
//
//
//int main()
//{
//    A<int,char,100> d;
//    return 0;
//
//}


//
//
//template<typename Type>
//Type Max(const Type& a, const Type& b)
//{
//
//    cout << "This is Max<Type>" << endl;
//
//    return a > b ? a : b;
//
//}
//
//template<>
//int Max<int>(const int& a, const int& b)
//{
//
//    cout << "This is Max<int>" << endl;
//
//    return a > b ? a : b;
//
//}
//
//template<>
//char Max<char>(const char& a, const char& b)
//{
//
//    cout << "This is Max<char>" << endl;
//
//    return a > b ? a : b;
//
//}
//
//int Max(const int& a, const int& b)
//{
//
//    cout << "This is Max" << endl;
//
//    return a > b ? a : b;
//
//}
//
//
//
//int main()
//
//{
//
//    Max(10, 20);
//
//    Max(12.34, 23.45);
//
//    Max('A', 'B');
//
//    Max<int>(20, 30);
//
//    return 0;
//
//}
//

//
//
//template<class T1, class T2>
//class Data
//
//{
//
//public:
//
//    Data() { cout << "Data<T1, T2>" << endl; }
//
//private:
//
//    T1 _d1;
//
//    T2 _d2;
//
//};
//
//
//
//template <class T1>
//class Data<T1, int>
//
//{
//
//public:
//
//    Data() { cout << "Data<T1, int>" << endl; }
//
//private:
//
//    T1 _d1;
//
//    int _d2;
//
//};
//
//
//
//template <typename T1, typename T2>
//class Data <T1*, T2*>
//
//{
//
//public:
//
//    Data() { cout << "Data<T1*, T2*>" << endl; }
//
//private:
//
//    T1 _d1;
//
//    T2 _d2;
//
//};
//
//
//
//template <typename T1, typename T2>
//class Data <T1&, T2&>
//{
//
//public:
//
//    Data(const T1& d1, const T2& d2)
//
//        : _d1(d1)
//
//        , _d2(d2)
//
//    {
//
//        cout << "Data<T1&, T2&>" << endl;
//
//    }
//
//private:
//
//    const T1& _d1;
//
//    const T2& _d2;
//
//};
//
//int main()
//
//{
//
//    Data<double, int> d1; // 调用特化的int版本
//
//    Data<int, double> d2; // 调用基础的模板
//
//    Data<int*, int*> d3; // 调用特化的指针版本
//
//    Data<int&, int&> d4(1, 2);
//
//    return 0;
//
//}

//
//
//int main()
//{
//    pair<int, char> t;
//    make_pair(1, 'c');
//}

//
//#include<iostream>
//#include<string.h>
//
//using namespace std;
//
//class A
//{
//public:
//    A()
//    {
//        a = new int[100];
//        cout << "A construct" << endl;
//    }
//
//    A(const A& x)
//    {
//        memcpy(a, x.a, sizeof(int) * 100);
//        cout << "A copy" << endl;
//    }
//
//    ~A()
//    {
//        cout << "A destruct" << endl;
//    }
//
//private:
//    int* a;
//};
//
//
//A func()
//{
//    return A();
//}
//
//
//int main()
//{
//    A a = func();
//    return 0;
//}


//
//int main()
//{
//    int a = 1;
//    int b = (++a )+ ((++a) + (++a));
//    cout << b << endl;
//}
//
//class Solution {
//public:
//    bool containsDuplicate(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        bool flag = false;
//        for (int i = 0; i < nums.size() - 1; i++)
//        {
//            if (nums[i] == nums[i + 1])
//            {
//                flag == true;
//                break;
//            }
//        }
//        return flag;
//    }
//};
//
//class Solution {
//public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//        if (n == 0)
//            return;
//        if (m == 0)
//        {
//            swap(nums1, nums2);
//            return;
//        }
//        int i = 0, j = 0;
//        vector<int> result;
//        while (i <= m-1 && j <= n-1)
//        {
//            if (nums1[i] <= nums2[j])
//            {
//                result.push_back(nums1[i]);
//                i++;
//            }
//            else
//            {
//                result.push_back(nums2[j]);
//                j++;
//            }
//        }
//        if (i == m)
//        {
//            while (j != n)
//            {
//                result.push_back(nums2[j]);
//                j++;
//            }
//        }
//        else {
//            while (i != m)
//            {
//                result.push_back(nums1[i]);
//                i++;
//            }
//        }
//
//        for (int m = 0; m < result.size(); m++)
//        {
//            nums1[m] = result[m];
//        }
//
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> nums1 = { 1,2,3,0,0,0 };
//    vector<int> nums2 = { 2,5,6 };
//    swap(nums1, nums2);
//    s.merge(nums1, 3, nums2, 3);
//    
//
//
//
//}

//
//int C(int rowIndex, int i)
//{
//    int n = rowIndex - 1;
//    int top = 1;
//    int bottom = 1;
//    for (int j = 0; j < i; j++)
//    {
//        top *= n;
//        n--;
//    }
//    int m = 1;
//    for (int j = 0; j < i; j++)
//    {
//        bottom *= m;
//        m++;
//    }
//    return top / bottom;
//
//}
//int main()
//{
//    /*vector<int> s;
//    s.resize(10);
//    s[9] = 20;*/
//
//    /*for (int i = 0; i < 3; i++)
//    {
//        cout << C(3, i) << endl;
//    }*/
//
//
//    vector<int> m = { 1,2,3,4,5 };
//    vector<int> n = m;
//
//
//
//
//
//
//
//
//
//}

#include<set>
#include<map>
//class Solution {
//public:
//    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//        set<int> window;
//        for (int j = 0; j < nums.size() - k; j++)
//        {
//            for (int i = j; i < k+j+1; i++)
//            {
//                window.insert(nums[i]);
//            }
//
//            if (window.size() < k+1)
//                return true;
//            else
//                window.clear();
//        }
//        return false;
//
//    }
//};

//
//class Solution {
//public:
//    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//        map<int, int> result;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            pair<map<int, int>::iterator,bool> it;
//            it=result.insert(pair<int,int>(nums[i], i));
//            if (it.second == false)
//            {
//                if (i <= it.first->second + k)
//                    return true;
//            }
//        }
//        return false;
//    }
//};





//class Solution {
//public:
//    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//        map<int, int> result;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            auto pre = result.end();
//            pair<map<int, int>::iterator, bool> it;
//            it = result.insert(pair<int, int>(nums[i], i));
//            if (it.second == true) //插入成功
//            {
//                if(it.first->first<=pre->first)
//            }
//            else
//            {
//
//
//
//            }
//        }
//        return false;
//    }
//};
//int main()
//{
//    //vector<int> s = { 5,4,3,2,1 };
//    //Solution t;
//    //bool result=t.containsNearbyDuplicate(s, 1);
//    int a = -1;
//    string s = to_string(a);
//    string t;
//    t += s;
//    t += string("->");
//}

//
//
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        set<int> result;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            result.insert(nums[i]);
//        }
//
//        for (int i = 0; i <= nums.size(); i++)
//        {
//            auto it = result.insert(i);
//            if (it.second)
//                return *(it.first);
//        }
//
//    }
//};


//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        vector<int> result;
//        sort(nums1.begin(), nums1.end());
//        sort(nums2.begin(), nums2.end());
//
//        if (nums1[0] > nums2[nums2.size() - 1] || nums1[nums1.size() - 1] < nums1[0])
//        {
//            return result;
//        }
//        else
//        {
//            int begin_num = max(nums1[0], nums2[0]);
//            int end_num = min(nums2[nums2.size() - 1], nums1[nums1.size() - 1]);
//
//            int nums1_start = 0;
//            int nums2_start = 0;
//
//            while (nums1[nums1_start] < begin_num)
//            {
//                nums1_start++;
//            }
//
//            while (nums2[nums2_start] < begin_num)
//            {
//                nums2_start++;
//            }
//
//            while (nums1_start < nums1.size() && nums2_start < nums2.size() && nums1[nums1_start] <= end_num && nums2[nums2_start] <= end_num )
//            {
//                if (nums1[nums1_start] == nums2[nums2_start])
//                {
//                    if (result.size() == 0 || result[result.size() - 1] != nums1[nums1_start])
//                    {
//                        result.push_back(nums1[nums1_start]);
//                    }
//                    nums1_start++;
//                    nums2_start++;
//                }
//                else if (nums1[nums1_start] < nums2[nums2_start])
//                {
//                    nums1_start++;
//                }
//                else
//                {
//                    nums2_start++;
//                }
//
//            }
//        }
//    }
//};
//
//int main()
//{
//    vector<int> s1 = { 1,2,2,1 };
//    vector<int> s2 = { 2,2 };
//    Solution c;
//    //int a=c.missingNumber(s);
//    
//    vector<int> result =c.intersection(s1, s2);
//}

//
//void fun(int a = 10);
//int main()
//{
//    fun(100);
//    return 0;
//}
//
//void fun(int a=10)
//{
//    cout << a << endl;
//}

//
//#define add(x,y) ((x)+(y))
//int main()
//{
//    if (add(1, 2)*3); //如果是x+y则这里就是2*3+1，运算结果出错
//    if (add(1 | 2, 1 & 2));//如果是(x+y)这里运算符优先级就会导致结果错误，实际上的顺序是1|( (2+1) & 2 )
//    return 0;
//}



//
//
//class Solution {
//public:
//    bool Find(int target, vector<vector<int> > array) {
//        if (target < array[0][0])
//        {
//            return false;
//        }
//        int i, j;
//
//        for (i = 0; i < array.size(); i++)
//        {
//            if (target == array[i][0] || (i == array.size() - 1 && target > array[i][0]) || (target > array[i][0] && target < array[i + 1][0]))
//            {
//                for (j = 0; j < array[i].size(); j++)
//                {
//                    if (target <= array[i][j])
//                        break;
//                }
//            }
//        }
//        i--;
//
//        for (int m = i; m >= 0; m--)
//        {
//            if (target == array[m][j])
//                return true;
//        }
//        return false;
//    }
//};
//
//int main()
//{
//    vector<vector<int>> s = { {1,2,8,9 }, { 2,4,9,12 }, { 4,7,10,13 }, { 6,8,11,15 } };
//    vector<vector<int>> s1;
//    cout << s1.size() << endl;
//    Solution so;
//    so.Find(7, s);
//}

//
//
//class Solution {
//public:
//    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//
//        stack<int> st;
//        int i = 0;
//        int j = 0;
//        for (i = 0; i < pushV.size(); i++)
//        {
//            if (pushV[i] != popV[j])
//            {
//                st.push(pushV[i]);
//            }
//            else {
//                while (1)
//                {
//                    j++;
//                    if (st.top() == popV[j])
//                    {
//                        j++;
//                        st.pop();
//                    }
//                    else
//                        break;
//                }
//            }
//        }
//        if (st.size() == 0)
//            return true;
//        else
//            return false;
//    }
//};
//
//
//int main()
//{
//    vector<int> s1 = { 1,2,3,4,5 };
//    vector<int> s2 = { 4,5,3,2,1 };
//    Solution s;
//    s.IsPopOrder(s1, s2);
//
//}

//
//
//class MinStack {
//public:
//    MinStack() {
//    }
//
//    void push(int val) {
//        if (pushS.size() == 0)
//        {
//            minS.push(val);
//
//        }
//        else
//        {
//            if (val <= minS.top())
//            {
//                minS.push(val);
//            }
//        }
//        pushS.push(val);
//    }
//
//    void pop() {
//        int i = pushS.top();
//        pushS.pop();
//        if (i == minS.top())
//            minS.pop();
//    }
//
//    int top() {
//        return pushS.top();
//    }
//
//    int getMin() {
//        return minS.top();
//    }
//
//private:
//    stack<int> pushS;
//    stack<int> minS;
//
//};
//
//int main()
//{
//    MinStack s;
//    s.push(-2);
//    s.push(0);
//    s.push(-3);
//
//
//    
//    cout << s.getMin() << endl;
//    s.pop();
//    cout << s.top() << endl;
//    cout << s.getMin() << endl;
//
//
//
//
//}


//
//class Solution {
//public:
//    int evalRPN(vector<string>& tokens) {
//        stack<int> st;
//        for (int i = 0; i < tokens.size(); i++)
//        {
//            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
//            {
//                pair<int, int> a;
//                a.first = st.top();
//                st.pop();
//                a.second = st.top();
//                st.pop();
//
//                if (tokens[i] == "+")
//                {
//                    st.push(a.second + a.first);
//                }
//                else if (tokens[i] == "-")
//                {
//                    st.push(a.second - a.first);
//                }
//                else if (tokens[i] == "*")
//                {
//                    st.push(a.second * a.first);
//                }
//                else if (tokens[i] == "/")
//                {
//                    st.push(a.second / a.first);
//                }
//            }
//            else
//            {
//                st.push(stoi(tokens[i]));
//            }
//
//            return st.top();
//        }
//    }
//};


//
//#include"My_queue.h"
//int main()
//{
//    sht::My_queue<int> st;
//    st.push(1);
//    st.push(2);
//    st.push(3);
//    st.push(4);
//    st.push(5);
//    st.push(6);
//
//
//    while (!st.empty())
//    {
//        cout << st.front() << endl;
//        st.pop();
//    }
//    return 0;
//}

//
//
//class A
//{
//public:
//    A();
//private:
//    int _a;
//};

//
//
//void func(char para[100])
//{
//    void* p = malloc(100);
//    printf("%d, %d\n", sizeof(para), sizeof(p));
//}
//
//
//int main()
//{
    /*char a = 101;
    int sum = 200;
    a += 27; sum += a;
    printf("%d\n", sum);*/

  /*  int value = 1024;
    char condition = *((char*)(&value));
    if (condition) value += 1; condition = *((char*)(&value));
    if (condition) value += 1; condition = *((char*)(&value));
    printf("%d %d", value, condition);*/
    /*char a[100];
    cout << sizeof(a) << endl;
    func(a);*/

//
//    string s = "l love you";
//    auto it = s.end();
//    it--;
//    while (it!=s.begin())
//    {
//        cout << *it << endl;
//        it--;
//    }
//}

//
//
//
//bool check(int num)
//{
//    long sq = num * num;
//    while (num != 0)
//    {
//        if (num % 10 != sq % 10)
//        {
//            return false;
//        }
//        num /= 10;
//        sq /= 10;
//    }
//    return true;
//
//}
//int main() {
//    int num;
//    while (cin >> num) { // 注意 while 处理多个 case
//        int count = 0;
//        for (int i = 0; i <= num; i++)
//        {
//            if (check(i))
//                count++;
//        }
//        return count;
//
//    }
//}

//
//
//#include <iostream>
//using namespace std;
//#include<math.h>
//int main() {
//    int num;
//    while (cin >> num)
//    {
//        int count = 0;
//        int flag = 1;
//        for (int j = 1; j <= num; j++)
//        {
//            flag = 1;
//            int a = sqrt(j) + 1;
//            for (int i = 1; i < a; i++)
//            {
//                if (j % i == 0)
//                {
//                    flag = 0;
//                    break;
//                }
//            }
//            if (flag)
//                count++;
//
//        }
//        cout << count << endl;
//
//    }
//}
//// 64 位输出请用 printf("%lld")

//
//class A
//{
//public:
//    A();
//};
//
//
//
//
//class A
//{
//public:
//    A()
//    {
//
//    }
//};

//
//int main()
//{
//    string s = "a";
//    cout << s.size() << endl;
//
//
//
//
//}

//
//class num
//{
//public:
//    num(int asic, int pos, int count = 1)
//        :_asic(asic)
//        , _pos(pos)
//    {
//    }
//    int _asic;
//    int _count;
//    int _pos;
//};
//class Solution {
//public:
//    int FirstNotRepeatingChar(string str) {
//        vector<num> s;
//        for (int i = 0; i < str.size(); i++)
//        {
//            int flag = 1;
//            for (int j = 0; j < s.size(); j++)
//            {
//                if ((int)str[i] == s[j]._asic)
//                {
//                    s[j]._count++;
//                    flag = 0;
//                    break;
//                }
//            }
//            if (flag)
//                s.push_back(num(str[i], i));
//        }
//        for (auto e : s)
//        {
//            if (e._count == 1)
//            {
//                return e._pos;
//            }
//        }
//        return -1;
//
//    }
//};
//
//int main()
//{
//    string s = "google";
//    Solution s1;
//    s1.FirstNotRepeatingChar(s);
//}

//
//class Solution {
//public:
//    vector<int> findDisappearedNumbers(vector<int>& nums) {
//        vector<pair<int, bool>> st;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            st.push_back(make_pair(i + 1, false));
//        }
//
//        for (int i = 0; i < nums.size(); i++)
//        {
//            st[i - 1].second = true;
//        }
//        vector<int> result;
//
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (st[i].second == false)
//                result.push_back(st[i].first);
//        }
//        return result;
//
//    }
//};
//
//
//int main()
//{
//    vector<int> a = { 4,3,2,7,8,2,3,1 };
//    Solution s;
//    s.findDisappearedNumbers(a);
//}

//
//class Solution {
//public:
//    bool canPermutePalindrome(string s) {
//        map<char, int> t;
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (t.count(s[i]))
//            {
//                /*auto it = find(t.begin(),t.end(),s[i]);
//                (*it).second++;*/
//
//                t[s[i]]++;
//            }
//            else
//                t.insert(make_pair(s[i], 1));
//        }
//
//        int count = 0;
//        for (auto e : t)
//        {
//            if (e.second % 2 != 0)
//                count++;
//        }
//        if (count < 2)
//            return true;
//        else
//            return false;
//
//
//
//    }
//};
//
//
//int main()
//{
//    string s = "tactcoa";
//    Solution a;
//    cout<<a.canPermutePalindrome(s);
//}

//
//
//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        int maxsize = max(num1.size(), num2.size());
//        int n1 = num1.size() - 1;
//        int n2 = num2.size() - 1;
//        stack<int> mid;
//        string result;
//        int forward = 0;
//        for (int i = 0; i < maxsize; i++)
//        {
//            if (n1 >= 0 && n2 >= 0)
//            {
//                int sum = num1[n1]-'0' + num2[n2]-'0' + forward;
//                mid.push(sum % 10);
//                forward = sum / 10;
//            }
//            else if (n1 >= 0 && n2 < 0)
//            {
//                int  sum = num1[n1] - '0' + forward;
//                mid.push(sum % 10);
//                forward = sum / 10;
//            }
//            else if (n2 >= 0 && n1 < 0)
//            {
//                int  sum = num2[n2] - '0' + forward;
//                mid.push(sum % 10);
//                forward = sum / 10;
//            }
//            n1--;
//            n2--;
//        }
//
//        if (forward)
//            mid.push(1);
//
//        while (!mid.empty())
//        {
//            result.push_back(mid.top()+'0');
//            mid.pop();
//        }
//        return result;
//
//    }
//};
//
//int main()
//{
//    string num1 = "923";
//    string num2 = "91";
//    Solution s;
//    cout<<s.addStrings(num1,num2);
//}



//int main()
//{
//    std::string foo = "alpha";
//    std::string bar = "beta";
//
//    if (foo == bar) std::cout << "foo and bar are equal\n";
//    if (foo != bar) std::cout << "foo and bar are not equal\n";
//    if (foo < bar) std::cout << "foo is less than bar\n";
//    if (foo > bar) std::cout << "foo is greater than bar\n";
//    if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
//    if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";
//
//    return 0;
//}

//
//
//int main()
//{
//    char a[20] = "i love you\0\0\0\0\0";
//    char b[20] = "love";
//    char* ptr = nullptr;
//    if (ptr=strstr(a, b))
//        cout << ptr-a << endl;
//}


//
//int main()
//{
//    int a = 0;
//    cin >> a;
//}

#include <iostream>
#include<string.h>
#include<vector>
#include<string>
using namespace std;
//int main() {
//    int a = 0;
//    while (cin >> a)
//    { // 注意 while 处理多个 case
//        vector<string> s;
//        for (int i = 0; i < a; i++)
//        {
//            string tmp;
//            cin >> tmp;
//            s.push_back(tmp);
//        }
//
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (s[i].size() >= 10)
//            {
//                char first = s[i][0];
//                char last = s[i][s[i].size() - 1];
//                string tmp;
//                tmp.push_back(first);
//                tmp.append(to_string(s[i].size() - 2));
//                tmp.push_back(last);
//                s[i].swap(tmp);
//            }
//        }
//
//        for (int i = 0; i < s.size(); i++)
//        {
//            cout << s[i] << endl;
//        }
//
//    }
//}
//// 64 位输出请用 printf("%lld")
//
//class Solution {
//public:
//    string replaceSpaces(string s, int length) {
//        int realsize = 0;
//        for (int i = length - 1; i >= 0; i--)
//        {
//            if (s[i] == ' ')
//                realsize++;
//        }
//        int pos = length + 2 * realsize-1;
//        for (int i = length - 1; i >= 0; i--)
//        {
//            if (s[i] == ' ')
//            {
//                s[pos--] = '0';
//                s[pos--] = '2';
//                s[pos--] = '%';
//            }
//            else
//            {
//               s[pos--] = s[i];
//            }
//
//        }
//        return s;
//    }
//};
//
//int main()
//{
//    string s1 = "ds sdfs afs sdfa dfssf asdf             ";
//    string s2 = "Mr John Smith    ";
//    Solution a;
//    cout<<a.replaceSpaces(s1, 27);
//}
//
//class Solution {
//public:
//    int exchangeBits(int num) {
//        int  result = 0;
//        int i = 1;
//        while (num > 0)
//        {
//            int flag = 0;
//            int tmp = num % 4;
//            if (tmp == 1)
//            {
//                flag = 2;
//            }
//            else if (tmp == 2)
//            {
//                flag = 1;
//            }
//            else
//            {
//                flag = tmp;
//            }
//            result += flag * i;
//            i *= 4;
//            num /= 4;
//
//        }
//        return result;
//    }
//};
//
//
//
//int main()
//{
//    int num;
//    Solution s;
//    cout<<s.exchangeBits(7);
//}


//
//class Solution {
//public:
//    int multiply(int A, int B) {
//        if (B == 0)
//            return 0;
//        return A + multiply(A, --B);
//    }
//};
//
//
//int main()
//{
//    Solution s;
//    cout<<s.multiply(4, 8);
//}
//
//int main()
//{
//    vector<int> s = { 1,2,3,4,5,6,7,8,9 };
//    auto it = s.begin();
//    while (it != s.end())
//    {
//        cout << *it << ' ';
//        it++;
//    }
//    cout << endl;
//    auto is = s.rbegin();
//    while (is != s.rend())
//    {
//        cout << *is << ' ';
//        is++;
//    }
//
//}

//
//class A
//{
//    friend ostream& operator<<(ostream& os, const A& a);
//public:
//    ostream& operator<<(ostream& os)
//    {
//        os << _a;
//        return os;
//    }
//private:
//    int _a=1;
//
//};
//
//ostream& operator<<(ostream& os, const A& a)
//{
//    os << a._a;
//    return os;
//}
//
//int main()
//{
//    A a;
//
//    //cout << a;   常见的流输出
//    a.operator<<(cout);  //实际上的流输出
//    a << cout;   //上面的等价写法
//    cout << a;
//}
//
//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        if (nums.size() == 1)
//            return 0;
//        int count = 0;
//        vector<int> a;
//        a.resize(nums.size() - 1);
//        int last = nums.size() - 1;
//        for (int i = last - 1; i >= 0; i--)
//        {
//            if (nums[i] >= last - i)
//                a[i] = 1;
//            else
//            {
//                if (nums[i] == 0)
//                {
//                   
//                    a[i] = -1;
//                }
//                else
//                {
//                    int min=a[nums[i]+i];
//                    for (int j = i+1; j <= i + nums[i]; j++)
//                    {
//                        if (a[j]!=-1 && a[j] < min)
//                            min = a[j];
//                    }
//                    a[i] = min + 1;
//                }
//            }
//        }
//        return a[0];
//    }
//};
//
//
//
//class Solution1 {
//public:
//    int jump(vector<int>& nums) {
//        if (nums.size() == 1)
//            return 0;
//        int count = 0;
//        vector<int> a;
//        a.resize(nums.size() - 1);
//        int last = nums.size() - 1;
//        for (int i = last - 1; i >= 0; i--)
//        {
//            if (nums[i] >= last - i)
//                a[i] = 1;
//            else
//            {
//                if (nums[i] == 0)
//                {
//                    a[i] = 0;
//                }
//                else
//                {
//                    int min = -2;
//                    for (int j = i + 1; j <= i + nums[i]; j++)
//                    {
//                        if (a[j] == -1)
//                            continue;
//                        if (a[j] > 0)
//                        {
//                            min = a[j];
//                            break;
//                        }
//                    }
//                    if (min != -2)
//                    {
//                        for (int j = i + 1; j <= i + nums[i]; j++)
//                        {
//                            if (a[j] != 0 && a[j] < min)
//                                min = a[j];
//                        }
//                        a[i] = min + 1;
//                    }
//                    else
//                        a[i] = 0;
//                }
//            }
//        }
//        return a[0];
//    }
//};
//
//int main()
//{
//    vector<int> s = { 2,3,0,1,4 };
//    Solution1 y;
//    cout<<y.jump(s);
//}

//
//
//int main()
//{
//    int* p = new int[10];
//    p[0] = 1;
//
//}

//
//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        int** p = new int* [m - 1];
//        for (int i = 0; i < m - 1; i++)
//        {
//            p[i] = new int[n - 1];
//            for (int j = n - 2; j >= 0; j--)
//            {
//                int up, right;
//
//                if (i == 0)
//                    up = 1;
//                else
//                    up = p[i - 1][j];
//                if (j == n - 2)
//                    right = 1;
//                else
//                    right = p[i][j + 1];
//
//                p[i][j] = up + right;
//            }
//        }
//        return p[m-2][0];
//    }
//};
//
//
//int main()
//{
//    Solution s;
//    cout<<s.uniquePaths(3, 7);
//}
//
//#include <iostream>
//using namespace std;
//int main() {
//    int count = 0;
//    while (cin >> count)
//    {
//        long* p = new long[count];
//        for (int i = 0; i < count; i++)
//        {
//            cin >> p[i];
//        }
//        int* result = new int[1000000];
//        result[0] = 1;
//        result[1] = 2;
//        for (int i = 2; i < count; i++)
//        {
//            result[i] = (result[i - 1] * 2 + result[i - 2]) % 32767;
//        }
//
//        for (int i = 0; i < count; i++)
//        {
//            cout << result[p[i] - 1] << endl;
//        }
//
//
//
//    }
//}
//// 64 位输出请用 printf("%lld")

//
//#include <iostream>
//using namespace std;
//#include<string.h>
//int main() {
//    char a[1000];
//    while (cin.getline(a, 1000))
//    {
//        int size = strlen(a);
//        int a = 0, b = 0, c = 0, d = 0;
//        for (int i = 0; i < size; i++)
//        {
//            if (a[i] >= 'a' && a[i] <= 'z')
//            {
//
//            }
//        }
//
//    }
//
//}

//
//
//int main()
//{
//    string s;
//    s.resize(1000);
//
//    getline(cin,s);
//
//    cout << s;
//}
//
//
//#include<iostream>
//using namespace std;
//int myfind(int* p, int n, int* i)
//{
//    for (int j = *i; j < n - 1; j++)
//    {
//        if (p[j] < p[j + 1])
//        {
//            *i = j;
//            return 1;
//        }
//        else if (p[j] > p[j + 1])
//        {
//            *i = j;
//            return 1;
//        }
//    }
//    return 0;
//}
//int main()
//{
//    int n;
//    while (cin >> n)
//    {
//        int* p = new int[n];
//        for (int i = 0; i < n; i++)
//        {
//            cin >> p[i];
//        }
//        int i = 0;
//        int flag = 0;
//        int count = 1;
//        flag = myfind(p, n, &i);
//        for (; i < n - 1; i++)
//        {
//            if (flag == 1)   //单增
//            {
//                if (p[i] > p[i + 1])
//                {
//                    count++;
//                    if (i + 1 == n - 1)
//                    {
//                        flag = 0;
//                        break;
//                    }
//                    else
//                    {
//                        i++;
//                        flag = myfind(p, n, &i);
//                    }
//                }
//            }
//            else
//            {
//                if (p[i] < p[i + 1])
//                {
//                    count++;
//                    if (i + 1 == n - 1)
//                    {
//                        flag = 0;
//                        break;
//                    }
//                    else
//                    {
//                        i++;
//                        flag = myfind(p, n, &i);
//                    }
//                }
//            }
//        }
//        if (flag == 0)
//            count++;
//        cout << count;
//
//    }
//}

//
//class Solution {
//public:
//    int find(int begin, int end, vector<int>& nums, int target)
//    {
//        int left = begin;
//        int right = end;
//        int mid;
//        while (left != right)
//        {
//            mid = (left + right) / 2;
//            if (target < nums[mid])
//                right = mid;
//            else if (target> nums[mid])
//                left = mid + 1;
//            else
//                return mid;
//        }
//        if (nums[left] == target)
//            return left;
//        else
//         return -1;		
//
//    }
//    int search(vector<int>& nums, int target) {
//        if (nums.size() == 1)
//        {
//            if (nums[0] == target)
//                return 0;
//            else
//                return -1;
//        }
//
//        int left = 0;
//        int right = nums.size() - 1;
//        int mid= (left + right) / 2;
//        int flag = 1;
//        while (left != right && left+1!=right)
//        {
//            mid = (left + right) / 2;
//            if (nums[left] > nums[mid])
//            {
//                right = mid;
//                flag = 0;
//            }
//            else if (nums[right] < nums[mid])
//            {
//                left = mid;
//                flag = 0;
//            }
//            
//            if (flag)
//                break;
//        }
//
//        if (flag == 1)
//        {
//            if (nums.size() == 2 && nums[0] > nums[1])
//            {
//                if (target == nums[0])
//                    return 0;
//                else if (target == nums[1])
//                    return 1;
//                else
//                    return -1;
//            }
//            return find(0, nums.size() - 1,nums, target);
//        }
//
//        if (nums[left] > nums[right])
//            mid = left;
//        if (target > nums[mid] || target < nums[mid + 1])
//            return -1;
//        else
//        {
//            if (target < nums[0])   //在右区间
//            {
//                return find(mid + 1, nums.size() - 1, nums, target);
//            }
//            else   //在左半区间
//            {
//                return find(0, mid, nums, target);
//            }
//        }
//
//
//    }
//};
//
//int main()
//{
//    vector<int> v = { 7,8,1,2,3,4,5,6};
//    Solution s;
//    cout<<s.search(v, 2);
//}

//
//#include <ctime>
//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//int main() {
//    stack<string>  s;
//    string p;
//    p.resize(1000);
//    getline(cin, p);
//    cout << p.size() << endl;
//    //p += '\n';
//    int start = 0;
//    for (int i = 0; ; i++)
//    {
//        if (p[i] == ' ' || p[i] == '\n')
//        {
//            string tmp(p.begin() + start, p.begin() + i );
//            s.push(tmp);
//            if (p[i] == '\n')
//                break;
//
//            start = i + 1;
//            s.push(" ");
//        }
//
//    }
//
//    string result;
//
//    while (!s.empty())
//    {
//        result += s.top();
//        s.pop();
//    }
//    cout << result;
//
//}

//
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    string s;
//    getline(cin, s);
//    s += 's';
//    string result;
//    int start = 0;
//    int maxsize = 0;
//    int flag = 0;
//    for (int i = 0; i < s.size(); i++)
//    {
//        if (s[i] <= '9' && s[i] >= '0')
//        {
//            if (flag == 0)
//                start = i;
//
//            flag = 1;
//        }
//        else if (flag == 1)
//        {
//            if (i - start > maxsize)
//            {
//                string tmp;
//                maxsize = i - start;
//                for (int j = start; j < i; j++)
//                {
//                    tmp += s[j];
//                }
//                result.swap(tmp);
//            }
//            flag = 0;
//        }
//    }
//    cout << result;
//}

//
//class Solution {
//public:
//    int MoreThanHalfNum_Solution(vector<int> numbers) {
//        int maxsize = 0;
//        int maxnum;
//        std::sort(numbers.begin(), numbers.end());
//        int num = numbers[0];
//        int count = 0;
//        int flag = 0;
//        for (int i = 0; i < numbers.size(); i++)
//        {
//            if (numbers[i] == num)
//                count++;
//            else
//            {
//                flag = 1;
//                if (count > maxsize)
//                {
//                    maxnum = num;
//                    maxsize = count;
//                }
//                count = 1;
//                num = numbers[i];
//            }
//
//        }
//        if (flag == 0)
//            return numbers[0];
//
//        return maxnum;
//
//    }
//};
//
//
//int main()
//{
//    Solution s;
//    vector<int> p = { 3,3,3,3,2,2,2 };
//    s.MoreThanHalfNum_Solution(p);
//}

//
//
//#include <iostream>
//using namespace std;
//
//int main() {
//    int s[4];
//    for (int i = 0; i < 4; i++)
//    {
//        cin >> s[i];
//    }
//
//    int a, b, c, d;
//
//
//    a = (s[0] + s[1]) / 2;
//    b = a - s[0];
//    c = b - s[1];
//
//
//    if (b + c == s[3])
//    {
//        cout << a << " " << b << " " << c;
//    }
//    else
//        cout << "No";
//
//
//
//}
//// 64 位输出请用 printf("%lld")


//
//#include <iostream>
//using namespace std;
//#include<string>
//bool jude(string& s)
//{
//    int begin = 0;
//    int end = s.size() - 1;
//    int flag = 0;
//    while (begin <= end)
//    {
//        if (s[begin] != s[end])
//        {
//            flag = 1;
//            break;
//        }
//        begin++;
//        end--;
//    }
//
//    if (flag == 1)
//        return false;
//    else
//        return true;
//
//}
//
//int main() {
//    string s1;
//    string s2;
//
//    while (cin >> s1 >> s2)
//    {
//        int count = 0;
//        for (int i = 0; i < s1.size(); i++)
//        {
//            string tmp(s1);
//            tmp.insert(i, s2);
//            if (jude(tmp))
//                count++;
//        }
//        cout << count;
//    }
//
//}
//// 64 位输出请用 printf("%lld")
//
// struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int left, int right) {
//        ListNode* begin=nullptr,* pre_begin=nullptr;
//        ListNode prehead;
//        prehead.next = head;
//        left++;
//        right++;
//        ListNode* end=nullptr, *next_end=nullptr;
//        ListNode* cur = &prehead;
//        int m = 1;
//        while (cur != nullptr)
//        {
//            if (m + 1 == left)
//                pre_begin = cur;
//            if (m == left)
//                begin = cur;
//            if (m == right)
//                end = cur;
//            m++;
//            cur = cur->next;
//        }
//        next_end = end->next;
//        pre_begin->next = end;
//        end->next = nullptr;
//
//        stack<ListNode*> st;
//        cur = begin;
//        while (cur != nullptr)
//        {
//            st.push(cur);
//            cur = cur->next;
//        }
//        ListNode* tmp=nullptr;
//        while (!st.empty())
//        {
//            tmp = st.top();
//            st.pop();
//            if(!st.empty())
//            tmp->next = st.top();
//        }
//        tmp->next = next_end;
//        return prehead.next;
//
//    }
//};
//
//
//int main()
//{
//    ListNode a1(1);
//    ListNode a2(2);
//    ListNode a3(3);
//    ListNode a4(4);
//    ListNode a5(5);
//    a1.next = &a2;
//    a2.next = &a3;
//    a3.next = &a4;
//    a4.next = &a5;
//
//
//    Solution s;
//    s.reverseBetween(&a1, 2, 4);
//
//}
//
//
//#include <iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//bool check_diction(string& s1, string& s2)
//{
//    int i = 0;
//    for (i = 0; i < s1.size() && i < s2.size(); i++)
//    {
//        if (s1[i] > s2[i])
//            return false;
//        else if (s1[i] < s2[i])
//            return true;
//    }
//
//    if (s2.size() <= s1.size())
//        return false;
//    else
//        return true;
//}
//bool check_length(string& s1, string& s2)
//{
//    return s1.size() < s2.size();
//}
//int main() {
//    int n;
//    cin >> n;
//    char a;
//    cin.get(a);
//    vector<string> s;
//    for (int i = 0; i < n; i++)
//    {
//        string tmp;
//        getline(cin, tmp);
//        s.push_back(tmp);
//    }
//
//    int flag1 = 1;
//    int flag2 = 1;
//
//    for (int i = 0; i < s.size() - 1; i++)
//    {
//        if (!check_diction(s[i], s[i + 1]))
//        {
//            flag1 = 0;
//        }
//
//        //if(!check_length(s[i], s[i+1]))
//        if (s[i].size() > s[i + 1].size())
//        {
//            flag2 = 0;
//        }
//        if (flag1 == 0 && flag2 == 0)
//            break;
//    }
//    if (flag1 == 1 && flag2 == 1)
//    {
//        cout << "both";
//    }
//    else if (flag1 == 1 && flag2 == 0)
//    {
//        cout << "lexicographically";
//    }
//    else if (flag1 == 0 && flag2 == 1)
//    {
//        cout << "lengths";
//    }
//    else
//    {
//        cout << "none";
//    }
//
//
//
//
//
//}

//
//class Solution {
//public:
//    string makeGood(string s) {
//        int oldsize = s.size();
//        do
//        {
//            oldsize = s.size();
//            string tmp;
//            for (int i = 0; i < s.size(); i++)
//            {
//                if (s[i] - 'a' == s[i + 1] - 'A' || s[i] - 'A' == s[i + 1] - 'a')
//                {
//                    i += 1;
//                }
//                else
//                    tmp.push_back(s[i]);
//            }
//            s.swap(tmp);
//
//        } while (oldsize != s.size());
//
//        return s;
//    }
//};
//
//int main()
//{
//    Solution s;
//    cout<<s.makeGood("leEeetcode");
//
//}

//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void print_info(char** envp)
//{
//    char** cur = envp;
//    char HOST_NAME[20]; // 主机型号和名称
//    char USER[20];      // 用户名
//    char PWD[100];
//    char CUR_dic[20];
//    while ((*cur) != NULL)
//    {
//
//        if (strstr(*cur, "HOSTNAME"))
//            strcpy(HOST_NAME, strstr(*cur, "="));
//
//        if (strstr(*cur, "USER"))
//            strcpy(USER, strstr(*cur, "="));
//
//        if (strstr(*cur, "PWD"))
//        {
//            strcpy(PWD, strstr(*cur, "="));
//            int i = 0;
//            for (i = strlen(PWD); i >= 0; i++)
//            {
//                if (i == '/')
//                    break;
//            }
//            strcpy(CUR_dic, PWD + i);
//        }
//        cur++;
//    }
//    if (strcmp(USER, "root"))
//        printf("[%s@%s %s]# ", USER, HOST_NAME, CUR_dic);
//    else
//        printf("[%s@%s %s]$ ", USER, HOST_NAME, CUR_dic);
//}
//int main(int argc, char** argv, char** envp)
//{
//    int flag = 1;
//    // while (flag)
//    {
//        print_info(envp); // 输出命令行前面的主机信息
//        // read_comand();       //读取 屏幕上输入的指令 并 分割
//        // excute_comand();     //执行 分割好的指令
//    }
//}
//
//int main()
//{
//    char a[20] = "adc";
//    char b[10];
//    strcpy(b, a);
//    cout << b << endl;

//
//
//#include<stdio.h>
//
//int main()
//{
//   /* char a[20] = " i love you";
//    char b[] = " ";
//    char* p = strtok(a, b);
//    while ((p = strtok(NULL, b))!=nullptr)
//    {
//        cout << p << endl;
//    }
//    return 0;*/
//
//
//   /* char* p = NULL;
//    int sz = 0;
//
//    getline(p, &sz, stdin);*/
//}

//
//
//  struct TreeNode {
//      int val;
//     TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };
//
//class Solution {
//public:
//    bool isRight(vector<TreeNode*> n, int flag)
//    {
//        if (flag == 1)   //是否是单增
//        {
//            for (int i = 0; i < n.size() - 1; i++)
//            {
//                if (n[i]->val > n[i + 1]->val)
//                {
//                    return false;
//                }
//            }
//            return true;
//        }
//        else   //是否是单减
//        {
//            for (int i = 0; i < n.size() - 1; i++)
//            {
//                if (n[i]->val < n[i + 1]->val)
//                {
//                    return false;
//                }
//            }
//            return true;
//        }
//    }
//    bool isEvenOddTree(TreeNode* root) {
//
//        vector<vector<TreeNode*>> num;
//        vector<TreeNode*> cur;
//        cur.push_back(root);
//        num.push_back(cur);
//
//        int i = 0;
//        while (i < num.size())
//        {
//            vector<TreeNode*> tmp;
//
//            for (int j = 0; j < num[i].size(); j++)
//            {
//                if (num[i][j]->left)
//                    tmp.push_back(num[i][j]->left);
//
//                if (num[i][j]->right)
//                    tmp.push_back(num[i][j]->right);
//            }
//            if (tmp.size())
//                num.push_back(tmp);
//            i++;
//        }
//
//
//        bool result = right;
//        for (int j = 0; j < num.size(); j++)
//        {
//            result = isRight(num[j], j%2);
//        }
//        return result;
//
//    }
//};
//
//
//int main()
//{
//    TreeNode p1(1);
//    TreeNode p2(2);
//    TreeNode p3(3);
//    p1.left = &p2;
//    p1.right = &p3;
//
//
//    Solution s;
//    s.isEvenOddTree(&p1);
//}

//#include<unordered_map>
//
//class Solution {
//public:
//    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
//        unordered_map<int, int> s1;
//
//        for (auto& e : arr1)
//        {
//            auto it = s1.insert(make_pair(e, 1));
//
//            if (it.second == false)
//            {
//                (*(it.first)).second++;
//            }
//        }
//
//        vector<int> left;
//        vector<int> result;
//        for (auto& e : arr2)
//        {
//            auto it = s1.find(e);
//            if (it == s1.end())
//                left.push_back((*it).first);
//            else
//            {
//                for (int i = 0; i < (*it).second; i++)
//                {
//                    result.push_back((*it).first);
//                }
//            }
//        }
//
//        sort(left.begin(), left.end());
//
//        for (auto& e : left)
//            result.push_back(e);
//
//        return result;
//
//    }
//};
//
//int main()
//{
//    vector<int> s1 = { 2,3,1,3,2,4,6,7,9,2,19 };
//    vector<int> s2 = { 2,1,4,3,9,6 };
//
//    Solution s;
//    s.relativeSortArray(s1, s2);
//}

//
//
//class Solution {
//public:
//    string sortSentence(string s) {
//        char* p1[9];
//        char* p2[9];
//        char* str = (char*)malloc(s.size());
//        strcpy(str, s.c_str());
//        int j = 0;
//        p2[j++] = str;
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (str[i] == ' ' )
//            {
//                str[i] = '\0';
//                p2[j++] = str + i + 1;
//            }
//        }
//
//        for (int i = 0; i < j; i++)
//        {
//            int sz = p2[i][strlen(p2[i]) - 1] - '0';
//            p2[i][strlen(p2[i]) - 1] = '\0';
//
//            p1[sz - 1] = p2[i];
//        }
//        p1[j] = NULL;
//
//
//
//
//
//
//
//        char** cur = p1;
//        string result;
//        while (*cur)
//        {
//            result += *cur;
//            result += " ";
//            cur++;
//        }
//        return result;
//
//    }
//};
//
//
//int main()
//{
//    string s = "is2 sentence4 This1 a3";
//    Solution t;
//    cout<<t.sortSentence(s);
//}

//
//
//#include<unordered_map>
//#include<unordered_set>
//
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//
//        int maxsize = 0;
//        for (int i = 0; i < s.size(); i++)
//        {
//            unordered_set<char> t;
//            t.insert(s[i]);
//            for (int j = i + 1; j < s.size(); j++)
//            {
//                auto it = t.insert(s[j]);
//                if (it.second == false)
//                {
//                    if (t.size() > maxsize)
//                        maxsize = t.size();
//                }
//            }
//        }
//        return maxsize;
//    }
//};
//
//int main()
//{
//    string s = "pwwkew";
//    Solution t;
//    t.lengthOfLongestSubstring(s);
//}



//
//
//
//  struct ListNode {
//      int val;
//      ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
//class Solution {
//public:
//    ListNode* fun(ListNode* a, ListNode* b, ListNode* c)
//    {
//        if (b == nullptr)
//        {
//            return a;
//        }
//        b->next = a;
//        if (c != nullptr)
//            return fun(b, c, c->next);
//        else
//            return fun(b, c, nullptr);
//    }
//    ListNode* reverseList(ListNode* head) {
//        if (head == nullptr || head->next == nullptr)
//            return head;
//        ListNode* a = head;
//        ListNode* b = head->next;
//        ListNode* c = c = head->next->next;
//        head->next = nullptr;
//        return fun(a, b, c);
//    }
//};
//
//int main()
//{
//    ListNode n1(1);
//    ListNode n2(2);
//    ListNode n3(3);
//
//    ListNode n4(4);
//
//    n1.next = &n2;
//    n2.next = &n3;
//    n3.next = &n4;
//
//    Solution s;
//    s.fun(&n1);
//}


//
//class person
//{
//public:
//    friend void printg();
//    person(string name="peter", int age=10)
//        :_name(name),_age(age)
//    {
//
//    }
//    person(person &s)
//    {
//        cout << "拷贝构造" << endl;
//    }
//   
//protected:
//    string _name ;
//    int _age ;
//};
//
////class student :public person
////{
////public:
////    student(int stuid=10, string name = "peter", int age = 10)
////        :_stuid(stuid)//,person(name,age)
////    {
////        
////    }
////private:
////
////    int _stuid;
////};
//
//
//
//void printg()
//{
//    /*cout << _name << endl;
//    cout << _age << endl;*/
//    cout << "jjj" << endl;
//}
//
//int main()
//{
//    //student s;
//    //person p1 = s;  //基类的对象
//    //person* p2 = &s; //基类的指针
//    //person& p3 = s;  //基类的引用 
//
//    person t;
//}


//
//class A
//{
//    friend void func();
//private:
//    int a;
//};
//
//
//
//class B:public A
//{
//private:
//    int b;
//};
//void func()
//{
//    cout << "友元函数" << endl;
//
//}
//
//
//
//int main()
//{
//    A a;
//    func();
//}

//
//class A
//
//{
//
//public:
//
//    A() :m_iVal(0) { test(); }
//
//    virtual void func() { std::cout << m_iVal << " "; }
//
//    void test() { func(); }
//
//public:
//
//    int m_iVal;
//
//};
//
//
//
//class B : public A
//
//{
//
//public:
//
//    B() { test(); }
//
//    virtual void func()
//
//    {
//
//        ++m_iVal;
//
//        std::cout << m_iVal << " ";
//
//    }
//
//};
//
//
//
//int main(int argc, char* argv[])
//
//{
//
//    A* p = new B;
//
//    p->test();
//
//    return 0;
//
//}






  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


//
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//
//        queue<TreeNode*> s;
//        vector<vector<int>> result;
//
//        s.push(root);
//
//        while (!s.empty())
//        {
//            vector<int> tmp;
//            int sz = s.size();
//            for (int i = 0; i < sz; i++)
//            {
//                TreeNode* p = s.front();
//                tmp.push_back(p->val);
//                if (s.front()->left)
//                    s.push(s.front()->left);
//                if (s.front()->right)
//                    s.push(s.front()->right);
//                s.pop();
//            }
//            if (tmp.size())
//                result.push_back(tmp);
//        }
//        return result;
//
//    }
//};
//
//
//int main()
//{
//    TreeNode* p1 = new TreeNode(1);
//    TreeNode* p2 = new TreeNode(2);
//    TreeNode* p3 = new TreeNode(3);
//    TreeNode* p4 = new TreeNode(4);
//
//    p1->left = p2;
//    p1->right = p3;
//    p3->left = p4;
//
//    Solution s;
//    s.levelOrder(p1);
//
//}


  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */





  //class Solution {
  //public:
  //    TreeNode* _bulidTree(vector<int>& preorder, vector<int>& inorder, int inbegin, int inend, int pre)
  //    {
  //        if (inbegin > inend)
  //            return nullptr;

  //        TreeNode* cur = new TreeNode(preorder[pre]);

  //        int rooti = inbegin;
  //        while (inorder[rooti] != preorder[pre])
  //        {
  //            rooti++;
  //        }

  //        cur->left = _bulidTree(preorder, inorder, inbegin, rooti - 1, pre + 1);
  //        cur->right = _bulidTree(preorder, inorder, rooti + 1, inend, pre + rooti-inbegin + 1);
  //        return cur;
  //    }
  //    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  //        return _bulidTree(preorder, inorder, 0, inorder.size() - 1, 0);
  //    }
  //};


  //int main()
  //{
  //    TreeNode p1(3);
  //    TreeNode p2(9);
  //    TreeNode p3(20);
  //    TreeNode p4(15);
  //    TreeNode p5(7);

  //    p1.left = &p2;
  //    p1.right = &p3;

  //    p3.left = &p4;
  //    p3.right = &p5;

  //    vector<int>  preorder = { 3, 9, 20, 15, 7 };
  //    vector<int>  inorder = { 9,3,15,20,7 };

  //    Solution s;
  //    s.buildTree(preorder, inorder);

  //}

//
//class Solution {
//public:
//    void fun(int n, int k, vector<int> num, vector<vector<int>>& result)
//    {
//        if (k == 0)
//        {
//            //结束条件
//            result.push_back(num);
//            return;
//        }
//
//        for (int i = num.size() == 0 ? 1 : num[num.size() - 1]; i <= n; i++)
//        {
//            if (find(num.begin(), num.end(), i) == num.end())
//            {
//                num.push_back(i);
//                fun(n, k - 1, num, result);
//                num.pop_back();
//            }
//        }
//    }
//    vector<vector<int>> combine(int n, int k) {
//        vector<int> num;
//        vector<vector<int>> result;
//
//        fun(n, k, num, result);
//        return result;
//    }
//};
//int main()
//{
//    Solution s;
//    s.combine(4, 2);
//}
//
//class Solution {
//public:
//    void fun(vector<vector<int>>& result, int k, int n, vector<int> num)
//    {
//        if (k == 0)
//        {
//            int sum = 0;
//            for (auto e : num)
//            {
//                sum += e;
//            }
//            if (sum == n)
//            {
//                result.push_back(num);
//                return;
//            }
//            else
//            {
//                return;
//            }
//
//        }
//
//        for (int i = num.size() == 0 ? 1 : num[num.size() - 1] + 1; i <= 9; i++)
//        {
//            if (find(num.begin(), num.end(), i) == num.end())
//            {
//                num.push_back(i);
//                fun(result, k - 1, n, num);
//                num.pop_back();
//            }
//        }
//    }
//    vector<vector<int>> combinationSum3(int k, int n) {
//        vector<vector<int>> result;
//
//        if (k > 9 || n<(k * k + k) / 2 || n>(19 * n - n * n) / 2)
//            return result;
//        vector<int> num;
//        fun(result, k, n, num);
//        return result;
//    }
//};
//
//
//int main()
//{
//    Solution s;
//    s.combinationSum3(9, 45);
//}
//
//class Solution {
//public:
//    void fun(vector<vector<int>>& result, vector<int>& candidates, int target, vector<int> used, vector<int> cur = vector<int>(), int k = -1)
//    {
//        int sum = 0;
//        for (auto e : cur)
//        {
//            sum += e;
//        }
//        if (sum > target)
//            return;
//        else if (sum == target)
//        {
//            result.push_back(cur);
//        }
//        else
//        {
//            for (int i = (k == -1 ? 0 : k + 1); i < candidates.size(); i++)
//            {
//                if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == 0)
//                    continue;
//                cur.push_back(candidates[i]);
//                used[i] = 1;
//                fun(result, candidates, target, used, cur, i);
//                used[i] = 0;
//                cur.pop_back();
//            }
//        }
//    }
//    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//        vector<vector<int>> result;
//        sort(candidates.begin(), candidates.end());
//        vector<int> used;
//        used.resize(candidates.size());
//        for (auto& e : used)
//        {
//            e = 0;
//        }
//        fun(result, candidates, target, used);
//        return result;
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector <int> v = { 1,1,2 };
//    s.combinationSum2(v, 3);
//}


//
// 
//
//
//class Solution {
//public:
//    TreeNode* _buildtree(vector<int>& nums, int begin, int end)
//    {
//        结束条件
//        if (begin > end)
//        {
//            return nullptr;
//        }
//
//        int max = nums[begin];
//        int j=begin;
//        for (int i = begin; i <= end; i++)
//        {
//            if (nums[i] > max)
//            {
//                max = nums[i];
//                j = i;
//            }
//        }
//
//        TreeNode* cur = new TreeNode(max);
//
//        cur->left = _buildtree(nums, begin, i - 1);
//        cur->right = _buildtree(nums, i + 1, end);
//        return cur;
//    }
//    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//        return _buildtree(nums, 0, nums.size() - 1);
//    }
//};
//
//
//
//int main()
//{
//    vector<int> s = { 3,2,1 };
//    Solution v;
//    v.constructMaximumBinaryTree(s);
//}

//
//class Solution {
//public:
//    bool check(vector<int>& postorder, int begin, int end)
//    {
//        //case finish
//        if (begin >= end)
//        {
//            return true;
//        }
//
//        int root = end;
//
//        int left;
//        for (left = end - 1; left >= begin; left--)
//        {
//            if (postorder[left] < postorder[root])
//            {
//                break;
//            }
//        }
//
//        int i = left;
//
//        while (i >= begin)
//        {
//            if (postorder[i] > postorder[root])
//                return false;
//            i--;
//        }
//
//        return check(postorder, begin, left) && check(postorder, left + 1, root - 1);
//
//    }
//    bool verifyPostorder(vector<int>& postorder) {
//        return check(postorder, 0, postorder.size() - 1);
//    }
//};
//
//
//int main()
//{
//    vector<int> v = { 1,2,5,10,6,9,4,3 };
//    Solution s;
//    s.verifyPostorder(v);
//
//
//
//
//
//}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    vector<int> postorderTraversal(TreeNode* root) {
//        TreeNode* prev=nullptr;
//
//        vector<int> result;
//
//        stack<TreeNode*> st;
//
//        while (root != nullptr || !st.empty())
//        {
//            while (root)
//            {
//                st.push(root);
//                root = root->left;
//            }
//            TreeNode* t = st.top();
//            if (t->right == prev)
//            {
//                result.push_back(t->val);
//                prev = st.top();
//                st.pop();
//                continue;
//            }
//
//            if (t->right == nullptr)
//            {
//                result.push_back(t->val);
//                prev = st.top();
//                st.pop();
//            }
//            else
//                root = t->right;
//        }
//        return result;
//    }
//};
//
//
//
//
//int main()
//{
//    TreeNode p1(1);
//    TreeNode p2(2);
//    TreeNode p3(3);
//
//    p1.right = &p2;
//    p2.left = &p3;
//
//
//    Solution s;
//    s.postorderTraversal(&p1);
//}


//
//class Solution {
//public:
//    void fun(map<int, int>& m, TreeNode* root)
//    {
//        if (root == nullptr)
//            return;
//        m[root->val]++;
//
//        fun(m, root->left);
//        fun(m, root->right);
//    }
//
//    struct cmp
//    {
//        bool operator()(pair<int, int>& x, pair<int, int>& y)
//        {
//            return x.second > y.second;
//        }
//    };
//
//    vector<int> findMode(TreeNode* root) {
//        map<int, int> m;
//
//        fun(m, root);
//        vector<int> result;
//        vector<pair<int, int>> v;
//
//        for (auto& e : m)
//        {
//            v.push_back(e);
//        }
//
//        sort(v.begin(), v.end(), cmp());
//        int max = v[0].second;
//        int i = 0;
//        while (v[i].second == max && i < v.size())
//        {
//            result.push_back(v[i].first);
//            i++;
//        }
//        return result;
//    }
//};
//
//
//int main()
//{
//    TreeNode p1(1);
//    TreeNode p2(2);
//    TreeNode p3(3);
//
//    p1.right = &p2;
//    p2.left = &p3;
//    Solution s;
//    vector<int> v=s.findMode(&p1);
//}
#include<unordered_set>
//class Solution {
//public:
//    vector<string> uncommonFromSentences(string s1, string s2) {
//        unordered_set<string> m1;
//        vector<string> m2;
//        vector<string> result;
//        auto start = s1.begin();
//
//
//        for (auto it = s1.begin(); it != s1.end(); it++)
//        {
//            if (*it == ' ')
//            {
//                string tmp(start, it);
//                start = it + 1;
//                m1.insert(tmp);
//            }
//        }
//
//        m1.insert(string(start, s1.end()));
//
//
//        start = s2.begin();
//        for (auto it = s2.begin(); it != s2.end(); it++)
//        {
//            if (*it == ' ')
//            {
//                string tmp(start, it);
//                start = it + 1;
//                m2.push_back(tmp);
//            }
//        }
//
//        m2.push_back(string(start, s2.end()));
//
//        for (auto& e : m2)
//        {
//            auto it = m1.insert(e);
//            if (it.second==true)
//            {
//                result.push_back(e);
//            }
//        }
//        return result;
//
//    }
//};
//
//
//
//int main()
//{
//    string s1 = "this apple is sweet";
//    string s2 = "this apple is sour";
//
//    Solution s;
//    s.uncommonFromSentences(s1, s2);
//}

//
//class Solution {
//public:
//    TreeNode* prev = nullptr;
//    void fun(TreeNode* root, vector<int>& result, int& count, int& maxcount)
//    {
//        if (root == nullptr)
//            return;
//
//
//        fun(root->left, result, count, maxcount);
//        //
//        if (prev == nullptr)
//        {
//            count = 1;
//        }
//        else if (prev->val == root->val)
//            count++;
//        else if (prev->val != root->val)
//        {
//            count = 1;
//        }
//        if (count == maxcount)
//            result.push_back(root->val);
//
//        if (count > maxcount)
//        {
//            while (result.size())
//            {
//                result.pop_back();
//            }
//            maxcount = count;
//            result.push_back(root->val);
//        }
//        prev = root;
//        //
//        fun(root->right, result, count, maxcount);
//    }
//    vector<int> findMode(TreeNode* root) {
//        vector<int> result;
//        fun(root, result, 1, 0);
//        return result;
//    }
//};
//
//int main()
//{
//    TreeNode p1(1);
//    TreeNode p2(2);
//    TreeNode p3(3);
//
//    p1.left= &p2;
//    //p2.left = &p3;
//    Solution s;
//    s.findMode(&p1);
//
//}


//
//int main()
//{
//    map<int, int> m;
//
//    m.insert(make_pair(1, 0));
//    m.insert(make_pair(2, 0));
//    auto it=m.insert(make_pair(1, 0));
//
//    if (it.first == m.end())
//        cout << "1";
//
//
//}

//class Solution {
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        int row_number = obstacleGrid.size();
//        int col_number = obstacleGrid[0].size();
//        if (obstacleGrid[row_number - 1][col_number - 1] == 1 || obstacleGrid[0][0] == 1)
//            return 0;
//        vector<int> nums;
//        nums.resize(col_number);
//        int flag = 0;
//        for (int i = 0; i < col_number; i++)
//        {
//            if (flag)
//            {
//                nums[i] = 0;
//                continue;
//            }
//            if (obstacleGrid[row_number - 1][i] != 1)
//                nums[i] = 1;
//            else
//            {
//                nums[i] = 0;
//                flag = 1;
//            }
//        }
//
//        for (int i = row_number - 2; i >= 0; i--)
//        {
//            for (int j = col_number - 1; j >= 0; j--)
//            {
//                if (obstacleGrid[i][j] == 1)
//                {
//                    nums[j] = 0;
//                    continue;
//                }
//                else
//                {
//                    int right = 0, down = 0;
//
//                    if (j + 1 < col_number && nums[j + 1] != -1)
//                        right = nums[j + 1];
//
//                    if (nums[j] != -1)
//                        down = nums[j];
//
//                    nums[j] = right + down;
//                }
//            }
//        }
//        return nums[0];
//    }
//};
//
//int main()
//{
//    vector<vector<int>> s = { {0,0},{1,0} };
//    Solution t;
//    t.uniquePathsWithObstacles(s);
//}



//int main()
//{
//    map<int, int> m;
//    vector<int> v = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//    for (auto e : v)
//    {
//        m.insert(make_pair(e, 0));
//    }
//    map<int, int>::const_iterator it = m.begin();
//}

//
//
//#include"map.h"
//int main()
//{
//    bit::map<int, int> m;
//    vector<int> v = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//       /* for (auto e : v)
//        {
//            m.insert(make_pair(e, 0));
//        }*/
//    bit::map<int, int>::const_iterator it = m.begin();
//   
//}

//
//
//max = max_prev.top();
//while (max->val > high || !max_prev.empty())
//{
//    max_prev.pop();
//    if (min_prev.empty())
//    {
//        root = max->left;
//        break;
//    }
//    else
//        min_prev.top()->right = max->left;
//
//    delete max;
//    max = max_prev.top();
//    while (max)
//    {
//        max_prev.push(max);
//        max = max->left;
//    }
//    max = max_prev.top();
//}


//class Solution {
//public:
//    void fun(const vector<int>& nums, vector<vector<int>>& result, vector<int>& cur, int k)
//    {
//
//        result.push_back(cur);
//        if (k == nums.size())
//        {
//           
//            return;
//        }
//        
//
//        for (int i = k; i < nums.size(); i++)
//        {
//            cur.push_back(nums[i]);
//            fun(nums, result, cur, i + 1);
//            cur.pop_back();
//        }
//
//    }
//    vector<vector<int>> subsets(vector<int>& nums) {
//        vector<vector<int>> result;
//        vector<int> cur;
//        fun(nums, result, cur, 0);
//        return result;
//    }
//};
//

//class Solution {
//public:
//    vector<vector<int>> result;
//
//    void fun(vector<vector<int>>& result, vector<int>& nums, vector<int> cur, int k)
//    {
//        result.push_back(cur);
//        if (k == nums.size())
//        {
//            return;
//        }
//        int set;
//
//        for (int i = k; i < nums.size(); i++)
//        {
//            if (i == k)
//            {
//                set = nums[i];
//                cur.push_back(nums[i]);
//                fun(result, nums, cur, i + 1);
//                cur.pop_back();
//            }
//            else
//            {
//                if (nums[i] == set)
//                    continue;
//
//                cur.push_back(nums[i]);
//                fun(result, nums, cur, i + 1);
//                cur.pop_back();
//
//            }
//        }
//    }
//    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//
//
//        fun(result, nums, vector<int>(), 0);
//        return result;
//    }
//};
//int main()
//{
//    vector<int> s = { 1,2,2 };
//    Solution t;
//    t.subsetsWithDup(s);
//}

//
//void fun(int a)
//{
//    cout << "int a" << endl;
//}
//
//void fun(const int a)
//{
//    cout << "const int a" << endl;
//}
//
//int main()
//{
//    //const map<int, int> m;
//
//    ////m.insert(make_pair(1, 10));
//
//    //auto it = m.begin();
//
//
//    //cout << it->second << endl;
//
//    int a = 10;
//    fun(a);
//}

#include<unordered_map>
//
//class Solution {
//public:
//
//    vector<vector<int>> result;
//    void fun(vector<int> cur, vector<int>& nums, vector<int>  used, set<int> s, int k)
//    {
//        if (cur.size() >= 2)
//        {
//            if (cur[cur.size() - 1] >= cur[cur.size() - 2])
//                result.push_back(cur);
//            else
//                return;
//        }
//
//        if (k == cur.size() - 1)
//        {
//            return;
//        }
//
//        for (int i = k; i < nums.size(); i++)
//        {
//            if (i == 0)
//            {
//                cur.push_back(nums[i]);
//                fun(cur, nums, used, s, i + 1);
//                cur.pop_back();
//            }
//            else if (s.find(nums[i]) == s.end() && (nums[i] != nums[i - 1] || used[i - 1] == 0))
//            {
//                cur.push_back(nums[i]);
//                fun(cur, nums, used, s, i + 1);
//                cur.pop_back();
//            }
//            used[i] = 1;
//            s.insert(nums[i]);
//        }
//    }
//    vector<vector<int>> findSubsequences(vector<int>& nums) {
//        vector<int> used;
//        used.resize(nums.size(), 0);
//        //sort(nums.begin(),nums.end());
//        fun(vector<int>(), nums, used, set<int>(), 0);
//        vector<vector<int>> m;
//
//        for (auto& e : result)
//        {
//            m.push_back(e);
//        }
//        return m;
//    }
//};
//class Solution {
//public:
//    vector<vector<int>> result;
//
//    void fun(vector<int>& nums, vector<int> cur, int k, set<int> s)
//    {
//        if (cur.size() == nums.size())
//        {
//            result.push_back(cur);
//            return;
//        }
//        
//
//
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (s.size() != 0)
//            {
//                if (s.find(nums[i]) != s.end())
//                    continue;
//            }
//
//
//            cur.push_back(nums[i]);
//            s.insert(nums[i]);
//            fun(nums, cur, i + 1, s);
//            cur.pop_back();
//            s.erase(nums[i]);
//        }
//
//    }
//    vector<vector<int>> permute(vector<int>& nums) {
//        fun(nums, vector<int>(), 0, set<int>());
//        return result;
//    }
//};
//int main()
//{
//    vector<int> s = {1,2,3};
//    Solution t;
//    vector<vector<int>> result = t.permute(s);
//}







  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
  /*class Solution {
  public:
      bool isAnagram(string s, string t) {
          unordered_map<char, int> s1;


          for (auto& e : s)
          {
              s1[e]++;
          }

          for (auto& e : t)
          {
              auto ret = s1.insert(e);

              if (ret.second == true)
                  return false;
              else
                  ((ret.first)->second)--;
          }


          for (auto e : s1)
          {
              if (e.second != 0)
                  return false;
          }

          return true;


      }
  };*/






  //int main()
  //{
  //    int x = INT_MAX;
  //    cout << x << endl;
  //}

//
//#include<unordered_set>
//  class Solution {
//  public:
//      vector<int> search(vector<vector<string>>& tickets, string start)
//      {
//          vector<int> v;
//          for (int i = 0; i < tickets.size(); i++)
//          {
//              if (tickets[i][0] == start)
//                  v.push_back(i);
//          }
//          for (int i = 0; i < v.size(); i++)
//          {
//              for (int j = 0; j < v.size() - i - 1; j++)
//              {
//                  if (tickets[v[j]][1] > tickets[v[j+1]][1])
//                  {
//                      swap(v[j], v[j + 1]);
//                  }
//              }
//          }
//          return v;
//      }
//      vector<string> result;
//      void fun(vector<vector<string>>& tickets, vector<string> cur, int k, unordered_map<string, unordered_map<string,int> > m, int prev)
//      {
//          // finish 
//          if (cur.size() == tickets.size() + 1)
//          {
//              result=cur;
//
//              return;
//          }
//
//
//          if (k == 0)
//          {
//              vector<int> line = search(tickets, "JFK");
//              for (int i = 0; i < line.size(); i++)
//              {
//                  
//                  if(cur.size()==0)
//                  cur.push_back(tickets[line[i]][0]);
//                  cur.push_back(tickets[line[i]][1]);
//                  m[tickets[line[i]][0]][tickets[line[i]][1]]--;
//                  fun(tickets, cur, k + 1, m, line[i]);
//                  if (result.size())
//                      return;
//                  m[tickets[line[i]][0]][tickets[line[i]][1]]++;
//                  cur.pop_back();
//                 
//              }
//
//          }
//          else
//          {
//              string start = tickets[prev][1];
//              vector<int> line = search(tickets, start);
//              for (int i = 0; i < line.size(); i++)
//              {
//                  if (m[tickets[line[i]][0]][tickets[line[i]][1]])
//                  {
//                      cur.push_back(tickets[line[i]][1]);
//                      m[tickets[line[i]][0]][tickets[line[i]][1]]--;
//                      fun(tickets, cur, k + 1, m, line[i]);
//                      if (result.size())
//                          return;
//                      m[tickets[line[i]][0]][tickets[line[i]][1]]++;
//                      cur.pop_back();
//                  }
//              }
//             
//          }
//
//      }
//      vector<string> findItinerary(vector<vector<string>>& tickets) {
//          unordered_map<string, unordered_map<string,int>> m;
//
//          for (auto e : tickets)
//          {
//              m[e[0]][e[1]]++;
//          }
//          fun(tickets, vector<string>(), 0, m, 0);
//          
//          return result;
//      }
//  };
//
//
//
//  int main()
//  {
//      vector<vector<string>> s = {{"EZE", "TIA"}, {"EZE", "HBA"}, {"AXA", "TIA"}, {"JFK", "AXA"}, {"ANU", "JFK"}, {"ADL", "ANU"}, {"TIA", "AUA"}, {"ANU", "AUA"}, {"ADL", "EZE"}, {"ADL", "EZE"}, {"EZE", "ADL"}, {"AXA", "EZE"}, {"AUA", "AXA"}, {"JFK", "AXA"}, {"AXA", "AUA"}, {"AUA", "ADL"}, {"ANU", "EZE"}, {"TIA", "ADL"}, {"EZE", "ANU"}, {"AUA", "ANU"}}
//      ;
//      Solution t;
//      t.findItinerary(s);
//  }



//
//
//class Solution {
//public:
//    bool check(int col, int row, unordered_map<int, int> prev)
//    {
//        for (auto e : prev)
//        {
//            if (e.second == col)
//                return false;
//
//            if (col == e.second + row - e.first)
//                return false;
//        }
//        return true;
//    }
//    vector<vector<string>> result;
//    void fun(vector<string> cur, unordered_map<int, int> prev, int n, int k = 0)
//    {
//        //finish case
//        if (k == n)
//        {
//            result.push_back(cur);
//            return;
//        }
//
//
//        if (k == 0)
//        {
//            string row;
//            row.resize(n);
//            for (auto& e : row)
//            {
//                e = '.';
//            }
//
//            for (int i = 0; i < n; i++)
//            {
//                row[i] = 'Q';
//                cur.push_back(row);
//                prev[k] = i;
//                fun(cur, prev, n, k + 1);
//                prev.erase(k);
//                cur.pop_back();
//                row[i] = '.';
//            }
//        }
//        else
//        {
//            string row;
//            row.resize(n);
//            for (auto& e : row)
//            {
//                e = '.';
//            }
//
//            for (int i = 0; i < n; i++)
//            {
//                if (check(i, k, prev))
//                {
//                    row[i] = 'Q';
//                    cur.push_back(row);
//                    prev[k] = i;
//                    fun(cur, prev, n, k + 1);
//                    prev.erase(k);
//                    cur.pop_back();
//                    row[i] = '.';
//                }
//            }
//
//        }
//
//    }
//    vector<vector<string>> solveNQueens(int n) {
//        fun(vector<string>(), unordered_map<int, int>(), n);
//        return result;
//
//    }
//};
//
//
//
//int main()
//{
//    Solution s;
//    s.solveNQueens(4);
//}
//
//
//
//bool is_in_block(int row, int col, vector<vector<char>>& board)
//{
//    int cbegin, cend, rbegin, rend;
//    if (row < 3)
//    {
//        vector<unordered_set<int>> row1;
//        if (col < 3)
//        {
//            unordered_set<int> block1;
//            cbegin = 0;
//            rbegin = 0;
//            cend = 2;
//            rend = 2;
//
//
//        }
//        else if (col >= 3 && col <= 5)
//        {
//            cbegin = 3;
//            rbegin = 0;
//            cend = 5;
//            rend = 2;
//        }
//        else
//        {
//            cbegin = 6;
//            rbegin = 0;
//            cend = 8;
//            rend = 2;
//        }
//    }
//    else if (row >= 3 && row <= 5)
//    {
//        if (col < 3)
//        {
//            cbegin = 0;
//            cend = 2;
//            rbegin = 3;
//            rend = 5;
//        }
//        else if (col >= 3 && col <= 5)
//        {
//            cbegin = 3;
//            cend = 5;
//            rbegin = 3;
//            rend = 5;
//        }
//        else
//        {
//            cbegin = 6;
//            cend = 8;
//            rbegin = 3;
//            rend = 5;
//        }
//    }
//    else
//    {
//        if (col < 3)
//        {
//            cbegin = 0;
//            cend = 2;
//            rbegin = 6;
//            rend = 8;
//        }
//        else if (col >= 3 && col <= 5)
//        {
//            cbegin = 3;
//            cend = 5;
//            rbegin = 6;
//            rend = 8;
//        }
//        else
//        {
//            cbegin = 6;
//            cend = 8;
//            rbegin = 6;
//            rend = 8;
//        }
//    }
//    unordered_set<int> s;
//    for (int i = rbegin; i <= rend; i++)
//    {
//        for (int j = cbegin; j <= cend; j++)
//        {
//            if (board[i][j] != '.')
//            {
//                auto it = s.insert(board[i][j] - '0');
//                if (it.second == false)
//                    return false;
//            }
//        }
//    }
//    return true;
//}
//
//
//void fun(vector<vector<char>>& board, int k, int i)
//{
//    if (k == 9 )
//    {
//
//        return;
//    }
//
//
//    unordered_set<int> row;
//    if (board[k][i] == '.')
//    {
//        for (int j = 1; j <= 9; j++)   //取数
//        {
//            //列去重
//            int flag_col = 1;
//            int flag_row = 1;
//            unordered_set<int> col;
//            unordered_set<int> row;
//            col.insert(j);
//            row.insert(j);
//
//            for (int m = 0; m < 9; m++)
//            {
//                if (board[k][m] != '.')
//                {
//                    auto ret1 = row.insert(board[k][m] - '0');
//                    if (ret1.second == false)
//                    {
//                        flag_row = 0;
//                        break;
//                    }
//                }
//                if (board[m][i] != '.')
//                {
//                    auto ret2 = col.insert(board[m][i] - '0');
//
//                    if (ret2.second == false)
//                    {
//                        flag_col = 0;
//                        break;
//                    }
//                }
//            }
//
//            //块去重
//            int flag_block = is_in_block(k, i, board);
//
//            if (flag_block && flag_col&& flag_row)
//            {
//                board[k][i] = j + '0';
//
//                if (i == 8)
//                {
//                    fun(board, k + 1, 0);
//                    board[k][i] = '.';
//                }
//                else
//                {
//                    fun(board, k, i + 1);
//                    board[k][i] = '.';
//                }
//            }
//        }
//    }
//    else
//    {
//       
//        if (i == 9)
//        {
//            fun(board, k + 1, 0);
//        }
//        else
//        {
//            fun(board, k, i + 1);
//        }
//    }
//
//}
//
//
//int main()
//{
//    vector<vector<char>> board = { {'5','3','.','.','7','.','.','.','.'} ,{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},
//        {'8','.','.','.','6','.','.','.','3'} ,{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'}
//                             ,{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'
//} };
//    fun(board, 0, 0);
//}
//
//
//class Solution {
//public:
//    vector<vector<int>> result;
//    void fun(vector<int>& nums, vector<int> cur, vector<int> used, int k, int target, int sum)
//    {
//        if (cur.size() == 3)
//        {
//            if (sum == target)
//            {
//                result.push_back(cur);
//            }
//            return;
//        }
//
//
//        for (int i = k; i < nums.size(); i++)
//        {
//            if (k == 0 && (nums[i] > 0 || (nums[i] < 0 && nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] < 0)))
//            {
//                continue;
//            }
//            else
//            {
//                if (i == 0 || nums[i] != nums[i - 1] || used[i-1] == 0)
//                {
//                    cur.push_back(nums[i]);
//                    fun(nums, cur, used, i + 1, target, nums[i] + sum);
//                    cur.pop_back();
//                    
//                }
//                used[i] = 1;
//            }
//        }
//    }
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<int> used;
//        used.resize(nums.size());
//        for (auto& e : used)
//        {
//            e = 0;
//        }
//        sort(nums.begin(), nums.end());
//        fun(nums, vector<int>(), used, 0, 0, 0);
//        return result;
//    }
//};

//
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//
//        vector<vector<int>> result;
//        sort(nums.begin(), nums.end());
//
//
//        int left;
//        int right;
//
//
//        for (int i = 0; i < nums.size() - 2; i++)
//        {
//            if (nums[i] > 0)
//                break;
//
//            if (i > 0 && nums[i] == nums[i - 1])
//                continue;
//            left = i + 1;
//            right = nums.size() - 1;
//            while (left < right)
//            {
//                if (nums[i] + nums[left] + nums[right] > 0)
//                    right--;
//                else if (nums[i] + nums[left] + nums[right] < 0)
//                    left++;
//                else
//                {
//                    vector<int> tmp;
//                    tmp.push_back(nums[i]);
//                    tmp.push_back(nums[left]);
//                    tmp.push_back(nums[right]);
//                    result.push_back(tmp);
//                }
//
//            }
//
//
//        }
//        return result;
//    }
//};
//
//int main()
//{
//    vector<int> s = { -1,0,1,2,-1,-4 };
//
//    int a[] = { 1,2,3 };
//    int(*p)[3] = &a;
//    
//    cout << a << endl;
//    cout << p << endl;
//
//    Solution t;
//    t.threeSum(s);
//}


//
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//
//        vector<vector<int>> result;
//        sort(nums.begin(), nums.end());
//
//
//        int left;
//        int right;
//
//
//        for (int i = 0; i < nums.size() - 2; i++)
//        {
//            if (nums[i] > 0)
//                break;
//
//            if (i > 0 && nums[i] == nums[i - 1])
//                continue;
//            left = i + 1;
//            right = nums.size() - 1;
//            while (left < right)
//            {
//                if (nums[i] + nums[left] + nums[right] > 0)
//                    right--;
//                else if (nums[i] + nums[left] + nums[right] < 0)
//                    left++;
//                else
//                {
//                    vector<int> tmp;
//                    tmp.push_back(nums[i]);
//                    tmp.push_back(nums[left]);
//                    tmp.push_back(nums[right]);
//                    result.push_back(tmp);
//                    left++;
//                    while (left < right)
//                    {
//                        if (nums[left] == nums[left - 1])
//                            left++;
//                    }
//                }
//
//            }
//
//
//        }
//        return result;
//    }
//};
//class Solution {
//public:
//    int threeSumClosest(vector<int>& nums, int target) {
//        sort(nums.begin(), nums.end());
//        int result;
//        for (int i = 0; i < nums.size() - 2; i++)
//        {
//            if (target < 0 && nums[i]>0)
//                break;
//
//
//            int left = i + 1;
//            int right = nums.size() - 1;
//            if (i == 0)
//                result = nums[i] + nums[left] + nums[right];
//            while (left < right)
//            {
//                if (abs(nums[i] + nums[left] + nums[right] - target) < abs(result - target))
//                    result = nums[i] + nums[left] + nums[right];
//                if (nums[i] + nums[left] + nums[right] > target)
//                    right--;
//                else if (nums[i] + nums[left] + nums[right] < target)
//                    left++;
//                else
//                {
//                    return target;
//                }
//
//                
//            }
//
//        }
//        return result;
//    }
//};
//
//int main()
//{
//    vector<int> s = { -1,2,1,-4 };
//
//    Solution t;
//    t.threeSumClosest(s,1);
//}


//class Solution {
//public:
//    int minSubarray(vector<int>& nums, int p) {
//
//        vector<int> sum;
//        sum.resize(nums.size());
//        sum[0] = nums[0];
//        for (int i = 1; i < nums.size(); i++)
//        {
//            sum[i] = nums[i] + sum[i - 1];
//            if (sum[i] % p == 0)
//                return nums.size() - 1 - i;
//        }
//
//        int  m = -1;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            int j = i;
//
//            for (; j < nums.size(); j++)
//            {
//                int left, right;
//
//                if (i == 0)
//                    left = 0;
//                else
//                    left = sum[i - 1];
//
//
//                if (j == nums.size() - 1)
//                    right = 0;
//                else
//                    right = sum[sum.size()-1] - sum[j];
//
//
//         
//                if (left + right != 0 && (left + right) % p == 0)
//                {
//                    if (m == -1)
//                        m = j - i + 1;
//                    else
//                        m = min(m, j - i + 1);
//                }
//            }
//        }
//        return m;
//
//    }
//};


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        if (nums.size() < 4)
            return result;
        for (int i = 0; i < nums.size() - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                if (j > 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right)
                {
                    if (nums[i] + nums[j] + nums[left] + nums[right] > target)
                        right--;
                    else if (nums[i] + nums[j] + nums[left] + nums[right] < target)
                        left++;
                    else
                    {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[left]);
                        tmp.push_back(nums[right]);

                        result.push_back(tmp);
                        left++;
                        while (left < right && nums[left] == nums[left - 1])
                        {
                            left++;
                        }
                    }
                }
            }
        }
        return result;
    }
};
int main()
{
    vector<int> s = { -2,-1,-1,1,1,2,2 };
    Solution t;
    t.fourSum(s, 0);
}

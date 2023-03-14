#define _CRT_SECURE_NO_WARNINGS 1

#include"string.h"
#include<iostream>
#include<vector>

typedef sht::string String;
using namespace std;

void foo(String x)
{
}

void bar(const String& x)
{
}

String baz()
{
	String ret("world");
	return ret;
}




void test1()
{
	//String s0;
	/*String s1("hello");
	String s2(s0);
	String s3 = s1;
	s2 = s1;

	foo(s1);
	bar(s1);
	foo("temporary");
	bar("temporary");
	String s4 = baz();

	std::vector<String> svec;
	svec.push_back(s0);
	svec.push_back(s1);
	svec.push_back(baz());
	svec.push_back("good job");*/
}

sht::string fun()
{
	sht::string s1 = "1223344556";
	//test1();
	sht::string a = "12sjfhskfhewlf";
	return a;
}

//void test2()
//{
//	sht::string s1("12345");
//	sht::string s5(sht::string("11111111111111111"));
//	sht::string s2(std::move(s1));
//	
//	sht::string s3("1") ;
//	//s3 =fun();
//	sht::string s4("12222222222");
//	s4 = fun();
//	sht::string s6("1444444444444");
//
//
//}



void test3()
{
	sht::string s1("12345");
	sht::string s2("1234234");
	sht::string s3("1");
	s1 + s2=s3;
	//s1 + s2 = s3;


}


int add(int x, int y)
{
	return x + y;
}


void test4()
{
	//左值 和 右值
	int a1 = 1;
	int* a2 = new int[10];
	const int a3 = 1;
	int a4 = a1 + a3;
	int a5 = add(a1, a3);


	//右值引用
	int&& r1 = 10;
	int&& r2 = a1 + a3;
	int&& r3 = add(a1, a3); 


	//左值引用
	int& l1 = a1;
	const int& l2 = a3;
	int*& l3 = a2;

}


sht::string function(string& s)
{
	sht::string tmp;
	//.........
	return tmp;
}
//int main()
//{
//	test4();
//	
//	std::string s1("123");
//	std::string s2("456");
//	std::string s3("789");
//	sht::string s4 = function(s1);
//	s1 + s2 = s3;
//}
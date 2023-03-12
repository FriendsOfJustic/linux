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

	return s1;
}

void test2()
{
	sht::string s1("12345");
	sht::string s5(sht::string("11111111111111111"));
	sht::string s2(std::move(s1));
	
	sht::string s3("1") ;
	s3 =fun();
}
int main()
{
	test2();
}
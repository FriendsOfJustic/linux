#pragma once

#include<iostream>
#include<assert.h>

using namespace std;

class Date

{

public:

	// ��ȡĳ��ĳ�µ�����

	int GetMonthDay(int year, int month);

	// ȫȱʡ�Ĺ��캯��

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}



	// �������캯��

  // d2(d1)

	Date(const Date& d);



	// ��ֵ���������

  // d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d);



	// ��������

	//~Date();



	// ����+=����

	Date& operator+=(int day);



	// ����+����

	Date operator+(int day);



	// ����-����

	Date operator-(int day);



	// ����-=����

	Date& operator-=(int day);



	// ǰ��++

	Date& operator++();



	// ����++

	Date operator++(int);



	// ����--

	Date operator--(int);



	// ǰ��--

	Date& operator--();

	// >���������

	bool operator>(const Date& d)const;



	// ==���������

	bool operator==(const Date& d)const;



	// >=���������

	inline bool operator >= (const Date& d)
	{
		return *this - d >= 0;
	}



	// <���������

	bool operator < (const Date& d)const;



	// <=���������

	bool operator <= (const Date& d)const;



	// !=���������

	bool operator != (const Date& d)const;



	// ����-���� ��������

	int operator-(const Date& d);




	void print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:

	int _year;

	int _month;

	int _day;

};





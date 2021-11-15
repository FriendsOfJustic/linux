#define _CRT_SECURE_NO_WARNINGS 1






#include"Date.h"

int Date::GetMonthDay(int year, int month)
{
	static int a[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			return 29;
		else
			return 28;
	}
	else
		return a[month-1];
}


Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}


Date& Date::operator+=(int day)
{
	_day += day;

	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;

		if (_month > 12)
		{
			_year++;
			_month = 1;
		}

	}

	return *this;
}



Date Date::operator+(int day)
{
	Date d1(*this);

	d1 += day;
	return d1;
}








// 日期-天数

Date Date::operator-(int day)
{
	Date d1(*this);
	d1 -= day;
	return d1;
}



// 日期-=天数

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day < 0)
	{
		_day += GetMonthDay(_year, _month);
		_month--;

		if (_month < 0)
		{
			_year--;
			_month = 12;
		}

	}
	return *this;
}



// 前置++

Date& Date::operator++()
{
	_day += 1;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;

		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}



// 后置++

Date Date::operator++(int)
{
	Date d1(*this);
	++(*this);
	return d1;
}



// 后置--

Date Date::operator--(int)
{
	Date d1(*this);
	--(*this);
	return d1;
}



// 前置--

Date& Date::operator--()
{
	_day -= 1;
	while (_day < 0)
	{
		_day += GetMonthDay(_year, _month);
		_month--;

		if (_month < 0)
		{
			_year--;
			_month = 12;
		}

	}
	return *this;
}



bool Date::operator>(const Date& d)const
{
	if (_year > d._year)
		return true;
	else if (_year == d._year && _month > d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day > d._day)
		return true;
	else
		return false;
}



// ==运算符重载

bool Date::operator==(const Date& d)const
{
	return _year==d._year&&_month==d._month&&_day==d._day;

}







// <运算符重载

bool Date::operator < (const Date& d)const
{
	if (*this <= d && *this != d)
		return true;
	else
		return false;

}



// <=运算符重载

bool Date::operator <= (const Date& d)const
{
	return !(*this>d);

}



// !=运算符重载

bool Date::operator != (const Date& d)const
{
	return !(*this==d);
}




int Date::operator-(const Date& d)
{
	int ret = 1;
	int count = 0;
	if (*this < d)
		ret = -1;
	Date max = (*this) > d ? *this : d;
	Date min = (*this) < d ? *this : d;

	while (min<max)
	{
		min++;
		count++;
	}
	return ret * count;
}
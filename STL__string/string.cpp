#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <assert.h>
#include <cstring>

namespace my
{

	class string
	{
		friend std::ostream &operator<<(std::ostream &i, string &s);
		friend void swap(string &s1, string &s2);

	public:
		typedef char *iterator;
		typedef const char *const_iterator;
		iterator begin()
		{
			return this->_str;
		}

		iterator end()
		{
			return this->_str + _size;
		}

		string(const char *p = "")
		{
			_size = strlen(p);
			_capacity = _size == 0 ? 5 : _size * 2;
			_str = new char[_capacity + 1];
			strcpy(_str, p);
		}

		string(const string &s)
		{
			_size = s._size;
			_capacity = s._capacity;
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		string &operator=(string s)
		{
			_size = s._size;
			_capacity = s._capacity;
			std::swap(_str, s._str);
			return *this;
		}

		char &operator[](int pos)
		{
			assert(pos < _size);
			return this->_str[pos];
		}

		char &operator[](int pos) const
		{
			assert(pos < _size);
			return this->_str[pos];
		}

		~string()
		{
			delete[] _str;
			_size = 0;
			_capacity = 0;
		}

		void reserve(int capacity)
		{
			if (capacity > _capacity)
			{
				_capacity = capacity;

				char *temp = new char[_capacity + 1];
				strcpy(temp, _str);
				delete[] _str;
				_str = temp;
			}
		}

		void resize(int size, char ch = '\0')
		{
			if (size <= _size)
			{
				_str[size] = '\0';
			}
			else
			{
				if (size > _capacity)
				{
					reserve(2 * size);
				}

				while (_size <= size)
				{
					_str[_size] = ch;
					_size++;
				}
			}
			_size = size;
			_str[_size] = '0';
		}

		void push_back(char p)
		{
			if (_size + 1 > _capacity)
			{
				reserve(2 * _capacity);
			}
			else
			{
				_str[_size] = p;
				_size++;
				_str[_size] = '\0';
			}
		}

		void append(const char *p)
		{
			int len = strlen(p);
			if (_size + len > _capacity)
			{
				reserve(len + _capacity);
			}

			for (int i = 0; i < len; i++)
			{
				_str[_size + i] = p[i];
			}
			_size += len;
			_str[_size] = '\0';
		}
		const char *c_str()
		{
			return _str;
		}

		bool operator<(const string &s)
		{
			int n1 = 0;
			int n2 = 0;

			while (n1 < _size && n2 < s._size)
			{
				if ((*this)[n1] == s[n2])
				{
					n1++;
					n2++;
				}
				else
				{
					if (_str[n1] < s._str[n2])
						return true;
					else
						return false;
				}
			}

			if (n1 == _size && n2 != s._size)
			{
				return true;
			}

			if (n1 != _size && n2 == s._size)
				return false;

			if (n1 == _size && n2 == s._size)
				return false;
		}

		bool operator<=(const string &s)
		{
			if (*this < s)
			{
				return true;
			}
			else if (*this < s)
				return true;
			else
				return false;
		}

		bool operator>(const string &s)
		{
			if (*this <= s)
				return false;
			else
				return true;
		}

		bool operator>=(const string &s)
		{
			if (*this < s)
				return false;
			else
				return true;
		}

		bool operator==(const string &s)
		{
			if (_size != s._size)
				return false;
			int n1 = 0;
			int n2 = 0;

			while (n1 < _size && n2 < s._size)
			{
				if ((*this)[n1] == s[n2])
				{
					n1++;
					n2++;
				}
				else
				{
					return false;
				}
			}
			return true;
		}

		bool operator!=(const string &s)
		{
			if (*this == s)
				return false;
			else
				return true;
		}

		// ����c��string�е�һ�γ��ֵ�λ��

		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == c)
					return i;
			}
			return -1;
		}

		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��

		size_t find(const char *s, size_t pos = 0) const
		{
			for (size_t i = pos; i < _size - strlen(s) + 1; i++)
			{
				if (_str[i] == s[0])
				{
					int k = i;
					int ret = 1;
					for (size_t j = 0; j < strlen(s); k++, j++)
					{
						if (_str[k] != s[j])
						{
							ret = 0;
							break;
						}
					}
					if (ret)
						return i;
				}
			}

			return -1;
		}

		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��

		string &insert(size_t pos, char c)
		{
			if (pos > _size)
				return *this;
			else
			{
				this->resize(_size + 1);
				int i;
				for (i = _size - 1; i >= (int)pos; i--) // ע��size_t�޷��ŵ�����
				{
					_str[i + 1] = _str[i];
				}
				_str[pos] = c;
				return *this;
			}
		}

		string &insert(size_t pos, const char *str)
		{
			int len = strlen(str);
			if (pos > _size)
				return *this;
			else
			{
				this->resize(_size + len);
				int i;
				for (i = _size - len; i >= (int)pos; i--)
				{
					_str[i + len] = _str[i];
				}
				for (int j = 0; j < len; j++)
				{
					_str[pos + j] = str[j];
				}

				return *this;
			}
		}

		// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��

		string &erase(size_t pos, size_t len)
		{
			assert(pos >= 0 && pos <= _size - len);
			_size -= len;
			for (int i = pos; i <= _size; i++)
			{
				_str[i] = _str[i + len];
			}
			return *this;
		}

	private:
		char *_str;
		size_t _size;
		size_t _capacity;
	};

	void swap(my::string &s1, my::string &s2)
	{
		std::swap(s1._size, s2._size);
		std::swap(s1._capacity, s2._capacity);
		std::swap(s1._str, s2._str);
	}
	std::ostream &operator<<(std::ostream &io, string &s)
	{
		for (int i = 0; i < s._size; i++)
		{
			io << s[i];
		}
		return io;
	}

	string &operator+=(string &s, char p)
	{
		s.push_back(p);

		return s;
	}

	string &operator+=(string &s, const char *p)
	{
		s.append(p);
		return s;
	}

}

using namespace std;
int main()
{
	my::string s1("abcabcd");
	my::string s2("abcd");

	cout << s1.erase(0, 2);

	/*cout << (s2 >= s1) << endl;*/

	/*my::string s2("fuck you");


	my::string::iterator it = s1.begin();
	auto io = s2.begin();

	while (it != s1.end())
	{
		cout << *it << endl;
		it++;

	}*/
	/*s1 += "a";
	cout << s1 << endl;

	s1 += "sssssssssss";
	cout << s1 << endl;
*/

	/*s1.push_back('c');
	cout << s1 << endl;

	const char* p = "sssssssssss";

	s2.append(p);
	cout << s2 << endl;*/

	/*s1.resize(20);
	s1[19] = 'x';
	std::cout << s1 <<std::endl;*/

	// s1.reserve(40);
	/*my::string s2;
	s2 = s1;
	my::string s3(s1);
	std::cout << s1[1] << std::endl;

	my::string s4("bit");
	my::swap(s1, s4);*/
}
#pragma once


#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<assert.h>

namespace my
{


	class string
	{
		friend std::istream& operator >> (std::istream& io, string& s);
		friend std::ostream& operator << (std::ostream& i, string& s);
		friend void swap(string& s1, string& s2);
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return this->_str;
		}

		const_iterator begin() const   //重载
		{
			return this->_str;
		}

		iterator end()
		{
			return this->_str + _size;
		}

		const_iterator end() const
		{
			return this->_str + _size;
		}


		string(const char* p = "")
		{
			_size = strlen(p);
			_capacity = _size == 0 ? 5 : _size * 2;
			_str = new char[_capacity + 1];
			strcpy(_str, p);
		}


		string(const string& s)  //现代写法
			:_str(new char[strlen(s._str) + 1])
		{
			_size = s._size;
			_capacity = s._capacity;
			strcpy(_str, s._str);
		}



		string& operator=(string s) //现代写法
		{
			_size = s._size;
			_capacity = s._capacity;
			std::swap(_str, s._str);
			return *this;
		}



		char& operator[](int pos)
		{
			assert(pos < _size);
			return this->_str[pos];
		}

		char& operator[](int pos)const
		{
			assert(pos < _size);
			return this->_str[pos];
		}

		~string()
		{
			delete[]_str;
			_size = 0;
			_capacity = 0;
		}

		void reserve(int capacity)
		{
			if (capacity > _capacity)
			{
				_capacity = capacity;

				char* temp = new char[_capacity + 1];
				for (int i = 0; i < _size; i++)
				{
					temp[i] = _str[i];
				}
				delete[]_str;
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
			_str[_size] = p;
			_size++;
			_str[_size] = '\0';

		}

		string& append(const string& str, size_t subpos, size_t sublen)  //subpos是拷贝的位置，sublen是拷贝多少个字符
		{
			int len = sublen;
			if (sublen + subpos - 1 > strlen(str._str)) //如果sublen超出了str的范围默认拷贝str后所有字符
			{
				len = strlen(str._str) - subpos + 1;
			}

			if (_size + len > _capacity)
			{
				reserve(len + _size);
			}

			for (int i = 0; i < len; i++)
			{
				_str[_size + i] = str[subpos - 1 + i];
			}
			_size += len;
			_str[_size] = '\0';
			return *this;


		}


		string& append(const char* p)
		{
			int len = strlen(p);
			if (_size + len > _capacity)
			{
				reserve(len + _size);
			}

			for (int i = 0; i < len; i++)
			{
				_str[_size + i] = p[i];
			}
			_size += len;
			_str[_size] = '\0';

			return *this;
		}
		const char* c_str()
		{
			return _str;
		}

		bool operator<(const string& s)
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

		bool operator<=(const string& s)
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

		bool operator>(const string& s)
		{
			if (*this <= s)
				return false;
			else
				return true;

		}

		bool operator>=(const string& s)
		{
			if (*this < s)
				return false;
			else
				return true;
		}

		bool operator==(const string& s)
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

		bool operator!=(const string& s)
		{
			if (*this == s)
				return false;
			else
				return true;

		}



		// 返回c在string中第一次出现的位置

		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == c)
					return i;
			}
			return -1;
		}

		// 返回子串s在string中第一次出现的位置

		size_t find(const char* s, size_t pos = 0) const
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

		// 在pos位置上插入字符c/字符串str，并返回该字符的位置

		string& insert(size_t pos, char c)
		{
			if (pos > _size)
				return *this;
			else
			{
				this->resize(_size + 1);
				int i;
				for (i = _size - 1; i >= (int)pos; i--) //注意size_t无符号的问题
				{
					_str[i + 1] = _str[i];
				}
				_str[pos] = c;
				return *this;
			}

		}

		string& insert(size_t pos, const char* str)
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



		// 删除pos位置上的元素，并返回该元素的下一个位置

		string& erase(size_t pos, size_t len)
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
		char* _str;
		size_t _size;
		size_t _capacity;
	};










	void swap(my::string& s1, my::string& s2)
	{
		std::swap(s1._size, s2._size);
		std::swap(s1._capacity, s2._capacity);
		std::swap(s1._str, s2._str);
	}
	std::ostream& operator << (std::ostream& io, string& s)
	{
		for (int i = 0; i < s._size; i++)
		{
			io << s[i];
		}
		return io;
	}

	std::istream& operator >> (std::istream& io, string& s)
	{
		char c = 'o';
		while (c != '\n')
		{
			io.get(c);
			s.push_back(c);
		}


		return io;
	}

	string& operator+=(string& s, char p)
	{
		s.push_back(p);

		return s;
	}

	string& operator+=(string& s, const char* p)
	{
		s.append(p);
		return s;

	}

}


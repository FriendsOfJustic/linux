#define _CRT_SECURE_NO_WARNINGS 1

#include<cstring>
namespace sht
{
	template<class T>
	class vector;
}

template<class T>
class sht::vector
{
	typedef T* iterator;
	typedef T* input_iterrator;
	typedef const T* const_iteraror;

public:
	vector(const int n=0,const T& type=T() )
		:_start(nullptr)
		,_finish(nullptr)
		,_endofstorage(nullptr)
	{
		_start = new T[2*n];
		for (int i = 0; i < n; i++)
		{
			new(_start+i) T(type);
		}

		_finish = _start + n;
		_endofstorage = _start + 2*n;
	}


	vector(input_iterrator first, input_iterrator last)
		:_start(nullptr)
		, _finish(nullptr)
		, _endofstorage(nullptr)
	{
		_start = new T[first - last];

		int size = first - last;
		_finish = _endofstorage =_start + size;

		for (int i = 0; i < size; i++)
		{
			_start[i] = first[i];
		}
	}

	vector(const vector<T>& v)
		:_start(nullptr)
		, _finish(nullptr)
		, _endofstorage(nullptr)
	{
		vector<T> tmp(v.size());
		for (int i = 0; i < v.size(); i++)
		{
			tmp._start[i] = v._start[i];
		}
		swap(tmp);

	}

	vector<T>& operator= (vector<T> tmp)
	{
		swap(tmp);

		return *this;


	}

	size_t size() const
	{
		return _finish - _start;

	}

	size_t capacity() const
	{
		return _endofstorage -_start;
	}

	~vector()
	{
		delete[] _start;
		_start = _finish = _endofstorage;
	}


	void resize(const int x=0)
	{
		if (_start + x >= _endofstorage)
		{
			reserve(2 * x);
		}
		_finish = _start + x;

	}


	void reserve(const int n=0)
	{
		if ( capacity() < n)
		{
			iterator temp = new T[n];
			int size = _finish - _start;

			for (int i = 0; i < size; i++)
			{
				temp[i] = _start[i];
			}

			delete[]_start;
			_start = temp;
			_finish = temp + size;
			_endofstorage = temp + n ;
		}
	}

	void push_back(const T& x)
	{
		if (size()+1 >= capacity() )
		{
			if (_endofstorage - _start == 0)
				reserve(1);
			else
				reserve(2 * (_endofstorage - _start));
		}
		*_finish = x;
		_finish++;
	}

	iterator begin()
	{
		return _start;
	}



	iterator end()
	{
		return _finish;
	}



	iterator& operator [](const int x)
	{
		assert(_start + x < _finish);

		return _start + x;
	}

	


	void print() const
	{
		for (int i = 0; i < (int)size(); i++)
		{
			std::cout << _start[i] << " ";
		}
		std::cout << std::endl;
	}



	

	void pop_back()
	{
		_finish--;
	}

	void swap(vector<T>& tmp)
	{
		std::swap(tmp._start, _start);
		std::swap(tmp._finish, _finish);
		std::swap(tmp._endofstorage, _endofstorage);
	}

	iterator insert(iterator pos, const T& x)
	{
		if (size() + 1 >= capacity())
		{
			if (capacity() == 0)
				reserve(10);
			else
				reserve(size() + 1);
		}
		else
		{
			iterator cur = end() - 1;

			while (cur >= pos)
			{
				*(cur + 1) = *cur;
				cur--;

			}

			*(cur+1) = x;
			_finish++;
		}
		return pos;
	}

	iterator erase(iterator pos)
	{
		iterator cur = pos;

		while (cur != end() - 1)
		{
			*cur = *(cur + 1);
			cur++;
		}
		
		_finish--;
		return pos;

	}


private:
	iterator _start;
	iterator _finish;
	iterator _endofstorage;

};
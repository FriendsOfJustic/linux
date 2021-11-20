#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
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
		_start = new T[2*n+1];
		for (int i = 0; i < n; i++)
		{
			new(_start+i) T(type);
		}

		_finish = _start + n;
		_endofstorage = _start + 2*n;
	}


	vector(input_iterrator first, input_iterrator last)
	{
		int s = last - first;
		_start = new T[2*s+1];

		_finish = _start + size;

		_endofstorage = _start + 2 * size;

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

	//vector<T>& operator= (vector<T> tmp) //现代写法 （优化）对基础版本的优化，拷贝构造直接在传值的时候就完成
	//{
	//	swap(tmp);
	//	return *this;
	//}

	//vector<T>& operator= (vector<T>& tmp) //现代写法 （基础）
	//{
	//	vector<T> p(tmp);
	//	swap(p);
	//	return *this;
	//}

	vector<T>& operator=(vector<T>& tmp)  // 传统写法
	{
		_start = new T[tmp._endofstorage - tmp._start];
		_finish = _start + tmp._finish - tmp._start;
		_endofstorage = _start + tmp._endofstorage - tmp._start;
		int sz=tmp._finish - tmp._start;

		for (int i = 0; i < sz; i++)
		{
			_start[i] = tmp._start;
		}

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


	void reserve(const int n=0)  //这里只增加空间，不减少空间
	{
		if ( capacity() < n)
		{
			iterator temp = new T[n+1];
			int size = _finish - _start; //记录新开辟空间的_finish的空间
			 
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

	//void push_back(const T& x)
	//{
	//	if (size()+1 > capacity() )
	//	{
	//		if (_endofstorage - _start == 0) //考虑头部问题，因为构造函数对没有传参的_start赋的是NULL
	//			reserve(1);
	//		else
	//			reserve(2 * (_endofstorage - _start));
	//	}
	//	*_finish = x;
	//	_finish++;
	//}


	void push_back(const T& x) //套用insert版本
	{
		insert(_finish + 1, x);

	}





	iterator begin()
	{
		return _start;
	}

	/*const_iterator begin() const
	{
		return _start;
	}*/


	/*const_iterator end() const
	{
		return _finish;
	}*/


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

	iterator insert(iterator pos, const T& x)  //这个要注意增容过后地址发生改变的情况
	{

		int sz = pos - _start;  //记录修改位置相对于_start的相对位置，防止增容后找不到修改数据的位置
		iterator newpos = pos;
		if (size() + 1 >= capacity())
		{
			if (capacity() == 0)
				reserve(1);
			else
				reserve(size() + 1);
			newpos = _start + sz; 
			pos = NULL;
		}
		iterator cur = end() - 1;

		while (cur >= newpos)
		{
			*(cur + 1) = *cur;
			cur--;

		}

		*(cur+1) = x;
		_finish++;
		return newpos;
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


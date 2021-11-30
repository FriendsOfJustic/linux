#pragma once


#include<vector>
#include<stdlib.h>
#include<deque>

namespace sht
{
	template<class T,class container = std::deque<T> >
	class stack
	{
	public:
		stack()
		{
		}

		void push(const T& x)
		{
			v.push_back(x);
		}

		void pop()
		{
			v.pop_back();
		}

		T& top()
		{
			return v.back();
		}

		const T& top()const
		{
			return v.back();

		}

		size_t size()const
		{
			return v.size();
		}

		bool empty()const
		{
			return v.empty();
		}

	private:
		container v;

	};


}
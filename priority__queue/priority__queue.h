#pragma once


#include<iostream>
#include<vector>

template<class T>   //less排的是大堆
class less
{
public:
	bool operator ()(const T &a,const T&b)
	{
		return a > b;
	}
};


template<class T>   //less排的是大堆
class greater
{
public:
	bool operator ()(const T& a, const T& b)
	{
		return a < b;
	}
};




namespace sht
{
	template<class T,class container = std::vector<T> ,class compare=less<T>> //默认排的是大堆
	class priority__queue
	{
	public:
		compare com;
		void Adjustup(int child)
		{
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_con[child], _con[parent]))  //主要还是看这个地方的大小比较compare(_con[child] , _con[parent])
				{
					std::swap(_con[child], _con[parent]);

					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;

			}

		}

		void Adjustdown(int parent)
		{
			int child = 2 * parent + 1;


			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child+1] , _con[child]))
				{
					child++;
				}

				if (com(_con[child], _con[parent]))
				{
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = 2 * parent + 1;

				}
				else
					break;

			}
		}



		void push(const T& x)
		{
			_con.push_back(x);
			Adjustup(_con.size() - 1);
		}

		const T& top()
		{
			return _con[0];
		}


		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			Adjustdown(0);

		}

		bool empty() const
		{
			return _con.empty();
		}

		size_t size()
		{
			return _con.size();
		}




	private:
		container _con;
	};

}
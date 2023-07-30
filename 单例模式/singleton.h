#pragma once
#include<map>
#include<mutex>


namespace sht
{
	////饿汉模式
	//class singleton
	//{
	//public:

	//	static singleton* getSingle()     //返回值只能返回指针因为拷贝和赋值都被禁用了
	//	{
	//		return &object;
	//	}

	//	map<string, int> m;
	//private:
	//	singleton()     //构造函数是不能delete的
	//	{

	//	}


	//	singleton(const singleton& x) = delete;      //拷贝一定需要delete
	//	singleton operator=(const singleton& x) = delete;    //赋值也需要delete



	//	static singleton object;
	//};



	//singleton singleton::object;




	class singleton
	{
	public:
		static singleton* getsingleton()
		{
			if (p == nullptr)
			{
				_mutex->lock();

				if (p == nullptr)
				{
					p = new singleton;
				}

				_mutex->unlock();
			}
			return p;
			
		}


		void print()
		{
			for (auto& e : m)
				cout << e.first << " " << e.second << endl;
		}

		map<string, int> m;
	private:
		singleton()
		{

		}
		singleton(const singleton& x) = delete;
		singleton operator=(const singleton& x) = delete;
		static singleton* p;
		static mutex* _mutex;
	};

	singleton* singleton::p=nullptr;
	mutex* singleton::_mutex = new mutex();
}


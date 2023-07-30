#pragma once
#include<map>
#include<mutex>


namespace sht
{
	////����ģʽ
	//class singleton
	//{
	//public:

	//	static singleton* getSingle()     //����ֵֻ�ܷ���ָ����Ϊ�����͸�ֵ����������
	//	{
	//		return &object;
	//	}

	//	map<string, int> m;
	//private:
	//	singleton()     //���캯���ǲ���delete��
	//	{

	//	}


	//	singleton(const singleton& x) = delete;      //����һ����Ҫdelete
	//	singleton operator=(const singleton& x) = delete;    //��ֵҲ��Ҫdelete



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


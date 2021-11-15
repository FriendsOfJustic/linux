#pragma once



#include<iostream>

namespace sht
{
	template<class T>
	struct _list__Node 
	{
		_list__Node* next;
		_list__Node* prev;
		T _val;

		_list__Node(const T& x = T() )
			:next(nullptr)
			,prev(nullptr)
		{
			_val = x;
		}
	};


	template<class T>
	struct list__iterator
	{

		_list__Node<T>* p;


		list__iterator(_list__Node<T>* temp)
			:p(temp)
		{}

		T& operator *()
		{
			return this->p->_val;
		}

		list__iterator& operator ++()
		{
			p = (p->next);
			return *this;
		}

		list__iterator operator ++(T)
		{
			list__iterator tmp(p);
			p = (p->next);
			return tmp;
		}

		list__iterator& operator --()
		{
			p = (p->prev);
			return *this;
		}

		bool operator != (const list__iterator& x)
		{
			return (this->p != x.p);
		}


	};

	template<class T>
	class list
	{
	public:
		typedef _list__Node<T> Node;
		typedef list__iterator<T> iterator;

		list()
			:head(nullptr)
		{
			head = new Node;
			head->next = head;
			head->prev = head;
		}

		void resize(const size_t& x,const T& n=T())
		{
			size_t num = size();

			if (num < x)
			{
				while (x != num)
				{
					push_back(n);
					x--;
				}
			}
			else
			{

			}

		}




		size_t size()
		{
			auto be = p.begin();
			auto en = p.end();
			size_t num = 0;

			while (be != en)
			{
				num++;
				++be;
			}
			return num;
		}


		void push_back(const T& x )
		{
			Node* newone = new Node(x);
			Node* tail = head->prev;

			tail->next = newone;
			newone->prev = tail;
			newone->next = head;
			head->prev = newone;


		}


		void pop_back()
		{

		}

		iterator end()
		{
			return iterator(head);
		}
		
		iterator begin()
		{
			return iterator(head->next);
			
		}





	private:
		Node* head;
	};
}






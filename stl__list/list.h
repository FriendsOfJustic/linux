#pragma once
#include<iostream>


namespace sht
{

	template<class T>
	struct DlistNode
	{
		DlistNode* next;
		DlistNode* prev;
		T data;


		DlistNode(T x=T() ) // 数据类型的构造函数
			:next(nullptr)
			,prev(nullptr)
			,data(x)
		{

		}
	};


	template<class T,class Ref,class Ptr>
	class list_iterator
	{
		typedef DlistNode<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;

	public:
		list_iterator(Node* x =nullptr)
			:p(x)
		{
		}

		list_iterator(const Self& l)
		{
			p = l.p;
		}



		Node* GetNode()
		{
			return p;
		}



		T& operator*()
		{
			return p->data;
		}

		Node* operator->()
		{
			return p;
		}

		Self& operator++()
		{
			p = p->next;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(p);
			p = p->next;
			return temp;

		}

		Self& operator--()
		{
			p = p->prev;
			return *this;
		}

		Self& operator--(int)
		{
			T temp = p->data;
			p = p->prev;
			return temp;
		}

		bool operator!=(const Self& l)
		{

			return p != l.p;

		}

		bool operator==(const Self& l)
		{
			return p == l.p;
		}

		

	private:
		Node* p;
	};



	template<class T>
	class list
	{
		typedef DlistNode<T> Node;
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T,const T&,const T*> const_iterator;

	public:

		list()
			:head(new Node)
		{
			head->next = head;
			head->prev = head;

		}


		/*void push_back(T x=T() )
		{

			Node* newNode = new Node(x);
			Node* tail = head->prev;
			tail->next = newNode;
			newNode->prev = tail;
			newNode->next = head;
			head->prev = newNode;
		}*/

		iterator begin()
		{
			return head->next;
		}

		iterator end()
		{
			return head;
		}


		const_iterator begin()const
		{
			return head->next;
		}

		const_iterator end() const 
		{
			return head;
		}



		// List Capacity

		size_t size()const
		{
			size_t sum = 0;
			auto it = begin();
			while (it != end())
			{
				sum++;
				it++;
			}
			return sum;
		}

		bool empty()const
		{
			return begin() == end();
		}



		////////////////////////////////////////////////////////////

		// List Access

		T& front()
		{
			return head->next->data;
		}

		const T& front()const
		{
			return head->next->data;

		}


		T& back()
		{
			return head->prev->data;
		}


		const T& back()const
		{
			return head->prev->data;
		}



		////////////////////////////////////////////////////////////

		// List Modify



		// 在pos位置前插入值为val的节点
		iterator insert(iterator pos, const T& val)
		{
			Node* before = pos->prev;
			Node* cur = pos->next->prev;

			Node* temp = new Node(val);

			before->next = temp;
			temp->prev = before;

			cur->prev = temp;
			temp->next = cur;

			return temp;
		}

		void push_back(const T& val)
		{ 
			insert(--begin(), val);
		}

		void pop_back() { erase(--end()); }

		void push_front(const T& val) { insert(begin(), val); }

		void pop_front() { erase(begin()); }

		

		

		// 删除pos位置的节点，返回该节点的下一个位置

		iterator erase(iterator pos)
		{
			Node* before = pos->prev;
			Node* after = pos->next;
			Node* cur = pos->next->prev;

			before->next = after;
			after->prev = before;
			delete cur;

			return after;


		}

		void clear()
		{
			auto it = begin();
			while (it != end())
			{
				Node* tmp = it.GetNode();
				it++;
				delete tmp;
			}

			Node* tmp = it.GetNode();
			tmp->next = tmp;
			tmp->prev = tmp;

		}

		void swap(list<T>& l)
		{
			::swap(head, l.head);
		}






	private:
		Node* head;  //为什么是头结点？因为抓住了头结点就相当于抓住了一串项链的“头”

	};


}
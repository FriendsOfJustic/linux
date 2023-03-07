#pragma once

#include"RedBlackTree.h"
namespace sht
{
	template<class key>
	class set
	{
	private:
		struct Get_key
		{
			key operator()(const key& x)
			{
				return x;
			}
		};

	public:
		typedef typename sht::RBTree < key, key, Get_key>::const_iterator iterator;
		typedef typename sht::RBTree < key, key, Get_key>::const_iterator const_iterator;

		iterator begin()
		{
			return tree.begin();
		}


		iterator end()
		{
			return tree.end();
		}


		const_iterator begin() const
		{
			return tree.begin();
		}


		const_iterator end() const 
		{
			return tree.end();
		}

		std::pair<iterator, bool> insert(const key& x)
		{
			return tree.insert(x);
		}

		void BFS()
		{
			tree.BFS();
		}
	private:

		RBTree < key, const key, Get_key> tree;

	};
}
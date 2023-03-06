#pragma once

#include"HashTable.h"

namespace sht
{
	template<class K, class V,class Hash=HashFunc<K> >
	class unordered_map
	{
		struct Get_Key
		{
			K operator()(const std::pair<K,V>& x )
			{
				return x.first;
			}
		};
	public:
		typedef std::pair<const K, V> ValueType;
		typedef sht::HashTable_iterator<ValueType,ValueType&,ValueType*,Hash,Get_Key> iterator;
		

		
		
		iterator begin()
		{
			return T.begin();
		}


		iterator end()
		{
			return T.end();
		}

		std::pair<iterator,bool>  insert(const ValueType& x)
		{
			return T.insert(x);
		}

		V& operator[](const K& x)
		{
			return (T.insert(std::make_pair(x, V())).first)->second;
		}




	private:
		HashTable<K, ValueType, Hash,Get_Key> T;
	};
}
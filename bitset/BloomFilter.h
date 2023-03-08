#pragma once

#include"bitset.h"
#include<string>


namespace sht
{
	struct BKDRHash
	{
		size_t operator()(const std::string& key)
		{
			size_t hash = 0;
			for (auto ch : key)
			{
				hash *= 131;
				hash += ch;
			}
			return hash;
		}
	};

	struct APHash
	{
		size_t operator()(const std::string& key)
		{
			unsigned int hash = 0;
			int i = 0;

			for (auto ch : key)
			{
				if ((i & 1) == 0)
				{
					hash ^= ((hash << 7) ^ (ch) ^ (hash >> 3));
				}
				else
				{
					hash ^= (~((hash << 11) ^ (ch) ^ (hash >> 5)));
				}

				++i;
			}

			return hash;
		}
	};

	struct DJBHash
	{
		size_t operator()(const std::string& key)
		{
			unsigned int hash = 5381;

			for (auto ch : key)
			{
				hash += (hash << 5) + ch;
			}

			return hash;
		}
	};

	struct JSHash
	{
		size_t operator()(const std::string& s)
		{
			size_t hash = 1315423911;
			for (auto ch : s)
			{
				hash ^= ((hash << 5) + ch + (hash >> 2));
			}
			return hash;
		}
	};
	template<class k,size_t N=100>
	class BloomFilter
	{
	public:
		void set(const k& x)
		{
			size_t H1 = BKDRHash()(x)%sz;
			size_t H2 = DJBHash()(x) % sz;
			size_t H3 = JSHash()(x) % sz;
			size_t H4 = APHash()(x) % sz;


			bitset.set(H1);
			bitset.set(H2);
			bitset.set(H3);
			bitset.set(H4);


			return;
		}


		bool test(const k& x)
		{
			size_t H1 = BKDRHash()(x) % sz;
			size_t H2 = DJBHash()(x) % sz;
			size_t H3 = JSHash()(x) % sz;
			size_t H4 = APHash()(x) % sz;
			if (bitset.test(H1) == false)
				return false;
			if (bitset.test(H2) == false)
				return false;
			if (bitset.test(H3) == false)
				return false;
			if (bitset.test(H4) == false)
				return false;

			return true;

		}

	private:
		sht::Bitset< N*6> bitset;
		int sz = N * 6;

	};
}
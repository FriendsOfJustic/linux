#pragma once

#include<vector>

namespace sht
{
	template<size_t N=10>
	class Bitset
	{
	public:
		Bitset()
		{
			bs.resize(N / 8 + 1);
		}


		void set(size_t x)
		{
			int i = x / 8;
			int j = x % 8;


			bs[i] = bs[i] | (1 << j);
		}


		void reset(size_t x)
		{
			int i = x / 8;
			int j = x % 8;

			bs[i] = bs[i] & (~(1 << j));
		}

		bool test(size_t x)
		{
			int i = x / 8;
			int j = x % 8;


			if (((bs[i] >> j) & 1) == 1)
				return true;
			else
				return false;

		}
	private:
		std::vector<char> bs;
	};
}
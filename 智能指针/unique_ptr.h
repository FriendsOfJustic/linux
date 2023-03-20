#pragma once

namespace sht
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr = nullptr, int count = 1)
			:_ptr(ptr)
		{
			_count = new int(count);
		}



		unique_ptr(const unique_ptr& x)
		{
			_ptr = x._ptr;
			_count = x._count;
			(*_count)++;
		}


		unique_ptr& operator =(const unique_ptr& x)
		{
			if (_ptr != x._ptr)
			{
				(*_count)--;
				if ((*_count) == 0)
				{
					delete _ptr;
					delete _count;
				}
				_ptr = x._ptr;
				_count = x._count;
				(*_count)++;
			}
			else      //如果指向相同资源的智能指针相互赋值 需要单独讨论
				return *this;
		}

		~unique_ptr()
		{
			if (*_count == 0)
			{
				delete _ptr;
				delete _count;
			}
			else
				(*_count)--;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _count;
	};
}
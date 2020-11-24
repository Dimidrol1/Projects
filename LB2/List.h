#pragma once
#include <iostream>
template<typename T, size_t max_size>
class List
{
private:
	size_t count_elemet;
	T mas[max_size];
public:
	
	List()
	{
		count_elemet = 0;
	}
	size_t size()
	{
		return count_elemet;
	}

	void operator+= (const T &obj)
	{
		try
		{
			if (count_elemet == max_size)
				throw std::exception("array is full");

			mas[count_elemet] = obj;
			count_elemet++;
		}
		catch (const std::exception&ex)
		{
			std::cout << ex.what();
		}

	}

	const T& operator [] (int index) const
	{
		try
		{
			if (index > max_size - 1 || index < 0)
				throw std::exception("out of range ");

			return mas[index];
		}
		catch (const std::exception&ex)
		{
			std::cout << ex.what();
		}
	}
};
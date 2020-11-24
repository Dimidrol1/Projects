#pragma once
#include<iostream>
#include <fstream>
#include <string>
namespace l1
{
	class Txt
	{
	public:
		Txt();
		Txt(const char *);
		Txt(const Txt&);
		Txt(Txt&&);
		~Txt();
		size_t size() const;

		Txt & operator= (const Txt&);
		Txt & operator= (Txt&&);
	private:
		std::string *pstr;
		size_t count_write;
	};

}